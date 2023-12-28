// Problem: https://codeforces.com/contest/863/problem/B
// Reference: https://codeforces.com/contest/863/submission/157430652


#include <algorithm> 
#include <iostream>

void solve()
{ 
    int n;
    std::cin >> n;

    int N = 2 * n, w[N];

    for (int i = 0; i < N; i++)
        std::cin >> w[i];

    std::sort(w, w + N);

    int i0 {w[1] - w[0]}, i1 {}, i2 {};

    for (int i = 3; i < N; i += 2) 
    {
        int currentWeightDifference = w[i] - w[i - 1];

        /* This line updates the minimum instability for the current tandem kayak in the current iteration. 
        It aims to minimize the overall instability by considering the weight difference between the current
        person and the previous person in the list of weights.
        It is responsible for assigning pairs of people to the (n - 1) tandem kayaks. */
        i1 = std::min(i0, w[i - 1] - w[i - 2] + i1);

        /* This line calculates the minimum instability for the current iteration, considering both single and tandem kayaks.
        It aims to minimize the total instability for the entire kayaking journey. 
        At the same time, it handles the assignment of the remaining two people to the single kayaks. */
        i2 = std::min(i1, currentWeightDifference + i2);

        i0 += currentWeightDifference;
    }

    std::cout << i2 << '\n'; 
}

int main() 
{
    solve();
}