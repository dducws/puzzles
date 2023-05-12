/* USACO 2015 February Contest, Bronze
Problem 1. Censoring (Bronze) */
// Link problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=526
// Video solution: https://www.youtube.com/watch?v=ag46IZcJRQk

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

void solve()
{
    std::string s, t; 
    std::cin >> s >> t;
    std::string answer {};
    for (const auto c : s)
    {
        answer += c;
        /* If the censored string is longer than 't' string and the last t characters of the censored string
        are equal to t string, remove the last t characters from the censored string. */
        if (answer.size() > t.size() && answer.substr(answer.size() - t.size()) == t)
            answer.resize(answer.size() - t.size());
    }
    std::cout << answer << '\n';
}

int main()
{
    setIO("censor"); 
    solve();
}
