// #include <iostream>
// #include <vector>
// using namespace std;

// bool isSafe(vector<string> &board, int row, int col, int n)
// {
//     // Check column
//     for (int i = 0; i < row; i++)
//         if (board[i][col] == 'Q')
//            return false;

//     // Check upper-left diagonal
//     int r = row - 1, c = col - 1;
//     while (r >= 0 && c >= 0)
//     {
//         if (board[r][c] == 'Q')
//             return false;
//         r--;
//         c--;
//     }

//     // Check upper-right diagonal
//     r = row - 1;
//     c = col + 1;
//     while (r >= 0 && c < n)
//     {
//         if (board[r][c] == 'Q')
//             return false;
//         r--;
//         c++;
//     }

//     return true;
// }

// void solve(vector<string> &board, vector<vector<string>> &result, int row, int n, int fixedRow)
// {
//     if (row == n)
//     {
//         result.push_back(board);
//         return;
//     }

//     // Skip the fixed row (where the first queen is placed)
//     if (row == fixedRow)
//     {
//         solve(board, result, row + 1, n, fixedRow);
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (isSafe(board, row, col, n))
//         {
//             board[row][col] = 'Q';
//             solve(board, result, row + 1, n, fixedRow);
//             board[row][col] = '.';
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter N: ";
//     cin >> n;

//     int fixedRow, fixedCol;
//     cout << "Enter row and column (0-indexed) where first Queen is already placed: ";
//     cin >> fixedRow >> fixedCol;

//     vector<string> board(n, string(n, '.'));
//     vector<vector<string>> result;

//     if (fixedRow >= 0 && fixedRow < n && fixedCol >= 0 && fixedCol < n)
//     {
//         board[fixedRow][fixedCol] = 'Q';
//         solve(board, result, 0, n, fixedRow);
//     }
//     else
//     {
//         cout << "Invalid position!" << endl;
//         return 0;
//     }

//     if (result.empty())
//         cout << "No solution possible with the given first Queen position." << endl;
//     else
//     {
//         for (auto &sol : result)
//         {
//             for (auto &r : sol)
//                 cout << r << endl;
//             cout << endl;
//         }
//     }

//     return 0;
// }

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n)
{
    // Check column above
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    int r=row-1;
    int c=col-1;
    while(r>=0 && c>=0)
    {
        if(board[r][c]=='Q') return false;
        r--;
        c--;
    }


    // Check upper-right diagonal
    r=row-1;
    c=col+1;
    while(r>=0 && c<n)
    {
        if(board[r][c]=='Q') return false;
        r--;
        c++;
    }

    return true;
}

bool solve(vector<string>& board, int row, int n, int fixedRow)
{
    if (row == n)
    {
        return true;
    }

    // Skip the row where queen is already fixed
    if (row == fixedRow)
    {
        return solve(board, row + 1, n, fixedRow); 
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            if(solve(board, row + 1, n, fixedRow))
            {
                return true;
            }
            board[row][i] = '.';
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int fr, fc;
    fr=0;
    cout << "Enter col: ";
    cin >> fc;

    vector<string> board(n, string(n, '.'));

    if (fr >= 0 && fc >= 0 && fr < n && fc < n)
    {
        board[fr][fc] = 'Q';
        if (solve(board, 0, n, fr))
        {
            for (string res : board)
                cout << res << endl;
        }
        else
        {
            cout << "No solution exists for " << n << " queens" << endl;
        }
    }
    else
    {
        cout << "Invalid" << endl;
    }
}
//col input lena hai sirf













// #include <iostream>
// #include<vector>

// using namespace std;

// bool isSafe(vector<string>&board, int col, int row, int n)
// {
//     // Check same column
//     for (int i = 0; i < row; i++)
//         if (board[i][col] == 'Q')
//             return false;

//     // Check upper-left diagonal
//     for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
//         if (board[r][c] == 'Q')
//             return false;

//     // Check upper-right diagonal
//     for (int r = row, c = col; r >= 0 && c < n; r--, c++)
//         if (board[r][c] == 'Q')
//             return false;

//     return true;
// }

// void solve(vector<string> &board, vector<vector<string>> &result, int row, int n)
// {
//     if (row == n)
//     {
//         result.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (isSafe(board, col, row, n))
//         {
//             board[row][col] = 'Q';
//             solve(board, result, row + 1, n);
//             board[row][col] = '.';
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter N: ";
//     cin >> n;

//     int fixedCol;
//     cout << "Enter column (0-indexed) where first Queen is already placed: ";
//     cin >> fixedCol;

//     // Initialize board
//     vector<string> board(n, string(n, '.'));
//     vector<vector<string>> result;

//     // Place first Queen
//     if (fixedCol >= 0 && fixedCol < n)
//     {
//         board[0][fixedCol] = 'Q';
//         // Start solving from second row since first is fixed
//         solve(board, result, 1, n);
//     }
//     else
//     {
//         cout << "Invalid column index!" << endl;
//         return 0;
//     }

//     // Print all possible solutions
//     if (result.empty())
//     {
//         cout << "No solution possible with the given first Queen position." << endl;
//     }
//     else
//     {
//         for (auto const &sol : result)
//         {
//             for (auto const &row : sol)
//                 cout << row << endl;
//             cout << endl;
//         }
//     }

//     return 0;
// }