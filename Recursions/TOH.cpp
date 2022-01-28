#include <bits/stdc++.h>
using namespace std;
void toh(int n, char s, char d, char h, int &c)
{
    if (n == 1)
    {
        c++;
        cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
        return;
    }
    toh(n - 1, s, h, d, c);
    c++;
    cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
    toh(n - 1, h, d, s, c);
    //c++;
    return;
}
int main()
{
    int n, c = 0;
    cin >> n;
    toh(n, 's', 'd', 'h', c);
    cout << c;
    return 0;
}