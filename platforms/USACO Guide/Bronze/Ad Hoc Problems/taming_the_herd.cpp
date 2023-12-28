// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=809
// Solution: https://www.youtube.com/watch?v=f_Otluj98kM

/* 
Check to make sure the first log entry is either -1 or 1. If not, output -1. 
Iterate through each day in the log from right to left. 
For each day, you update t or the log entry accordingly. 
If there's ever a contradiction between t and the log entry, output -1. 
At the end of each day, decrement t. 
Integer Variables t (number of days since the last breakout), 
req (number of breakouts that MUST have occurred), 
pos (number of breakouts that could have occurred)
*/


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

void solve()
{
    int N; 
    std::cin >> N;

    std::vector<int> log (N);

    // Read the log entries
    for (auto& day : log)
        std::cin >> day;

    if (log[0] > 0)
    {
        // If the first log entry is greater than 0, it is a contradiction, so output -1
        std::cout << -1 << '\n';
        return;
    }
    else 
    {
        log[0] = 0;
        int t {-1}, req {}, pos {};
        
        // Iterate through each day in the log from right to left
        for (int i {N - 1}; i >= 0; --i)
        {
            if (log[i] > 0)
            {
                // If the log entry is greater than 0, update the value of t
                if (t <= 0)
                    t = log[i];
            }

            if (t > -1)
            {
                // If t is a positive value, check for contradictions between t and the log entry
                if (log[i] != -1 && log[i] != t)
                {
                    // If there's a contradiction, output -1
                    std::cout << -1 << '\n';
                    return;
                }
                else 
                    log[i] = t;
                --t;
            }

            // Count the number of required breakouts and possible breakouts
            if (log[i] == 0)
                ++req;
            else if (log[i] == -1)
                ++pos;
        }

        // Output the minimum and maximum number of breakouts
        std::cout << req << ' ' << req + pos << '\n';
    }
}

int main()
{
    setIO("taming"); 
    solve();
}
