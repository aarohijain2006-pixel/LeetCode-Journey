class Solution {
public:
    int possible(vector<int>& weights, int days, int capacity){
        int daynum = 0;
        int cnt = 0;
        for(int i = 0; i<weights.size(); i++){
            cnt += weights[i];
            if(cnt>capacity){
                cnt = weights[i];
                daynum++;
            }
        }
        daynum++;
        return daynum;
    }
    int maximum(vector<int>& weights){
        int maxi = INT_MIN;
        for(int i = 0; i<weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int sum(vector<int>& weights){
        int total = 0;
        for(int i = 0; i<weights.size(); i++){
            total += weights[i];
        }
        return total;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = maximum(weights);
        int e = sum(weights);
        while(s<e){
            int mid = s + (e-s)/2;
            int daynum = possible(weights, days, mid);

            if(daynum > days){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
};