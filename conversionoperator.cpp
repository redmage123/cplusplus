class Example{
    public:
        Example();
        Example(int val);
        operator unsigned int();
        ~Example(){}
    private:
        int itsVal;
};

Example::Example():itsVal(0){}
Example::Example(int val):itsVal(val){}
Example::operator unsigned int (){
        return (itsVal);
}

int main() {
    int theInt = 5;
    Example exObject = theInt; // here 
    Example ctr(5);
    int theInt1 = ctr; // here
    return 0;
}
