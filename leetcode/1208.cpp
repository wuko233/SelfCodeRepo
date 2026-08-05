class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            diff.push_back(abs(s[i] - t[i]));
        }

        int start = 0, curSum = 0, maxLen = 0;
        for (int end = 0;end < diff.size(); end++) {
            curSum += diff[end];
            while (curSum > maxCost) {
                curSum -= diff[start];
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};