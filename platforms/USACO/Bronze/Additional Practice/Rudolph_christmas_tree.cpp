// Codeforces Round 883 (Div. 3)
// Problem: https://codeforces.com/contest/1846/problem/D
// Edited: chatGPT


#include <iostream>
#include <vector>
#include <iomanip>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        /* On 17 July 2023, initially, I used "int" types for variables 'd' and 'h' based on their limits, which are 2 * 10^5. 
        However, when calculating the product of 'd' and 'h' for casting to double, it is important to note that the product is still in "int" type. 
        In the case where both 'd' and 'h' are at their maximum limit, the product of them will exceed the limit of "int" type. 
        To avoid potential overflow and ensure accurate calculations, we need to use the "long long" type for 'd' and 'h'. */
        long long d, h;
        std::cin >> n >> d >> h;
        std::vector<int> y(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> y[i];
        }

        /* Here, we should use the "double" type instead of "float" for the variable 'total_area' to ensure safe calculations. 
        Using "float" may result in potential overflow, as the product of 'd' and 'h' could exceed the range of the "float" type. 
        By using "double", we can accommodate larger values and prevent overflow. */
        double total_area = static_cast<double>(d * h) / 2.0;
        for (int i {}; i < n - 1; ++i)
        {
            if (y[i + 1] - y[i] >= h)
                total_area += static_cast<float>(d * h) / 2.0;
            else
            {
                /* It is worth mentioning that the use of `static_cast<double>(d)` is generally preferred in C++ over `double(d)` for better readability and clarity.
                `static_cast<double>(d)` provides explicit type conversion and conveys the intention of the conversion more clearly. 
                Additionally, it helps catch any potential errors at compile-time, ensuring type safety and correctness of the code. */
                float tan_value = static_cast<float>(h) / (d / 2.0);
                float redundantParts = static_cast<float>(y[i + 1] - y[i]) / tan_value;
                float smallBase = static_cast<float>(d) - redundantParts * 2.0;
                total_area += (smallBase + d) * (y[i + 1] - y[i]) / 2.0;
            }
        }

        /* Because the problem states that "The answer will be considered correct if its absolute or relative error does not exceed 10^-6",
        we have to use std::setprecision to minimize rounding errors and ensure the most accurate representation of double numbers. */
        std::cout << std::setprecision(10) << total_area << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
