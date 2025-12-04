class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        right = 0
        while right <= len(s):
            if s[right] in s[left:right]:
                
                

            right += 1
