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

bool sortBySellingPrices(const std::pair<ll, ll>& customer1, const std::pair<ll, ll>& customer2)
{
    return customer1.second > customer2.second;
}

void solve()
{
    int N, M, R;
    std::cin >> N >> M >> R;

    std::vector<int> milkProductions (N);
    for (int i {}; i < N; ++i)
    {
        std::cin >> milkProductions[i];
    }
    std::sort(all(milkProductions), std::greater<int>());

    std::vector<std::pair<int, int>> sellingPrices (M);
    for (int i {}; i < M; ++i)
    {
        std::cin >> sellingPrices[i].first >> sellingPrices[i].second;
    }
    std::sort(all(sellingPrices), sortBySellingPrices);

    std::vector<int> rentalPrices (R);
    for (int i {}; i < R; ++i)
    {
        std::cin >> rentalPrices[i];
    }
    std::sort(all(rentalPrices), std::greater<int>());

    std::vector<ll> prefixSumsRental (R);
    prefixSumsRental[0] = rentalPrices[0];
    for (int i {1}; i < R; ++i)
    {
        prefixSumsRental[i] += prefixSumsRental[i - 1] + rentalPrices[i];
    }

    std::vector<ll> prefixSumsSelling; 
    int id {};
    for (int i {}; i < N; ++i)
    {
        int amount {};
        ll profit {};
        while (milkProductions[i] > 0 && id < M)
        {
            amount = std::min(milkProductions[i], sellingPrices[id].first);
            milkProductions[i] -= amount; 
            profit += amount * sellingPrices[id].second; 

            if (amount == sellingPrices[id].first)
                ++id; 
            else 
                sellingPrices[id].first -= amount; 
        }

        if (profit > 0)
        {
            prefixSumsSelling.push_back(profit);
            if (sz(prefixSumsSelling) >= 2)
                prefixSumsSelling[sz(prefixSumsSelling) - 1] += prefixSumsSelling[sz(prefixSumsSelling) - 2];
        }
        else 
            break;
    }

    ll maxProfit {};
    if (R + sz(prefixSumsSelling) <= N)
        maxProfit = prefixSumsSelling[sz(prefixSumsSelling) - 1] + prefixSumsRental[R - 1];
    else 
    {
        for (int j {sz(prefixSumsSelling) - 1}; j >= 0; --j)
        {
            int rentNeed = N - (j + 1);
            if (rentNeed > R)
                break;
            
            if (rentNeed > 0)
                maxProfit = std::max(maxProfit, prefixSumsSelling[j] + prefixSumsRental[rentNeed - 1]);
            else 
            {
                if (sz(prefixSumsSelling) >= N)
                    maxProfit = std::max(maxProfit, prefixSumsSelling[N - 1]);
            }
        }

        for (int j {R - 1}; j >= 0; --j)
        {
            int sellNeed = N - (j + 1);
            if (sellNeed > sz(prefixSumsSelling))
                break; 
            
            if (sellNeed > 0)
                maxProfit = std::max(maxProfit, prefixSumsRental[j] + prefixSumsSelling[sellNeed - 1]);
            else
            {
                if (R >= N) 
                    maxProfit = std::max(maxProfit, prefixSumsRental[N - 1]);
            }
        }
    }

    std::cout << maxProfit;
}

int main()
{
    setIO("rental"); 
    solve();
}
