type TextEditor struct {
    lst *list.List
    it *list.Element 
}


func Constructor() TextEditor {
    l := list.New()
    return TextEditor{
        lst: l,
        it: l.PushBack(nil),
    }
}


func (this *TextEditor) AddText(text string)  {
    for _, c := range text {
        this.lst.InsertBefore(c, this.it)
    }
}


func (this *TextEditor) DeleteText(k int) int {
    cnt := 0
    for cnt=0; this.it != this.lst.Front() && cnt < k; cnt++{
        j := this.it
        this.it = this.it.Prev()
        this.lst.Remove(this.it)        
        this.it = j
    }
    return cnt 
}


func (this *TextEditor) CursorLeft(k int) string {
    res := ""
    for cnt:=0; this.it != this.lst.Front() && cnt<k; cnt++{
        this.it = this.it.Prev()
    }
    for cnt, i:=0, this.it; i != this.lst.Front() && cnt<10; cnt++ {
        p := i.Prev()
        res = string(p.Value.(rune)) + res 
        i = p
    }
    return res 
}


func (this *TextEditor) CursorRight(k int) string {
    for cnt:=0; this.it != this.lst.Back() && cnt<k; cnt++ {
        this.it = this.it.Next()
    }
    res := ""
    for cnt, i:=0, this.it; i != this.lst.Front() && cnt<10; cnt++ {
        p := i.Prev()
        res = string(p.Value.(rune)) + res 
        i = p 
    }
    return res 
}