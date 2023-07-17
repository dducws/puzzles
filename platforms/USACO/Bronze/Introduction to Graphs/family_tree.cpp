/* USACO 2018 US Open Contest, Bronze
Problem 3. Family Tree */
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=833
// Edited: chatGPT


#include <iostream> 
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack> 
#include <algorithm>

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


std::unordered_map<std::string, std::unordered_set<std::string>> cows;
std::string cow1, cow2, cow1Peer, cow2Peer; 
std::vector<std::string> relatedCows;

int dfs(const std::string& firstGapCow, const std::string& secondGapCow)
{
    std::stack<std::string> s;
    std::unordered_set<std::string> visited;
    visited.insert(firstGapCow);
    s.push(firstGapCow);
    int count {1};

    while (!s.empty())
    {
        std::string currentCow = s.top();
        s.pop();

        for (std::string cow : cows[currentCow])
        {
            if (cow == secondGapCow)
                return count;

            if (!visited.count(cow))
            {
                visited.insert(cow);
                s.push(cow);
            }
        }

        ++count;
    }

    return -1;
}

/* On 17 July 2023, Initially, I assume that if both of the cows we are finding getRelationships for have some relationship with other cows in the dataset,
then they must have a getRelationship with each other as well. I reason that if they are not sisters, aunts, or mothers of each other,
they must be cousins. However, this assumption is incorrect because it is possible for two cows to have no common ancestor or getRelationship at all.
In such cases, they would be considered "NOT RELATED." For example, consider a test case: 
2 AA BB
MOTHER AA
GMOTHER BB 
Here, AA and BB have no common ancestor and are not directly related, so they would be classified as "NOT RELATED" instead of "COUSINS." */
bool areCousins(const std::string& firstGapCow, const std::string& secondGapCow)
{
    std::stack<std::string> s;
    std::unordered_set<std::string> visited; 
    visited.insert(firstGapCow);
    s.push(firstGapCow);

    while (!s.empty())
    {
        std::string currentCow = s.top();
        s.pop();

        for (std::string cow : cows[currentCow])
        {
            if (!visited.count(cow))
            {
                visited.insert(cow);
                s.push(cow);
            }
        }
    }

    if (visited.count(cow1) == 1 && visited.count(cow2) == 1)
        return true;
    return false;
}

std::string getRelationship(const std::string& firstGapCow, const std::string& secondGapCow, int generationGap, bool direct_relationship)
{
    std::string relationship; 

    if (direct_relationship)
    {
        if (generationGap == 1)
            relationship = "mother";
        else if (generationGap == 2)
            relationship = "grand-mother";
        else 
        {
            for (int i {}; i < generationGap - 2; ++i)
            {
                relationship += "great-";
            }
            relationship += "grand-mother";
        }
    }
    else 
    {
        for (int i {}; i < generationGap - 1; ++i)
        {
            relationship += "great-";
        }
        relationship += "aunt";
    }

    return firstGapCow + " is the " + relationship + " of " + secondGapCow;
}

void solve()
{
    int N; 
    std::string X, Y; 
    std::cin >> N >> cow1 >> cow2;
    while (N--)
    {
        std::cin >> X >> Y;
        cows[X].insert(Y);

        if (X != cow1 && X != cow2 && std::find(all(relatedCows), X) == relatedCows.end())
            relatedCows.push_back(X);
        if (Y != cow1 && Y != cow2 && std::find(all(relatedCows), Y) == relatedCows.end())
            relatedCows.push_back(Y);
    }

    for (const auto& [cow, related_cows] : cows)
    {
        if (related_cows.count(cow1) == 1 && related_cows.count(cow2) == 1)
        {
            std::cout << "SIBLINGS";
            return;
        }

        if (related_cows.count(cow1) == 1 && sz(related_cows) == 2)
        {
            for (const auto& peer : related_cows)
            {
                if (peer != cow1)
                    cow1Peer = peer;
            }
        }

        if (related_cows.count(cow2) == 1 && sz(related_cows) == 2)
        {
            for (const auto& peer : related_cows)
            {
                if (peer != cow2)
                    cow2Peer = peer;
            }
        }
    }

    int firstGap {dfs(cow1, cow2)}, secondGap {dfs(cow2, cow1)}, thirdGap {dfs(cow1Peer, cow2)}, fourthGap {dfs(cow2Peer, cow1)};
    
    if (std::max({firstGap, secondGap, thirdGap, fourthGap}) >= 1)
    {
        if (firstGap >= 1)
        {
            std::cout << getRelationship(cow1, cow2, firstGap, true);
            return;
        }

        if (secondGap >= 1)
        {
            std::cout << getRelationship(cow2, cow1, secondGap, true);
            return;
        }

        if (thirdGap >= 1)
        {
            std::cout << getRelationship(cow1, cow2, thirdGap, false);
            return;
        }

        if (fourthGap >= 1)
        {
            std::cout << getRelationship(cow2, cow1, fourthGap, false);
            return;
        }
    }
    else 
    {
        for (int i {}; i < sz(relatedCows); ++i)
        {
            for (int j {i + 1}; j < sz(relatedCows); ++j)
            {
                if (areCousins(relatedCows[i], relatedCows[j]))
                {
                    std::cout << "COUSINS";
                    return;
                }
            }
        }
        std::cout << "NOT RELATED";
    }
}

int main()
{
    setIO("family"); 
    solve();
}