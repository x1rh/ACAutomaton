// 最小公倍数
func lcm(a, b int) int {
	x := gcd(a, b)
	return (a / x) * (b / x)
}

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b 
}