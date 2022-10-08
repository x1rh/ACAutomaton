func knightProbability(n int, k int, row int, column int) float64 {
    dx := []int{2, 2, -2, -2, 1, 1, -1, -1}
    dy := []int{1, -1, 1, -1, 2, -2, 2, -2}
    dp := make([][][]float64, k+1);
    for s:=0; s<=k; s++ {
        dp[s] = make([][]float64, n)
        for i:=0; i<n; i++ {
            dp[s][i] = make([]float64, n)
            for j:=0; j<n; j++ {
                if s==0 {
                    dp[s][i][j] = 1
                } else {
                    for h:=0; h<8; h++ {
                        x := dx[h] + i
                        y := dy[h] + j
                        if 0<=x&&x<n && 0<=y&&y<n {
                            dp[s][i][j] += dp[s-1][x][y] / 8
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column]
}