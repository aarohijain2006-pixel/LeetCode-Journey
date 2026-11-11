class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums){
        int i = low;
        int j = mid+1;
        vector<int>temp;

        while(i<=mid && j<=high){
            if(nums[i] <nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low; k<=high; k++){
                nums[k] = temp[k-low];
            }
    }

    void mergeSort(int low, int high, vector<int>& nums){
        int mid = low + (high - low)/2;
        if(low == high) return;

        mergeSort(low, mid, nums);
        mergeSort(mid+1, high, nums);
        merge(low, mid, high, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return nums;
    }
};