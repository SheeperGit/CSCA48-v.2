// Example of using a library you may have created yourself!
//
//
// Notice that compiling as usual:
//
// gcc caesar_sample.c
//
// doesn't work! (try it!) - the linker doesn't know what to do to find the code for 
//  the functions in caesar_cipher_lib - that code is not in the header file (.h),
//  but instead it's in the pre-compiled .o file.
//
// So, to compile this:
//
// 1)  gcc -c caesar_sample.c
//
//    This will create a .o file for 'caesar_sample'
//
// 2) gcc caesar_sample.o caesar_cipher_lib.o -o caesar_sample
//
//    Now link together the code from your sample application, and from the library to produce the executable.
// 
// Du DUN!

#include<stdio.h>
#include<stdlib.h>

#include "caesar_cipher_lib.h"       //  Notice the "" instead of <>... this is important!

int main()
{
    // Put a message in the string below that you wish to encode, any message!
    unsigned char a_message[MAX_STR_LEN]="Hello! I'm a cute little message!\nJust try to decode me ;)";
    unsigned char passPic[SX][SY];

    // Load an image using the library function readPGMimage, the image is called 'tile_1.pgm';
    readPGMimage("tile_1.pgm", &passPic[0][0]);

    // Print the input message 
    printf("**** Original input message:\n\n");
    printf("%s",a_message);

    // Encode the input test lines using the library
    caesar_cipher(&a_message[0],&passPic[0][0]);

    // Print the result of encoding
    printf("\n\n**** Encrypted text lines:\n\n");
    printf("%s",a_message);

    // Decode the encrypted message using the library
    caesar_cipher(&a_message[0],&passPic[0][0]);

    // See if we got it back
    printf("\n\n**** Decoded text lines (should be identical to original input!):\n\n");
    printf("%s\n",a_message);
    
    return 0;    
}
