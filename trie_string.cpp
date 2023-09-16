/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *n)
    {
        links[ch - 'a'] = n;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setend()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *n = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!n->containsKey(word[i]))
            {
                Node *temp = new Node();
                n->put(word[i], temp);
            }
            n = n->get(word[i]);
        }
        n->setend();
    }
    bool search(string word)
    {
        Node *n = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!n->containsKey(word[i]))
            {
                return false;
            }
            n = n->get(word[i]);
        }
        return n->isend();
    }
    bool startsWith(string prefix)
    {
        Node *n = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!n->containsKey(prefix[i]))
            {
                return false;
            }
            n = n->get(prefix[i]);
        }
        return true;
    }
};

signed main()
{
    Trie *t = new Trie();
    string s;
    cin >> s;
    t->insert(s);
    t->search(s);
    t->startsWith(s);
    return 0;
}