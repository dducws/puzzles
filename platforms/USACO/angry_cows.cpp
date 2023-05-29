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
    int N; 
    std::cin >> N; 
    std::vector<int> hay_bales_locations (N);

    for (auto& location : hay_bales_locations)
        std::cin >> location; 
    
    std::sort(hay_bales_locations.begin(), hay_bales_locations.end());

    int best_explosion {};

    for (int i {}; i < N; ++i)
    {
        int bales_left {}, bales_right {}, left_radius {1}, right_radius {1}, left_edge {i}, right_edge {i};

        for (int j {i + 1}; j < N; ++j)
        {
            if (hay_bales_locations[j] - hay_bales_locations[right_edge] <= right_radius)
                ++bales_right;
            else
            {
                if (bales_right)
                {
                    ++right_radius;
                    right_edge = j - 1;
                    if (hay_bales_locations[j] - hay_bales_locations[right_edge] <= right_radius)
                    {
                        ++bales_right;
                    }
                    else 
                        break;
                }
                else 
                    break;
            }
        }

        for (int j {i - 1}; j >= 0; --j)
        {
            if (std::abs(hay_bales_locations[j] - hay_bales_locations[left_edge]) <= left_radius)
                ++bales_left;
            else 
            {
                if (bales_left)
                {
                    ++left_radius;
                    left_edge = j + 1;
                    if (std::abs(hay_bales_locations[j] - hay_bales_locations[left_edge]) <= left_radius)
                    {
                        ++bales_left;
                    }
                    else 
                        break;
                }
                else 
                    break;
            }
        }

        best_explosion = std::max(best_explosion, 1 + bales_left + bales_right);
    }

    std::cout << best_explosion << '\n';
}

int main()
{
    setIO("angry"); 
    solve();
}

// A solution with better readability from USACO ()
/*
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

int N;
std::vector<int> hay_bales_locations;

int exploded_num(int start, int direction)
{
    int radius {1}, previous {start};
    while (true)
    {
        int next {previous};
        // Get the furthest explosion index without exceeding the current radius 
        while (next + direction >= 0 && next + direction < N && std::abs(hay_bales_locations[next + direction] - hay_bales_locations[previous]) <= radius)
        {
            next += direction;
        }

        // If we can't find a new haybale, the chain explosion will be over 
        if (next == previous)
        {
            break;
        }

        // Update the previous explosion and increment radius
        previous = next;
        ++radius;
    }

    return std::abs(previous - start);
}

void solve()
{
    std::cin >> N; 
    hay_bales_locations.resize(N);

    for (auto& location : hay_bales_locations)
        std::cin >> location; 

    std::sort(hay_bales_locations.begin(), hay_bales_locations.end());

    int max_exploded {};
    for (int i {}; i < N; ++i)
    {
        // Get the number of exploded bales for the left & right side
        max_exploded = std::max(max_exploded, exploded_num(i, -1) + exploded_num(i, 1) + 1);
    }
 
    std::cout << max_exploded << '\n';
}

int main()
{
    //setIO("angry"); 
    solve();
}
*/
