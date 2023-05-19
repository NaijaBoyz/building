#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t pid = getpid();
  printf("My PID is %d\n", pid);
  return 0;
}
