class Solution {
public:
    int possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int numOfBouq = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                numOfBouq += cnt/k;
                cnt = 0;
            }
        }
        numOfBouq += cnt/k;
        return numOfBouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k)
            return -1;
        int n = bloomDay.size();
        vector<int>copy(n);
        copy = bloomDay;
        sort(copy.begin(), copy.end());
        
        int s = 0;
        int e = n-1;
        while(s<e){
            int mid = s+(e-s)/2;
            int numOfBouq = possible(bloomDay, copy[mid], m, k);
            if(numOfBouq < m){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return copy[s];
    }
};