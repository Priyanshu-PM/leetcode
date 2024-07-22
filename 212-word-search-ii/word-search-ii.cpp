class Node {
public:
    Node* links[26] = {NULL};
    bool isEnd;
    Node() {
        isEnd = false;
    }
};

class Solution {
    const vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int n, m;
    string path;
    Node* buildTrie(vector<string>& words)
    {
        Node* root = new Node();
        Node* node = root;
        for(string word: words) {
            for(char c: word)
            {
                if(node->links[c - 'a'] == NULL)
                    node->links[c - 'a'] = new Node();
                node = node->links[c - 'a'];
            }
            node->isEnd = true;
            node = root;
        }

        return root;
    }

    void dfs(vector<string>& ans, vector<vector<char>>& board, int i, int j, Node* trie)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$' || trie->links[board[i][j] - 'a'] == NULL) return;
        

        char c = board[i][j];
        path.push_back(c);

        if(trie->links[c - 'a']->isEnd) {
            ans.push_back(path);
            trie->links[c - 'a']->isEnd = false;
        }

        board[i][j] = '$';

        for(auto offset: offsets) {
            dfs(ans, board, i + offset.first, j + offset.second, trie->links[c - 'a']);
        }
        board[i][j] = c;
        path.pop_back();
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        n = board.size();
        m = board[0].size();

        Node *trie = buildTrie(words);

        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dfs(ans, board, i, j, trie);
            }
        }

        return ans;
    }
};