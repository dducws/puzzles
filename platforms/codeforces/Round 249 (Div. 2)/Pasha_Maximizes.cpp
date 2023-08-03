// Problem: https://codeforces.com/contest/435/problem/B


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    std::string a; 
    int k; 
    std::cin >> a >> k;

    for (int i {}; i < a.length() - 1 && k > 0; ++i)
    {
        int maxIndex {i};
        // Find the index of the maximum digit in the remaining part of the string
        for (int j {i + 1}; j < a.length() && j - i <= k && a[maxIndex] != '9'; ++j)
        {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }
        // Swap the characters to move the maximum digit to its correct position
        for (int j {maxIndex}; j > i; --j)
        {
            std::swap(a[j], a[j - 1]);
        }
        // Decrement the number of swaps have just been used
        k -= (maxIndex - i);
    }

    std::cout << a;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
