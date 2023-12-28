// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=526
// Explanation: https://www.youtube.com/watch?v=ag46IZcJRQk


#include <iostream>
#include <vector>

#define all(x) begin(x), end(x)

void setIO(std::string name = "") {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() 
{
    std::string s, t;
    std::cin >> s >> t;
    std::string answer;
    for (const auto c : s) 
    {
        answer.push_back(c);
        if (answer.size() >= t.size() && answer.substr(answer.size() - t.size()) == t)
            answer.resize(answer.size() - t.size());
    }
    std::cout << answer << '\n';
}

int main() 
{
    setIO("censor");
    solve();    
}
