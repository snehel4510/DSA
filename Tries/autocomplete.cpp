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

bool isWord(Trie *root, string word)
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

void autocomplete(Trie *root, string str, vector<string> &ans)
{
    if (isWord(root, str))
    {
        ans.push_back(str);
        return;
    }
    Trie *curr = root;
    for (char c : str)
        curr = curr->next[c];
    for (auto &p : curr->next)
        autocomplete(root, str + p.first, ans);
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
    string prefix;
    cin >> prefix;
    if (!isPrefix(root, prefix))
        cout << "No suggestions" << endl;
    else
    {
        vector<string> ans;
        autocomplete(root, prefix, ans);
        cout << "autocomplete suggestions: " << endl;
        for (auto &s : ans)
            cout << s << endl;
    }
    return 0;
}
