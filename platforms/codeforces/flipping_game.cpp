// Codeforces Round 191 (Div. 2)
// Problem: https://codeforces.com/contest/327/problem/A
// Edited: chatGPT

// My brute force implementation
/* 
#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int n; 
    std::cin >> n; 
    std::vector<int> a (n);
    for (int i {}; i < n; ++i)
    {
        std::cin >> a[i];
    }

    int max_1s {};
    if (sz(a) == 1)
    {
        if (!a[0])
            max_1s = 1;
    }
    else 
    {
        for (int i {}; i < n; ++i)
        {
            int number_of_1s {};
            for (int j {}; j <= i; ++j)
            {
                if (a[j])
                    ++number_of_1s;
            }
            for (int k {i + 1}; k < n; ++k)
            {
                int another_1s {};
                for (int m {k + 1}; m < n; ++m)
                {
                    if (a[m])
                        ++another_1s;
                }
                int number_of_0s {};
                for (int l {i}; l <= k; ++l)
                {
                    if (!a[l])
                        ++number_of_0s;
                }
                max_1s = std::max(max_1s, number_of_1s + number_of_0s + another_1s);
            }
        }
    }

    std::cout << max_1s << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}

*/

// Efficient implementation using greedy algorithm
/* 
The greedy approach in this implementation works by iteratively updating the maxScore based on the current element's contribution to the score.
It keeps track of the count of ones encountered (count_ones) and maintains the highest score encountered so far (maxScore). 
By resetting the currentScore to 0 when it becomes negative, the algorithm greedily selects the subarray starting from the current position that maximizes the score. 
*/

#include <iostream>
#include <algorithm>

int main()
{
    int n, maxScore {-1}, currentScore {}, count_ones {};
    std::cin >> n;
    
    while (n--)
    {
        int num;
        std::cin >> num;
        count_ones += num;
        currentScore += 1 - 2 * num;
        maxScore = std::max(maxScore, currentScore);
        /* By setting currentScore to 0 if it is negative,
        we effectively "reset" the score to start counting from the current position. */
        currentScore = std::max(0, currentScore);
    }
    
    int result = count_ones + maxScore;
    std::cout << result << '\n';
}
