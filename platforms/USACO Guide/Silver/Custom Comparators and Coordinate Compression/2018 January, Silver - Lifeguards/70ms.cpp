// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=786
// Source: Cao Duy Nguyen (https://usaco.guide/problems/usaco-786/user-solutions)


#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int INFINITY_VALUE = 1e9;

void solve() 
{
    int numLifeguards;
    std::cin >> numLifeguards;
    
    // Store the shifts of lifeguards, including 2 dummy shifts for boundary cases
    std::vector<std::pair<int, int>> shifts (numLifeguards + 2);
    
    for (int i = 1; i <= numLifeguards; i++) 
    {
        std::cin >> shifts[i].first >> shifts[i].second;
    }
    
    shifts[numLifeguards + 1] = {INFINITY_VALUE, INFINITY_VALUE};
    std::sort(all(shifts));  

    int totalCoverage {}, minTimeLoss {INFINITY_VALUE + 1}, maxEndSoFar {-1}, currentIntervalEnd {-1}, currentMinLoss {}, currentIntervalStart {};
    for (int i {1}; i <= numLifeguards; i++) 
    {
        // Calculate total time that is covered by lifeguards
        currentIntervalStart = std::max(shifts[i].first, shifts[i - 1].second);
        currentIntervalEnd = std::min(shifts[i].second, shifts[i + 1].first);
        maxEndSoFar = std::max(maxEndSoFar, currentIntervalStart);
        totalCoverage += std::max(0, shifts[i].second - maxEndSoFar);

        // Find the lifeguard who has the minimum time alone.
        currentMinLoss = std::max(0, currentIntervalEnd - currentIntervalStart);
        minTimeLoss = std::min(minTimeLoss, currentMinLoss);
    }
    
    std::cout << totalCoverage - minTimeLoss;
}

int main() 
{
    setIO("lifeguards");
    solve();
}
