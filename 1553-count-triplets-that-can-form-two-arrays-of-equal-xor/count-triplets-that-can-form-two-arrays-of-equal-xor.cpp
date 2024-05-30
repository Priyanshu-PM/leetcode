class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        //  brute force
        int count = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {

            for(int j = i+1; j < n; j++) {

                int part1 = 0;
                for(int k = i; k < j; k++) {
                    part1 = part1 ^ arr[k];
                }

                int part2 = 0;
                for(int k = j; k < n; k++) {
                    part2 = part2 ^ arr[k];
                    if(part1 == part2)  count++;
                }
            }
        }

        return count;
    }
};