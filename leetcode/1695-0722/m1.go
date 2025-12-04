package main

func maximumUniqueSubarray(nums []int) int {
	maxSum := 0
	curSum := 0
	left := 0
	freq := make(map[int]int)

	for right := 0; right < len(nums); right++ {
		num := nums[right]
		curSum += num
		freq[num]++

		for freq[num] > 1 {
			leftNum := nums[left]
			curSum -= leftNum
			freq[leftNum]--
			left++
		}

		if curSum > maxSum {
			maxSum = curSum
		}
	}

	return maxSum
}
