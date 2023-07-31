// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=919


#include <iostream>
#include <vector>
#include <unordered_map>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "") {
    std::cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) { 
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAX_N = 1000;
std::vector<std::vector<int>> prefixSums(MAX_N + 1, std::vector<int>(MAX_N + 1));
int count {};

void solve() 
{
    int N, K;
    std::cin >> N >> K;
    for (int i = 0; i < N; ++i) 
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        /* On 29 July 2023, I made a mistake in the updating of prefixSums. I incorrectly assumed
        that the top-right corner point has coordinates (x1 + x2, y1 + y2), the top-left corner
        point has coordinates (x1, y1 + y2), and the bottom-right corner point has coordinates
        (x1 + x2, y1). */
        ++prefixSums[x1][y1];
        --prefixSums[x1][y2];
        --prefixSums[x2][y1];
        ++prefixSums[x2][y2];
    }

   for (int i {}; i <= MAX_N; ++i) 
   {
        for (int j {}; j <= MAX_N; ++j) 
        {
            if (j == 0)
            {
                if (i > 0)
                    prefixSums[i][j] += prefixSums[i - 1][j];
            }
            else if (i == 0)
            {
                if (j > 0)
                    prefixSums[i][j] += prefixSums[i][j - 1];
            }
            else
            { 
                prefixSums[i][j] += prefixSums[i - 1][j] + prefixSums[i][j - 1] - prefixSums[i - 1][j - 1];
            }
            /* I initially used an std::unordered_map to keep track of the values of
            all prefixSums, but it was very inefficient and unnecessary for this problem. 
            Since I only need to find the number of values of prefixSums that
            equals to K, using a simple int variable "count" is enough and makes my code much more
            efficient by reducing memory usage and lookup time in the unordered_map. */
            if (prefixSums[i][j] == K)
                ++count;
        }
    }
    
    std::cout << count << '\n';
}

int main() 
{
    setIO("paintbarn");
    solve();
}
