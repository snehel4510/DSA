// 1&2) infix to postfix/prefix

// #include <bits/stdc++.h>
// using namespace std;
// int prec(char c)
// {
//     if (c == '^')
//         return 3;
//     else if (c == '/' || c == '*' || c == '%')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     else
//         return -1;
// }
// string infixToPostfix(string s)
// {
//     stack<char> st;
//     string result;
//     for (int i = 0; i < s.length(); i++)
//     {
//         char c = s[i];
//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//             result += c;
//         else if (c == '(')
//             st.push('(');
//         else if (c == ')')
//         {
//             while (st.top() != '(')
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             if (s[i] == '^')
//             {
//                 while (prec(s[i]) <= prec(st.top()))
//                 {
//                     result += st.top();
//                     st.pop();
//                 }
//             }
//             else
//             {
//                 while (!st.empty() && prec(s[i]) < prec(st.top()))
//                 {
//                     result += st.top();
//                     st.pop();
//                 }
//             }
//             st.push(c);
//         }
//     }
//     while (!st.empty())
//     {
//         result += st.top();
//         st.pop();
//     }
//     return result;
// }
// string infixToPrefix(string infix)
// {
//     int l = infix.size();
//     reverse(infix.begin(), infix.end());
//     for (int i = 0; i < l; i++)
//     {
//         if (infix[i] == '(')
//         {
//             infix[i] = ')';
//             i++;
//         }
//         else if (infix[i] == ')')
//         {
//             infix[i] = '(';
//             i++;
//         }
//     }
//     string prefix = infixToPostfix(infix);
//     reverse(prefix.begin(), prefix.end());
//     return prefix;
// }
// int main()
// {
//     string s;
//     cin >> s;
//     cout << infixToPrefix(s);
//     cout << infixToPostfix(s);
//     return 0;
// }

// 3) prefix to infix

#include <bits/stdc++.h>
using namespace std;
string preToInfix(string pre)
{
    stack<string> s;
    int l = pre.size();
    for (int i = l - 1; i >= 0; i--)
    {
        char p = pre[i];
        if (p == '+' || p == '-' || p == '/' || p == '*' || p == '^' || p == '%')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + p + op2;
            s.push(temp);
        }
        else
        {
            s.push(string(1, p));
        }
    }
    return s.top();
}
int main()
{
    string pre;
    cin >> pre;
    cout << preToInfix(pre) << endl;
    return 0;
}

// 4) postfix to infix

// #include <bits/stdc++.h>
// using namespace std;
// string postToInfix(string post)
// {
//     stack<string> s;
//     int l = post.size();
//     for (int i = 0; i < l; i++)
//     {
//         char p = post[i];
//         if (p == '+' || p == '-' || p == '/' || p == '*' || p == '^' || p == '%')
//         {
//             string op1 = s.top();
//             s.pop();
//             string op2 = s.top();
//             s.pop();
//             string temp = "(" + op2 + p + op1 + ")";
//             s.push(temp);
//         }
//         else
//         {
//             s.push(string(1, p));
//         }
//     }
//     return s.top();
// }
// int main()
// {
//     string post;
//     cin >> post;
//     cout << postToInfix(post);
//     return 0;
// }