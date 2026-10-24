class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = -1, right = letters.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right < letters.size()? letters[right]: letters[0];
    }
};