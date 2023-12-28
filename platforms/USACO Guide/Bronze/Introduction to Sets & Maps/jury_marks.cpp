// Problem: https://codeforces.com/contest/831/problem/C


#include <iostream> 
#include <vector> 
#include <unordered_set>

void solve()
{
    int k, n;
    std::cin >> k >> n;
    std::vector<int> A (k), B(n);

    for (int i {}; i < k; ++i)
    {
        std::cin >> A[i];
        if (i)
        {
            A[i] += A[i - 1];
        }
    }

    for (auto& remembered_point : B)
    {
        std::cin >> remembered_point;
    }

    std::unordered_set<int> potential_starting_points; 
    potential_starting_points.reserve(k);

    for (int i {}; i < k; ++i)
    {
        /* If the code were to choose a different remembered score as the reference point, 
        it would still find valid potential starting scores, but the values would be shifted accordingly. 
        The choice of the first remembered score is arbitrary and simply serves as a reference point for the calculation. */
        potential_starting_points.insert(B[0] - A[i]);
    }

    int points {};
    for (const auto starting_point : potential_starting_points)
    {
        bool satisfy {true};
        std::unordered_set<int> prefix_points;
        prefix_points.reserve(k);

        for (int i {}; i < k; ++i)
            prefix_points.insert(starting_point + A[i]);
        
        for (const auto remembered_point : B)
        {
            if (prefix_points.find(remembered_point) == prefix_points.end())
            {
                satisfy = false;
                break;
            }
        }

        if (satisfy)
            ++points;
    }

    std::cout << points << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
