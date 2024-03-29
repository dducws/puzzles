// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=787
// Solution https://usaco.guide/problems/usaco-787-rental-service/solution


#include <iostream> 
#include <vector>
#include <algorithm>

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

/* (As of August 10, 2023) My initial approach led me to spend a considerable amount of time debugging specific test cases for runtime errors. 
This was due to my reliance on the prefix sums technique for managing two arrays and formulating the incorrect   
conditions to keep track of the indexes of both of them.

Also through this problem, I realize that my preconceived notion that prefix sum techniques solely apply to arrays
is inaccurate. We can use a variable with a large value, such as with 'long long' data type to store the cumulative sum.

It's also worth noting that in this implementation, we eliminate the need for a custom comparator.
By simply inverting the input values from the stores, we can still can sort the list by selling prices. */
void solve()
{
    int n, m, r;
    std::cin >> n >> m >> r;

    std::vector<int> milkAmounts(n);
    for (auto& amount : milkAmounts)
        std::cin >> amount;
    
    // Read shop information, sort by selling price (in descending order)
    std::vector<std::pair<int, int>> shops(m);
    for (auto& shop : shops)
        std::cin >> shop.second >> shop.first;
    std::sort(all(shops), std::greater<std::pair<int, int>>());
    
    std::vector<int> rents(r);
    for (auto& rent : rents)
        std::cin >> rent;
    std::sort(all(rents), std::greater<int>());

    std::sort(all(milkAmounts), std::greater<int>());
    
    int shop_at {}, rent_at {}, current_cow {};
    ll maxProfit {};

    while (current_cow < n)
    {
        // Few temporary variables for calculating profit from selling milk
        int milkAmount {milkAmounts[current_cow]}, sell_profit {}, new_deal {}, current_shop {shop_at};

        while (current_shop < m)
        {
            int trade_amount = std::min(milkAmount, shops[current_shop].second);
            sell_profit += trade_amount * shops[current_shop].first; 
            milkAmount -= trade_amount;

            // When we've sold all the milk of the current cow, store the amount sold for the current shop
            if (milkAmount == 0)
            {
                new_deal = trade_amount;
                break;
            }
            else 
                ++current_shop;
        }

        if (rent_at >= r || sell_profit > rents[rent_at])
        {
            maxProfit += sell_profit;
            shop_at = current_shop;
            // Update remaining milk amount the shop can buy for a new cow
            if (current_shop < m)
                shops[current_shop].second -= new_deal; 
            ++current_cow;
        }
        else 
        {
            maxProfit += rents[rent_at];
            /* This decrement helps optimize profit by simulating renting the cows with the least milk production
            (at the beginning of the list). */
            --n;
            ++rent_at;
        }
    }

    std::cout << maxProfit;
}

int main()
{
    setIO("rental"); 
    solve();
}