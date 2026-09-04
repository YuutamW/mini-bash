/** 
* This is a header file that includes all necessary libraries and functions/datastruct declerations
*/
#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define BASH_PROMPT "mini-bash$"

/**print prompt: simply outputs the BASH_PROMPT to the stdrd output
 * will return -1 upon error encounter
 */
int print_prompt(int out_fd,const char* prompt, size_t prompt_size);

/**Read Input: will read the input from the input file discriptor, 
 * loaded directly to the passed buffer without unnecessary copying
 *  
 */
int read_input(int in_fd, char const* input_buf, int in_buf_size);




#endif