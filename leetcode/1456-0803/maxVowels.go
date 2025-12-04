package main

func maxVowels(s string, k int) int {
	vowels := map[byte]bool{
		'a': true, 'e': true, 'i': true, 'o': true, 'u': true,
		'A': true, 'E': true, 'I': true, 'O': true, 'U': true,
	}

	cur := 0

	for i := 0; i < k; i++ {
		if vowels[s[i]] {
			cur++
		}
	}
	max := cur

	for i := k; i < len(s); i++ {
		if vowels[s[i-k]] {
			cur--
		}
		if vowels[s[i]] {
			cur++
		}
		if cur > max {
			max = cur
		}
	}

	return max
}
