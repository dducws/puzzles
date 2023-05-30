#include <iostream> 
#include <unordered_map>
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

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<std::string, std::string>> USA (N);

    for (int i {}; i < N; ++i)
    {
        std::string city, state; 
        std::cin >> city >> state; 
        // Extracts the first two letters of the city name as the city code
        USA[i] = {city.substr(0, 2), state};
    }

    int special_pairs {};
    std::unordered_map<std::string, int> exist;

    for (const auto& [c, s] : USA) 
    {
        /* 
        This condition checks if the pair of cities being considered are from different states.
        A pair of cities and states is considered special if the first city's code matches 
        the second state's code and the second city's code matches the first state's code
        */
        if (c != s)
        {
            // Count the reverse pair (which satisfies the condition of a special pair if it exists)
            special_pairs += exist[s + c];
        }
        ++exist[c + s];
    }

    std::cout << special_pairs << '\n';
}

int main()
{
    setIO("citystate"); 
    solve();
}
