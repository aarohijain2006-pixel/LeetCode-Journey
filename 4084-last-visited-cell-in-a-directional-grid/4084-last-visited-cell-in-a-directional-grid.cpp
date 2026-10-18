class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        int row = i;
        int col = j;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(i<m && j<n && i>=0 && j>=0){

            if(visited[i][j] == true) break;
            visited[i][j] = true;
            row = i;
            col = j;
            char c = grid[i][j];

            if(c == 'R'){
                j++;
            }
            else if(c == 'D'){
                i++;
            }
            else if(c == 'U'){
                i--;
            }
            else if(c == 'L'){
                j--;
            }
            
        }
        return {row, col};
    }
};