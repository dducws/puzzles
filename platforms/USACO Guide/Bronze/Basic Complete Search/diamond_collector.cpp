// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=639


#include <iostream> 
#include <vector>
#include <algorithm>

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
    int N, K; 
    std::cin >> N >> K; 

    std::vector<int> diamonds_sizes (N);
    for (int i {}; i < N; ++i) 
        std::cin >> diamonds_sizes[i];
    
    std::sort(diamonds_sizes.begin(), diamonds_sizes.end());

    int left {}, max_count {};

    for (int right {}; right < N; ++right)
    {
        if (diamonds_sizes[right] - diamonds_sizes[left] > K)  
            ++left;
        
        max_count = std::max(max_count, right - left + 1);
    }

    std::cout << max_count << '\n';
}

int main()
{
    setIO("diamond"); 
    solve();
}
