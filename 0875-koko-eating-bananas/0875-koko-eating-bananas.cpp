class Solution {
public:
    int hourTaken(vector<int>& piles, int hours){
        int total = 0; 
        for(int i = 0; i<piles.size(); i++){
            total += ceil((double)piles[i]/(double)hours);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int s = 1;
        int e = piles[n-1];
        int totalHours = 0;

        while(s<e){
            int mid = s + (e-s)/2;
            totalHours = hourTaken(piles, mid);
            if(totalHours > h){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
};