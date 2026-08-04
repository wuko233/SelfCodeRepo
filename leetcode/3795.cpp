class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int start = 0, end = 0, curK = 0, res = INT_MAX;

        while (end < nums.size()) {
            int cur = nums[end];
            cnt[cur]++;
            curK += cnt[cur] == 1? cur: 0;

            while (curK >= k) {
                res = min(res, end - start + 1);
                cnt[nums[start]]--;
                if (cnt[nums[start]] == 0) curK -= nums[start];
                start++;
            }

            end++;
        }

        return res == INT_MAX? -1: res;
    }
};