#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
{
   
 
    if (low == high)                    
    {
        if (max < nums[low]) {          
            max = nums[low];
        }
 
        if (min > nums[high]) {         
            min = nums[high];
        }
 
        return;
    }
 
    if (high - low == 1)
    {
        if (nums[low] < nums[high])       
        {
            if (min > nums[low]) {
                min = nums[low];
            }
 
            if (max < nums[high]) {      
                max = nums[high];
            }
        }
        else {
            if (min > nums[high]) {      
                min = nums[high];
            }
 
            if (max < nums[low]) {       
                max = nums[low];
            }
        }
        return;
    }
 
    
    int mid = (low + high) / 2;
 
    
    findMinAndMax(nums, low, mid, min, max);
 
    
    findMinAndMax(nums, mid + 1, high, min, max);
}
 
int main()
{
    vector<int> nums = { 11, 23, 91, 31, 9, 49, 66, 71, 6 };
    int max = INT_MIN, min = INT_MAX;
 
    int n = nums.size();
    findMinAndMax(nums, 0, n - 1, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
 
    return 0;
}
