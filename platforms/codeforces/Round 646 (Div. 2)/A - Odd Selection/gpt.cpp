// Problem: https://codeforces.com/contest/1363/problem/A


#include <iostream>
#include <vector>

void solve()
{
    int t, n, x;
    std::cin >> t;
    
    while (t--)
    {
        std::cin >> n >> x;
        std::vector<int> a(n);

        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            if (a[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        /* This condition covers all possible scenarios where it's not possible to select elements with an odd sum, 
        and for the other cases, it automatically handles the selection of elements with an odd sum.*/
        if (odd == 0 || (odd % 2 == 0 && x == n) || (odd == n && x % 2 == 0))
            std::cout << "No\n";
        else
            std::cout << "Yes\n";
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}