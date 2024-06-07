class Node {
public:
    bool isEnd = false;
    Node* links[26] = {NULL};

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
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string &s)
    {
        Node* temp = root;
        for(int i = 0; i < s.size(); i++)
        {
            if(!temp->containsKey(s[i])) {
                temp->put(s[i], new Node());
            }
            temp = temp->get(s[i]);
        }
        temp->isEnd = true;
        cout << s <<  " - inserted in trie\n";
    }

    string containsRoot(string s) {
        Node* temp = root;
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(temp->links[c - 'a'] == NULL)    return "";
            temp = temp->links[c - 'a'];
            ans += c;
            if(temp->isEnd) return ans;
        }
        return "";
    }
};

class Solution {
private:

public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        //  trie implementation
        Trie *obj = new Trie();
        for(string &s: dictionary) obj->insert(s);

        stringstream ss(sentence);
        string temp;
        string ans = "";
        while(getline(ss, temp, ' '))
        {
            string rootword = obj->containsRoot(temp);
            cout << "temp - " << temp << " || rootword - " << rootword << "\n";
            if(rootword != "") {
                ans += rootword + " ";
            }
            else {
                ans += temp + " ";
            }
        }
        return ans.substr(0, ans.size()-1);
    }
};