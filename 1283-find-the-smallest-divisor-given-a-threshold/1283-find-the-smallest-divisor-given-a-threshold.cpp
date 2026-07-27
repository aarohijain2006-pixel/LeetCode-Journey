class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 1;
        int e = nums[n-1];
        while(s<e){
            int mid = s + (e - s)/2;
            int val = 0;
            for(int i = 0; i<n; i++){
                val += ceil((double)nums[i]/(double)mid);
            }
            if(val > threshold){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
};