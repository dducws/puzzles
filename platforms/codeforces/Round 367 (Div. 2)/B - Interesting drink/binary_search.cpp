// Problem: https://codeforces.com/contest/706/problem/B


#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int binarySearch(const std::vector<int>& prices, int m)
{
    int l {0}, r {sz(prices) - 1}, mid {};
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (prices[mid] == m)
        {
            if (mid < sz(prices) - 1 && prices[mid + 1] == m)
            {
                /* (On 1 August 2023) In some cases, there might be multiple duplicates with the same price m. To get the correct count of shops,
                we need to find the rightmost index where prices[r] == m instead of the leftmost index, so it would be much more 
                efficient if we loop from the right through the left. */ 
                while (prices[r] > m)
                {
                    --r;
                }
                mid = r;
            }

            return mid + 1;
        }
        else if (prices[mid] < m)
            l = mid + 1;
        else 
            r = mid - 1;
    }

    // If m is not found in the prices array, return the index where m should be inserted
    return r + 1;
}

void solve()
{
    int n, q, m;
    std::cin >> n; 
    std::vector<int> prices (n);
    for (int i {}; i < n; ++i)
    {
        std::cin >> prices[i];
    }
    std::sort(all(prices));
    std::cin >> q;
    while (q--)
    {
        std::cin >> m;
        std::cout << binarySearch(prices, m) << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}