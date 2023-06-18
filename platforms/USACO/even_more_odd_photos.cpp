/* USACO 2021 January Contest, Bronze
Problem 2. Even More Odd Photos */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1084


#include <iostream> 

void solve()
{
    int N;
    std::cin >> N;

    int odd_IDs {}, even_IDs {}, groups {};

    for (int i {}; i < N; ++i)    
    {
        int cow; 
        std::cin >> cow; 
        if (cow % 2)
            ++odd_IDs;
        else 
            ++even_IDs;
    }

    while (odd_IDs > 0 || even_IDs > 0)
    {
        if (groups % 2) 
        {
            if (odd_IDs > 0)
                --odd_IDs;
            else 
                break;
        }
        else
        {
            if (even_IDs > 0)
                --even_IDs;
            else 
            {
                if (odd_IDs >= 2)
                    odd_IDs -= 2;
                else 
                {
                    odd_IDs = 0;
                    --groups;
                    break;
                }
            }
        }
        ++groups;
    }

    std::cout << groups << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}


// Here is a better solution from USACO team (https://usaco.guide/problems/usaco-1084-even-more-odd-photos/solution)
/* 
int main()
{
    int N {}, O {}, E {};
    std::cin >> N;
    for (int i {}; i < N; ++i)
    {
        int x;
        std::cin >> x;
        if (x % 2)
            ++O;
        else 
            ++E;
    }
    while (O > E)
    {
        O -= 2;
        ++E;
    }
    if (E > O + 1)
        E = O + 1;
    std::cout << E + O << '\n';
}
*/