class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;

        int start = 0, end = 0, cnt = 0;

        for (;end < nums.size(); end++) {
            int cur = nums[end];
            cnt += 1 - cur;

            while (cnt > 1) {
                cnt -= 1 - nums[start];
                start++;
            }

            res = max(res, end - start);
        }

        return res;
    }
};