class Solution {
private:
    int solve(vector<int>& arr, int index, vector<int>& vis)
    {
        if(arr[index] == 0) return 1;
        vis[index] = 1;

        int extra = arr[index];
        if(index + extra < arr.size() && !vis[index + extra] && solve(arr, index + extra, vis))
            return 1;
        else if(index - extra >= 0 && !vis[index - extra] && solve(arr, index - extra, vis))
            return 1;
        return 0;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return solve(arr, start, vis);
    }
};