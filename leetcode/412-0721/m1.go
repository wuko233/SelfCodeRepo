package main

import (
	"strconv"
	"strings"
)

func fizzBuzz(n int) []string {
	ans := []string{}
	for i := 1; i <= n; i++ {
		res := strings.Builder{}
		if i%3 == 0 {
			res.WriteString("Fizz")
		}
		if i%5 == 0 {
			res.WriteString("Buzz")
		}
		if res.Len() == 0 {
			res.WriteString(strconv.Itoa(i))
		}
		ans = append(ans, res.String())
	}

	return ans
}
