class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size();
       int low = 0;
       int high = n-1;
       while(low<=high){
          int mid = low + (high - low)/2;
          int missing = arr[mid] - (mid + 1);
          if(missing < k){
             low = mid + 1;
          }
          else{
            high = mid - 1;
          }
       }
       return low + k;
    }
};
// At the end ans = arr[high] + more, where more is k - missing(at the end). So missing = arr[high] - (high + 1). so, after putting values ans = high + 1+ k. And heigh = low -1. finally ans = low + k. 