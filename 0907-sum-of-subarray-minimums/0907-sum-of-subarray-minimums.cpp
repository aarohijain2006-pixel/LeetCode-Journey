class Solution {
public:
    vector<int>findPSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }

    vector<int>findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
       

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> psee(n);
        nse = findNSE(arr);
        psee = findPSEE(arr);
        long long total = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i<n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (1LL*right*left*arr[i]) % mod) % mod;
        }
        return total;
    }
};