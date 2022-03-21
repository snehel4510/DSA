#include <bits/stdc++.h>
using namespace std;
bool safe(int row, int col, vector<string> board, int n)
{
    int r = row;
    int c = col;
    // upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = r;
    col = c;
    // lower diagonal
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    row = r;
    col = c;
    // column
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, int &ans, int n)
{
    if (col == n)
    {
        ans++;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (safe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
int NQueens(int n)
{
    int ans = 0;
    string s(n, '.');
    vector<string> board(n, s);
    solve(0, board, ans, n);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << NQueens(n);
    return 0;
}