class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int start = 0, curDiff = 0;

        for (int end = 0; end < nums.size(); end++) {
            int cur = nums[end];
            if (cur == 0) curDiff++;

            while (curDiff > k) {
                if (nums[start] == 0) {
                    curDiff--;
                }
                start++;
            }

            res = max(end - start + 1, res);
        }

        return res;
    }
};