// Problem: https://atcoder.jp/contests/abc125/tasks/abc125_c


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int N, max_number {}; 
ll MAX_GCD {1};
std::unordered_map<int, std::pair<int, int>> primeFactors;

void findPrimeFactors(int n)
{
    std::unordered_map<int, std::pair<int, int>> count;

    // Handle the case for 2 as a special prime factor
    while (n % 2 == 0)
    {
        ++count[2].first;
        n /= 2;
    }

    // Find other prime factors starting from 3
    for (int i = 3; pow(i, 2) <= n; i += 2)
    {
        while (n % i == 0)
        {
            ++count[i].first;
            n /= i;
        }
    }

    // If the remaining number is still greater than 2, it is also a prime factor
    if (n > 2)
        ++count[n].first;

    for (const auto& factor : count)
    {
        if (primeFactors[factor.first].second == 0)
            primeFactors[factor.first].first = factor.second.first;
        else
            primeFactors[factor.first].first = std::min(primeFactors[factor.first].first, factor.second.first);
        ++primeFactors[factor.first].second;
    }
}

void solve()
{
    std::cin >> N;
    std::vector<int> A (N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        findPrimeFactors(A[i]);
        max_number = std::max(A[i], max_number);
    }

    double extra1 {1}, extra2 {};
    std::vector<int> primeCheck;
    for (const auto& factor : primeFactors)
    {
        if (primeFactors[factor.first].second == N)
            MAX_GCD *= pow(factor.first, factor.second.first);
        else if (factor.second.second == N - 1)
        {
            extra1 *= pow(factor.first, factor.second.first);
            extra2 = std::max(extra2, pow(factor.first, factor.second.first));
            primeCheck.push_back(factor.first);
        }   
    }

    for (int i {}; i < N; ++i)
    {
        bool stop = true;
        for (int j {}; j < sz(primeCheck); ++j)
        {
            if (A[i] % primeCheck[j] == 0)
            {
                stop = false;
                break;
            }
        }

        if (stop)
        {
            std::cout << std::min(ll(max_number), MAX_GCD * static_cast<ll>(extra1)) << '\n';
            return;
        }
    }

    if (N == 2 && MAX_GCD < max_number)
        std::cout << max_number << '\n';
    else 
        std::cout << std::min(ll(max_number), MAX_GCD * static_cast<ll>(extra2)) << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
