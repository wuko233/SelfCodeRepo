class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            
            if (cur >= 0) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int negative = right;

        left = right - 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int postive = n - right;
        return max(postive, negative);
    }
};