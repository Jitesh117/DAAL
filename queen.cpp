#include<bits/stdc++.h>
using namespace std;
bool safe(int col,int row,vector<string>board,int n)
{
    int duprow = row;
    int dupcol = col;
    while(row>=0 and col>=0)
    {
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(col>=0)
    {
        if(board[row][col] == 'Q')
            return false;
        col--;
    }
    col = dupcol;
    while(row<n and col>=0)
    {
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void queen(int col, int n,vector<vector<string>> & result, vector<string> board)
{
    if( col == n)
    {
        result.push_back(board);
        for (int i = 0; i < n;i++)
           {
               for (int j = 0; j < n;j++)
                   cout << board[i][j];
               cout << endl;
           }
           cout << endl;
           return;
    }
    for (int row = 0; row < n;row++)
    {
        if(safe(col,row,board,n))
        {
            board[row][col] = 'Q';
            queen(col + 1, n, result, board);
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cout << "Enter value of n";
    cin >> n;
    string s(n, '.');
    vector<string> board(n);
    vector<vector<string>> result;
    for (int i = 0; i < n;i++)
        board[i] = s;
    queen(0, n, result, board);
    return 0;
}