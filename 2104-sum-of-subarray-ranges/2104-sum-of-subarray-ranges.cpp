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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> psee(n);
        nse = findNSE(arr);
        psee = findPSEE(arr);
        long long total = 0;

        for(int i = 0; i<n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = total + (1LL*right*left*arr[i]);
        }
        return total;
    }

    vector<int>findPLEE(vector<int>& arr){
        int n = arr.size();
        vector<int> plee(n);
        stack<int> st;
        

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                plee[i] = -1;
            }
            else{
                plee[i] = st.top();
            }
            st.push(i);
        }
        return plee;
    }

    vector<int>findNLE(vector<int>& arr){
        int n = arr.size();
        vector<int> nle(n);
        stack<int> st;
       

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nle[i] = n;
            }
            else{
                nle[i] = st.top();
            }
            st.push(i);
        }
        return nle;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> psee(n);
        nse = findNLE(arr);
        psee = findPLEE(arr);
        long long total = 0;

        for(int i = 0; i<n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = total + (1LL*right*left*arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long ans = sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        return ans;
    }
};