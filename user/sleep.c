#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int 
main(int argc, char *argv[])
{
  if(argc != 2){
    exit(0);
  }
  int sleep_count;
  sleep_count = atoi(argv[1]);
  sleep(sleep_count);
  exit(0);
}