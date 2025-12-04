class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a ,b = 'a', 'b'
        if y > x:
            x, y = y, x
            a, b = b, a
        res = cnt1 = cnt2 = 0
        for ch in s:
            if ch == a:
                cnt1 += 1
            elif ch == b:
                if cnt1:
                    res += x
                    cnt1 -= 1
                else:
                    cnt2 += 1
            else:
                res += min(cnt1, cnt2) * y
                cnt2 = cnt1 = 0
        res += min(cnt1, cnt2) * y
        return res
