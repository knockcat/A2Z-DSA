#include <bits/stdc++.h> 

class Node
{

public:
    Node *child[26] = {nullptr};
    bool isWord = false;

    bool containsKey(char ch)
    {
        return (child[ch - 'a'] != nullptr);
    }

    void put(char ch, Node *node)
    {
        child[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return child[ch - 'a'];
    }

    bool setEnd()
    {
        isWord = true;
    }

    bool isEnd()
    {
        return isWord;
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // insert string into trie data structure
    void insert(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!temp->containsKey(word[i]))
                temp->put(word[i], new Node());
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }


    // check if all prefixes exist
    bool checkIfAllPrefixesExists(string& word)
    {
       Node *temp = root;
       bool ok = true;
        for (int i = 0; i < word.size(); ++i)
        {
            if(temp->containsKey(word[i]))
            {
                temp = temp->get(word[i]);
                ok = ok & temp->isEnd();
            }
            else
                return false;
        }
        return ok;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.

   Trie *obj = new Trie();
   
   for(auto word : a)
        obj->insert(word);
    
    string ans;
    for(auto word : a)
    {
        if(obj->checkIfAllPrefixesExists(word))
        {
                if(ans.size() < word.size())
                    ans = word;
                else if(ans.size() == word.size() and word < ans)
                    ans = word;
        }
    } 

    if(ans.empty())
            return "None";

    return ans;

}
