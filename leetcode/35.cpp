class Solution {
public:
    int bs(vector<int>& nums, int target) {
        int left = 0, len = nums.size();
        int right = len;
            while (left < right) {
                int mid = left + (right - left) / 2;
                int cur = nums[mid];
                if (cur >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            return left;
        }
        
    int searchInsert(vector<int>& nums, int target) {
        int start = bs(nums, target);
        return start;


    }
};