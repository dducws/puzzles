/* USACO 2022 US Open Contest, Bronze
Problem 1. Photoshoot */
// Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1227
// Explanation: https://youtu.be/CMdPvI82D6A?t=72


#include <iostream> 

void solve()
{
    int N;
    std::string order, reduced;
    std::cin >> N >> order;  

    for (int i {}; i < N; i += 2)
    {
        if (order[i] != order[i + 1])
        {
            if (order[i] == 'G')
                reduced += '1';
            else 
                reduced += '0';
        }
    }

    reduced += '0';
    int reversals {};

    for (int i {}; i <= reduced.length() - 2; ++i)
    {
        if (reduced[i] != reduced[i + 1])
            ++reversals;
    }

    std::cout << reversals << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}