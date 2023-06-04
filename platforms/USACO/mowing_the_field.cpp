/* USACO 2016 January Contest, Bronze
Problem 3. Mowing the Field */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=593
// Edited: chatGPT

#include <iostream> 
#include <vector>
#include <map>

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

void solve()
{
    int N;  
    std::cin >> N;

    int current_time_unit {1};
    std::map<int, std::pair<int, int>> timeline;
    std::pair<int, int> current_position {0, 0};

    for (int i {}; i < N; ++i)
    {
        char direction; 
        int distance; 
        std::cin >> direction >> distance;

        while (distance--)
        {
            if (direction == 'N')
                ++current_position.second;
            else if (direction == 'E')
                ++current_position.first;
            else if (direction == 'S')
                --current_position.second;
            else if (direction == 'W')
                --current_position.first;
            
            timeline[current_time_unit++] = current_position;
        }
    }

    int x {current_time_unit};
    for (auto it = timeline.begin(); it != timeline.end(); ++it)
    {
        for (auto next_it = std::next(it); next_it != timeline.end(); ++next_it)
        {
            if (it->second == next_it->second)
            {
                x = std::min(x, next_it->first - it->first);
            }
        }
    }

    if (x != current_time_unit)
        std::cout << x << '\n';
    else 
        std::cout << -1 << '\n';
}

int main()
{
    setIO("mowing"); 
    solve();
}
