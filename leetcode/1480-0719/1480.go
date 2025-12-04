package t1480

func runningSum(nums []int) []int {
	var last = nums[0]
	res := []int{last}
	for i := 1; i < len(nums); i++ {
		last = last + nums[i]
		res = append(res, last)
	}

	return res
}
