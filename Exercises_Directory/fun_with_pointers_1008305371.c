///////////////////////////////////////////////////////////
//
// CSCA48 - Exercise 4 - a nice workout with pointers
//                       and strings
//
// (C) F. Estrada, Feb. 2022
///////////////////////////////////////////////////////////

///// DO NOT ADD ANY ADDITIONAL LIBRARIES ///////////////////////
///// DO NOT USE the string library <string.h> for this exercise
#include<stdio.h>
#include<stdlib.h>
#define MAX_STR_LEN 1024
/////////////////////////////////////////////////////////////////

void wordSwapper(char *dest, char *src)
{
  // This function takes a pointer to a source ('src') string (an array
  // of chars, with maximum size MAX_STR_LEN), and
  // makes a new string inside the destination ('dest') string
  // (which is also passed as a pointer) so that the order
  // of the words in the destination string is the reverse
  // of the order in the source string. 
  //
  // e.g. if:
  // The 'source' string contains "Hello I Am A String!"
  //
  // then the 'destination' string will contain
  //
  // 'String! A Am I Hello"
  // (notice that we add a space between each word in the
  // destination string - these are *added*, not *copied*)
  //
  // The only character to be used in separating words is
  // a blank space, so any other characters are considered
  // part of a word, for example "Hello, I; Am! A. *String*"
  // will become "*String* A. Am! I; Hello,"
  //
  // Notice there is NO SPACE at the end of the destination string.
  // (that is, we do not add a space after the last word in
  // destination)
  //
  // You *MUST* use pointers and pointer addressing to complete
  // this exercise (that is, no array notation with brackets []),
  // and you can not assume the 'destination' string is empty,
  // it could (and likely does) contain junk.
  //
  // If you decide to write helper functions, make sure they
  // are placed *above* this function's code.

  /////////////////////////////////////////////////////////////////
  // TO DO: Complete this function
  /////////////////////////////////////////////////////////////////

  char *start = src, *finish;

  // Effectively gets needed length of 'src' while also terminating 'dest' w.r.t. the length of 'src'.
  while (*(start++) != '\0'){
    dest++;
  }

  // Man, I spent a long time wondering why this shit wasn't working :p
  // Don't forget to terminate your strings, kids.
  *(dest) = '\0';

  while (*(src) != '\0')
  {
    // Accounts for multiple ' ' characters! (And copies them obviously.)
    while (*(src) == ' '){
      // Cool syntax shortcuts I found!
      *(--dest) = *(src++);
    }

    // Reset
    start = src;
    finish = src;

    // Gets word length
    while (*(finish) != ' ' && *(finish) != '\0'){
      finish++;
    }
    
    // Continue loop through this pos since we found where the word is.
    src = finish;

    // Puts words from 'src' (in reverse order) into 'dest'.
    while (finish > start){
      *(--dest) = *(--finish);
    }
  }
}

#ifndef __TESTING
int main()
{
    char source[MAX_STR_LEN]="silence .is a looking bird:the turning; edge, of life. e. e. cummings";
    char destination[MAX_STR_LEN]="I am a destination string and I contain lots of junk 1234517265716572@qsajdkuhasdgsahiehwjauhiuiuhdsj!";

    printf("The original string is: \n%s\n",source);

    // Call word swapper with the address of the first character in 'source' and the first character in 'destination'
    wordSwapper(&destination[0], &source[0]);
    // You could also call wordSwapper like this: wordSwapper(destination,source) since, as we will have seen in
    // lecture this week, the array's name can be used to pass into a function the address of the first entry
    // in the array.
    
    printf("Destination string after swapping: \n%s\n",destination);    
}
#endif
