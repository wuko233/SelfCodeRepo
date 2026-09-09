class Solution {
public:
    int bs(vector<int> nums, int target) {
        int left = 0, right, len = nums.size();
        right = len;
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

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = bs(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        int end = bs(nums, target + 1) - 1;
        return {start, end};
    }
};