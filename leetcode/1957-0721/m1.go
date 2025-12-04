package m1

import "strings"

func makeFancyString(s string) string {

	if len(s) < 3 {
		return s
	}

	builder := strings.Builder{}
	builder.Grow(len(s))

	builder.WriteByte(s[0])
	builder.WriteByte(s[1])
	for i := 2; i < len(s); i++ {

		if s[i] == s[i-2] && s[i] == s[i-1] {
			continue
		}
		builder.WriteByte(s[i])
	}
	return builder.String()
}
