class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> type;
        int start = 0, res = 0, typeCnt = 0;

        for (int end = 0; end < fruits.size(); end++) {
            int cur = fruits[end];
            if (type[cur] == 0) typeCnt++;
            type[cur]++;

            while (typeCnt > 2) {
                type[fruits[start]]--;
                if (type[fruits[start]] == 0) typeCnt--;
                start++;
            }

            res = max(res, end - start + 1);
        }

        return res;
    }
};