// 最小公倍数
func lcm(a, b int) int { 
	return a * (b / gcd(a, b))
}

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b 
}