func luckyNumbers (matrix [][]int) []int {
    m := len(matrix)
    n := len(matrix[0])

    var ans []int 

    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {

            flag := false 
            for k:=0; k<n; k++ {
                if k == j {
                    continue 
                }
                if matrix[i][k] > matrix[i][j] {
                    continue
                } else {
                    flag = true 
                    break
                }
            }        

            if flag {
                continue
            }

            for k:=0; k<m; k++ {
                if i == k {
                    continue
                }
                if matrix[k][j] < matrix[i][j] {
                    continue;
                } else {
                    flag = true;
                    break;
                }
            }
            if flag {
                continue;
            }
            ans = append(ans, matrix[i][j])
        }
    }
    return ans
}