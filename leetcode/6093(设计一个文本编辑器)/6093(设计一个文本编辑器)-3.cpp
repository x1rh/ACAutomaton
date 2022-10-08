class TextEditor {
public:
    deque<char> l, r;
    TextEditor() {
        l.clear();
        r.clear();
    }

    void addText(string text) {
        for(int i=0; i<text.size(); i++) {
            l.push_back(text[i]);
        }
    }

    int deleteText(int k) {
        int backup = k;
        while(k && !l.empty()) {
            k--;
            l.pop_back();
        }
        return backup - k ;
    }

    string cursorLeft(int k) {
        while(k && !l.empty()) {
            k--;
            auto x = l.back();
            l.pop_back();
            r.push_front(x);
        }
        int d = min((int)l.size(), 10);
        return {l.end()-d, l.end()};
    }

    string cursorRight(int k) {
        while(k && !r.empty()) {
            k--;
            auto x = r.front();
            l.push_back(x);
            r.pop_front();
        }
        int d = min((int)l.size(), 10);
        return {l.end()-d, l.end()};
    }
};