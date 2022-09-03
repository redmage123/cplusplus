public class Student {

    private:
        const char * StudentName;
        int StudentAge;
        const char * StudentIDNum;
        char * StudentMajor;


        Student(sname,sage,sid) : {StudentName(sname},StudentAge(sage),StudentIDNum(sid)}  {

                char * StudentMajor = new char [50];
        }

    // Function declarations.
        friend boolean RegisterForClass( char *);
        void foo(int);

        ~Student() {
            delete [] StudentMajor;
        }


};

void Student::foo () {
}

boolean RegisterForClass(className) {
    register(this->StudentName,className);
}


cout << "Hello" << endl;




Student s1 = new Student("Braun Brelin", 21, "bbrelin123");




export PATH=/usr/bin:$PATH

