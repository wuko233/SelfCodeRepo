package main

func coinChange(coins []int, amount int) int {
	m := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		m[i] = amount + 1
		for _, coin := range coins {
			if coin > i {
				continue
			}
			m[i] = min(m[i], 1+m[i-coin])
		}
	}
	if m[amount] > amount {
		return -1
	}
	return m[amount]

}
