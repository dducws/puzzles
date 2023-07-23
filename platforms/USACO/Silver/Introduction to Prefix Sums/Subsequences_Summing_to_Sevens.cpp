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

/* A cleaner and more efficient solution which is written based on the solution from USACO.*/
const int MOD {7};

void solve()
{
    int N, largest_group {};
    std::cin >> N; 
    /* I realized that there's no need to use a vector to store the prefix sum of IDs of all cows.
    Instead, we can achieve the same result using just two variables: `sumIDs` and `id`.
    `sumIDs` keeps track of the cumulative sum of cow IDs up to the current cow, 
    and `id` stores the ID of the current cow being processed.
    This simplifies the code and avoids unnecessary memory usage. */
    ll sumIDs {};
    /* Instead of using a 2D array or a 1D array with std::pair<int, int> to store the first and 
    last element of every prefix sum modules 7, we only need a 1D array with type "int" to keep track of the first indices for each modulo value.
    If we encounter the same modulo value again, we compare the current cow's position `i` with the first index to find the largest_group. */
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