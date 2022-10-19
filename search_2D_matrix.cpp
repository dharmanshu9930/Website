#include <iostream>
#include <vector>
// IN this we have to search and element in 2-d matrix
using namespace std;
class search2dmatrix
{
private:
    vector<vector<int>> matrix;

public:
    search2dmatrix()
    {
        int row, column;
        cin >> row >> column;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < column; j++)
            {
                int tempvar;
                cin >> tempvar;
                temp.push_back(tempvar);
            }
            matrix.push_back(temp);
        }
    }
    bool ispresent()
    {
        int target;
        cin >> target;
        // Using two pointer approach
        int temprow = 0;
        int tempcolumn = matrix[0].size() - 1;
        int rowsize = matrix.size();

        while (temprow < rowsize && tempcolumn >= 0)
        {
            int temp = matrix[temprow][tempcolumn];
            cout << temp << " " << endl;
            if (temp == target)
            {
                return true;
            }
            else if (temp < target)
            {
                temprow++;
            }
            else
            {

                tempcolumn--;
            }
        }
        return false;
    }
};
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
int main()
{
    search2dmatrix s1;
    cout << s1.ispresent() << endl;

    return 0;
}