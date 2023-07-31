// Problem: https://codeforces.com/contest/816/problem/B


#include <iostream>
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int MAX = 200000;
int count[MAX + 1] {}, prefixSums[MAX + 1] {};

void solve()
{
    int n, k, q, l, r;
    std::cin >> n >> k >> q;
    for (int i{}; i < n; ++i)
    {
        std::cin >> l >> r;
        ++count[l];
        --count[r + 1];
    }

    /* Instead of accumulating the prefix sums in a separate loop, we can use a variable to keep track of the current prefix sum
    and update it on the fly while processing each recipe. This way, we avoid the need for a separate loop and reduce the running time almost by half. */
    int currentSum {};
    for (int i {1}; i <= MAX; ++i)
    {
        count[i] += count[i - 1];
        if (count[i] >= k)
            ++currentSum;
        prefixSums[i] = currentSum; 
    }

    while (q--)
    {
        std::cin >> l >> r;
        std::cout << prefixSums[r] - prefixSums[l - 1] << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
