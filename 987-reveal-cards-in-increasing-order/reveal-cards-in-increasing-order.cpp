class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end()); //  sorting in increasing order
        int n = deck.size();
        vector<int> ans(n);
        deque<int> indices;

        for(int i = 0; i < n; i++)
            indices.push_back(i);

        for(int card: deck)
        {
            int index = indices.front();
            indices.pop_front();
            ans[index] = card;

            if(!indices.empty())
            {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        
        return ans;
    }
};