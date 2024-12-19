class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int prev = -1;
        int l = 0; int h = matrix.size() - 1;

        while (l<=h){
            int mid = (l+h)/2;
            cout<<"mid"<<endl;
            cout<<mid<<endl;
            if (matrix[mid][0] == target){
                return true;
            }

            if(matrix[mid][0] > target){
                h = mid - 1;
            }else{
                row = mid;
                l = mid + 1;
            }
            prev = matrix[mid][0];
        }

        l = 0; h = matrix[row].size() - 1;

        while (l<=h){
            
            int mid = (l+h)/2;

            cout<<matrix[row][mid]<<endl;

            if (matrix[row][mid] == target){
                return true;
            }

            if (matrix[row][mid] > target){
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return false;
    }
};