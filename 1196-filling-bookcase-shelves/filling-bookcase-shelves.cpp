class Solution {
public:
    int n;
    int WIDTH;
    int solve(int index, vector<vector<int>>& books, int remainW, int maxHeight, vector<vector<int>>& dp)
    {
        if(index >= n)  return maxHeight;

        if(dp[index][remainW] != -1)    return dp[index][remainW];

        int bookW = books[index][0];
        int bookH = books[index][1];

        int keep = INT_MAX, notKeep = INT_MAX;

        //  keep the book in current shelf
        if(bookW <= remainW) {
            keep = solve(index+1, books, remainW - bookW, max(maxHeight, bookH), dp);
        }
        //  put in next shelf
        notKeep = maxHeight + solve(index+1, books, WIDTH - bookW, bookH, dp);

        return dp[index][remainW] = min(keep, notKeep);
        
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        // [[1, 1], [2, 3], [2, 3], [1, 1], [1, 1], [1, 1], [1, 2]] //greedy fails here

        n = books.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        WIDTH = shelfWidth;
        return solve(0, books, WIDTH, 0, dp);
    }
};