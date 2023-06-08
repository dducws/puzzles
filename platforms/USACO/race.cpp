/* USACO 2020 January Contest, Bronze
Problem 3. Race */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=989
// Solution: http://www.usaco.org/current/data/sol_race_bronze_jan20.html

#include <iostream>

void setIO(std::string name = "") {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() 
{
    int K, N;
    std::cin >> K >> N;

    while (N--)
    {
        int X;
        std::cin >> X;
        int timeUsed {}, speeding_up_distance {}, slowing_down_distance {};

        for (int current_speed {1};; current_speed++)
        {
            speeding_up_distance += current_speed;
            timeUsed++;

            if (speeding_up_distance + slowing_down_distance >= K)
                break;
            
            if (current_speed >= X)
            {
                slowing_down_distance += current_speed;
                timeUsed++;

                if (speeding_up_distance + slowing_down_distance >= K)
                    break;
            }
        }

        std::cout << timeUsed << '\n';
    }
}

int main()
{    
    setIO("race");
    solve(); 
}