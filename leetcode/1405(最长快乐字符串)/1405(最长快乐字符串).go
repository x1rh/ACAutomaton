func longestDiverseString(a int, b int, c int) string {
	ans := []byte{}
	arr := []struct{x byte; cnt int}{{'a', a}, {'b', b}, {'c', c}}
	for {
		sort.Slice(arr, func(i, j int) bool {return arr[i].cnt > arr[j].cnt})
		flag := false
		for i, x := range arr{
			if x.cnt == 0 {
				break
			}
			sz := len(ans)
			if sz>=2 && ans[sz-1]==x.x && ans[sz-2]==x.x {
				continue
			}
			flag = true
			arr[i].cnt--
			ans = append(ans, x.x)
			break
		}
		if !flag {
			break
		}
	}
	return string(ans)
}