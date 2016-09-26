//Java Version
 public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();  
        int n=nums.length;
        if(n==0) return res;
        if(n==1) {
            res.add(Integer.toString(nums[0]));
            return res;
        }
        int i=0,k;
        while(i<n){
            //res.add(Integer.toString(nums[i])); //first element
            k=i;
            while((i<n-1)&&(nums[i+1]-nums[i]==1)) i++;
            if(i!=k){
                res.add(Integer.toString(nums[k])+"->"+Integer.toString(nums[i]));
            }
            else res.add(Integer.toString(nums[k]));
                //res.add(); //last element
               
                i++;
            
        }
        return res;
    }
}