// prefix tree or Trie representation using array

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *next[26];
    // ends with
    int ew = 0;
    // count prefix
    int cp = 0;
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
        curr->cp++;
    }
    curr->ew++;
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
    return curr->ew;
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

int countWords(Trie *root, string str)
{
    if (!search(root, str))
        return 0;
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        curr = curr->next[c];
    }
    return curr->ew;
}

int countPrefix(Trie *root, string str)
{
    if (!isPrefix(root, str))
        return 0;
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        curr = curr->next[c];
    }
    return curr->cp;
}

void deleteWord(Trie *root, string str)
{
    if (!search(root, str))
        return;
    Trie *curr = root;
    for (char c : str)
    {
        c -= 'a';
        curr = curr->next[c];
        curr->cp--;
    }
    curr->ew--;
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