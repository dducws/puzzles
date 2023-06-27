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


// A much more efficient implementation using greedy algorithm
/* 
The approach works because it greedily selects the subarray that maximizes the score (number of 1s) after performing the flip operation.
By iteratively updating the maxScore based on the current element's contribution to the score,
the algorithm identifies the optimal subarray to flip in order to maximize the number of 1s.
*/

#include <iostream>
#include <algorithm>

int main()
{
    /* The reason for initializing maxScore = -1 is because in a niche test case when n = 1 and num = 1,
    the correct output has to be 0. Initializing maxScore = 0 leads to the output will be 1 which is incorrect. */
    // The purpose of using maxScore variable is to keep track the maximum additional 1s that can be obtained by flipping a subarray. 
    int n, maxScore {-1}, currentScore {}, count_ones {};
    std::cin >> n;
    
    while (n--)
    {
        int num;
        std::cin >> num;
        count_ones += num;
        // The expression '1 - 2 * num' represents the net change in the score resulting from flipping the current element.
        currentScore += 1 - 2 * num;
        maxScore = std::max(maxScore, currentScore);
        /* If the currentScore becomes negative, it means that the cumulative score has become negative, 
        indicating that the previous flips have resulted in more 0s than 1s. 
        In this case, it is more beneficial to start counting the score from the current position (resetting it to 0)
        rather than including the negative score in the calculation. */
        currentScore = std::max(0, currentScore);
    }
    
    int result = count_ones + maxScore;
    std::cout << result << '\n';
}
