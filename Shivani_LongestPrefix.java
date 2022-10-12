package Leetcode;

public class LongestPrefix {
    public static void main(String[] args) {

    }

        public String longestCommonPrefix(String[] strs) {
            int min = Integer.MAX_VALUE;

            String a = strs[0];
            for(int i=0;i< strs.length;i++)
            {
                String temp = strs[i];
                int j=0, k=0, count =0;

                while(j <a.length() && k< temp.length() && a.charAt(j)==temp.charAt(k))
                {
                    count++;
                    j++;
                    k++;
                }

                min = Math.min(min,count);
            }


            return a.substring(0,min);
        }



}
