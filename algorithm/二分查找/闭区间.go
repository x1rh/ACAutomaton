func lower_bound(a []int, key int) int {
	l, r := 0, len(a)-1    // 注意 
	for l <= r {           // 保证[l, r]不为空
		m := l + (r-l)/2 
		if a[m] < key {
			l = m + 1      // 更新l=m+1后意味着l-1指向的是小于key的区域
		} else { 
			r = m - 1      // 没有改变l； a[m] >= key 则更新r=m-1后，r+1指向的区域大于等于key
		}
	}                      
	return l               // r+1是我们寻找的答案；退出循环时，l=r+1
}                          // 如果key大于所有的数组元素，那么l=len(a)
                           // 如果key小于所有的数组元素，那么r=-1, l=0
						   // 所以处理返回结果时，先判断l是否数组下标越界，<len(a)，然后判断a[l]是否等于key  
