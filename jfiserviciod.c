#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <stdlib.h>
#include <sys/types.h>
#include <err.h>
#include <syslog.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(){
  
  //DAEMON PART*************************************
  pid_t pid, sid;

  //Fork the Parent Process
  pid = fork();

  if (pid < 0) { exit(EXIT_FAILURE); }

  //We got a good pid, Close the Parent Process
  if (pid > 0) { exit(EXIT_SUCCESS); }

  //Change File Mask
  umask(0);

  //Create a new Signature Id for our child
  sid = setsid();
  if (sid < 0) { exit(EXIT_FAILURE); }

  //Change Directory
  //If we cant find the directory we exit with failure.
  if ((chdir("/")) < 0) { exit(EXIT_FAILURE); }

  //Close Standard File Descriptors
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  //DAEMON PART*************************************
  
  time_t inicial;
  time_t actual;
  int segundos;
  time(&inicial);
  FILE* hola = fopen("/home/julio/Desktop/hola","w");
  fputs(asctime(localtime(&inicial)),hola);
  fclose(hola);
  while(1){
    time(&actual);
    segundos = (int) difftime(actual,inicial);
    FILE* hola = fopen("/home/julio/Desktop/hola","w");
    fprintf(hola,"Hora actual: %sTiempo que el servicio ha estado encendido: %d",asctime(localtime(&actual)),segundos);
    fclose(hola);
    sleep(2);
  }
  return 0;
}

//   memoria->tiempo = (int) difftime(actual,inicial);