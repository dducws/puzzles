// Problem: https://atcoder.jp/contests/agc015/tasks/agc015_c
// Source: Finn Pomfret (https://usaco.guide/problems/ac-nuske/user-solutions)


#include <iostream> 
#include <vector>

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

/* (On 31 July 2023) Important observation: 
1) A connected component is a group of blue cells that are adjacent to each other either horizontally or vertically, but not diagonally.
2) The total number of blue cells in each submatrix tells us how many cells are part of any connected component in that submatrix.
For example, if we have a submatrix with four blue cells, then we know that there are at most four connected components in that submatrix.
3) The number of connected components in each column of each submatrix tells us how many connections between adjacent blue cells are there in that column.
For example, if we have a column with three blue cells and two connections between them, then we know that there is only one connected component in that column.
4) The number of connected components in each row of each submatrix tells us how many connections between adjacent blue cells are there in that row. 
For example, if we have a row with three blue cells and one connection between them, then we know that there are two connected components in that row.

By calculating these three kinds of prefix sums, we can use a simple formula to find the number of connected components in any submatrix:
    connectedComponents = blueCells - prefixSumsColumns - prefixSumsRows
This formula eliminates overlapping segments of the same connected component and counts only distinct ones.
If we only calculate one kind of prefix sum, such as the total number of blue cells, We would need to use a different technique,
such as depth-first search or union-find, to traverse the grid and mark the visited cells.
*/

const int MAX = 2000; 

int n, m, q;
ll X1, Y1, X2, Y2; 
char grid[MAX + 1][MAX + 1];
int totalBlue[MAX + 1][MAX + 1], connectedInColumns[MAX + 1][MAX + 1], connectedInRows[MAX + 1][MAX + 1];

/*
void printArray(int arr[MAX + 1][MAX + 1], int rows, int cols)
{
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
*/

void calculatePrefixSums()
{
    for (int i {1}; i <= n; ++i)
    {
        for (int j {1}; j <= m; ++j)
        {
            // Count the total blue cells in the (1, 1) to (i, j) rectangle
            totalBlue[i][j] = (grid[i][j] == '1') - totalBlue[i - 1][j - 1] + totalBlue[i][j - 1] + totalBlue[i - 1][j] ;
            // Count the number of connected components in the column (1, 1) to (i, j)
            connectedInColumns[i][j] = (grid[i - 1][j] == '1' && grid[i][j] == '1') - connectedInColumns[i - 1][j - 1] + connectedInColumns[i][j - 1] + connectedInColumns[i - 1][j];
            // Count the number of connected components in the row (1, 1) to (i, j)
            connectedInRows[i][j] = (grid[i][j - 1] == '1' && grid[i][j] == '1') - connectedInRows[i - 1][j - 1] + connectedInRows[i][j - 1] + connectedInRows[i - 1][j];
        }
    }
}

void solve()
{
    std::cin >> n >> m >> q; 
    for (int i {1}; i <= n; ++i)
    {
        for (int j {1}; j <= m; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    calculatePrefixSums();
    int blueCells {}, prefixSumsColumns {}, prefixSumsRows {}, connectedComponents {};

    while (q--)
    {
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        
        // Calculate the number of blue cells in the given rectangle using prefix sums
        blueCells = totalBlue[X2][Y2] - totalBlue[X1 - 1][Y2] - totalBlue[X2][Y1 - 1] + totalBlue[X1 - 1][Y1 - 1];
        // Calculate the number of connected components in the columns of the given rectangle using prefix sums
        prefixSumsColumns = connectedInColumns[X2][Y2] - connectedInColumns[X1][Y2] - connectedInColumns[X2][Y1 - 1] + connectedInColumns[X1][Y1 - 1];
        // Calculate the number of connected components in the rows of the given rectangle using prefix sums
        prefixSumsRows = connectedInRows[X2][Y2] - connectedInRows[X2][Y1] - connectedInRows[X1 - 1][Y2] + connectedInRows[X1 - 1][Y1];
        // Calculate the number of connected components in the given rectangle
        connectedComponents = blueCells - prefixSumsColumns - prefixSumsRows;

        std::cout << connectedComponents << '\n';
    }
    
    /*
    std::cout << "\nTotal Blue Cells Array:\n";
    printArray(totalBlue, n, m);

    std::cout << "\nConnected in Columns Array:\n";
    printArray(connectedInColumns, n, m);

    std::cout << "\nConnected in Rows Array:\n";
    printArray(connectedInRows, n, m);
    */
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();
}