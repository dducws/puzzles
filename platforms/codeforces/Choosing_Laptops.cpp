// Problem: https://codeforces.com/contest/106/problem/B


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

/* Define a struct to represent a Laptop, encapsulating all its properties. 
Using user-defined type Laptop makes the code much cleaner and easier to read. */
struct Laptop 
{
    int speed, ram, hdd, cost;
};

const int most_expensive = 1000;

void solve()
{
    int n, chose {}, cheapest {most_expensive + 1};
    std::cin >> n;
    // Use a vector of Laptops instead of a 2D array to store the laptop information for better readability.
    std::vector<Laptop> laptops (n);
    std::vector<bool> outdated (n);

    for (int i {}; i < n; ++i)
    {
        std::cin >> laptops[i].speed >> laptops[i].ram >> laptops[i].hdd >> laptops[i].cost;
    }

    for (int i {}; i < n; ++i)
    {
        for (int j {i + 1}; j < n; ++j)
        {
            if (laptops[i].speed > laptops[j].speed && laptops[i].ram > laptops[j].ram && laptops[i].hdd > laptops[j].hdd)
                outdated[j] = true;
            else if (laptops[i].speed < laptops[j].speed && laptops[i].ram < laptops[j].ram && laptops[i].hdd < laptops[j].hdd)
                outdated[i] = true;
        }
    }

    for (int i {}; i < n; ++i)
    {
        if (!outdated[i] && laptops[i].cost < cheapest)
        {
            chose = i;
            cheapest = laptops[i].cost;
        }
    }

    std::cout << chose + 1;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
