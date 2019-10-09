/* This program program will create a parent and child where the parent process will
read X and the child process will read Y
 child process will send Y to parent process by
communicating parent process through a pipe.Then the parent process will
add Y to X and produce the sum*/
//Written by Ositadinma Arimah
//250 981 235
//oarimah@uwo.ca

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int x,y,pipeline,fd[2],sum;
    pid_t pid;

    if(argc != 3) {//check the number of requirements
        printf("Error: 2 Arguments required\n");
        exit(1);
    }
    if(pipe(fd) < 0) {//handle the pipe error, else create a pipe connection
        perror("pipe error");
        exit(0);
    }
    printf("A pipe is created for communication between parent (PID %d) and child\n", getpid());
    pid = fork();//create the child process
    if (pid < 0) {//handle the fork error if fork is unsuccessful
        perror("fork error");
        exit(0);
    }
    if (pid > 0) {//if the pid is a parent process
        printf("parent (PID %d) create a child (PID %d) \n", getpid(), pid);
        printf("parent (PID %d) Reading X = 10 from the user \n", getpid());
        wait(NULL);
        x = atoi(argv[1]);//use atoi to take in first argument and convert to int; store as X
        read(fd[0], &pipeline, sizeof(pipeline));//read in the variable into the pipeline
        printf("parent (PID %d) Reading Y from the pipe (Y = %d) \n", getpid(), pipeline);
        sum = x + pipeline;//get the sum of the two variables
        printf("parent (PID %d) adding X + Y = %d \n", getpid(), sum);
    } else {// if pid is the child process
        printf("child (PID %d) Reading Y = 20 from the user \n", getpid());
        y = atoi(argv[2]);//use atoi to take in the second argument and convert to int; store as Y
        printf("child (PID %d) Writing Y into the pipe \n", getpid());
        write(fd[1], &y, sizeof(y));// write in the y variable into the pipe
    }
    return 0;
}