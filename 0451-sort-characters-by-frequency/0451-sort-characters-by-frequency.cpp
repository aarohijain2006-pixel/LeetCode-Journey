class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> freq;

        // Count frequency
        for(char ch : s)
            freq[ch]++;

        string ans = "";

        while(!freq.empty()) {

            char maxChar;
            int maxFreq = 0;

            // Find character with maximum frequency
            for(auto it : freq) {
                if(it.second > maxFreq) {
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }

            // Add it maxFreq times
            while(maxFreq--) {
                ans.push_back(maxChar);
            }

            // Remove it from map
            freq.erase(maxChar);
        }

        return ans;
    }
};