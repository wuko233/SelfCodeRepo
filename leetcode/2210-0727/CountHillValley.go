package main

func countHillValley(nums []int) (ans int) {
	pre := nums[0]
	for i := 1; i < len(nums)-1; i++ {
		cur := nums[i]
		nxt := nums[i+1]
		if cur == nxt {
			continue
		}
		if pre != cur && (pre < cur) == (cur > nxt) {
			ans++
		}
		pre = cur
	}
	return
}
