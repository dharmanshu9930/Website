void sortColors(vector<int>& nums) {
    int zero =0, l = 0, r = nums.size()-1;
    while (l <= r) {
        if (nums[l] == 0) 
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2) 
            swap(nums[l], nums[r--]);
        else
            l++;
    }
}
