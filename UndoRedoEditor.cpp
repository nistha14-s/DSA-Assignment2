#include <iostream>
    #include <stack>
    using namespace std;

    class Editor {
    public:
        stack<string> undoStack, redoStack;
        string text = "";

        void type(string word) {
            undoStack.push(text);
            text += word;
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

        void show() {
            cout << "Text: " << text << endl;
        }
    };

    int main() {
        Editor ed;
        ed.type("Hello ");
        ed.type("World");
        ed.show();
        ed.undo();
        ed.show();
        ed.redo();
        ed.show();
    }
    