// Problem: https://www.usaco.org/index.php?page=viewproblem2&cpid=739
// Tutorial: https://usaco.guide/problems/usaco-739-bovine-genomics/solution


#include <iostream> 
#include <vector>
#include <unordered_map>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(std::string name = "")
{
    std::cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name))
    { 
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
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
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> spotty_cows (N), plain_cows (N);

    for (auto& spotty_cow : spotty_cows)
        std::cin >> spotty_cow;
    
    for (auto &plain_cow : plain_cows)
        std::cin >> plain_cow;

    int spottiness {};

    for (int i {}; i < M; ++i)
    {
        for (int j {i + 1}; j < M; ++j)
        {
            for (int k {j + 1}; k < M; ++k)
            {
                bool distinct {true};
                std::unordered_map<std::string, bool> spotty_genomics (N);

                // Store the genomic sequences of spotty cows in the unordered map
                for (const auto& spotty_cow : spotty_cows)
                {
                    std::string genomics ({static_cast<char>(spotty_cow[i]), static_cast<char>(spotty_cow[j]), static_cast<char>(spotty_cow[k])});     
                    spotty_genomics[genomics] = true;
                }

                // Check if the genomic sequences of plain cows exist in the unordered map
                for (const auto& plain_cow : plain_cows)
                {
                    std::string genomics ({static_cast<char>(plain_cow[i]), static_cast<char>(plain_cow[j]), static_cast<char>(plain_cow[k])});
                    if (spotty_genomics[genomics])
                    {
                        distinct = false;
                        break;
                    }
                }

                // If the set of three positions is distinct, increment the spottiness count
                if (distinct)
                    ++spottiness;
            }
        }
    }

    std::cout << spottiness << '\n';
}

int main()
{
    setIO("cownomics"); 
    solve();
}
