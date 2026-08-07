class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int start = 0, cur1 = 0, minLen = INT_MAX;

        string res = "";

        for (int end = 0; end < s.size(); end++) {
            char cur = s[end];
            if (cur == '1') cur1++;

            while (cur1 > k) {
                char startCh = s[start];
                if (startCh == '1') cur1--;

                start++;
            }

            while (start < end && cur1 == k && s[start] == '0') start++;

            int curLen = end - start + 1;
            if (cur1 == k) {
                int curLen = end - start + 1;
                string curStr = s.substr(start, curLen);
                if (curLen < minLen || (curLen == minLen && curStr < res)) {
                    minLen = curLen;
                    res = curStr;
                }
            }
        }

        return res;
    }
};