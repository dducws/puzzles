/* USACO 2018 January Contest, Bronze
Problem 1. Blocked Billboard II */
// Problem: https://www.usaco.org/index.php?page=viewproblem2&cpid=783
// Tutorial: https://usaco.guide/problems/usaco-783-blocked-billboard-ii/solution

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

struct Rectangular
{
    int x1, y1, x2, y2;

    int length() const  { return (x2 - x1); }
    int width() const { return (y2 - y1); }

    int xOverlap(const Rectangular& other) const { return (std::min(x2, other.x2) - std::max(x1, other.x1));}
    int yOverlap(const Rectangular& other) const { return (std::min(y2, other.y2) - std::max(y1, other.y1));}
};

void solve()
{
    Rectangular lawnmower_billboard, cow_feed_billboard; 
    std::cin >> lawnmower_billboard.x1 >> lawnmower_billboard.y1 >> lawnmower_billboard.x2 >> lawnmower_billboard.y2;
    std::cin >> cow_feed_billboard.x1 >> cow_feed_billboard.y1 >> cow_feed_billboard.x2 >> cow_feed_billboard.y2;

    int obscured_length {lawnmower_billboard.xOverlap(cow_feed_billboard)};
    int obscured_width {lawnmower_billboard.yOverlap(cow_feed_billboard)};

    int lawnmower_billboard_length {lawnmower_billboard.length()}, lawnmower_billboard_width {lawnmower_billboard.width()};
    int cow_feed_billboard_length {cow_feed_billboard.length()}, cow_feed_billboard_width {cow_feed_billboard.width()};
    
    int length_tarp {lawnmower_billboard_length}, width_tarp {lawnmower_billboard_width};

    if (obscured_length > 0 && obscured_width > 0)
    {
        if (obscured_length == lawnmower_billboard_length)
        {
            if ((lawnmower_billboard.y2 <= cow_feed_billboard.y2 && lawnmower_billboard.y2 > cow_feed_billboard.y1) || (lawnmower_billboard.y1 >= cow_feed_billboard.y1 & lawnmower_billboard.y1 <cow_feed_billboard.y2))
                width_tarp -= obscured_width;
        }

        if (obscured_width == lawnmower_billboard_width)
        {
            if ((lawnmower_billboard.x2 <= cow_feed_billboard.x2 && lawnmower_billboard.x2 > cow_feed_billboard.x1) || (lawnmower_billboard.x1 >= cow_feed_billboard.x1 & lawnmower_billboard.x1 <cow_feed_billboard.x2))
                length_tarp -= obscured_length;
        }
    }
    std::cout << length_tarp * width_tarp << '\n';
}

int main()
{
    setIO("billboard"); 
    solve();
}
