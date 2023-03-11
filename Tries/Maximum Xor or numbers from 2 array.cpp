class Node{
    public:
      Node *child[2] = {nullptr};

      bool containsKey(int bit)
      {
          return (child[bit] != nullptr);
      }

      Node *get(int bit)
       {
        return child[bit];
        }

    void put(int bit , Node* node)
    {
        child[bit] = node;
    }
};

class Trie{

    private:
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    public:
    void insert(int num)
    {
        Node*temp = root;

        for(int i = 31; i>=0; --i)
        {
            int bit = (num >> i) & 1;
            if(!temp->containsKey(bit))
            {
                temp->put(bit,new Node());
            }
            temp = temp->get(bit);
        }
    }
    public:
    int getMax(int num){
        Node* temp = root;
        int maxNum = 0;
        for(int i = 31; i>=0; --i)
        {
            int bit = (num >> i) & 1;
            if(temp->containsKey(1-bit)) // opposite
            {
                maxNum = maxNum  | (1 << i);
                temp = temp->get(1-bit);
            }
            else{
                temp = temp->get(bit);
            }
        }

        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   

    Trie *obj = new Trie();

    for(auto itr : arr1)
    {
        obj->insert(itr);
    }

    int maxi = 0;
    for(auto itr : arr2)
    {
        maxi = max(maxi,obj->getMax(itr));
    }

    return maxi;

}
