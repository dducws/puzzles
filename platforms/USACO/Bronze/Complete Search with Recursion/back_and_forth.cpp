/* USACO 2018 December Contest, Bronze
Problem 3. Back and Forth */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=857
// Edited + Solution: chatGPT


#include <iostream> 
#include <vector>
#include <unordered_set>

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

// Here, we use an unordered_set instead of a set because we don't require the elements to be stored in sorted order.
std::unordered_set<int> readings; 
const int BUCKETS = 10;

/*
    On 23 Jun, 2023, I couldn't write this recursive function properly. 
    I declared two variables, id_first and id_second, to keep track of the current indices used in the two vectors. However, both variables are redundant. 
    A better approach is to use a single variable, "day," in the function to keep track of the status of all trips.
    Additionally, I forgot to include the necessary steps to restore the barns to their previous states by using pop_back and insert operations. 
    This caused the barns to accumulate extra buckets, leading to incorrect results.
    Furthermore, I used another vector, "temp," to store all the milk that is transferred from barn1 to barn2 in four trips. 
    However, this approach is unnecessary. Instead, we can simply use an int variable named "milk" to keep track of the current milk in the first barn.  
    This modification also saves memory usage.
    Finally, the corrected implementation is provided below, which addresses these issues and produces the desired outcome.
*/

// Upon reflecting on this implementation, I find the recursive function to be truly beautiful in its design and execution.
void simulation(int day, std::vector<int>& barn1, std::vector<int>& barn2, int milk)
{
    if (day == 5)
    {
        readings.insert(milk);
        return;
    }

    if (day % 2)
    {
        for (int i {}; i < BUCKETS; ++i)
        {
            int bucket {barn1[i]};
            barn1.erase(barn1.begin() + i);
            barn2.push_back(bucket);
            simulation(day + 1, barn1, barn2, milk - bucket);
            barn2.pop_back();
            barn1.insert(barn1.begin() + i, bucket);
        }
    }
    else 
    {
        for (int i {}; i < BUCKETS; ++i)
        {
            int bucket {barn2[i]};
            barn2.erase(barn2.begin() + i);
            barn1.push_back(bucket);
            simulation(day + 1, barn1, barn2, milk + bucket);
            barn1.pop_back();
            barn2.insert(barn2.begin() + i, bucket);
        }
    }
}

void solve()
{
    std::vector<int> barn1 (BUCKETS), barn2 (BUCKETS);
    for (int i {}; i < BUCKETS; ++i)
    {
        std::cin >> barn1[i];
    }
    for (int j {}; j < BUCKETS; ++j)
    {
        std::cin >> barn2[j];
    }

    simulation(1, barn1, barn2, 1000);
    std::cout << sz(readings) << '\n';
}

int main()
{
    setIO("backforth");
    solve();
}