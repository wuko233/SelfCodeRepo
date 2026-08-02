class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int start = 0, end = 0, len = s.size();
        int max = 0;

        while (end < len) {
            char cur = s[end];
            cnt[cur]++;
            end++;
            if (cnt[cur] > 1) {
                while (s[start] != cur) {
                    cnt[s[start]] = 0;
                    start++;
                }
                cnt[cur] = 1;
                start++;
            }

            int curLen = end - start;
            if (curLen > max) max = curLen;
        }

        return max;
    }
};