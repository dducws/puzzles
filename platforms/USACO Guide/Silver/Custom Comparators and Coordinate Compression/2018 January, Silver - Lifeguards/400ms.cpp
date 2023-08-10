// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=786


#include <iostream> 
#include <vector>
#include <map>

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

const int MAX = 1e9;

bool sortByEndPoint(const std::pair<int, int>& shift1, const std::pair<int, int>& shift2)
{
    return shift1.second < shift2.second;
}

/* This implementation has a time complexity of O(N^2), which is relatively inefficient. Moreover, the use of iterators
to traverse the map can make the code less readable for other developers. To address these concerns, I have rewritten a
more efficient solution based on an approach by USACO user Cao Duy Nguyen. This improved solution has a time complexity
of O(N * logN), resulting in significantly faster execution times (around 70ms) compared to the original implementation's
execution time of approximately 400ms.*/
void solve()
{
    int N;
    std::cin >> N;
    std::map<int, int> logs; 
    std::vector<std::pair<int, int>> shifts (N);
    for (auto& shift : shifts)
    {
        std::cin >> shift.first >> shift.second;
        ++logs[shift.first];
        --logs[shift.second];
    }
    
    ll maxTime {};
    auto it = logs.begin();
    while (std::next(it) != logs.end())
    {
        /* (As of 11 August 2023) In the prefix sum list, if a time point has a value of 0, it indicates
        that no lifeguards are present during that time interval. Therefore, we don't add it to the total
        time that is covered. I spent a considerable amount of time debugging because I initially omitted
        this condition, which resulted in inaccurate calculation of the total time coverage. */
        if (it->second)
            maxTime += std::next(it)->first - it->first;
        std::next(it)->second += it->second;
        ++it;
    }
    /* The last element in the prefix sum must be set to 0. Although I include this step to clarify the logic,
    it does not directly contribute to the calculation process of finding a lifeguard with minimum time alone.*/
    it->second = 0;

    int minShift {MAX + 1};
    for (int i {}; i < N; ++i)
    {
        int start = shifts[i].first, end = shifts[i].second, currentShift {};
        auto startIter = logs.lower_bound(start), endIter = logs.lower_bound(end);
        // Calculate the time alone of the current lifeguard using prefix sum
        for (auto it = startIter; it != endIter; ++it)
        {
            /* If the current point in the prefix sum list is 1, it is only covered
            by the current lifeguard, so add its time interval to currentShift. */
            if (it->second == 1)
                currentShift += std::next(it)->first - it->first;
        }

        minShift = std::min(minShift, currentShift);
        // If the time alone of the current lifeguard is 0, no need to check further, exit the loop
        if (minShift == 0)
            break;
    }

    std::cout << maxTime - minShift;
}

int main()
{
    setIO("lifeguards");
    solve();
}