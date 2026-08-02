class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int cnt = 0;
        while(start!=0 || goal!=0){
            int bit1 = start & 1;
            int bit2 = goal & 1;
            if(bit1 == bit2){
               start = start>>1;
               goal = goal>>1;
               continue;
            }
            else{
               cnt++;
               start = start>>1;
               goal = goal>>1;
            }
        }
        return cnt;
    }
};