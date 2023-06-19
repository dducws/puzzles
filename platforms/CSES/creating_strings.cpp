// Creating Strings - CSES Problem Set
// Problem: https://cses.fi/problemset/task/1622
// Solution: https://usaco.guide/bronze/complete-rec?lang=cpp#generating-permutations-using-next_permutation

/* One small detail is that you need to sort the string before calling next_permutation() 
because the method generates strings in lexicographical order. If the string isn't sorted,
then strings which are lexicographically smaller than the initial string won't be generated. */


#include <iostream> 
#include <vector>
#include <algorithm>

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    std::string s;
    std::cin >> s; 
    /* Sort the string in lexicographical order using std::sort.
    This works for sorting all characters in a string. */
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
