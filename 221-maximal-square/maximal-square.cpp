class Solution {
private:
    int solve(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())  width = i;
                else    width = i - st.top() - 1;

                area = max(area, min(height, width) * min(height, width));
            }
            st.push(i);
        }
        return area;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix[0].size();
        vector<int> heights(n, 0);

        int maxSquare = 0;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')    heights[j] += 1;
                else    heights[j] = 0;
                cout << heights[j] << " ";
            }
            cout << "\n";

            int temp = solve(heights);
            maxSquare = max(maxSquare, temp);
            cout << "max area = " << maxSquare << " at row - " << i << "\n";
        }
        return maxSquare;
    }
};