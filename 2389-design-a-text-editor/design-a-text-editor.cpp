class TextEditor {
public:
    struct Node {
        char c;
        Node* prev;
        Node* next;
        Node(char ch = '#') : c(ch), prev(nullptr), next(nullptr) {}
    };

    Node* head;   
    Node* tail;   
    Node* cursor; 

    TextEditor() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cursor = head; 
    }
    
    void addText(string text) {
        for (char ch : text) {
            Node* node = new Node(ch);
            Node* right = cursor->next;
            node->prev = cursor;
            node->next = right;
            cursor->next = node;
            right->prev = node;
            cursor = node; 
        }
    }
    
    int deleteText(int k) {
        int deleted = 0;
        while (cursor != head && k > 0) {
            Node* toDelete = cursor;
            Node* left = toDelete->prev;
            Node* right = toDelete->next;
            left->next = right;
            right->prev = left;
            cursor = left;
            delete toDelete;
            deleted++;
            k--;
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while (cursor != head && k > 0) {
            cursor = cursor->prev;
            k--;
        }
        return getLeft10();
    }
    
    string cursorRight(int k) {
        while (cursor->next != tail && k > 0) {
        cursor = cursor->next;
        k--;
        }
        return getLeft10();
    }

private:
    string getLeft10() {
        string res;
        Node* p = cursor;
        int cnt = 0;
        while (p != head && cnt < 10) {
            res.push_back(p->c);
            p = p->prev;
            cnt++;
        }
        reverse(res.begin(), res.end());
        return res;
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