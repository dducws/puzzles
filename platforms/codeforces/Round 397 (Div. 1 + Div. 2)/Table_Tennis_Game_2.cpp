// Problem: https://codeforces.com/contest/765/problem/C


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

/* On 4 August 2023, Initially my code in Python failed to pass this test case:
Input: 666666 6666666 666665
Output: -1
Because of my carelessness, I assumed that a % k == 0 in this test case. However, in reality, it would be 6.
After receiving some help, I realize that in the niche situations when one in two player has scores below k,
in order for the situation to happen, the other player has to have the score larger than and divisible by k.
That's the most important observation for this problem. */
void solve()
{
    int k, a, b; 
    std::cin >> k >> a >> b; 
    int maxSets {-1};
    if (a >= k && b >= k)
        maxSets = a / k + b / k;
    else if (a < k && b >= k && b % k == 0)
        maxSets = b / k;
    else if (a >= k && b < k && a % k == 0)
        maxSets = a / k;
    
    std::cout << maxSets;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
