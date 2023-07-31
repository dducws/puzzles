// Problem: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/double-beauty-711a7ca1/


#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    int T;
    std::cin >> T; 
    while (T--)
    {
        int K, N;
        std::cin >> N >> K;
        std::vector<int> A (N);
        for (int i {}; i < N; ++i)
        {
            std::cin >> A[i];
        }

        /* (On 17 July 2023) Mistake: do not carefully reading the problem requirements. 
        If the requirement is to find the maximum beauty among all PERMUTATIONS, it is necessary to sort the list first. */
        std::sort(all(A));
        int max_beauty_all_permutations {};

        for (int i {N - 1}; i > N - 1 - K; --i)
        {
            max_beauty_all_permutations += A[i];
        }

        std::cout << max_beauty_all_permutations * 2 << '\n';
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
