class TextEditor {
public:
    int idx;
    string s;
    TextEditor() {
        idx = 0;
    }
    
    void addText(string text) {
        s.insert(idx, text);
        idx += text.size();
    }
    
    int deleteText(int k) {
        int cnt = min(idx, k);
        idx -= cnt;
        s.erase(idx, cnt);
        return cnt;
    }
    
    string cursorLeft(int k) {
        int old = idx;
        idx -= k;
        if(idx < 0) {
            idx = 0;
        }
        int cnt = min(idx, 10);
        return s.substr(idx-cnt, cnt);
    }
    
    string cursorRight(int k) {
        int old = idx;
        idx += k;
        if(idx >= s.size()) {
            idx = s.size();
        }
        
        int cnt = min(idx, 10);
        return s.substr(idx-cnt, cnt);
    }
};
