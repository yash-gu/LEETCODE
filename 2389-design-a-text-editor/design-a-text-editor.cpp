class TextEditor {
public:
    string left;   
    string right;  

    TextEditor() {
        left = "";
        right = "";
    }
    
    void addText(string text) {
        left += text;
    }
    
    int deleteText(int k) {
        int del = min(k, (int)left.size());
        left.erase(left.size() - del, del);
        return del;
    }
    
    string cursorLeft(int k) {
        int move = min(k, (int)left.size());
        right = left.substr(left.size() - move, move) + right;
        left.erase(left.size() - move, move);
        return left.substr(left.size() > 10 ? left.size() - 10 : 0);
    }
    
    string cursorRight(int k) {
        int move = min(k, (int)right.size());
        left += right.substr(0, move);
        right.erase(0, move);
        return left.substr(left.size() > 10 ? left.size() - 10 : 0);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */