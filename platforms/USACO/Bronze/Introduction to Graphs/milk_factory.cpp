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

int N;
std::vector<std::vector<int>> stations;
int central_station {-1};

void dfs(int i)
{
    if (sz(stations[i]) > 0)
    {
        std::vector<bool> visited (N + 1);
        int count {};

        std::vector<int> stack; 
        stack.push_back(i);

        while (!stack.empty())
        {
            int currentStation = stack.back();
            stack.pop_back();

            for (int station : stations[currentStation])
            {
                if (!visited[station])
                {
                    visited[station] = true;
                    stack.push_back(station);
                    ++count; 

                    if (count == N - 1)
                    {
                        central_station = i;
                        return;
                    }
                }
            }
        }
    }    
}

void solve()
{
    std::cin >> N;
    stations.resize(N + 1);

    for (int i {}; i < N - 1; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        stations[to].push_back(from);
    }

    for (int i {1}; i <= N; ++i)
    {
        dfs(i);

        if (central_station > 0)
            break;
    }
    
    std::cout << central_station << '\n';
}

int main()
{
    setIO("factory"); 
    solve();
}

