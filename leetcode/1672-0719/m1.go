package m1

func maximumWealth(accounts [][]int) int {
	max := 0
	for _, row := range accounts {
		asset := 0
		for _, val := range row {
			asset += val
		}
		if asset > max {
			max = asset
		}
	}

	return max
}
