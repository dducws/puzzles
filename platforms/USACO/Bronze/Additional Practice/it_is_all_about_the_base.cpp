// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=509
// Official analysis: http://www.usaco.org/current/data/sol_whatbase_bronze.html


#include <iostream> 
#include <vector>
#include <cmath>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

/*
std::vector<int> digits(int number)
{
    std::vector<int> all_digits;

    for (int i {2}; i >= 0; --i)
    {
        all_digits.push_back(number / static_cast<int>(pow(10, i)));
        number = number % static_cast<int>(pow(10, i));
    }

    return all_digits;
}

void solve()
{
    int K;
    std::cin >> K; 
    while (K--)
    {
        int first, second; 
        std::cin >> first >> second;
        std::vector<int> digits_first {digits(first)}, digits_second {digits(second)};
        int first1 = digits_first[0], first2 = digits_first[1], first3 = digits_first[2],
            second1 = digits_second[0], second2 = digits_second[1], second3 = digits_second[2];
        
        for (int X {10}; X <= 15000; ++X)
        {
            double Y = (-second2 + sqrt(pow(second2, 2) - 4 * second1 * static_cast<ll>(second3 - first1 * pow(X, 2) - first2 * X - first3))) / (2.0 * second1);
            if (Y == std::ceil(Y) && Y == std::floor(Y) && Y <= 15000.0 && Y >= 10)
            {
                std::cout << X << ' ' << static_cast<int>(Y) << '\n';
                break;
            }
        }
    }
}
*/

/* Rewritten implementation based on the official analysis from the USACO, which I find cleaner and more efficient than my original approach. */
const int MAX_BASE = 15000;

int numberInBase(const std::string& number, int base)
{
    return (number[0] - '0') * pow(base, 2) + (number[1] - '0') * base + (number[2] - '0');
}

void solve()
{
    int K; 
    std::cin >> K;
    while (K--)
    {
        std::string number_in_base_X, number_in_base_Y;
        std::cin >> number_in_base_X >> number_in_base_Y;

        int X {10}, Y {10};
        while (X <= MAX_BASE && Y <= MAX_BASE)
        {
            int number_X = numberInBase(number_in_base_X, X),
                number_Y = numberInBase(number_in_base_Y, Y);
            
            if (number_X < number_Y)
                ++X;
            else if (number_X > number_Y)
                ++Y;
            else 
            {
                std::cout << X << ' ' << Y << '\n';
                break;
            }
        }
    }
}

int main()
{
    setIO("whatbase"); 
    solve();
}
