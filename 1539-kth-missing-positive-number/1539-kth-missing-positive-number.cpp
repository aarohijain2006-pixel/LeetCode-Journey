class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>miss;
        for(int i = 1; i<=arr.size() + k; i++){
            if(!binary_search(arr.begin(), arr.end(), i)){
                miss.push_back(i);
            }
        }
        return miss[k-1];
    }
};