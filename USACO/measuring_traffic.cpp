/* USACO 2019 February Contest, Bronze
Problem 3. Measuring Traffic */
// Link problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=917
// Video solution: https://www.youtube.com/watch?v=RZBnIYC3GTw

#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

// An useful template for debugging by printing out the values of a pair.
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << pair.first << ' ' << pair.second << '\n';
}

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    std::pair<int, int> before_first_mile {};

    std::pair<int, int> after_last_mile {};

    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, std::pair <int, int>>> traffic_records (N); 

    /* 
    To find the range of possible final flows of traffic.
    Assuming that the values range of the traffic flow before the first mile is [x, y]
    When we encounter an on-ramp sensor with the range [a, b], we update the flow as [x + a, y + b]
                         off-ramp                                                    [x - b, y - a]
                         none                                                        [max(x, a), min(y, b)]
    */

    /* Warning: The lower bound range of the traffic flow in anytime can't be a negative value. */

    for (int i {}; i < N; ++i)
    {
        std::string sensor_type; 
        int lower_endpoints, upper_endpoints; 
        std::cin >> sensor_type >> lower_endpoints >> upper_endpoints;


        if (after_last_mile.first != 0 and after_last_mile.second != 0)
        {
            if (sensor_type == "on")
            {
                after_last_mile.first += lower_endpoints;
                after_last_mile.second += upper_endpoints;
            }
            else if (sensor_type == "off")
            {
                after_last_mile.first -= std::min(upper_endpoints, after_last_mile.first);
                after_last_mile.second -= lower_endpoints;
            }
            else 
            {
                after_last_mile.first = std::max(after_last_mile.first, lower_endpoints);
                after_last_mile.second = std::min(after_last_mile.second, upper_endpoints);
            }
        }
        else 
        {
            if (sensor_type == "none")
            {
                after_last_mile.first = lower_endpoints;
                after_last_mile.second = upper_endpoints;
            }

        }

        traffic_records[i].first = sensor_type; 
        traffic_records[i].second.first = lower_endpoints;
        traffic_records[i].second.second = upper_endpoints;
    }

    /* After we find out the value of the range most specific possible for the rate of 
    traffic flow after the last mile, we move backwards to find of that of before the first mile. */

    before_first_mile = after_last_mile;

    for (int j {N - 1}; j >= 0; --j)
    {
        if (traffic_records[j].first == "on")
        {
            before_first_mile.first -= std::min(traffic_records[j].second.second, before_first_mile.first);
            before_first_mile.second -= traffic_records[j].second.first;
        }
        else if (traffic_records[j].first == "off")
        {
            before_first_mile.first += traffic_records[j].second.first;
            before_first_mile.second += traffic_records[j].second.second;
        }
        else 
        {
            before_first_mile.first = std::max(before_first_mile.first, traffic_records[j].second.first);
            before_first_mile.second = std::min(before_first_mile.second, traffic_records[j].second.second);
        }
    }

    std::cout << before_first_mile << after_last_mile;
}

int main()
{
    setIO("traffic"); 
    solve();
}
