// Problem: https://codeforces.com/contest/1839/problem/B


#include <iostream> 
#include <vector>
#include <algorithm>
using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

void solve()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> lamps(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> lamps[i].first >> lamps[i].second;
        }
        std::sort(all(lamps), comparePairs);

        std::vector<int> turnedOnLamps;
        turnedOnLamps.reserve(n);
        /* maxA keeps track of the maximum a value encountered among the turned on lamps
        and ensures that lamps with smaller or equal a values are broken when necessary. */
        int maxA {}; 
        ll points {}; 

        // Iterate over the lamps in the sorted vector
        for (int i {}; i < n; ++i)
        {
            int numTurnedOn = turnedOnLamps.size();
            // Check if the lamp can be turned on
            if (lamps[i].first > numTurnedOn && lamps[i].first > maxA)
            {
                turnedOnLamps.push_back(lamps[i].first);
                points += lamps[i].second;
                int mark {};
                // Find the index up to which lamps should be removed from the turnedOnLamps vector
                while (turnedOnLamps[mark] <= numTurnedOn && mark < numTurnedOn)
                {
                    mark++;
                }
                turnedOnLamps.erase(turnedOnLamps.begin(), turnedOnLamps.begin() + mark);
                maxA = numTurnedOn;
            }
        }

        std::cout << points << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}