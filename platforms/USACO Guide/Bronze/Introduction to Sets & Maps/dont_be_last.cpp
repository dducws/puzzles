/* USACO 2017 January Contest, Bronze
Problem 1. Don't Be Last! */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=687
// Edited: chatGPT


#include <iostream> 
#include <unordered_map>
#include <algorithm>
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool compareCows(const std::pair<std::string, int>& cow1, const std::pair<std::string, int>& cow2)
{
    return cow1.second < cow2.second;
}

void solve()
{
    int N;
    std::cin >> N;
    std::unordered_map<std::string, int> milking_log;

    // Initialize the milking log with all cow names and zero milk production
    for (const auto& name : {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"})
    {
        milking_log[name] = 0;
    }    
    
    for (int i {}; i < N; ++i)
    {
        std::string cow_name;
        int milk;
        std::cin >> cow_name >> milk;
        milking_log[cow_name] += milk;
    }
    
    // Convert the milking log to a vector of pairs for easier sorting
    std::vector<std::pair<std::string, int>> log(milking_log.begin(), milking_log.end()); 
    std::sort(log.begin(), log.end(), compareCows);

    std::vector<std::string> cows;
    int lowest_amount {log[0].second};

    for (int i {1}; i < (int) log.size(); ++i)
    {
        if (log[i].second != lowest_amount)
        {
            lowest_amount = log[i].second;
            cows.push_back(log[i].first);
            for (int j {i + 1}; j < (int) log.size(); ++j)
            {
                if (log[j].second != lowest_amount)
                    break;
                cows.push_back(log[j].first);
            }
            break;
        }
    }

    if (cows.size() == 1)
        std::cout << cows[0] << '\n';
    else 
        std::cout << "Tie\n";
}

int main()
{
    setIO("notlast"); 
    solve();
}
