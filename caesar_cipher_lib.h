////////////////////////////////////////////////////////////
// Caesar Cipher Lib
//
// This is an example of building software from libraries
// that someone else designed
//
// (c) F. Estrada, March 2023
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#ifndef __caesar_cipher_lib         // This checks if we have already imported this library from another module
#define __caesar_cipher_lib         // works as a 'flag'. Once it's set (once __caesar_cipher_lib' has been #defined
                                    // any other #include "caesar_cipher_lib" will not re-read the definitions below.

#define MAX_STR_LEN 1024*1024
#define SX 50
#define SY 50

void readPGMimage(const char *filename, unsigned char *image_array);
 // This function read the image to be used for encoding/decoding from an image file
 // The image must be in correct .pgm format
 // The image is read into the specified array, and must have a size (SX,SY) - see the #defines at the top.
 //
 // Input arguments:
 //    filename - The name of the input file (including path if needed)
 //    image_array - A pointer to an array where the image will be loaded. Must have the correct size
 //
 // Returns: 
 //    Nothing!
 //
 // Example:
 //   readPGMimage("./my_image.png", &my_array[0][0]);

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], unsigned char passPic[SX][SY]);
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the image in passPic[][] for displacement values.
 //
 // Input arguments:
 //   plaintext - A string of characters to be encoded. Max length is fixed to MAX_STR_LEN
 //   passPic - An array with the image being used to encode the text, must have the right size
 //
 // Returns:
 //   Nothing!
 //
 // Example:
 //   caesar_cipher(&my_text[0],&passPic[0][0]);

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], unsigned char passPic[SX][SY]);
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the passPic[][]
 //
 // Input arguments:
 //   plaintext - A string of characters to be decoded. Max length is fixed to MAX_STR_LEN
 //   passPic - An array with the image being used to encode the text, must have the right size
 //
 // Returns:
 //   Nothing!
 //
 // Example:
 //   caesar_decipher(&my_text[0],&passPic[0][0]);}

#endif
