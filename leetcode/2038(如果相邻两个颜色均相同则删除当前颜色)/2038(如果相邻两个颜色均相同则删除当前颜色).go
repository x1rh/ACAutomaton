func winnerOfGame(colors string) bool {
    i := 0 
    n := len(colors)

    a := 0
    b := 0 

    for i < n {
        var j int 
        if colors[i] == 'A' {
            for j=i; j<n&&colors[j]=='A'; j++ {}

            if j-i>2 {
                a += j-i-2
            }
        } else {
            for j=i; j<n&&colors[j]=='B'; j++ {}
            if j-i>2 {
                b += j-i-2
            }
        }
        i = j 
    }

    return a > b  
}