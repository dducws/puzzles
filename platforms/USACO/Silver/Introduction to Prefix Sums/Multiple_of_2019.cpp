// Problem: https://atcoder.jp/contests/abc164/tasks/abc164_d
// Explanation: https://www.youtube.com/watch?v=83yW2Pp6HMk


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int MOD = 2019;

/* In this problem, we apply the "prefix sum" technique but instead of exploiting the 
value of sum of digits, we utilize the value represented by the prefixes so we can keep
track the mod of a subarray of avery big number without directly storing it. 
Besides that, it is necessary to apply the formula (a + b) % m = (a % m + b % m) % m
to keep track of the remainder after each suffix and the power_of_10. */
void solve()
{
    std::string S;
    std::cin >> S;

    int n = S.length(), suffix {}, power_of_10 {1};
    ll answer {};
    int count_suffixes [MOD] {};

    /* We have to increment the value of 0 initially in the count_suffixes array because as we loop through the array, 
    when we meet an element with suffix mod 2019 = 0, we have to add it to the answer right away. */
    ++count_suffixes[0];

    for (int i {n - 1}; i >= 0; --i)
    {
        int digit = S[i] - '0';
        /* The 'suffix' represents the remainder when the substring S[i:n-1] 
        (from i-th character to the last character) is divided by MOD.
        As we iterate through the characters of S from the end (right to left), 
        'suffix' effectively represents the remainder of S[i:n-1], S[i-1:n-1] ..., S[0:n-1].*/
        suffix = (suffix + digit * power_of_10) % MOD; 
        /* The 'power_of_10' variable represents the value of 10 raised to the power of 'i', 
        where 'i' is the position of the current digit in the substring. This value is used
        to correctly calculate the suffix when adding the current digit to the existing suffix. */
        power_of_10 = power_of_10 * 10 % MOD;
        answer += count_suffixes[suffix];
        ++count_suffixes[suffix];
    }

    std::cout << answer << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve(); 
}
