package main

func numIdenticalPairs(nums []int) int {
	res := 0
	freq := make(map[int]int)
	for _, v := range nums {
		if freq[v] >= 1 {
			res += freq[v]
		}
		freq[v]++
	}
	return res
}
