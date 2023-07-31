/* USACO 2017 December Contest, Bronze
Problem 2. The Bovine Shuffle */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=760
// Solution: https://usaco.guide/problems/usaco-760-the-bovine-shuffle/solution


#include <iostream> 
#include <vector>

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

const int SHUFFLE_TIMES = 3;

void solve()
{
    int N;
    std::cin >> N; 

    // This vector describes the mechanism of the shuffle.
    std::vector<int> shuffle (N);
    for (int &i : shuffle)
    {
        std::cin >> i;
    }

    // This vector stores the order of IDs of all cows after three shuffles.
    std::vector<int> IDs (N);
    for (int &id : IDs)
    {
        std::cin >> id;
    }

    for (int times {}; times < SHUFFLE_TIMES; ++times)
    {
        std::vector<int> past_order (N);
        for (int j {}; j < N; ++j)
        {
            past_order[j] = IDs[shuffle[j] - 1];
        }
        IDs = past_order;
    }

    for (const auto& id : IDs)
        std::cout << id << '\n';

    /*
    std::vector<int> current_order (N);
    for (int i {1}; i <= N; ++i)
        current_order[i - 1] = i;
    
    for (int j {}; j < 3; ++j)
    {
        std::vector<int> future_order (N);
        for (int i {}; i < N; ++i)
        {
            future_order[shuffle[i] - 1] = current_order[i];
        }
        current_order = future_order;
        std::cout << future_order << '\n';
    }
    */
}

int main()
{
    setIO("shuffle"); 
    solve();
}
