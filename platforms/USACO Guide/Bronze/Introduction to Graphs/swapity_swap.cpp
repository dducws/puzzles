/* USACO 2020 February Contest, Bronze
Problem 3. Swapity Swap */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1013
// Edited: chatGPT


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

void solve()
{
    int N, K, A1, A2, B1, B2;
    std::cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    std::vector<int> initialOrder (N), finalOrder (N);
    
    for (int i {}; i < N; ++i)
    {
        initialOrder[i] = finalOrder[i] = i + 1;
    }

    int cycle {};
    /* On 15 July 2023, I initially assumed that the number of cycles for all test cases is 4, 
    but it turned out to be incorrect. To find the exact number of cycles, we need to iterate 
    until the initial order matches the final order. */
    while (true)
    {
        std::reverse(initialOrder.begin() + (A1 - 1), initialOrder.begin() + A2);
        std::reverse(initialOrder.begin() + (B1 - 1), initialOrder.begin() + B2);
        ++cycle;
        if (initialOrder == finalOrder)
            break;
    }

    for (int i {1}; i <= K % cycle; ++i)
    {
        std::reverse(finalOrder.begin() + (A1 - 1), finalOrder.begin() + A2);
        std::reverse(finalOrder.begin() + (B1 - 1), finalOrder.begin() + B2);
    }

    for (int number : finalOrder)
        std::cout << number << '\n';
}

int main()
{
    setIO("swap"); 
    solve();
}

