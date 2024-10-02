class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        unordered_map<int, int> valueToRank;  // Map to store value-to-rank mapping
        vector<int> sortedUniqueNumbers = arr; 
        
        // Remove duplicates and sort
        std::sort(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end());
        sortedUniqueNumbers.erase(unique(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end()), sortedUniqueNumbers.end());
        
        // Assign ranks to sorted unique elements
        for (int i = 0; i < sortedUniqueNumbers.size(); i++) {
            valueToRank[sortedUniqueNumbers[i]] = i + 1;
        }

        // Replace each element in the original array with its rank
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = valueToRank[arr[i]];
        }

        return arr;  // Return the updated array
    }
};