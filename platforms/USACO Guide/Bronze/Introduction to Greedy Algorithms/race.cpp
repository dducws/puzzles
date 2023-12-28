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
        int timeUsed {}, speeding_up_distances {}, slowing_down_distances {};

        for (int current_speed {1};; current_speed++)
        {
            speeding_up_distances += current_speed;
            timeUsed++;

            if (speeding_up_distances + slowing_down_distances >= K)
                break;
            
            if (current_speed >= X)
            {
                slowing_down_distances += current_speed;
                timeUsed++;

                if (speeding_up_distances + slowing_down_distances >= K)
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
