/* USACO 2019 December Contest, Bronze
Problem 1. Cow Gymnastics */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <iostream> 
#include <vector>
#include <map>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

// An useful template for debugging by printing out all elements of a vector
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

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
    int K, N;
    std::cin >> K >> N;
    std::vector<std::vector<int>> performanceCounter(N, std::vector<int>(N, 0)); // Using A 2D array will be a little bit faster than that of vector + map.

    for (int i {}; i < K; ++i)
    {
        std::vector<int> currentRanking (N);
        
        for (int j {}; j < N; ++j)
            std::cin >> currentRanking[j];
        
        for (int j {}; j < N - 1; ++j)
        {
            for (int k {j + 1}; k < N; ++k)
                ++performanceCounter[currentRanking[j] - 1][currentRanking[k] - 1];
        }
    }

    int consistentPairs {};

    for (int i {}; i < N; ++i)
    {
        for (int j {}; j < N; ++j)
        {
            // If a pair of cows has a performance count equal to the number of practice sessions (K), increment the count of consistent pairs
            if (performanceCounter[i][j] == K)
            {
                ++consistentPairs;
            }
        }
    }

    std::cout << consistentPairs << '\n';
}

int main()
{
    setIO("gymnastics"); 
    solve();
}
