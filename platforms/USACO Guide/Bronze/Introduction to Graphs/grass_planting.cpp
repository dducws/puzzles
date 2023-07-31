/* USACO 2019 January Contest, Silver
Problem 1. Grass Planting */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=894
// Explanation: https://www.youtube.com/watch?v=WygnoGqUluY


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

/* 2 July 2023: Initially, I had an assumption that if 1 <= N <= 3, the minimum number of grass types would be N. And if N > 3, 
the minimum number of grass types would always be 3 because we can always use just 3 grass types to satisfy the 2 conditions in the problem. 
However, this assumption is incorrect because the graph is not cyclic. To demonstrate the flaw in the assumption, consider the following test case: 
5
2 1
3 1
4 1
5 1
*/

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> pathways_of_each_field (N + 1);
    for (int i {}; i < N - 1; ++i)
    {
        int field1, field2;
        std::cin >> field1 >> field2;
        ++pathways_of_each_field[field1];
        ++pathways_of_each_field[field2];
    }

    std::cout << *std::max_element(all(pathways_of_each_field)) + 1 << '\n';
}

int main()
{
    setIO("planting"); 
    solve();
}

