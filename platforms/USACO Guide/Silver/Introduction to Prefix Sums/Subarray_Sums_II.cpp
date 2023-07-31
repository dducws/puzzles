// Problem: https://cses.fi/problemset/task/1661


#include <iostream> 
#include <vector>
#include <unordered_map>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<ll> a(n + 1);
    std::unordered_map<ll, int> count;
    ll subArrays {};
    for (int i {1}; i <= n; ++i)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
        /* Without the condition 'a[i] != 0', the subarrays with sum 'x' will
        be counted twice: once during this input loop and again in the loop below. */
        if (a[i] == x && a[i] != 0)
            ++subArrays;
        
        ++count[a[i]];
    }

    for (int i {1}; i <= n; ++i)
    {
        subArrays += count[a[i] + x];
        --count[a[i]];
    }

    std::cout << subArrays << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}