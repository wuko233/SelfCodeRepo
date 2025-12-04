package main

import "slices"

func maxSum(nums []int) (ans int) {
	max := slices.Max(nums)
	if max <= 0 {
		return max
	}
	set := make(map[int]bool)
	for _, x := range nums {
		if x < 0 || set[x] {
			continue
		}
		ans += x
		set[x] = true
	}

	return
}
