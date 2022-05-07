#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MYFILE "book.toml"
#define FILEMODE "r"

int main(int argc, char **argv) {
  // argc denotes the size of total memory denoting the command line arguments
  // argv is a pointer to start of characters that represent the command line
  // arguments
  puts("Hello World"); // pushing char array to standard out

  // creating file descriptor
  char *filename = "book.toml";
  char *filemode =
      "r"; // check documentation or page 151 for more file opening flags
  FILE *toml = fopen(filename, filemode);
  if (toml == NULL) {
    puts("File could not be opened");
  } else {
    puts("File does indeed exist");
    fclose(toml);
  }
  // Using POSIX function
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // read documentation in POSIX open function
  const char *pathname = "/tmp/file";
  if ((fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1){
    fprintf(stderr,"Can't open %s.\n", pathname);
    return EXIT_FAILURE;
  }else{
    puts("File opened properly");
    return EXIT_SUCCESS;
  }
}
