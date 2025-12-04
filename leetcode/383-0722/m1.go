package main

func canConstruct(ransomNote string, magazine string) bool {
	dic := make(map[rune]int)
	for _, ch := range magazine {
		dic[ch]++
	}
	for _, ch := range ransomNote {
		if dic[ch] < 1 {
			return false
		}
		dic[ch]--
	}
	return true
}
