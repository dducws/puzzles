// Chessboard and Queens - CSES Problem Set 
// Problem: https://cses.fi/problemset/task/1624
// Edited + solution: chatGPT


#include <iostream> 
#include <array> 

const int n {8};
int count {};
std::array<std::array<char, n>, n> chessboard; 
std::array<bool, 2 * n - 1> diagonal1, diagonal2;
/* Reminder: Don't initialize a separate array to keep track the number of queens in each row.
Made this mistake for the first time at 22:15 on Jun 19, 23 */
std::array<bool, n> rows; 

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
        // Mark the row and diagonals as occupied
        rows[y] = diagonal1[x + y] = diagonal2[x - y + n - 1] = true; 
        
        // Recursive call to search for a valid placement in the next column (x + 1)
        search(x + 1);
        
        // Backtrack: Remove the queen from the current cell
        chessboard[x][y] = '.';
        // Mark the row and diagonals as available again
        rows[y] = diagonal1[x + y] = diagonal2[x - y + n - 1] = false; 
    }
}

void solve()
{
    for (int i {}; i < n; ++i)
    {
        for (int j {}; j < n; ++j)
        {
            std::cin >> chessboard[i][j];  
        }
    }

    search(0);  // Start the recursive search from the first column (x = 0)
    std::cout << count << '\n';
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    solve();  
}
