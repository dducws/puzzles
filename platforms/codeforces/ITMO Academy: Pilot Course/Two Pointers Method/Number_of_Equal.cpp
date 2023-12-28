// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (ll) (x).size()

void countPair(std::vector<ll>& a, std::vector<ll>& b)
{
    ll count {};
    int i {}, j {};
    while (i < sz(a) && j < sz(b))
    {
        if (a[i] < b[j])
            ++i;
        else if (a[i] > b[j])
            ++j;
        else
        {
        /*
        On 28/12/2023: The solution was incorrect on the test 13 multiple times because I initially set the data types 
        of inA and inB as int; however, they should be long long. This is because when inA * inB is added to count, 
        if they are of type int, overflow might occur.
        */
            ll inA {}, inB {}, equalValue {a[i]};
            while (i < sz(a) && a[i] == equalValue)
            {
                ++i; 
                ++inA;
            }

            while (j < sz(b) && b[j] == equalValue)
            {
                ++j;
                ++inB;
            }

            count += inA * inB;
        }
    }

    std::cout << count << '\n';
 }

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<ll> a (n), b(m);
    for (int i {}; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for (int j {}; j < m; ++j)
    {
        std::cin >> b[j];
    }

    countPair(a, b);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}