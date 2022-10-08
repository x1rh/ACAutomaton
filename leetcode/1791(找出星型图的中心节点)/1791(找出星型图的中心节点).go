func findCenter(edges [][]int) int {
    mp := make(map[int]int)

    for _, x := range edges {
        mp[x[0]] += 1
        mp[x[1]] += 1
    }

    max := 0
    ans := -1

    for k, v := range mp {
        if v > max {
            max = v
            ans = k
        }
    }
    
    return ans 
}