/* USACO 2022 February Contest, Bronze
Problem 1. Sleeping in Class */
// Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1203
// Solution: http://usaco.org/current/data/sol_prob1_bronze_feb22.html


#include <iostream> 
#include <vector>

void solve()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N; 
        std::cin >> N; 
        std::vector<int> a(N);
        int sum_a {};

        for (int i {}; i < N; ++i)
        {
            std::cin >> a[i];
            sum_a += a[i];
        }

        for (int j {N}; j >= 1; --j)
        {
            if (sum_a % j == 0)
            {
                // The desired sum for each range
                int targetSum {sum_a / j}; 
                // The sum of the current range
                int currentSum {};
                bool ok {true};

                for (int i {}; i < N; ++i)
                {
                    currentSum += a[i];
                    if (currentSum > targetSum)
                    {
                        // Can't split the array into j equal elements
                        ok = false;
                        break;
                    }
                    else if (currentSum == targetSum)
                    {
                        currentSum = 0;
                    }
                }

                if (ok)
                {
                    /* j is the maximum number of elements that could remain in the array after all modifications, 
                    then the minimum number of modifications will equal N - j */
                    std::cout << N - j << '\n';
                    // Finish this test case. 
                    break;
                }
            }
        }
    }
}

int main()
{
    solve();
}
