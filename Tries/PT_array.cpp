// prefix tree or Trie representation using array

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *next[26];
    bool isEnd = false;
};

void insert(Trie *root, string str)
{
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        if (curr->next[c] == NULL)
            curr->next[c] = new Trie();
        curr = curr->next[c];
    }
    curr->isEnd = true;
}

bool search(Trie *root, string str)
{
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        if (curr->next[c] == NULL)
            return false;
        curr = curr->next[c];
    }
    return curr->isEnd;
}

bool isPrefix(Trie *root, string str)
{
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        if (curr->next[c] == NULL)
            return false;
        curr = curr->next[c];
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    Trie *root = new Trie();
    for (int i = 0; i < n; i++)
        insert(root, words[i]);
    string str;
    cin >> str;
    isPrefix(root, str) ? cout << "YES" : cout << "NO";
    cout << endl;
    search(root, str) ? cout << "YES" : cout << "NO";
    cout << endl;
    return 0;
}