/* USACO 2017 February Contest, Bronze
Problem 2. Why Did the Cow Cross the Road II */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=712
// Solution 2: https://usaco.guide/problems/usaco-712-why-did-the-cow-cross-the-road-ii/solution

#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct Cow
{
    int entryPoint {-1}, exitPoint {-1};
};

void solve()
{
    std::string crossings;
    std::cin >> crossings; 
    int crossing_pairs {};
    std::vector<Cow> cows (26);

    for (int i {}; i < crossings.size(); ++i)
    {
        if (cows[crossings[i] - 'A'].entryPoint == -1)
        {
            cows[crossings[i] - 'A'].entryPoint = i;
        }
        else 
        {
            cows[crossings[i] - 'A'].exitPoint = i;
        }
    }

    for (int i {}; i < crossings.size() / 2; ++i)
    {
        for (int j {}; j < crossings.size() / 2; ++j)
        {
            crossing_pairs += (cows[i].entryPoint < cows[j].entryPoint && cows[j].entryPoint < cows[i].exitPoint && cows[i].exitPoint < cows[j].exitPoint);
        }
    }

    std::cout << crossing_pairs << '\n';
}

int main()
{
    setIO("circlecross"); 
    solve();
}
