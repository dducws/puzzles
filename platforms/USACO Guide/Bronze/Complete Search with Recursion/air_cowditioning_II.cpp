/* USACO 2023 January Contest, Bronze
Problem 2. Air Cownditioning II */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
// Edited: chatGPT

// On 21st June 2023

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

// A useful template that prints out all elements of a vector
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

/* 
   This function was the most challenging aspect of the problem. 
   I really struggled to generate all subsets of conditioners with lengths ranging from 1 to M - 1.
   I also made a mistake by assuming that the functions chosen and combination operate the same way, and that I only need one of them.
   However, in reality, these two vectors serve different purposes:
   - The first vector, "chosen," represents the status of all conditioners as either chosen or not chosen.
   - The second vector, "combination," stores the indices of the conditioners that have been chosen.
*/
std::vector<std::vector<int>> generateCombinations(const std::vector<std::vector<int>>& conditioners, int quantity)
{
    std::vector<std::vector<int>> combinations; 
    std::vector<bool> chosen(sz(conditioners));
    std::fill(chosen.begin(), chosen.begin() + quantity, true);

    do 
    {
        std::vector<int> combination; 
        for (int j {}; j < sz(conditioners); ++j)
        {
            if (chosen[j])
                combination.push_back(j);
        }
        combinations.push_back(combination);
    }
    /* 
        Throughout this problem, I also learned how the std::prev_permutation function works. 
        It generates the previous lexicographically smaller permutation of a sequence and 
        rearranges the elements of the range into the previous lexicographically smaller permutation if it exists, 
        or it returns false if the current permutation is already the smallest.
        On the other hand, std::next_permutation generates the next lexicographically larger permutation of a sequence. 
        In this situation, the chosen vector we initialized initially already represents the largest lexicographically ordered permutation. 
        That's the reason why we have to use prev_permutation here. 
    */
    while (std::prev_permutation(all(chosen)));

    return combinations;
}

bool coolEnough(const std::vector<int>& stalls, const std::vector<int>& coolingAmount)
{
    for (int i {1}; i < sz(stalls); ++i)
    {
        if (stalls[i] > coolingAmount[i])
            return false;
    }
    
    return true;
}

void solve()
{
    std::vector<int> stalls(101, 0);
    int N, M;
    std::cin >> N >> M;
    for (int i {}; i < N; ++i)
    {
        int s, t, c; 
        std::cin >> s >> t >> c;
        for (int j {s}; j <= t; ++j)
        {
            stalls[j] += c;
        }
    }
    std::vector<std::vector<int>> conditioners (M, std::vector<int> (4));
    for (int i {}; i < M; ++i)
    {
        int a, b, p, m;
        std::cin >> a >> b >> p >> m;
        conditioners[i] = {a, b, p, m};
    }

    int cheapest {INT_MAX};
    for (int i {1}; i < M; ++i)
    {
        // All combinations of conditioners with a quantity of i will be generated.
        auto combinations = generateCombinations(conditioners, i);
        for (const auto& combination : combinations)
        {
            std::vector<int> currentCoolingAmount(101);
            int spent {};
            for (const auto& id : combination)
            {
                int starting_range {conditioners[id][0]}, ending_range {conditioners[id][1]}, coolingAmount {conditioners[id][2]}, price_tag {conditioners[id][3]};
                for (int k {starting_range}; k <= ending_range; ++k)
                {
                    currentCoolingAmount[k] += coolingAmount;
                }
                spent += price_tag;
            }

            if (coolEnough(stalls, currentCoolingAmount))
                cheapest = std::min(cheapest, spent);
        }
    }

    std::cout << cheapest << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
