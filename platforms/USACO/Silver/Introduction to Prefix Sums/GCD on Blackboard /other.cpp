// Problem: https://atcoder.jp/contests/abc125/tasks/abc125_c
// Source: https://atcoder.jp/contests/abc125/submissions/43936515


#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

// Function to calculate the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.
int calculate_gcd(int a, int b) 
{
    if (b == 0) return a;
    return calculate_gcd(b, a % b);
}

/* This implementation is based on the idea that the maximum possible GCD of N numbers after
replacing one of them with another number is equal to the GCD of the remaining N - 1 numbers. 
For example, if we have an array [2, 4, 6, 8], and we replace the third element with 5, 
the maximum possible GCD is 2, which is the same as the GCD of [2, 4, 8]. 

For example, if we have an array [2, 4, 6, 8], and we apply the function calculate_gcd to it, we get:
prefix_gcd = [2, 2, 2, 2] suffix_gcd = [2, 2, 2, 8]

The prefix_gcd[i] value represents the GCD of all the elements from arr[0] to arr[i]. 
The suffix_gcd[i] value represents the GCD of all the elements from arr[i] to arr[n - 1]. 
Using these arrays, we can easily find the GCD of any subarray of arr by combining the 
corresponding prefix and suffix values. For example, if we want to find the GCD of arr[1…3], we can use:
calculate_gcd(prefix_gcd[0], suffix_gcd[3]) = calculate_gcd(2, 8) = 2 */
void solve() 
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i]; 
    }

    std::vector<int> prefix_gcd(n), suffix_gcd(n);

    prefix_gcd[0] = arr[0];
    for (int i = 1; i < n; ++i) 
    {
        prefix_gcd[i] = calculate_gcd(prefix_gcd[i - 1], arr[i]);
    }

    suffix_gcd[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) 
    {
        suffix_gcd[i] = calculate_gcd(suffix_gcd[i + 1], arr[i]);
    }

    int max_gcd = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (i == 0) 
            max_gcd = std::max(max_gcd, suffix_gcd[i + 1]);
        else if (i == n - 1) 
            max_gcd = std::max(max_gcd, prefix_gcd[i - 1]);
        else 
            max_gcd = std::max(max_gcd, calculate_gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]));
    }

    std::cout << max_gcd << '\n';
}

int main() 
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
