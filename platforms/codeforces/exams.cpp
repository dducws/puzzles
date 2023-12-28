// Problem: https://codeforces.com/contest/479/problem/C


#include <iostream> 
#include <vector>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

bool compareDates(const std::pair<int, int>& date1, const std::pair<int, int>& date2)
{
    if (date1.first == date2.first)
        return date1.second < date2.second;
    
    return date1.first < date2.first;
}

void solve()
{
    int n; 
    std::cin >> n; 
    std::vector<std::pair<int, int>> exams_dates (n);
    for (auto& [onRecord, inReality] : exams_dates)
    {
        std::cin >> onRecord >> inReality;
    }

    std::sort(all(exams_dates), compareDates);

    std::vector<int> taking_exams_dates (n);
    taking_exams_dates[0] = exams_dates[0].second;

    for (int i {1}; i < n; ++i)
    {
        /* It might seem that if Valera can the last exam on record on the last day of all early dates,
        it will be the maximum number of dates Valera will take an exam. However, there can be scenarios where this condition is incorrect.
        For example:
        Input:
        4
        2 1
        8 7
        9 6
        10 8

        This condition was mistakenly assumed to be true on June 20th, 23.
        */

        if (exams_dates[i].second >= taking_exams_dates[i - 1])
            taking_exams_dates[i] = exams_dates[i].second;
        else 
            taking_exams_dates[i] = exams_dates[i].first;
    }

    std::cout << taking_exams_dates.back() << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}