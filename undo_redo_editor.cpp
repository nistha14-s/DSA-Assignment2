#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    string text;
    stack<string> undoStack, redoStack;

public:
    void type(const string& newText) {
        undoStack.push(text);
        text += newText;
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();
        }
    }

    void show() { cout << "Text: " << text << endl; }
};

int main() {
    TextEditor t;
    t.type("Hello ");
    t.type("World");
    t.show();

    t.undo();
    t.show();

    t.redo();
    t.show();
}
