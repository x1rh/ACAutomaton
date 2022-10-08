type node struct{
    x, y, c int 
}

func updateMatrix(mat [][]int) [][]int {
    m := len(mat)
    n := len(mat[0])
    d := []struct{x,y int}{{-1,0},{1,0},{0,-1},{0,1}}
    inf := 0x3f3f3f3f 

    ans := make([][]int , m)


    q := []node{}
    
    for i := range mat {
        ans[i] = make([]int, n)
        for j := range mat[i] {
            if mat[i][j] == 0 {
                ans[i][j] = 0 
                q = append(q, node{i,j,0})
            } else {
                ans[i][j] = inf 
            }
        }
    }
    
    for len(q) > 0 {
        fr := q[0]
        q = q[1:len(q)]
        for i := range d {
            x := d[i].x + fr.x 
            y := d[i].y + fr.y 
            c := fr.c + 1
            if 0<=x&&x<m && 0<=y&&y<n && c<ans[x][y]{
                ans[x][y] = c 
                q = append(q, node{x,y,c})           
            }               
        }
    }
    
    return ans 
}