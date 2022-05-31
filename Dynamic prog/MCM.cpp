// MATRIX CHAIN MULTIPLICATION
// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

// background -> mulitply 2 matrices together
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     // 2 matrices of size a*b and b*c
//     // a*b*c -> total cost of multiplication resulting in a matrix of size a*c
//     int m1[a][b], m2[b][c];
//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < b; j++)
//             cin >> m1[i][j];
//     }
//     for (int i = 0; i < b; i++)
//     {
//         for (int j = 0; j < c; j++)
//             cin >> m2[i][j];
//     }
//     int m3[a][c];
//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             m3[i][j] = 0;
//             for (int k = 0; k < b; k++)
//             {
//                 m3[i][j] += m1[i][k] * m2[k][j];
//             }
//         }
//     }
//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < c; j++)
//             cout << m3[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int m[N][N];
int s[N][N];
int main()
{
    // for n matrices -> total no of ways we can multiply them = (2nCn)/n+1
    int n;
    cin >> n;
    int d[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (j <= i)
            {
                m[i][j] = 0;
                s[i][j] = 0;
            }
        }
    }
    int i = 1, x = 2, j = x;
    while (i <= n && j <= n)
    {
        m[i][j] = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int z = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
            m[i][j] = min(m[i][j], z);
            if (m[i][j] == z)
                s[i][j] = k;
        }
        i++;
        j++;
        if (j > n)
            i = 1, j = ++x;
    }
    cout << "Our " << n << " matrices are : -\n";
    for (int i = 0; i < n; i++)
        cout << "A" << i + 1 << " : " << d[i] << "x" << d[i + 1] << endl;
    cout << "Matrix table is :- \n";
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << "S table is :- \n";
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    cout << "Minimum cost of multiplication is : " << m[1][n];
    return 0;
}