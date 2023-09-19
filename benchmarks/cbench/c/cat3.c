#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#include <fcntl.h>

char *program_name, *infile;
int input_desc, ok = 1;

void
error(int status, int errnum, char *message)
{
  fprintf(stderr, "%s: ", program_name);
  if (errnum)
    perror(message);
  else
    fprintf(stderr, "%s\n", message);
  fflush(stderr);
  if (status)
    exit(status);
  ok = 0;
}

int
main(int argc, char **argv)
{
  size_t insize = 128*1024, page_size = getpagesize(), count, n_rw;
  char *inbuf, *buf, *ptr;
  int argind = 0;

  program_name = argv[argind++];
  infile = "-";
  inbuf = malloc(insize + page_size - 1);
  if (!inbuf)
    error(EXIT_FAILURE, 0, "memory exhausted");
  buf = inbuf + page_size - 1;
  buf = buf - (uintptr_t) buf % page_size;
  do {
    if (argind < argc)
      infile = argv[argind];
    if (*infile == '-' && infile[1])
      error(0, 0, "options not implemented");
    input_desc =
      strcmp(infile, "-") == 0 ? STDIN_FILENO : open(infile, O_RDONLY);
    if (input_desc < 0) {
      error(0, 1, infile);
      continue;
    }
    while (1) {
      count = read(input_desc, buf, insize);
      if (count == (size_t) -1) {
        error(0, 1, infile);
        break;
      }
      if (count == 0)
        break;
      ptr = buf;
      while (count > 0) {
        n_rw = write(STDOUT_FILENO, ptr, count);
        if (n_rw == (size_t) -1)
          break;
        if (n_rw == 0)
          break;
        count -= n_rw;
        ptr += n_rw;
      }
      if (count != 0)
        error(EXIT_FAILURE, 1, "write error");
    }
    if (strcmp(infile, "-") != 0 && close(input_desc) < 0)
      error(0, 1, infile);
  } while (++argind < argc);
  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
