/* USACO 2019 December Contest, Bronze
Problem 2. Where Am I? */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=964
// Edited: chatGPT


#include <iostream> 
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
    std::string s;
    std::cin >> N >> s; 

    for (int i {1}; i <= N; ++i)
    {
        bool different {true};  
        std::unordered_set<std::string> sequences;

        // Generate all possible sequences of length i
        for (int j {}; j <= N - i; ++j)
        {
            // Extract the current sequence
            auto sequence = s.substr(j, i); 

            // Check if the sequence has already been encountered
            if (sequences.count(sequence) == 1)
            {
                different = false;
                break;
            }

            // Add the current sequence to the set
            sequences.insert(sequence);
        }

        // If all sequences of length i are different, output i and return
        if (different)
        {
            std::cout << i << '\n';
            return;
        }
    }
}

int main()
{
    setIO("whereami"); 
    solve();
}
