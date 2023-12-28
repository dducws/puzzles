// Problem: https://codeforces.com/contest/466/submission/166792530


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

/* (On 7 August 2023) Compared to my initial solution, this implementation avoids using additional data structures like sets or unordered sets,
which simplifies the code and potentially improves efficiency. In addition, it also iterates through the array only once in the main loop (instead
of twice with a nested loop as my initial implementation did), reducing the number of iterations and improving efficiency. The logic is used more
concisely to directly check if the remaining part's sum is two-thirds of the total sum and if the first part's sum is one-third of the total sum.
Thanks to all these improvements, the execution time is reduced from 280ms to just 78ms. */
void solve()
{
    int n;
    std::cin >> n;
    std::vector<ll> prefixSums (n + 1);
    for (int i {1}; i <= n; ++i)
    {
        std::cin >> prefixSums[i];
        prefixSums[i] += prefixSums[i - 1];
    }

    ll ways_to_split {}; 
    int firstGroups {};
    for (int i {1}; i < n; ++i)
    {
        /* Warning: We should prefer multiplications to divisions when checking conditions to prevent
        rounding errors when we divide a number in long long by another number in long long type. */
        // Check if the remaining part's sum is two-thirds of the total sum
        if ((prefixSums[n] - prefixSums[i]) * 3 == prefixSums[n])
            ways_to_split += firstGroups;
        
        // Check if the first part's sum is one-third of the total sum and there are more than one element in the middle part
        if (prefixSums[i] * 3 == prefixSums[n] && n - i > 1)
            ++firstGroups;
    }

    std::cout << ways_to_split;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
    