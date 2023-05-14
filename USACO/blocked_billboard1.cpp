/* USACO 2017 December Contest, Bronze
Problem 1. Blocked Billboard */
// Link problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=759
// Modified code: chatGPT

#include <iostream> 
#include <vector>

struct Rectangular
{
    int x1, y1, x2, y2; 
    
    int area() const { return (x2 - x1) * (y2 - y1);}   

    int intersection_area(const Rectangular& other) const 
    {
        int dx = std::max(0, std::min(x2, other.x2) - std::max(x1, other.x1));
        int dy = std::max(0, std::min(y2, other.y2) - std::max(y1, other.y1)); 

        return dx * dy;
    }
};

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    Rectangular first, second, truck;
    std::cin >> first.x1 >> first.y1 >> first.x2 >> first.y2;
    std::cin >> second.x1 >> second.y1 >> second.x2 >> second.y2;
    std::cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;

    int visible_area = first.area() + second.area();
    visible_area -= (first.intersection_area(truck) + second.intersection_area(truck));

    std::cout << visible_area << '\n';
}

int main()
{
    setIO("billboard");
    solve();
}