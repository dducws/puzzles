// Problem: https://codeforces.com/problemset/problem/616/A


#include <iostream> 
#include <string> 

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void solve()
{
    std::string a, b;
    std::cin >> a >> b;

    /* 'find_first_not_of' is a member function of the std::string class in C++. 
    It is used to find the position of the first character in the string that is
    not equal to any of the characters specified in the argument.
    Here's the syntax of the find_first_not_of function:
    
    size_t find_first_not_of(const char* chars, size_t pos = 0) const;
    
    chars: A C-style string or a character array containing the characters to search for in the string.
    pos: An optional parameter that specifies the starting position for the search. If not provided, 
    the search starts from the beginning of the string. 
    The function returns the index of the first character that does not match any of the characters
    in the chars argument, or std::string::npos if no such character is found. */
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));

    if (a.length() < b.length())
        std::cout << "<\n";
    else if (a.length() > b.length())
        std::cout << ">\n";
    else 
    {
        /* The reason why using a bool type for the comparison might lead to 
        incorrect results is due to the way the std::string::compare() function works.
        The std::string::compare() function returns an integer value that represents the
        result of the comparison. The possible return values are:
        1.) Negative value (< 0): The calling string is lexicographically less than the argument string.
        2.) Zero (0): Both strings are equal.
        3.) Positive value (> 0): The calling string is lexicographically greater than the argument string. */
        int comparison = a.compare(b);
        if (comparison > 0)
            std::cout << ">\n";
        else if (comparison < 0)
            std::cout << "<\n";
        else 
            std::cout << "=\n";
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}
