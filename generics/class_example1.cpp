#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

/* This is an example of a template class.  We're creating a simple 
 * stack data structure.  We're using a template class because we want
 * to determine what data types we want to store on the stack  at compile
 * time and then have the compiler generate code for each of those types.
 * This, of course, makes your code type safe.
*/

template <class T> class myStack {
    private:
        vector <T> elems; // elems store the items on the stack.

    public: 
        void push (T const &);
        void pop();
        T top() const;
        bool isEmpty() const {
            return (elems.empty());
        }
};

template <class T> void myStack<T>::push(T const & elem) {
    elems.push_back(elem);
}

template <class T> void myStack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("myStack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <class T> T myStack<T>::top () const {
    if (elems.empty()) {
        throw out_of_range("myStack<>::top(): empty stack");
    }
    return(elems.back());
}


int main() {
    try {
        myStack<int>  intmyStack; // Stack of integers
        myStack<string> stringmyStack; // Stack of strings


        // Create a stack of integers and push a value on to it. 
        intmyStack.push(7);
        cout << intmyStack.top() << endl; 

        // Create a stack of strings and push a value on to it. 
        stringmyStack.push("Hello");
        cout << stringmyStack.top() << endl;

        stringmyStack.pop();
        stringmyStack.pop(); // This should throw an exception!
    } catch (exception const & e) {
        cerr << "Exception: " << e.what() << endl;
    }
}
