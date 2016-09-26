class Solution {
    private:int mostcase;
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};


摩尔投票法
    /**
     * 算法基础：摩尔投票法
     * @param nums
     * @return
     */
    public int majorityElement(int[] nums) {

        int majority = -1;

        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                majority = num;
                count++;
            } else {
                if (majority == num) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        int counter = 0;
        if (count <= 0) {
            return -1;
        } else {
            for (int num : nums) {
                if (num == majority) counter ++;
            }
        }

        if (counter > nums.length / 2) {
            return majority;
        }

        return -1;
    }