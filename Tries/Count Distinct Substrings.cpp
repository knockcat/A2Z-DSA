class Node{
    public:
    
    Node* child[26];
   
    bool containsKey(char ch)
    {
        return child[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node)
    {
        child[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return child[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    
    int cnt = 0;

    Node* root = new Node();

    for(int i = 0; i < s.size(); ++i)
    {
        Node *temp = root;
        for(int j = i; j < s.size(); ++j)
        {
            if(!temp->containsKey(s[j]))
            {
                ++cnt;
                temp->put(s[j],new Node());
            }
            temp = temp->get(s[j]);
        }
    }

    return cnt + 1;

}
