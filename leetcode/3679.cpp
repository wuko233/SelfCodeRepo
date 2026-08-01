#include <unordered_map>

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int res = 0;
        unordered_map<int, int> cnt;

        for (int i = 0; i < arrivals.size(); ++i) {
            int& cur = arrivals[i];

            if (cnt[cur] >= m) {
                res++;
                cur = 0;
            } else {
                cnt[cur]++;
            }

            int left = i + 1 - w;
            if (left >= 0) {
                cnt[arrivals[left]]--;
            }
        }
        return res;
    }
};