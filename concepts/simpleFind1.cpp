#include <iostream>

/* This is our first pass at "genericizing" our find 
 * iterator. 
 * 
 * 1.  It still only understands characters.  I.e. I can't 
 * pass integer arrays or, indeed, any other type of 
 * collection into the find function.  
 * 
 * 2.  But!  It no longer assumes that the end character is the
 * null terminator. Now it will take any arbitrary end value
 * passed to it. 
 */


// Note that the find function takes three specific param types, 
// two char * which represent the lower and upper bounds of the 
// string to iterate over and a char which represents the character
// to look for. 
// 
//
char * find(char * f, char * l, char c) {


    // Now, our while loop runs in a deterministic fashion with the upper and
    // lower bound. 
    while (f != l && *f != c) {
        ++f;
    }

    //We no longer worry about having to return the null character since
    // we're bounding the string. Also we're returning a pointer to the
    // string starting at the character we're looking for, or the end
    // of the string if we didn't find it. 

    return f;
}


// The price for making the find more generic is apparent
// in the main program.  Now we need to defind the end point.
// Note that the end point (endOfStory) is one greater than the
// size of story (Remember, we start counting from zero!). 

int main() {
    char Story [] = "Once Upon a Time ...";

    // Define our end point.
    char *endOfStory = Story + sizeof(Story);

// This find function only works on character arrays. 
    char *p = find(Story,endOfStory,'U');

// We know that the find was successful if p doesn't point to the same
// place as the end.
    if (p != endOfStory) {
        std::cout << p << std::endl;
    }
}
