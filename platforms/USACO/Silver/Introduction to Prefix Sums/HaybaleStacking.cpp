/* USACO 2012 January Contest, Bronze Division
Problem 2. Haybale Stacking */
// Problem: https://www.spoj.com/problems/HAYBALE/


#include <iostream> 
#include <vector>
#include <algorithm>
 
using ll = long long;
 
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

/* On 26 July 2023, my code encountered a TLE error due to the use of nested for loops for input processing.
However, this approach was unnecessary and highly inefficient. By keeping track of only the first and last elements of
the added haybales' group, we can apply the prefix sum technique to efficiently compute the median height of a stack,
which is represented by the element at index (N + 1) / 2 in the "prefixSum" list. */
void solve()
{
    int N, K, from, to;
    std::cin >> N >> K;
    std::vector<int> prefixSum(N + 1);

    for (int i = 0; i < K; ++i)
    {
        std::cin >> from >> to;
        ++prefixSum[from];
        --prefixSum[to + 1];
    }

    for (int i = 1; i <= N; ++i)
    {
        prefixSum[i] += prefixSum[i - 1];
    }

    std::sort(all(prefixSum));
    std::cout << prefixSum[(N + 1) / 2] << '\n';
}
 
int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
