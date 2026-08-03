class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (1LL * nums[left] * k < nums[right]) {
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return nums.size() - max_len;
    }
};