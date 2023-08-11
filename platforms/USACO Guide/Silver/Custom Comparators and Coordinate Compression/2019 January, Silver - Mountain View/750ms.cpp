// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=896


#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>

using ll = long long;

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

const double epsilon = 1e-9;

bool sortByYCoordinate(const std::pair<int, int>& A, const std::pair<int, int>& B)
{
    return A.second > B.second;   
}

// Barycentric coordinates
bool isInside(const std::pair<double, double>& A, const std::pair<double, double>& B,
             const std::pair<double, double>& C, const std::pair<double, double>& P, double detT)
{
    double alpha = ((B.second - C.second) * (P.first - C.first) + (C.first - B.first) * (P.second - C.second)) / detT;
    double beta = ((C.second - A.second) * (P.first - C.first) + (A.first - C.first) * (P.second - C.second)) / detT;
    double gamma = 1.0 - alpha - beta;
    
    /* In the case of multiple peaks with the same y-coordinates, such as the eleventh test case,
    the subtraction of gamma from 1 may lead to rounding errors, causing gamma to have a very small negative value. 
    This condition addresses such precision issues and sets gamma to zero if its absolute value is 
    within the specified epsilon range.*/
    if (std::abs(gamma) < epsilon)
        gamma = 0.0;

    return (alpha >= 0) && (beta >= 0) && (gamma >= 0);
}

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> peaks (N);
    /* The use of std::unordered_map is a memory-efficient choice over std::set in this context.
    Ideally, we would prefer to use std::unordered_set, but to achieve that, we would need to define a specific hash function
    capable of handling the type std::pair<int, int>. By utilizing std::unordered_map, we can efficiently associate each
    peak's x-coordinate with its corresponding y-coordinate, effectively managing the mountain data. */
    std::unordered_map<int, int> seen; 
    for (auto& peak : peaks)
    {
        std::cin >> peak.first >> peak.second;
        seen[peak.first] = peak.second;
    }
    std::sort(all(peaks), sortByYCoordinate);

    for (int i = 0; i < N; ++i)
    {
        std::pair<double, double> A = {static_cast<double>(peaks[i].first), static_cast<double>(peaks[i].second)};
        std::pair<double, double> B = {static_cast<double>(peaks[i].first - peaks[i].second), 0.0};
        std::pair<double, double> C = {static_cast<double>(peaks[i].first + peaks[i].second), 0.0};
        double detT = (B.second - C.second) * (A.first - C.first) + (C.first - B.first) * (A.second - C.second);
        auto it = seen.begin();
        while (it != seen.end())
        {
            // This condition ensures that the peaks being compared are not the same.
            if (it->first != peaks[i].first || it->second != peaks[i].second)
            {
                std::pair<double, double> P = {static_cast<double>(it->first), static_cast<double>(it->second)};
                // If P lies within the right isosceles triangle ABC, we remove it from the map and move to the next iterator.
                if (isInside(A, B, C, P, detT))
                    it = seen.erase(it);
                else
                    ++it;
            }
            else
                ++it;
        }
    }

    std::cout << sz(seen);
}

int main()
{
    setIO("mountains");
    solve();
}