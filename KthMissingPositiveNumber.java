class KthMissingNumber{
  public static void main(String[] args){
    int[] arr = {2,3,4,7,11};
    int k = 5;
    System.out.println(findKthPositive(arr, k)); // Output: 9
  }
  public static int findKthPositive(int[] arr, int k) {
        int start = 0;
        int end = arr.length - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(arr[mid]-mid-1 >= k){
                end =mid-1;
            }else {
                start=mid+1; 
            }
        }
        return start+k;
    }
}
