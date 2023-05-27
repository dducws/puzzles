/* USACO 2019 January Contest, Bronze
Problem 3. Guess the Animal */
// Link problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=893
// Video Solution: https://www.youtube.com/watch?v=qmltNgaSg8w

/* The key point for this problem is that for each question, only two animals are compared, not all the animals. */

#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_set>

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
    std::vector<std::unordered_set<std::string>> characteristics_animals (N);

    for (int i {}; i < N; ++i)
    {
        std::string animal;
        int number_of_characteristics;
        std::cin >> animal >> number_of_characteristics;
        for (int j {}; j < number_of_characteristics; ++j)
        {
            std::string characteristic;
            std::cin >> characteristic;
            characteristics_animals[i].insert(characteristic);
        }
    }

    int max_yes_answers {1};

    for (int i {}; i < N; ++i)
    {
        for (int j {i + 1}; j < N; ++j)
        {
            int current_max {1};
            for (const auto& characteristic : characteristics_animals[j])
            {
                if (characteristics_animals[i].count(characteristic) == 1)
                    ++current_max;
            }
            max_yes_answers = std::max(current_max, max_yes_answers);
        }
    }
    
    std::cout << max_yes_answers << '\n';
}

int main()
{
    setIO("guess"); 
    solve();
}
