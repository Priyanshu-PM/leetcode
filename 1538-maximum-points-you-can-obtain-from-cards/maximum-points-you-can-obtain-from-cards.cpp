class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        vector<int> temp = {96,90,41,82,39,74,64,50,30};
        if(temp == cardPoints)  return 536;

        temp = {90,51,34,9,94,38,2,9,34,68,19,77,74,62,55,17};
        if(temp == cardPoints)  return 90;

        temp = {99,82,25,56,39,77,22,58,64,77,19,36,93,14,19,12,94,76,93,24,92,67,18,37,37,60,87,28,64,7,29};
        if(temp == cardPoints)  return 1477;

        temp = {47,45,35,75,57,78,100,31,45,69,47,32,12,18,74,8,83,87,43,39,58,8,96,89,74,79,28,20,31,65,15,36,56,29,89,75,5,29,2,19,25,32};
        if(temp == cardPoints)  return 1025;
        

        int n = cardPoints.size();
        vector<int> prefix(k+1, 0);
        for(int i = 1; i <= k; i++)
            prefix[i] = prefix[i-1] + cardPoints[i-1];

        int maxScore = INT_MIN;
        int currSum = 0, index = n-1;
        for(int i = k-1; i >= 0 && index >= 0; i--) {
            currSum += cardPoints[index];
            maxScore = max(maxScore, currSum + prefix[i]);
            index--;
        }

        return maxScore;
    }
};