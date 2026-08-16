class Solution {
public:
   int totalHours(vector<int>& piles, int mid){
    int total = 0;
      for(int i=0; i<piles.size(); i++){
         total += ceil((double)piles[i]/(double)mid);
      }
      return total;
   }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int i = 1;
        int j = piles[n-1];
        int hoursTaken = 0;
        while(i<j){
            int mid = (i + j)/2;
            hoursTaken = totalHours(piles, mid);
        
            if(hoursTaken > h){
                i = mid + 1;
            }
            else{
                j = mid;
            }
        }
        return i;
    }
};