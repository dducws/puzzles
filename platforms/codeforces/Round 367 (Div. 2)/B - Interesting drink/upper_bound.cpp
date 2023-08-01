// Problem: https://codeforces.com/contest/706/problem/B


#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int n, q, m;
    std::cin >> n;
    std::vector<int> x(n);
    for (int i {}; i < n; ++i)
    {
        std::cin >> x[i];
    }
    std::sort(all(x));
    std::cin >> q;
    while (q--)
    {
        std::cin >> m;
        // Use std::upper_bound to find the first element greater than m in the sorted prices vector.
        int shops = std::upper_bound(all(x), m) - x.begin();
        std::cout << shops << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
