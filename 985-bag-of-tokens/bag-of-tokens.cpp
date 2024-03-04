class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int start = 0, end = n-1;
        int score = 0;
        while(start <= end)
        {
            if(power >= tokens[start])
            {
                power -= tokens[start];
                score++;
                start++;
            }
            else if(tokens[start] > power && score >= 1)
            {
                if(start == end)
                {
                    return score;
                }
                power += tokens[end];
                score--;
                end--;
            }
            else
            {
                break;
            }
        }
        return score;
    }
};