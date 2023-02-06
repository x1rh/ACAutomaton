func lower_bound(a []int, target int) int {
	l, r := -1, len(a)  // 注意
	for l + 1 < r {     // 区间(l,r)不空 
		m := l + (r-l)/2 
		if a[m] < target {
			l = m
		} else {
			r = m
		}
	}                   // 退出循环时，l+1=r 
	return r            // l指向的是小于target的区域，那么l+1指向的就是大于等于target的区域，又l+1=r, 所以返回r 
}