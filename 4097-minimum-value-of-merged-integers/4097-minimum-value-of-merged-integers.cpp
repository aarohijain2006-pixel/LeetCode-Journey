class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
       int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i += 2) {
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i + 1]);

            string merged = s1 + s2;

            int number = stoi(merged);

            mini = min(mini, number);
        }

        return mini;
    }
};