package main

import (
	"strconv"
)

func maximum69Number(num int) int {
	str := strconv.Itoa(num)
	res := ""
	change := false
	for _, ch := range str {
		if !change && ch == '6' {
			res += "9"
			change = true
		} else {
			res += ch
		}
	}
	return strconv.Atoi(res)
}
