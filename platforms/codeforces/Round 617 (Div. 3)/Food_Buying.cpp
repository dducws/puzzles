// Problem: https://codeforces.com/contest/1296/problem/B


#include <iostream>

using ll = long long;

void solve()
{
    int t;
    std::cin >> t;
    
    while (t--)
    {
        ll s;
        std::cin >> s;
        
        ll max_burles = 0;
        
        while (s >= 10)
        {
            ll cashback = s / 10; // Calculate cashback using integer division instead of floating-point division
            max_burles += cashback * 10; // Accumulate the maximum burles spent after receiving the cashback
            s -= cashback * 9; // After spending 'cashback', Mishka keeps 1 burle as cashback for the next round
        }
        
        max_burles += s; // Add the remaining burles (less than 10) after all the cashbacks
        std::cout << max_burles << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}