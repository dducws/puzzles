// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
// Solution: https://usaco.guide/problems/usaco-595-subsequences-summing-to-sevens/solution


#include <iostream> 
#include <vector>
#include <algorithm>

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

const int MOD {7};

/* This is a cleaner and more efficient solution than mine. I rewrote it based on the solution from USACO.*/
void solve()
{
    int N, largest_group {};
    std::cin >> N; 
    ll sumIDs {};
    std::vector<int> mods (7);

    for (int i {1}; i <= N; ++i)
    {
        int id {};
        std::cin >> id;
        sumIDs += id;

        if (mods[sumIDs % MOD] == 0)
            mods[sumIDs % MOD] = i;
        else 
            largest_group = std::max(largest_group, i - mods[sumIDs % MOD]);
    }

    std::cout << largest_group << '\n';
}

int main()
{
    setIO("div7"); 
    solve();
}