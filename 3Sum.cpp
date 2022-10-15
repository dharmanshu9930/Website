
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	vector<int> nums;
	
	cout<<"Enter the size of the array to be entered: ";
	cin>>n;
	cout<<"Enter the array values: ";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	
	// Vector ans to store the ans vector
    vector<vector<int>> ans;
    
    //Sorting the nums vector
    sort(nums.begin(),nums.end());
    
    // Apply two sum logic
    int k=0;
    for(k=0;k<nums.size();k++){
        while(k>0 && nums[k]==nums[k-1]){
            k++;
        }
        int s = 0-nums[k];
        int i=k+1,j=nums.size()-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==s){
                ans.push_back({nums[k],nums[i],nums[j]});
                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;
                i++;
                j--;
            }
            else if(sum<s){
                i++;
            }
            else if(sum>s){
                j--;
            }
        }
        while(k+1<nums.size() && nums[k+1]==nums[k])k++;
    }
    
    cout<<"Answer: ";
    for(int i=0;i<ans.size();i++){
    	cout<<"[";
    	for(int j=0;j<ans[0].size();j++){
    		cout<<ans[i][j]<<" ";
		}
		cout<<"] ";
	}
	
	return 0;
}
