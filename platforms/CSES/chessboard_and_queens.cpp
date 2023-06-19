// Chessboard and Queens - CSES Problem Set 
// Problem: https://cses.fi/problemset/task/1624
// Edited + solution: chatGPT


#include <iostream> 
#include <array> 

const int n {8};
int count {};
std::array<std::array<char, n>, n> chessboard; 
std::array<int, 2 * n - 1> diagonal1, diagonal2;
// Reminder: Separate array to track queens in each row
std::array<int, n> rows; 

void search(int x)
{
    if (x == n)
    {
        count++;
        return;  // Base case: If all columns are filled (x == n), increment the count of valid placements and return
    }

    for (int y {}; y < n; ++y)
    {
        // Check if the current cell is reserved or conflicts with existing queens
        if (chessboard[x][y] == '*' || rows[y] || diagonal1[x + y] || diagonal2[x - y + n - 1])
            continue;  // Skip this cell and move to the next one
        
        // Place a queen in the current cell
        chessboard[x][y] = 'Q';
        rows[y] = diagonal1[x + y] = diagonal2[x - y + n - 1] = 1;  // Mark the row and diagonals as occupied
        
        // Recursive call to search for a valid placement in the next column (x + 1)
        search(x + 1);
        
        // Backtrack: Remove the queen from the current cell
        chessboard[x][y] = '.';
        rows[y] = diagonal1[x + y] = diagonal2[x - y + n - 1] = 0;  // Mark the row and diagonals as available again
    }
}

void solve()
{
    for (int i {}; i < n; ++i)
    {
        for (int j {}; j < n; ++j)
        {
            std::cin >> chessboard[i][j];  // Read the chessboard configuration
        }
    }

    search(0);  // Start the recursive search from the first column (x = 0)
    std::cout << count << '\n';  // Print the count of valid placements
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();  // Call the solve function to solve the problem
}
