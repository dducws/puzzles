// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=617


#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void setIO(std::string name = "") {
    std::cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() 
{
    int N, B;
    std::cin >> N >> B;
    std::vector<int> x_coordinates(N), y_coordinates(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> x_coordinates[i] >> y_coordinates[i];
    }

    int M {B};

    for (int i {}; i < N; ++i)
    {
        for (int j {}; j < N; ++j)
        {
            int a {x_coordinates[i] + 1}, b {y_coordinates[j] + 1};
            std::vector<int> regions (4);
            for (int k {}; k < N; ++k)
            {
                if (x_coordinates[k] > a && y_coordinates[k] > b)
                    ++regions[0];
                else if (x_coordinates[k] < a && y_coordinates[k] > b)
                    ++regions[1];
                else if (x_coordinates[k] < a && y_coordinates[k] < b)
                    ++regions[2];
                else if (x_coordinates[k] > a && y_coordinates[k] < b)
                    ++regions[3];   
            }
            /* To make four regions as balanced as possible, 
            we just need to make sure that the maximum cows in a region is as small as possible */
            M = std::min(M, *std::max_element(regions.begin(), regions.end()));
        }
    }
    std::cout << M << '\n';
}

int main() 
{
    setIO("balancing");
    solve();
}
