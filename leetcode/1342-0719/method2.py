class Solution:
    def numberOfSteps(self, num: int) -> int:
        # 5 -> 101 /2次数2，-1次数2 count = 4
        return (num.bit_length() - 1 ) + num.bit_count() if num > 0 else 0