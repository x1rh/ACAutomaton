func findRestaurant(list1 []string, list2 []string) []string {
    x := 0x3f3f3f3f
    y := 0x3f3f3f3f 
    var ans []string 

    for i:=0; i<len(list1); i++ {
        for j:=0; j<len(list2); j++ {
            if list1[i] == list2[j] && i+j<=x+y {
                if i+j < x+y {
                    ans = nil 
                    ans = append(ans, list1[i])
                    x = i
                    y = j 
                } else {
                    ans = append(ans, list1[i])
                }
            }
        }
    }

    return ans 
}