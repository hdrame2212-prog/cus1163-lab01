#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {
    // TODO: Declare an integer 'fd' for the file descripton
       int fd;
    // TODO: Declare a variable 'bytes_written' of type ssize_t to store how many bytes are written.
      ssize_t bytes_written;
    // TODO: Print a message showing which file is being created.
       printf("Creating file: %s\n", filename);

    // TODO: Print a message showing what content will be written.
        printf("Writing content: %s\n", content);
    // TODO: Open or create the file for writing using the open() system call.
    // TODO: Use flags O_CREAT | O_WRONLY | O_TRUNC and permissions 0644.
       fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
        if (fd == -1) {
        perror("Error opening file");
        return -1;
    }
    // TODO: Print the file descriptor value.
       printf("File descriptor: %d\n", fd);

    // TODO: Write the content to the file using the write() system call.       
    // TODO: Use the length of 'content' as the size to write.
       bytes_written = write(fd, content, strlen(content));

    // TODO: Check if write() failed (bytes_written == -1). If so, print an error using perror, close the file, and return -1.
       if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return -1;
    }
    // TODO: Print a success message with the number of bytes written and the filename.
       printf("Wrote %zd bytes to '%s'\n", bytes_written, filename);

    // TODO: Close the file using close(fd).
       int close_status = close(fd);

    // TODO: Check if close() failed. If so, print an error using perror and return -1.
       if (close_status == -1) {
        perror("Error closing file");
        return -1;
    }
    // TODO: Print a message that the file was closed successfully.
       printf("File '%s' closed successfully.\n", filename);
    return 0;
}

int read_file_contents(const char *filename) {
    // TODO: Declare an integer 'fd' for the file descriptor.
       int fd;
    // TODO: Create a buffer array of size 1024 to store the file data.
       char buffer[1024];
    // TODO: Declare a variable 'bytes_read' of type ssize_t to store how many bytes are read.
       ssize_t bytes_read;
    // TODO: Print a message showing which file is being read.
       printf("Reading file: %s\n", filename);
    // TODO: Open the file for reading using the open() system call.
    // TODO: Use the O_RDONLY flag.
       fd = open(filename, O_RDONLY);
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
       if (fd == -1) {
        perror("Error opening file");
        return -1;
    }
    // TODO: Print the file descriptor value.
       printf("File descriptor: %d\n", fd);
    // TODO: Print a header for the file contents.
       printf("=== File Contents ===\n");
    // TODO: Read the file contents using the read() system call in a loop.
    // TODO: Use sizeof(buffer) - 1 for the buffer size.
       while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
    // TODO: Null-terminate the buffer after each read.
       buffer[bytes_read] = '\0';
    // TODO: Print the contents of the buffer.
       printf("%s", buffer);
    // TODO: Continue reading until read() returns 0.
       }
    // TODO: Check if read() failed (bytes_read == -1). If so, print an error using perror, close the file, and return -1.
       if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return -1;
    }
    // TODO: Print a footer for the end of the file.
       printf("\n=== End of File ===\n");

    // TODO: Close the file using close(fd).
       int close_status = close(fd);
    // TODO: Check if close() failed. If so, print an error using perror and return -1.
       if (close_status == -1) {
        perror("Error closing file");
        return -1;
    }
    // TODO: Print a message that the file was closed successfully.
       printf("File '%s' closed successfully.\n", filename);
    return 0;
}
