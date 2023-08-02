// Problem: https://codeforces.com/problemset/problem/616/A


#include <iostream> 
#include <string> 

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    std::string a, b;
    std::cin >> a >> b;

    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));

    if (a.length() < b.length())
        std::cout << "<\n";
    else if (a.length() > b.length())
        std::cout << ">\n";
    else 
    {
        int comparison = a.compare(b);
        if (comparison > 0)
            std::cout << ">\n";
        else if (comparison < 0)
            std::cout << "<\n";
        else 
            std::cout << "=\n";
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
