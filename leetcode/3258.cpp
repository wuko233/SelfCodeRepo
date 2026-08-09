class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0;

        int start = 0, cur0 = 0, cur1 = 0;
        for (int end = 0; end < s.size(); end++) {
            char cur = s[end];
            if (cur == '1') cur1++;
            else cur0++;

            while (min(cur0, cur1) > k) {
                char sCh = s[start];
                if (sCh == '1') cur1--;
                else cur0--;

                start++;
            }

            res += end - start + 1;
        }

        return res;
    }
};