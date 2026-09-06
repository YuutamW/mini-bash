#include "structure.h"

// out_fd is assumed already opened, prompt_title & size initialized 
int print_prompt(int out_fd,const char* prompt_title, size_t prompt_size) {
    size_t total_written = 0;
    /* Loop until the entire title is written to fd */
    while(total_written < prompt_size) {
        // attempt to write the remaining bytes
        ssize_t bytes_wrritten = write(out_fd,prompt_title,prompt_size);
        // error handling
        if(bytes_wrritten == -1) {
            if(errno == EINTR) continue; // syscall was interrupted - try again
            else {perror("prompt_title write error"); return -1;}
        }
        total_written += bytes_wrritten; // advance tracker of bytes successfully written
    }
    return 0;
}

// in_fd is assumed to be open already, input buf & size asumed initialized 
int read_input(int in_fd, char* input_buf, int in_buf_size) {
    ssize_t bytes_read = 0;

    /* Loop Only if an interrupt occurred during the read syscall: */
    do
    {
        // leave 1 byte for the null terminator char
        bytes_read = read(in_fd , input_buf , in_buf_size - 1);
    } while (bytes_read == -1 && errno == EINTR);
    
    /* Error handling */
    if(bytes_read == -1) {
        perror("read input error");
        return -1;
    }

    /* handle the EOF (user pressed enter) */
    if(bytes_read == 0) return 0;

    /* Null terminate the string */
    input_buf[bytes_read] = '\0';

    /* Strip the trailing newline character (\n) */
    if (bytes_read > 0 && input_buf[bytes_read - 1] == '\n') {
        input_buf[bytes_read - 1] = '\0';
    }

    return bytes_read;
}


