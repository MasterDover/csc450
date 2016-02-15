#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif
/* Allow "cc -D" to override definition */
int main(int argc, char *argv[])
{
  int inputFd, outputFd, openFlags; mode_t filePerms;
  ssize_t numRead;
  char buf[BUF_SIZE];
  FILE *inputFp, *outputFp;
  int total;


  /* Open input and output files */
  inputFd = open(argv[1], O_RDONLY);
  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw- */
  outputFd = open(argv[2], openFlags, filePerms);



if (inputFp = fopen(argv[1], "r"))    
    {
  outputFp = fopen(argv[2], "w+");
  char nextChar = getc(inputFp);
  int numCharacters = 0;
  while (nextChar != EOF) {
    numCharacters++;
    nextChar = getc(inputFp);
  }
  total = numCharacters;
  fseek(inputFp, -1, SEEK_END);

  for (int j = total; j >= 0; j--) {
    char currChar = fgetc(inputFp);
    fseek(inputFp, -2, SEEK_CUR);
    fputc(currChar, outputFp);
  }
}
  /* Transfer data until we encounter end of input or an error 
  while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
  {
    
    if (write(outputFd, buf, numRead) != numRead)
    {
      printf("ouch\n");
    }
    count--;
  }
  */
  close(inputFd);
  close(outputFd);
  exit(EXIT_SUCCESS);
}