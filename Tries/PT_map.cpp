// prefix tree or Trie representation using hashmaps

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char, Trie *> next;
    // ends with
    int ew = 0;
    // count prefix
    int cp = 0;
};

void insert(Trie *root, string word)
{
    Trie *t = root;
    for (auto c : word)
    {
        if (!t->next[c])
            t->next[c] = new Trie();
        t = t->next[c];
        t->cp++;
    }
    t->ew++;
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
    return t->ew;
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

int countWords(Trie *root, string str)
{
    if (!search(root, str))
        return 0;
    Trie *curr = root;
    for (char c : str)
        curr = curr->next[c];
    return curr->ew;
}

int countPrefix(Trie *root, string str)
{
    if (!isPrefix(root, str))
        return 0;
    Trie *curr = root;
    for (char c : str)
        curr = curr->next[c];
    return curr->cp;
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
    cout << countWords(root, str) << endl;
    cout << countPrefix(root, str) << endl;
    return 0;
}
