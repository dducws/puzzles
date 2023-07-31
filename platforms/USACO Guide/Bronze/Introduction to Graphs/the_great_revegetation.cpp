/* USACO 2019 February Contest, Bronze
Problem 2. The Great Revegetation */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=916
// Explanation: https://youtu.be/GT9PEJbJjxo
// Edited: chatGPT


#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <set>

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

void solve()
{
    int N, M;
    std::cin >> N >> M;
    /* The code uses the line grassTypes[pasture - 1] = *(s.begin()) to assign the smallest available grass type to each pasture. 
    However, this logic depends on the fact that std::map iterates over its elements in ascending order of the keys.
    If we switch to std::unordered_map, the iteration order of elements is not deterministic and not based on the key values.
    This means that the logic of assigning grass types based on the smallest available type would no longer work correctly. 
    The assigned grass types may not be the smallest available ones, and the results would be incorrect. */
    std::map<int, std::vector<int>> cowFavorites;

    for (int i {}; i < M; ++i)
    {
        int favorite1, favorite2; 
        std::cin >> favorite1 >> favorite2;
        cowFavorites[favorite1].push_back(favorite2);
        cowFavorites[favorite2].push_back(favorite1);
    }

    std::vector<int> grassTypes(N, 0);

    for (const auto& [pasture, favorites] : cowFavorites)
    {
        std::set<int> s {1, 2, 3, 4};
        for (int i {}; i < sz(favorites); ++i)
        {
            if (s.count(grassTypes[favorites[i] - 1]))
                s.erase(grassTypes[favorites[i] - 1]);
        }

        /* Only 2 July 2023: Initially, I made a mistake by assigning the smallest available grass type based on 
        the maximum grass type among the favorite pastures. However, this logic is incorrect because it doesn't 
        guarantee that the assigned grass type is the smallest and at most 4. The correct approach is to assign the 
        smallest available grass type using a set and the `s.begin()` iterator. */
        grassTypes[pasture - 1] = *(s.begin());
    }

    for (int i {}; i < N; ++i)
    {
        if (grassTypes[i])
            std::cout << grassTypes[i];
        /* I also made a mistake here when I forgot to assign grass types to unassigned pastures.
        With this line, any pasture without an assigned grass type will be assigned the smallest type (1).*/
        else 
            std::cout << 1;     
    }
}

int main()
{
    setIO("revegetate");
    solve();
}
