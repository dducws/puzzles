// Source: https://github.com/DucMinh2206/usaco_usa/blob/main/custom_comparators_n_compression/mountain_view.cpp


#include <iostream> 
#include <vector>
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


bool sortByYCoordinate(const std::pair<int, int>& A, const std::pair<int, int>& B)
{
    if (A.second != B.second)
        return A.second > B.second;
    
    return A.first > B.first;
}

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> peaks (N);
    std::vector<int> flags (N);
    for (auto& point : peaks)
    {
        std::cin >> point.first >> point.second;
    }
    std::sort(all(peaks), sortByYCoordinate);
    
    int hidden {};
    for (int i {}; i < N; ++i) 
    {
        /* If the first mountain's peak is already within the bounds of a larger mountain, the larger mountain is assuredly not concealed and can
        adequately represent both of them in the subsequent search for hidden mountains. Consequently, we only need to consider the first 
        mountain if it has not been hidden by other mountains.*/
        if (!flags[i])
        {
            for (int j {i + 1}; j < N; ++j)
            {
                // We only need to consider the second mountain if it has not been hidden by other mountains.
                if (!flags[j])
                {
                    /* This condition checks if the peak of mountain 'j' lies within or on the triangular region formed by mountain 'i'.
                    By virtue of sorting based on y-coordinates, we ensure that the first triangle, represented by peaks[i], occupies a
                    higher position than the second triangle, represented by peaks[j], in the comparison (Yi > Yj).
                    Furthermore, a crucial observation arises from the distinctive characteristics of right isosceles triangles:
                    a solitary peak point uniquely delineates two boundary points in its hypotenuse, which correspond to the 
                    leftmost and rightmost points. Building on this insight, if both the leftmost and rightmost points on the
                    hypotenuse of one triangle lie within or on the lines defined by the corresponding points of another triangle
                    (taking into account that the peak of the second triangle lies below that of the first triangle),
                    we can confidently infer that the second triangle is entirely obscured by the first.
                    The inherent attributes of right isosceles triangles significantly simplify the problem-solving process,
                    obviating the need for intricate mathematical formulas as I used in my initial implementation. */
                    if (peaks[j].first + peaks[j].second <= peaks[i].first + peaks[i].second && peaks[j].first - peaks[j].second >= peaks[i].first - peaks[i].second)
                    {
                        flags[j] = true;
                        ++hidden;
                    }
                }
            }
        }
    }

    std::cout << N - hidden;
}

int main()
{
    setIO("mountains");
    solve();
}
