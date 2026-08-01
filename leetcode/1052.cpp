class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int baseHappy = 0;
        for (int i = 0; i < customers.size(); i++) baseHappy += grumpy[i] == 0 ? customers[i] : 0;

        int start = 0, end = minutes, max = baseHappy;

        int curHappy = baseHappy;
        for (int i = 0;i < end; i++) {
            curHappy += grumpy[i] == 1? customers[i]: 0;
        }
        max = curHappy;

        while (end < customers.size()) {
            curHappy -= grumpy[start] == 1? customers[start]: 0;
            start++;
            
            curHappy += grumpy[end] == 1? customers[end]: 0;

            if (curHappy > max) max = curHappy;
            end++;
        }

        return max;
    }
};