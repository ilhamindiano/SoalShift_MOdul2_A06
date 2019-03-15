
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int check(const char *filename)
{
  FILE *file;
  if ((file = fopen(filename, "r")))
  {
    fclose(file);
    return 1;
  }
  return 0;
}

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    // main program here
if (check("/home/hafidzasqalany28/modul2/haitku/elen.ku"))
{
   char permission[]="0777";
   char buf[100] = "/home/hafidzasqalany28/modul2/hatiku/elen.ku";
   int n;
   n = strtol(permission, 0, 8);
   chmod (buf,n);
   struct stat info;
   stat("home/hafidzasqalany28/modul2/hatiku/elen.ku", &info);
   struct passwd *pw = getpwuid(info.st_uid);
   struct group *gr = getgrgid(info.st_gid);
   if (strcmp (pw->pw_name, "www-data") == 0 && strcmp (gr->gr_name, "www-data") == 0){
      remove("/home/hafidzasqalany28/modul2/hatiku/elen.ku");
   }
}
 sleep(10);
  }
  
  exit(EXIT_SUCCESS);
}
