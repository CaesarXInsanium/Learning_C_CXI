#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MYFILE "book.toml"
#define FILEMODE "r"

int main(int argc, char **argv) {

  // creating file descriptor
  char *filename = "book.toml";
  char *filemode =
      "r"; // check documentation or page 151 for more file opening flags
  FILE *toml = fopen(filename, filemode);
  if (toml == NULL) {
    puts("File could not be opened");
  } else {
    puts("File does indeed exist");
    // always good practice to close file after finishing with them in order to
    // save resources
    fclose(toml); // even this function can fail
  }
  // Using POSIX function
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP |
                S_IROTH; // read documentation in POSIX open function
  const char *pathname = "/tmp/file";
  if ((fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1) {
    fprintf(stderr, "Can't open %s.\n", pathname);
  } else {
    puts("File opened properly");
    close(fd); // defined
  }
  printf("\n");

  // Writing and Reading
  char *testfile = "testfile.txt";
  char *testmode = "rw";
  FILE *test = fopen(testfile, testmode);
  if (test == NULL) {
    puts("test file could not be found");
    return EXIT_FAILURE;
  }
  int success = fputs("This is a stupid file", test);
  if (success == EOF) {
    puts("Writing to Stream failed");
  }
  fputc(80, test); // write character to file
  if (fseek(test, 0, SEEK_END) != 0) {
    fputs("Seek to end of file failed\n", stderr);
    return EXIT_FAILURE;
  }
  long int fpi = ftell(test);
  if (fpi == -1) {
    perror("Tell");
    return EXIT_FAILURE;
  }
  fflush(test);
  printf("File Position: %ld\n", fpi);
  if (fclose(test) == EOF) {
    fputs("Failed to close file\n.", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
