func convert(s string, numRows int) string {
    if numRows == 1 {
        return s 
    }

    delta := (numRows-1) * 2
    var ans []byte 
    for i:=0; i<numRows; i++ {
        for j:=i; j<len(s); {
            ans = append(ans, s[j])
            j = j + delta 
            k := j-2*i
            if i==0 || i==numRows-1 {
                continue;
            } else if 0<=k && k < len(s){
                ans = append(ans, s[j-2*i])
            }
        }
    }

    return string(ans)
}