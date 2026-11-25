class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(int i=0; i<words.size(); i++){
            int size = words[i].size();
            int sum = 0;
            for(int j = 0; j<size; j++){
                int ch = words[i][j] - 'a';
                sum += weights[ch];
            }
            sum = sum % 26;
            char val = 'a' + 26 - sum - 1;
            ans.push_back(val);
        }
        return ans;
    }
};