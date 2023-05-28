// Codeforces Round 861 (Div. 2) 
// Problem: https://codeforces.com/contest/1808/problem/B
// Solution: https://usaco.guide/problems/cf-playing-in-a-casino/solution

#include <iostream> 
#include <vector> 
#include <algorithm>

void solve()
{
    int t; 
    std::cin >> t; 

    while (t--)  
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> c (n, std::vector<int> (m));

        for (int i {}; i < n; ++i)
        {
            for (int j {}; j < m; ++j)
            {
                std::cin >> c[i][j];
            }
        }

        long long winnings {};

        if (n > 1)
        {
            for (int i {}; i < m; ++i)
            {
                std::vector<long long> temp (n);
                long long sum {};

                for (int j {}; j < n; ++j)
                {
                    temp[j] = c[j][i];
                    sum += temp[j];
                }
                
                std::sort(temp.begin(), temp.end());
                long long current {};

                // Iterate over each player (except the last one)
                for (int j {}; j < n - 1; ++j)
                {
                    current += temp[j];
                    winnings += llabs((sum - current) - (n - 1 - j) * temp[j]);
                }
            }
        }

        std::cout << winnings << '\n';
    }
}

int main()
{
    solve();
}