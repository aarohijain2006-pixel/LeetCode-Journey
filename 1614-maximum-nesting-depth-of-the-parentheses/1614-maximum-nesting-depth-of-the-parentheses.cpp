class Solution {
public:
    int maxDepth(string s) {
        int count = 0; 
        int depth = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                count++;
                depth = max(depth, count);
            }
            if(s[i] == ')'){
                count--;
            }
        }
        return depth;
    }
};