class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0;

        int start = 0, curM = 1;
        for (int end = 0; end < nums.size(); end++) {
            int cur = nums[end];
            curM *= cur;

            while (curM >= k) {
                curM /= nums[start];
                start++;
            }

            res += end - start + 1;
        }

        return res;
    }
};