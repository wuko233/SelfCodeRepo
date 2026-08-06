class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int curT = 0, curF = 0;

        int start = 0;
        for (int end = 0; end < answerKey.size(); end++) {
            char cur = answerKey[end];
            if (cur == 'T') {
                curT++;
            } else {
                curF++;
            }

            int curDiff = min(curF, curT);
            while (min(curF, curT) > k) {
                char chS = answerKey[start];
                if (chS == 'T') {
                    curT--;
                } else {
                    curF--;
                }
                start++;
            }

            res = max(res, end - start + 1);
        }

        return res;
    }
};