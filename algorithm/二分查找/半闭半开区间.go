// 左闭右开 
func lower_bound(a []int, target int) int {
	l, r := 0, len(a)        // 注意 r =len(a)
	for l < r {              // 保证区间[l, r)不为空 
		mid := l + (r-l)/2 
		if a[mid] < target { 
			l = mid + 1 
		} else {
			r = mid          // 闭区间的时候是r=mid-1， 那么开区间就是r=mid，是不是非常合情合理 
		}
	}                        // 退出循环时，l==r 
	return l                 // l和r都指向答案 
}                            // 边界情况，l最大为len(a), l最小为0，r最小为0 