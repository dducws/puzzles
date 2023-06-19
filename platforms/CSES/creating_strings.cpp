// Creating Strings - CSES Problem Set
// Problem: https://cses.fi/problemset/task/1622
// Solution: https://usaco.guide/bronze/complete-rec?lang=cpp#generating-permutations-using-next_permutation


#include <iostream> 
#include <vector>
#include <algorithm>

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()


void solve()
{
    std::string s;
    std::cin >> s; 
    std::sort(all(s));
    std::vector<std::string> permutations; 

    do 
    {
        permutations.push_back(s);
    }
    while (std::next_permutation(all(s)));

    std::cout << sz(permutations) << '\n';
    for (const auto& permutation : permutations)
    {
        std::cout << permutation << '\n';
    }

}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
