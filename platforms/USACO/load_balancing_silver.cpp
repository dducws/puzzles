/* USACO 2016 February Contest, Silver
Problem 2. Load Balancing */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=619
// Solution: https://usaco.guide/problems/usaco-619-load-balancing/solution
// Edited by: chatGPT

/* 
The key point (main difference) between this problem and the one in the Bronze contest is that the input size is 10 times larger.
To optimize for better time complexity, we can reduce the constant factors by removing duplicate coordinates and considering
only the most likely ranges of possible x and y values, which are [N/4, 3N/4].
*/


#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "") {
    std::cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

std::vector<int> potential_positions(std::vector<int> v)
{
    std::sort(v.begin(), v.end());
    std::vector<int> reduced_v;
    int n {sz(v)};
    int lower_bound {std::min(n / 4, n - 1)}, upper_bound {std::min(3 * n / 4, n - 1)};
    for (int i {lower_bound}; i <= upper_bound; ++i)
    {
        if (reduced_v.empty() || (reduced_v.back() != v[i] + 1))
            reduced_v.push_back(v[i] + 1);
    }
    return reduced_v;
}

void solve() 
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> cows_locations (N);
    std::vector<int> x_coordinates (N), y_coordinates (N);
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> cows_locations[i].first >> cows_locations[i].second;
        x_coordinates[i] = cows_locations[i].first;
        y_coordinates[i] = cows_locations[i].second;
    }

    std::vector<int> possible_a {potential_positions(x_coordinates)}, possible_b {potential_positions(y_coordinates)};
    size_t i {}, j {};

    int M {1000000};

    while (i < possible_a.size())
    {
        int a {possible_a[i]}, b {possible_b[j]};
        std::vector<int> regions (4);
        for (const auto& [x, y] : cows_locations)
        {
            if (x > a && y > b)
                ++regions[0];
            else if (x < a && y > b)
                ++regions[1];
            else if (x < a && y < b)
                ++regions[2];
            else if (x > a && y < b)
                ++regions[3];   
        }
        ++j;
        /* To make four regions as balanced as possible, 
        we just need to make sure that the maximum cows in a region is as small as possible */
        M = std::min(M, *std::max_element(regions.begin(), regions.end()));
        if (j == possible_b.size())
        {
            j = 0;
            ++i;
        }
    }
    std::cout << M << '\n';
}

int main() 
{
    setIO("balancing");
    solve();
}
