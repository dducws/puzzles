// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=965
// Brute-force approach tutorial: https://www.youtube.com/watch?v=xed_5FjVMoo
// Graphs approach solution: https://usaco.guide/bronze/intro-graphs?lang=cpp


#include <iostream> 
#include <vector>
#include <map> 
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

// Graphs approach
void solve()
{
    // Define the initial order of cows and sort it alphabetically
    std::vector<std::string> cows {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    std::sort(all(cows));

    // Create a mapping of cow names to their corresponding indices
    std::map<std::string, int> cows_ids; 
    for (int i {}; i < sz(cows); ++i)
    {
        cows_ids[cows[i]] = i;
    }

    // Create a vector to store the neighbors of each cow
    std::vector<std::vector<int>> neighbors; 
    neighbors.reserve(sz(cows));

    // Read the number of constraints (N) from input
    int N;
    std::cin >> N;

    // Read each constraint and update the neighbors vector accordingly
    for (int i {}; i < N; ++i)
    {
        std::string cow1, _, cow2;
        std::cin >> cow1 >> _ >> _ >> _ >> _ >> cow2;
        neighbors[cows_ids[cow1]].push_back(cows_ids[cow2]);
        neighbors[cows_ids[cow2]].push_back(cows_ids[cow1]);
    }

    // Create a vector to keep track of whether a cow has been added to the final order
    std::vector<bool> added (sz(cows));

    // Create a vector to store the final order of cows
    std::vector<int> final_order; 
    final_order.reserve(sz(cows));

    // Iterate through each cow to determine its position in the final order
    for (int id {}; id < sz(cows); ++id)
    {
        // Check if the current cow has not been added and has at most one neighbor
        if (!added[id] && sz(neighbors[id]) <= 1)
        {
            added[id] = true;
            final_order.push_back(id);

            // If the cow has one neighbor, follow the sequence of cows until reaching the end
            if (sz(neighbors[id]) == 1)
            {
                int prev = id, at = neighbors[id][0];
                while (sz(neighbors[at]) == 2)
                {
                    added[at] = true;
                    final_order.push_back(at);

                    // Determine the next cow in the sequence
                    int a = neighbors[at][0], b = neighbors[at][1];
                    int temp = a == prev ? b : a;
                    prev = at;
                    at = temp;
                }

                // Add the last cow in the sequence to the final order
                added[at] = true; 
                final_order.push_back(at);
            }
        }

        // If all cows have been added to the final order, exit the loop
        if (sz(final_order) == sz(cows))
            break;
    }

    // Print the final order of cows
    for (const auto id : final_order)
        std::cout << cows[id] << '\n';
}

// Brute force approach
/* 
void solve()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, std::string>> restrictions; 
    for (int i {}; i < N; ++i)
    {
        std::string cow1, trash, cow2;
        std::cin >> cow1; 
        std::cin >> trash >> trash >> trash >> trash;
        std::cin >> cow2;
        restrictions.push_back({cow1, cow2});
    }
    
    std::vector<std::string> cows {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella",  "Blue", "Betsy", "Sue"};
    std::sort(all(cows));

    while (std::next_permutation(all(cows)))
    {
        bool passed {true};
        for (const auto& p : restrictions)
        {
            std::string cow1 = p.first, cow2 = p.second; 
            auto cow1_id = std::find(all(cows), cow1), cow2_id = std::find(all(cows), cow2);
            if (abs(cow1_id - cow2_id) != 1)
            {
                passed = false;
                break;
            }
        }

        if (passed)
            break;
    }

    for (const auto& cow : cows)
        std::cout << cow << '\n';
}
*/

int main()
{
    setIO("lineup"); 
    solve();
}
