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
    col = dupcol;
    row = duprow;
    while (col >= 0 and row < n)
    {
        if (board[row][col] == 'Q')
            return false;
        row++, col--;
    }
    return true;
}
void queen(int col, vector<string> &board, vector<vector<string>> &result, int n)
{
    if (col == n)
    {
        result.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
        if (safe(board, row, col, n))
        {
            board[row][col] = 'Q';
            queen(col + 1, board, result, n);
            board[row][col] = '.';
        }
}
int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    vector<string> board(n);
    vector<vector<string>> result;
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    queen(0, board, result, n);
    int k = 1;
    for (auto it : result)
    {
        cout << "solution :" << k << endl;
        k++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << it[i][j];

            cout << endl;
        }
        cout << endl
             << endl;
    }
}