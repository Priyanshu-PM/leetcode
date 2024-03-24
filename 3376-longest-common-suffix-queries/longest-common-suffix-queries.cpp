struct Node {
public:
    Node* links[26];
    int endsWith = 0;
    int countPrefix = 0;
    int index = -1, minLen = INT_MAX;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch)
    {
        return (links[ch - 'a']);
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    // void increaseEnd()
    // {
    //     endsWith++;
    // }

    // void increasePrefix()
    // {
    //     countPrefix++;
    // }
};

class Trie{

private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string &word, int i){

        Node* node = root;
        int len = word.size();
        for(char ch: word)
        {
            if(!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            if(node->index == -1 || node->minLen > len)
            {
                node->minLen = min(node->minLen, len);
                node->index = i;
            }
            // node->increasePrefix();
        }
        if(node->index == -1 || node->minLen > len)
        {
            node->minLen = min(node->minLen, len);
            node->index = i;
        }
        // node->increaseEnd();
    }

    int countWordsStartingWith(string &word){
       
        Node* node = root;
        int currIndex = 0;
        bool found = false;
        for(char ch: word)
        {
            if(node->containsKey(ch))
            {
                found = true;
                node = node->get(ch);
                currIndex = node->index;
            }
            else
            {
                break;
            }
        }
        if(!found)  return -1;
        return node->index;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int n = wordsQuery.size();
        int minLenIndex = -1, minLen = INT_MAX;
        Trie* root = new Trie();
        for(int i = 0; i < wordsContainer.size(); i++)
        {
            if(minLen > wordsContainer[i].size())
            {
                minLen = wordsContainer[i].size();
                minLenIndex = i;
            }
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            root->insert(wordsContainer[i], i);
        }
        vector<int> ans;
        for(string word: wordsQuery)
        {
            reverse(word.begin(), word.end());
            int index = root->countWordsStartingWith(word);
            if(index == -1)   ans.push_back(minLenIndex);
            else ans.push_back(index);
        }
        return ans;
    }
};