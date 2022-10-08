func pushDominoes(dominoes string) string {
    n := len(dominoes)
    v := make([]int, n)
    for i:=0; i<n; i++ {
        if dominoes[i] == 'L' {
            v[i] += -1;
        } else if dominoes[i] == 'R' {
            v[i] += 1;
        }
    }

    for i:=0; i<n-1; {
        if dominoes[i] == 'R' && dominoes[i+1] == '.'{
            var j int 
            for j=i+1; j<n && dominoes[j] == '.'; j++ {};

            if j==n || dominoes[j] == 'R' {
                for k:=i+1; k<j; k++ {
                    v[k] += 1
                }
            } else {
                for k:=i+1; k<i+(j-i+1)/2; k++ {
                    v[k] += 1
                }
            }
            i = j;
        } else {
            i += 1;
        }
        
    }

    for i:=n-1; i>=1;{
        if dominoes[i] == 'L' && dominoes[i-1] == '.'{
            var j int 
            for j=i-1; j>=0 && dominoes[j] == '.'; j-- {};
            if j == -1 || dominoes[j] == 'L' {
                for k:=i-1; k>j; k-- {
                    v[k] += -1;
                }    
            } else {
                for k:=i-1; k>i-(i-j+1)/2; k-- {
                    v[k] += -1;
                }
            }
            i = j;
        } else {
            i -= 1;
        }
    }

    ans := make([]byte, n)

    for i:=0; i<n; i++ {
        if v[i] == 0 {
            ans[i] = '.'
        } else if v[i] == -1 {
            ans[i] = 'L'
        } else {
            ans[i] = 'R'
        }
    }

    return string(ans)
}