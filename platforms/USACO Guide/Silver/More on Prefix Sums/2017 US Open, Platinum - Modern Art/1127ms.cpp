// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=744


#include <iostream> 
#include <vector>
#include <set> 
#include <unordered_set>

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

int N;
struct Dimension 
{
    int top, bottom, left, right;
};

std::vector<std::vector<int>> canvas; 
std::vector<Dimension> colors;
std::set<int> importantColors;

// Check whether color 1 is put on top of color 2
bool check_on_top(int color1, int color2)
{
    Dimension bounding_box = colors[color2]; 
    // Check if color1 appears within the bounding box of color2
    for (int i {bounding_box.top}; i <= bounding_box.bottom; ++i)
    {
        for (int j {bounding_box.left}; j <= bounding_box.right; ++j)
        {
            if (canvas[i][j] == color1)
                return true;
        }
    }
    
    return false;
}

void solve()
{
    std::cin >> N;
    canvas.resize(N, std::vector<int> (N));
    colors.resize(N * N + 1, {N, 0, N, 0}); 

    for (int i {}; i < N; ++i)
    {
        for (int j {}; j < N; ++j)
        {
            std::cin >> canvas[i][j];
            
            // If a color is painted, it will be added to check whether it can be first.
            if (canvas[i][j])                
                importantColors.insert(canvas[i][j]);

            Dimension& color = colors[canvas[i][j]];
            color.top = std::min(color.top, i);
            color.bottom = std::max(color.bottom, i);
            color.left = std::min(color.left, j);
            color.right = std::max(color.right, j);
        }
    }

    std::unordered_set<int> paintedAfter; 
    for (int color1 : importantColors)
    {
        for (int color2 : importantColors)
        {
            if (color1 != color2 && check_on_top(color1, color2))
            {
                paintedAfter.insert(color1);
                // If color1 can't be the first color to be painted, break this current loop of color2 to move on to the new color1
                break;
            }
        }
    }

    /* On August 6, 2023, I initially made a mistake when I didn't read the problem carefully and missed this specific situation.
    In the second test case:
    4
    0 0 0 0
    0 1 1 0
    0 1 1 0
    0 0 0 0
    The correct output should be 15 instead of 16 because all N^2 colors are used, and color 1 is the last to be applied.
    Since all colors are used exactly once, color 1 cannot be one of the first colors to be painted.
    And in the third test case:
    5
    0 0 0 0 0
    0 1 0 2 0
    0 1 0 2 0
    0 1 0 2 0
    0 0 0 0 0
    The correct output would be 25 instead of 23. To determine the maximum possible number of first colors to be painted, we consider two situations:
    1) If color 1 is one of the first colors to be painted, we have 24 colors left to be painted, and 23 of these colors could be the first color 
    to be painted, now covered by color 2. This implies that the maximum number of first colors is 24, all colors from 1 to 25 excluding 2.
    2) If color 2 is one of the first colors to be painted, the same logic applies, and the maximum number of first colors remains 24 (all colors from
    2 to 25).
    By merging these two situations, we conclude that all 25 colors can be the first colors to be painted. */
    if (sz(importantColors) == 1)
        std::cout << N * N - 1 << '\n';
    else 
        std::cout << N * N - sz(paintedAfter) << '\n';
}

int main()
{
    setIO("art"); 
    solve();
}
