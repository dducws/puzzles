// Codeforces Round 587 (Div. 3)
// Link problem: https://codeforces.com/contest/1216/problem/C
// Reference: https://codeforces.com/contest/1216/submission/154819087 

#include <iostream> 

bool solve()
{
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    std::cin >> x1 >> y1 >> x2 >> y2; 
    std::cin >> x3 >> y3 >> x4 >> y4;
    std::cin >> x5 >> y5 >> x6 >> y6;

    // Check if white sheet is fully covered by either black sheet
    if (x1 >= x3 && x4 >= x2 && y1 >= y3 && y4 >= y2) // The first black sheet is the only needed
        return false; 
    else if (x1 >= x5 && x6 >= x2 && y1 >= y5 && y6 >= y2) // The second black sheet is the only needed
        return false; 

    // Check if white sheet is fully covered by both black sheets horizontally 
    else if (x1 >= x5 && x6 >= x2 && x1 >= x3 && x4 >= x2 && y1 >= y3 && y6 >= y2 && y4 >= y5) // Two black sheets can be in the same position or the second black sheet will be in the above
        return false; 
    else if (x1 >= x5 && x6 >= x2 && x1 >= x3 && x4 >= x2 && y1 >= y5 && y4 >= y2 && y6 >= y3) // Two black sheets can be in the same position or the first black sheet will be in the above
        return false;

    // Check if white sheet is fully covered by both black sheets vertically 
    else if (y1 >= y5 && y6 >= y2 && y1 >= y3 && y4 >= y2 && x1 >= x3 && x6 >= x2 && x4 >= x5) // Two black sheets can be in the same position or the first black sheet will be in the left of two of them
        return false; 
    else if (y1 >= y5 && y6 >= y2 && y1 >= y3 && y4 >= y2 && x1 >= x5 && x4 >= x2 && x6 >= x3) // Two black sheets can be in the same position or the first black sheet will be in the right of two of them
        return false;    

    return true;
}

int main()
{
    bool visibility {solve()};

    if (visibility)
        std::cout << "YES\n";
    else 
        std::cout << "NO\n";
}