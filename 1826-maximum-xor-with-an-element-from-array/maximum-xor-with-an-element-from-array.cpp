struct Node {
    Node* links[2];
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
    Trie() {
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

    int getMax(int num)
    {
        Node* node = root;
        int maxi = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(), nums.end()); //  sorting the numbers
        for(int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);    //  offline queries method
        }

        //  sorting the queries on the basis of mi
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }); 
        
        int n = queries.size();
        Trie *root = new Trie();

        vector<int> ans(n);
        int j = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            while(j < nums.size() && nums[j] <= queries[i][1])
            {
                root->insert(nums[j]);
                j++;
            }

            if(j != 0)  ans[queries[i][2]] = root->getMax(queries[i][0]);
            else    ans[queries[i][2]] = -1;
        }

        return ans;
    }
};