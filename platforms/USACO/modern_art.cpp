/* USACO 2017 US Open Contest, Bronze
Problem 3. Modern Art */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=737
// Solution: http://www.usaco.org/current/data/sol_art_bronze_open17.html
// Edited: chatGPT


#include <iostream> 
#include <vector>
#include <set> 
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

int N;
std::vector<std::vector<int>> canvas; 

struct Dimension
{
    int top {N}, bottom {0}, left {N}, right {};

    // Calculate the bounding box for the given color 
    void measurement(int color)
    {
        for (int i {}; i < N; ++i)
        {
            for (int j {}; j < N; ++j)
            {
                if (canvas[i][j] == color)
                {
                    top = std::min(top, i);
                    bottom = std::max(bottom, i);
                    left = std::min(left, j);
                    right = std::max(right, j);
                }
            }
        }
    }
};

// Check whether color 1 is put on top of color 2
bool check_on_top(int color1, int color2)
{
    Dimension bounding_box; 
    bounding_box.measurement(color2);

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
    
    std::set<int> colors;

    for (int i {}; i < N; ++i)
    {
        std::string s; 
        std::cin >> s;
        
        for (int j {}; j < N; ++j)
        {
            int color {s[j] - '0'};
            canvas[i][j] = color;

            if (color)
                colors.insert(color);
        }
    }

    int answer {};
    for (const auto color1 : colors)
    {
        bool be_first = true;
        for (const auto color2 : colors)
        {
            if (color1 != color2 && check_on_top(color1, color2))
                be_first = false;
        }

        if (be_first)
            ++answer;
    }

    std::cout << answer << '\n';
}

int main()
{
    setIO("art"); 
    solve();
}
