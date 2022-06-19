#include <bits/stdc++.h>
using namespace std;
bool safe(int col, int row, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;
    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (row < n and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &result, int n)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    for (int row = 0; row < n; row++)
    {
        if (safe(col, row, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, result, n);
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    string s(n, '.');
    vector<string> board(n);
    vector<vector<string>> result;
    for (int i = 0; i < n; i++)
        board[i] = s;
    solve(0, board, result, n);
    return 0;
}