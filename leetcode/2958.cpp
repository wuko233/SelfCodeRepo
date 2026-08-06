class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> fre;

        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            int cur = nums[end];
            fre[cur]++;

            while (fre[cur] > k) {
                fre[nums[start]]--;
                start++;
            }

            res = max(res, end - start + 1);
        }

        return res;
    }
};