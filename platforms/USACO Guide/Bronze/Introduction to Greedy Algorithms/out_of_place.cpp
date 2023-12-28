// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=785
// Solution: https://www.youtube.com/watch?v=FaoAL7Prc6o&t=401s


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

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> original (N);

    for (int i {}; i < N; ++i)
    {
        std::cin >> original[i];
    }

    std::vector<int> sorted = original;
    std::sort(all(sorted));

    int differences {};
    for (int i {}; i < N; ++i)
    {
        if (original[i] != sorted[i])
            ++differences;
    }

    std::cout << std::max(0, differences - 1) << '\n';
} 

int main()
{
    setIO("outofplace"); 
    solve();
}
