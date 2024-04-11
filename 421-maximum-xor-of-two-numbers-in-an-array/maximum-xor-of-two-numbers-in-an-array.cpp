struct Node {
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num)
    {
        int maxNum = 0;
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie *root = new Trie();
        for(int num: nums)  root->insert(num);

        int maxi = 0;
        for(int num: nums)
        {
            maxi = max(maxi, root->findMax(num));
        }
        return maxi;
    }
};