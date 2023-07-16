/* USACO 2019 US Open Contest, Bronze
Problem 3. Cow Evolution */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=941
// Explanation: https://www.youtube.com/watch?v=4YTijr0BbrA
// Edited: chatGPT

/* In the official analysis, the author suggests mentions another approach, which is highly applicable in real-world scenarios to solve problems in biology. 
However, I find it challenging to grasp the intricacies of this approach at the moment. 
I intend to revisit this problem in the future and attempt to solve it using that approach. */
// Official analysis: http://www.usaco.org/current/data/sol_evolution_bronze_open19.html


#include <iostream> 
#include <vector>
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


/* On 16 July 2023, initially, I attempted to solve this problem by using nested loops to compare 
the characteristics of sub-populations. My assumption was that if two sub-populations have the same number of characteristics, 
I could determine their relationship based on the number of different characteristics between them.
The logic I used was as follows:
- If the number of different characteristics between the two sub-populations equals the number of characteristics in each of them,
I concluded that they have different ancestor characteristics.
- Furthermore, if there are no two cows with the same number of characteristics, it would imply that each sub-population belongs 
exclusively to one of the two children of the root in the evolutionary tree.
However this approach is insufficient to determine the proper evolutionary tree in all cases. */

/* It is crucial to be aware of the condition for constructing a proper tree, which states that an evolutionary tree is called "proper"
if each newly evolved feature originates in exactly one edge of the tree, meaning it evolved at a single point in history. 
This condition ensures that the evolutionary tree accurately represents the lineage and development of characteristics within the bovine population. 
Failing to adhere to this condition will result in an invalid tree structure. */

/* The correct approach considers the relationships between pairs of characteristics. 
If we can find a cow that has characteristic A but not characteristic B, a cow that has characteristic B but not characteristic A, 
and a cow that has both characteristic A and B, it indicates that forming a proper evolutionary tree is impossible. 
This is because if we have a cow that has characteristic A but not characteristic B, and another cow that has characteristic B but not characteristic A, 
this suggests that these two characteristics are on separate branches. If either cow descended from the other one, 
it would have to possess both characteristic A and characteristic B. Therefore, finding a cow with both characteristics implies that it randomly
 developed either characteristic A or characteristic B, which invalidates the tree structure. */


int N;
std::vector<std::vector<std::string>> sub_populations;
std::vector<std::string> differentCharacteristics; 

bool check(int A, int B)
{
    bool AnotB {}, BnotA {}, both {};
    for (int i {}; i < N; ++i)
    {
        bool hasA {}, hasB {};
        for (const auto& characteristic : sub_populations[i])
        {
            if (characteristic == differentCharacteristics[A])
                hasA = true;
            else if (characteristic == differentCharacteristics[B])
                hasB = true;
        }

        if (hasA && !hasB)
            AnotB = true;
        if (!hasA && hasB)
            BnotA = true;
        if (hasA && hasB)
            both = true;
    }

    if (AnotB && BnotA && both)
        return false;
    else 
        return true;
}

void solve()
{
    std::cin >> N;
    sub_populations.resize(N);
    for (int i {}; i < N; ++i)
    {
        int K;
        std::string characteristic;
        std::cin >> K;
        sub_populations[i].resize(K);
        for (int j {}; j < K; ++j)
        {
            std::cin >> characteristic;
            sub_populations[i][j] = characteristic;
            if (std::find(all(differentCharacteristics), characteristic) == differentCharacteristics.end())
                differentCharacteristics.push_back(characteristic);
        }
    }

    for (int i {}; i < sz(differentCharacteristics); ++i)
    {
        for (int j {i + 1}; j < sz(differentCharacteristics); ++j)
        {
            if (!check(i, j))
            {
                std::cout << "no\n";
                return;
            }
        }
    }

    std::cout << "yes\n";
}

int main()
{
    setIO("evolution"); 
    solve();
}


