using namespace std;

template <class T> class myVector {
    private:
        unsigned int mv_size;
        unsigned int mv_capacity;
        char * buffer;

    public:

        typedef T* Iterator;
        myVector();
        myVector (unsigned int size, const T & initial);
        myVector (const myVector<T> &v); // Copy constructor
        ~myVector();

        myVector<T> & operator = (const Vector <T> &); // Copy assignment

        unsigned int capacity() const;
        unsigned int size() const;

        bool empty() const;

        Iterator begin();
        Iterator end();
        T& front();
        T& back();
        void push_back (const T& value);
        void pop_back();
        void reserve (unsigned int capacity);
        void resize(unsigned int size);


        T& operator [] (unsigned int index);
};


