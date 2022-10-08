class TextEditor {
public:
    list<char> lst;
    list<char>::iterator it;
    TextEditor() {
        lst.clear();
        it = lst.end();
    }
    
    void addText(string text) {        
        for(int i=0; i<text.size(); i++) {
            lst.insert(it, text[i]);
        }
    }
    
    int deleteText(int k) {
        int res = 0; 
        for(; it!=lst.begin() && res<k; ) {
            lst.erase(prev(it));           
            res++;
        } 
        return res; 
    }
    
    string cursorLeft(int k) {
        int cnt = 0;
        for(; it!=lst.begin() && cnt<k; it--) {
            cnt++;
        }
        cnt = 0;
        string res = "";
        for(auto i=it; i!=lst.begin() && cnt<10; i--) {
            res = *prev(i) + res;
            cnt++;
        }
        return res; 
    }
    
    string cursorRight(int k) {
        int cnt = 0;
        for(; it!=lst.end() && cnt<k; it++) {
            cnt++;
        }
        cnt = 0;
        string res = "";
        for(auto i=it; i!=lst.begin() && cnt<10; i--) {
            res = *prev(i) + res;
            cnt++;
        }
        return res;
    }
};