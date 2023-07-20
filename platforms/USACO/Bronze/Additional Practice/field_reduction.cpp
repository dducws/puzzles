// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=642


#include <iostream> 
#include <vector>
#include <algorithm>
#include <map>
#include <set>

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

const int MAX_COORDINATE = 40001;

void insertCows(std::set<std::pair<int, int>>& shortlist, std::multimap<int, int>& data, int k, bool reverse)
{
    int count = 0;
    for (auto it = data.begin(); it != data.end() && count < k; ++it, ++count)
    {
        if (!reverse)
            shortlist.insert(*it);
        else 
            shortlist.insert({(*it).second, (*it).first});
    }

    count = 0;
    for (auto it = data.rbegin(); it != data.rend() && count < k; ++it, ++count)
    {
        if (!reverse)
            shortlist.insert(*it);
        else 
            shortlist.insert({(*it).second, (*it).first});
    }
}

int computeEnclosingRectangleArea(const std::vector<std::pair<int, int>>& selected_cows, int i, int j, int k)
{
    int xMin = MAX_COORDINATE, xMax = 0, yMin = MAX_COORDINATE, yMax = 0;                
    for (int a = 0; a < sz(selected_cows); ++a)
    {
        if (a != i && a != j && a != k)
        {
            xMin = std::min(xMin, selected_cows[a].first);
            xMax = std::max(xMax, selected_cows[a].first);
            yMin = std::min(yMin, selected_cows[a].second);
            yMax = std::max(yMax, selected_cows[a].second);
        }
    }
    return (xMax - xMin) * (yMax - yMin);
}

/* On 19 July 2023, initially, I attempted to solve the problem by calculating the distance from each cow to its nearest neighbor,
and then excluding the three cows with the longest distances. However, I realized that this approach is flawed,
as it fails to guarantee the smallest enclosing rectangle. The test case:
6
1 1
90 40
4 100
50 7
100 50
50 40
demonstrates the incorrectness of this approach.
*/
void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> cow_positions(N);
    /* Here, the use of multimap is crucial because it allows multiple key-value pairs to have the same value,
    whereas using a regular map would update the value of an existing key if encountered again, leading to incorrect results. */
    std::multimap<int, int> x_y, y_x;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> cow_positions[i].first >> cow_positions[i].second;
        x_y.emplace(cow_positions[i]);
        y_x.emplace(cow_positions[i].second, cow_positions[i].first);
    }

    std::set<std::pair<int, int>> shortlist; 
    /* The reason for selecting 4 cows for each corner of the largest rectangle is to avoid a situation 
    where all 3 selected cows are removed from the same corner (e.g., left, right, bottom, or top). 
    If we choose only 3 cows, it becomes challenging to find the smallest area of the enclosing rectangle without
    knowing the values of all four crucial variables: minX, minY, maxX, and maxY. By selecting 4 cows, 
    we ensure that we have enough information to accurately determine the smallest area of the enclosing rectangle for the remaining cows. */
    insertCows(shortlist, x_y, 4, false);
    insertCows(shortlist, y_x, 4, true);

    int minArea = MAX_COORDINATE * MAX_COORDINATE;
    std::vector<std::pair<int, int>> selected_cows(all(shortlist));
    int max_cows = sz(selected_cows);
    
    for (int i = 0; i < max_cows; ++i)
    {
        for (int j = i + 1; j < max_cows; ++j)
        {
            for (int k = j + 1; k < max_cows; ++k)
            {
                minArea = std::min(minArea, computeEnclosingRectangleArea(selected_cows, i, j, k));
            }
        }
    }
    
    std::cout << minArea << '\n';
}

int main()
{
    setIO("reduce"); 
    solve();
}
