#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>

using namespace std;

/* This is our sample class to show how we can use a custom deleter with a 
 * unique_ptr.  This class simply opens, reads, writes and closes a file 
 * whose name is supplied in the constructor
 */
class MakeFile {

    private:
        FILE * myfile;

    public:
        MakeFile(const char * fileName) {
            cerr << "In constructor " << endl;
            myfile = fopen(fileName,"rw");
        }
        ~MakeFile() {
            cerr << "Calling the destructor" <<endl;
        }

        void closeFile() {
            fclose(myfile);
        }

        void writeFile(const char * data) {
            cerr << " in writeFile method" << endl;
            fprintf(myfile ,"%s\n",data);
            fflush(myfile);
        }
        char * readFile() {
            char buf[1024];
            return(fgets(buf,sizeof(buf),myfile));
        }
};

/* This is our customized deleter.  It's called as part of the unique_ptr declaration. 
 * It writes an error to stderr, (A silly thing to do in real life, however, unless you're 
 * debugging) closes the open file * and deletes the MakeFile object
 * 
*/
void myDeleter(MakeFile * m) {
    cerr << "Called the customized deleter to close the file and delete the MakeFile object" << endl;
    m->closeFile();
    delete m;
}
    
int main() {

    /* The reason we're using a nested block here is because if we don't, the exit(0) function 
     * will get called *before* the unique_ptr goes out of scope, and thus the custom deleter
     * doesn't get called because the program has already terminated.  
    */ 

    /* Instantiate the unique_ptr object, note that the second argument is a pointer to a void function
     * which takes a MakeFile object as its parameter.  When creating the object with a 'new', the second
     * argument is the name of the customized deleter function
    */
    {
 //       unique_ptr <MakeFile,void (*) (MakeFile *)> m (new MakeFile("./test.dat"),myDeleter);
       unique_ptr <MakeFile,void (*) (MakeFile *)> m  = std::make_unique<MakeFile,myDeleter>("test.dat");
        m->writeFile("foo bar baz");
    /* The object is about to go out of scope, so the compiler will automatically call the 
     * myDeleter function here before the exit() function is executed. 
    */
    }
    exit(0);

}
