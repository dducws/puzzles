// Problem: https://cses.fi/problemset/task/1623
// Solution: https://usaco.guide/bronze/complete-rec?lang=cpp#problems


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

ll findMinDifference(int index, ll sumGroup1, ll sumGroup2, const std::vector<ll>& appleWeights)
{
    if (index == sz(appleWeights))
        return (std::abs(sumGroup1 - sumGroup2));
    
    return std::min(findMinDifference(index + 1, sumGroup1 + appleWeights[index], sumGroup2, appleWeights),
                    findMinDifference(index + 1, sumGroup1, sumGroup2 + appleWeights[index], appleWeights));
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<ll> appleWeights (n);
    for (int i {}; i < n; ++i)
    {
        std::cin >> appleWeights[i];
    }

    ll minDifference {findMinDifference(0, 0, 0, appleWeights)};
    std::cout << minDifference;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
