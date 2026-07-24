class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        int pse = 0;
        int nse = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                nse = i;
                if(st.empty())
                   pse = -1;
                else
                   pse = st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse -1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            int element = st.top();
            st.pop();
            if(st.empty())
               pse = -1;
            else
               pse = st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }
};