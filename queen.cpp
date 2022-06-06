#include <bits/stdc++.h>
using namespace std;
bool safe(vector<string> &board, int row, int col, int n)
{
    int duprow = row;
    int dupcol = col;
    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--, col--;
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
        row++, col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &result, int n)
{
    if (col == n)
    {
        result.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (safe(board, row, col, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, result, n);
            board[row][col] = '.';
        }
    }
}
int main()
{
    cout << "Enter value of n:";
    int n;
    cin >> n;
    vector<vector<string>> result;
    string s(n, '.');
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        board[i] = s;
    solve(0, board, result, n);
    cout << result.size() << endl;
    for (auto it : result)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << it[i][j];
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}