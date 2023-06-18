// Problem: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/too-chocolatey-232e97e0/
// Edited: chatGPT


#include <iostream> 
#include <set>

using ll = long long;

void solve()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N; 
        std::cin >> N;
        std::multiset<int> A;
        for (int i {}; i < N; ++i)
        {
            int sugar; 
            std::cin >> sugar; 
            if (A.count(sugar) < 2)
                A.insert(sugar);
        }
        ll Alex {}, Bob {};
        // Alex goes first
        bool order = true;

        for (auto rit = A.rbegin(); rit != A.rend(); ++rit)
        {
            order ? Alex += *rit : Bob += *rit;
            order = !order;
        }

        std::cout << (Alex > Bob ? "Alex\n" : "Bob\n");
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
