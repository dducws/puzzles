/* USACO 2017 US Open Contest, Bronze
Problem 2. Bovine Genomics */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=736
// Edited by: chatGPT

#include <iostream>
#include <vector> 
#include <set> 

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
    int N, M; 
    std::cin >> N >> M; 

    std::vector<std::string> spottyCows (N);
    std::vector<std::string> plainCows (N);

    for (int i {}; i < N; ++i)
        std::cin >> spottyCows[i];

    for (int j {}; j < N; ++j)
        std::cin >> plainCows[j];

    int spottiness {};

    for (int i {}; i < M; ++i)
    {
        std::set<char> spotty_chars;
        std::set<char> plain_chars; 

        for (int j {}; j < N; ++j)
        {
            spotty_chars.insert(spottyCows[j][i]);
            plain_chars.insert(plainCows[j][i]);
        }

        bool check_char {true};

        for (char c : spotty_chars)
        {
            if (plain_chars.count(c) > 0)
            {
                check_char = false; 
                break;
            }
        }

        if (check_char)
            ++spottiness;
    }

    std::cout << spottiness << '\n';
}

int main()
{
    setIO("cownomics");
    solve();
}
