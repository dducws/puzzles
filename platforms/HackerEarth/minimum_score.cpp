// Problem: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/minimum-score-1528c5c0/

#include <iostream> 
#include <vector>
 
using ll = long long;
 
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
void solve()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> array (N);
    for (int i {}; i < N; ++i)
    {
        std::cin >> array[i];
    }
 
    if (N == K)
    {
        std::cout << 0 << '\n';
        for (int i {1}; i <= N; ++i)
        {
            std::cout << i << ' ' << i << '\n';
        }
    }
    else 
    {
        int count {}, sum {};
        std::vector<std::pair<int, int>> subArrays;
        for (int i {}; i < N - 1; ++i)
        {
            if (array[i] != array[i + 1])
                ++count; 
        }

        if (count + 1 > K)
        {
            sum = 1;
            for (int i {}; i < K; ++i)
            {
                subArrays.push_back({i, i});
            }
            subArrays.back().second = N - 1;
        }
        else 
        {
            int left {};
            if (count + 1 == K)
            {
                for (int i {}; i < N - 1; ++i)
                {
                    if (array[i] != array[i + 1])
                    {
                        subArrays.push_back({left, i});
                        left = i + 1;
                    }
                }
                subArrays.push_back({left, N - 1});
            }
            else if (count == 0)
            {
                for (int i {}; i < K; ++i)
                {
                    subArrays.push_back({i, i});
                }
                subArrays.back().second = N - 1;
            }
            else 
            {
                int count2 {}, left {};
                for (int i {}; i < N - 1; ++i)
                {
                    if (array[i] != array[i + 1])
                        ++count2;
                    subArrays.push_back({i, i});
                    if (K - sz(subArrays) == count - count2 + 1)
                    {
                        left = i + 1;
                        break;
                    }
                }

                for (int i = left; i < N - 1; ++i)
                {
                    if (array[i] != array[i + 1])
                    {
                        subArrays.push_back({left, i});
                        left = i + 1;
                    }
                }
                subArrays.push_back({left, N - 1});
            }
        }
        
        std::cout << sum << '\n';
        for (const auto& [left, right] : subArrays)
        {
            std::cout << left + 1 << ' ' << right + 1 << '\n';   
        }
    }
}
 
int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
