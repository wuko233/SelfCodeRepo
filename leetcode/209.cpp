class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0,curSum = 0, res = INT_MAX;

        while (end < nums.size()) {
            curSum += nums[end];
            while (curSum >= target) {
                res = min(res, end - start + 1);
                curSum -= nums[start];
                start++;
            }

            end++;
        }

        return res == INT_MAX? 0: res;
    }
};