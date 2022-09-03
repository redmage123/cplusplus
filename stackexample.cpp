#include <iostream.

using namespace std;

class Stack {
    int items[10];
    int sp;
    public: 
        friend class StackIter;
        Stack() {
            sp = -1;
        }
        void push (int in) {
            item(++sp) = in;
        }
        int pop() {
            return items[sp--];
        }
        bool isEmpty() {
            return (sp == -1);
        }
        StackIter *createIterator() const;
};

class StackIter {
    const Stack *stk;
    int index;
    public:
        StackIter(const Stack *s) {
            stk = s;
        }
        void first() {
            index=0;
        }
        void next() {
            index++;
        }
        bool isDone() {
            return (index== stk->sp + 1);
        }
        int currentItem()  {
            return stk->items[index];
        }
};




