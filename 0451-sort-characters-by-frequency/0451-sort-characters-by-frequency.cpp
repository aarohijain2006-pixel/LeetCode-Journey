class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> freq;

        for(char ch : s)
            freq[ch]++;

        string ans = "";

        while(!freq.empty()) {

            char maxChar;
            int maxFreq = 0;

            for(auto it : freq) {
                if(it.second > maxFreq) {
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }

            while(maxFreq--) {
                ans.push_back(maxChar);
            }

            freq.erase(maxChar);
        }

        return ans;
    }
};