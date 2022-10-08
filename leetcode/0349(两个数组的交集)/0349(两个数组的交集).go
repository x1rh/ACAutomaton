func intersection(nums1 []int, nums2 []int) []int {
    sort.Ints(nums1)
    sort.Ints(nums2)
    set := make(map[int]struct{})

    for i := range nums1 {
        if bs(nums2, nums1[i]) {
            set[nums1[i]] = struct{}{} 
        }
    }

    ans := make([]int, 0)
    for k, _ := range set {
        ans = append(ans, k)
    }

    return ans 
}

func bs(arr []int, key int) bool {
    for l, r:=0, len(arr)-1; l<=r; {
        mid := (l+r)/2
        if arr[mid] == key {
            return true 
        } else if arr[mid] < key {
            l = mid +1
        } else {
            r = mid -1 
        }
    }
    return false 
}