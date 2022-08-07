// a user searches for a word, find all words present in the trie whose prefix is that serach word

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char, Trie *> next;
    int ew = 0;
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

void autocomplete(Trie *curr, string str, vector<string> &ans)
{
    if (curr->ew)
        ans.push_back(str);
    for (auto &p : curr->next)
        if (p.second)
            autocomplete(curr->next[p.first], str + p.first, ans);
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
    // search word
    string sw;
    cin >> sw;
    Trie *curr = root;
    for (char c : sw)
        curr = curr->next[c];
    // suggestions
    vector<string> sug;
    autocomplete(curr, sw, sug);
    for (auto i : sug)
        cout << i << " ";
    return 0;
}
