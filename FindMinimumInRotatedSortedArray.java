// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class FindMinimumInRotatedSortedArray{
    public static void main(String[] args) {
        int[] arr = {4,5,6,7,0,1,2}; //Output: 0
        System.out.println(findMin(arr));
    }
    public static int findMin(int[] nums) {
        int start = 0;
        int end = nums.length -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mid<end && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }else if(mid>start && nums[mid]<nums[mid-1]){
                return nums[mid];
            }else if(nums[start]<=nums[mid]){
                start = mid+1;
            }else{
                end=mid-1;
            }
        }
        return nums[0];
    }
}
