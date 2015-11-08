class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowNum = matrix.size();
    
        //
        for(int i = 0; i < rowNum/2; ++i ) {
            swap(matrix[i], matrix[rowNum-1-i]);
        }
        //
        for(int i = 0; i < rowNum; ++i) {
            for(int j = i+1; j < rowNum; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
