// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=744
// Solution: https://usaco.guide/problems/usaco-744-modern-art/solution


#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

// A template to print vectors for debugging. 
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < sz(vec) - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

/* (As of August 7, 2023) Comparing this implementation to my initial approach, which was based on a solution from the
Bronze division of the same problem, reveals significant efficiency improvements achieved through several key optimizations:
1) Leveraging the prefix sum technique to determine whether colors can be painted first, 
as opposed to relying on nested loops to check for color superimposition within each pair of visible colors.
This pivotal insight dramatically enhances performance and execution time, reducing it from 1127ms (in my initial implementation) to 350ms.
2) Employing a generalized condition to identify the first color to be painted, thereby enhancing code readability and streamlining the logical flow.
3) Avoiding the use of global variables, which not only minimizes the risk of conflicts but also promotes better coding practices and modularity. */
struct Bound 
{
    int top, bottom, left, right;
};

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> canvas(N, std::vector<int> (N));
    std::unordered_map<int, Bound> visible; 

    for (int row {}; row < N; ++row)
    {
        for (int column {}; column < N; ++column)
        {
            std::cin >> canvas[row][column];

            if (canvas[row][column])
            {
                int color = canvas[row][column];
                if (visible.count(color) == 0)
                    visible[color] = {row, row, column, column};
                
                Bound &rectangle = visible[color];
                rectangle.top = std::min(row, rectangle.top);
                rectangle.bottom = std::max(row, rectangle.bottom);
                rectangle.left = std::min(column, rectangle.left);
                rectangle.right = std::max(column, rectangle.right);
            }
        }
    }

    int possibleFirstColors {N * N - sz(visible)};
    /* If there is only one color visible in the final state, it would be the only color that can't be the first color to be painted.
    So we only need to handle situations when the number of visible colors is more than one. */
    if (sz(visible) > 1)
    {
        std::vector<std::vector<int>> prefixSums(N + 1, std::vector<int>(N + 1));
        std::unordered_set<int> validColors;

        for (const auto& [color, dimension] : visible)
        {
            validColors.insert(color);
            ++prefixSums[dimension.top][dimension.left];
            /* Although the prefixSums matrix has size (N + 1) * (N + 1), we only care about colors in an N * N matrix.
            Therefore, we don't need to calculate the prefix of the last column and the last row because they won't be used. */
            if (dimension.bottom + 1 < N)
                --prefixSums[dimension.bottom + 1][dimension.left];
            if (dimension.right + 1 < N)
            {
                --prefixSums[dimension.top][dimension.right + 1];
                ++prefixSums[dimension.bottom + 1][dimension.right + 1];
            }
        }

        for (int row {}; row < N; ++row)
        {
            for (int column {}; column < N; ++ column)
            {
                if (row > 0)
                    prefixSums[row][column] += prefixSums[row - 1][column];
                if (column > 0)
                    prefixSums[row][column] += prefixSums[row][column - 1];
                if (row > 0 && column > 0)
                    prefixSums[row][column] -= prefixSums[row - 1][column - 1];

                if (prefixSums[row][column] > 1)
                    validColors.erase(canvas[row][column]);
            }
        }
        possibleFirstColors += sz(validColors);
    }

    std::cout << possibleFirstColors;
}

int main()
{
    setIO("art"); 
    solve();
}