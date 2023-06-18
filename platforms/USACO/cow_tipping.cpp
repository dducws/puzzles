/* USACO 2017 January Contest, Bronze
Problem 3. Cow Tipping */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=689
// Explanation: https://www.youtube.com/watch?v=RoOaXLTFS3E


#include <iostream> 
#include <vector>

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
    std::vector<std::string> grid (N);

    for (int i {}; i < N; ++i)
    {
        std::cin >> grid[i];
    }

    int times {};

    for (int i {N - 1}; i >= 0; --i)
    {
        for (int j {N - 1}; j >= 0; --j)
        {
            if (grid[i][j] == '1')
            {
                ++times;
                for (int x {i}; x >= 0; --x)
                {
                    for (int y {j}; y >= 0; --y)
                    {
                        grid[x][y] = (grid[x][y] == '1') ? '0' : '1';
                    }                
                }
                /*
                std::cout << '\n';
                for (const auto line : grid)
                    std::cout << line << '\n';
                std::cout << '\n';
                */
            }
        }
    }

    std::cout << times << '\n';
}

int main()
{
    setIO("cowtip"); 
    solve();
}
