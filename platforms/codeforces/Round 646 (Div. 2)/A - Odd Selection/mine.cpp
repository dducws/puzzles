// Problem: https://codeforces.com/contest/1363/problem/A


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int t, n, x;
    std::cin >> t; 
    while (t--)
    {
        std::cin >> n >> x; 
        std::vector<int> a (n);
        int odd {}, even {};
        for (int i {}; i < n; ++i)
        {
            std::cin >> a[i];
            if (a[i] % 2)
                ++odd;
        }
        even = n - odd;

        if (odd == 0)
            std::cout << "No\n";
        else 
        {
            int odd_convert_to_even {}, even_needed {x - 1};
            if (odd > 2)
            {
                if (odd % 2 == 1)
                {
                    odd_convert_to_even = odd - 1;
                    odd = 1;
                }
                else 
                {
                    odd_convert_to_even = odd - 2;
                    odd = 2;
                }
            }

            if (even_needed % 2)
                even_needed = std::max(1, even_needed - odd_convert_to_even);
            else 
                even_needed = std::max(0, even_needed - odd_convert_to_even);

            if (even_needed > 0)
                even_needed = std::max(0, even_needed - even);

            if (even_needed)
                std::cout << "No\n";
            else 
                std::cout << "Yes\n";

        }
    }   
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}