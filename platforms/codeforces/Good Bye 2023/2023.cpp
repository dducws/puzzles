#include <iostream>
#include <vector>
#include <algorithm>
 
using ll = long long;
 
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int t, left_element, left_elements, removed_elements; 
    std::cin >> t; 
    while (t--)
    {
        std::cin >> left_elements >> removed_elements;
        // Use the long long type to prevent overflow.
        ll total {1};
        
        while (left_elements--)
        {
            std::cin >> left_element;
            total *= left_element;
        }
        
        // If the remainder of the division is not zero.
        if (2023 % total)
            std::cout << "NO\n";
        else 
        {
            /* (On 1/1/2024) The condition for the removed element is that there is at least one of them. As long as the product of all the remaining elements in the list 
            is divisible by 2023, we can find the other element by dividing 2023 by the current total. After that, all remaining elements are just 1. 
            It is unnecessarily complex when I was trying to factor 2023 out and see that only 1, 7, 17, and 2023 are the elements that can be divisible 
            by 2023. Also, a logical mistake in my submission solution in the contest can be illustrated through this test case:
            1 
            1 1 
            7
            My contest solution output:
            NO
            Expected output:
            YES 
            289 */
            std::cout << "YES\n";
            std::cout << 2023 / total << " ";
            --removed_elements; 
            while (removed_elements--)
            {
                std::cout << 1 << " ";
            }
            std::cout << '\n';
        }
    }
}
 
int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
