// prefix tree or Trie representation using hashmaps

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char, Trie *> next;
    bool isEnd = false;
};

void insert(Trie *root, string word)
{
    Trie *t = root;
    for (auto c : word)
    {
        if (!t->next[c])
            t->next[c] = new Trie();
        t = t->next[c];
    }
    t->isEnd = true;
}

bool search(Trie *root, string word)
{
    Trie *t = root;
    for (auto c : word)
    {
        if (!t->next[c])
            return false;
        t = t->next[c];
    }
    return t->isEnd;
}

bool isPrefix(Trie *root, string word)
{
    Trie *t = root;
    for (auto c : word)
    {
        if (!t->next[c])
            return false;
        t = t->next[c];
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
