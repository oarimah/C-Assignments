/* This program will create a parent process which will create two child processes (e.g., child_1,
and child_2)
 parent will wait for child_1 to complete before creating child_2
 child_1 will create its own child child_1.1
parent will wait for child_1 to complete before creating child_2child_1 will create its own child child_1.1
Inside child_2, a system call to an external program will be made, and as a result of this external
program call, child_2 will be replaced by external_program.out */
//Written by Ositadinma Arimah
//250 981 235
//oarimah@uwo.ca

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main() {
    pid_t child_one, child_two, child_one_one;

    //create the child_one process
    child_one = fork();

    //error handle if fork is unsuccessful
    if(child_one < 0) {
        printf("fork unsuccessful \n");
        exit(1);
    }
    //is the process is a parent process, enter this if statement
    if(child_one > 0) {
        printf("parent process (PID %d) created child_1 (PID %d) \n", getpid(), child_one);
        wait(NULL);//wait for the other process to complete
        printf("child_1 (PID %d) is now complete \n", child_one);
        child_two = fork(); //create child_two process in parent process
        //this is parent process for child_2
        if(child_two > 0) {
            printf("parent (PID %d) created child_2 (PID %d) \n", getpid(), child_two);
        }
        //error handle if child_two for is unsuccessful
        else if(child_two < 0) {
            printf("fork unsuccessful \n");
            exit(1);
        }
        //if child_two process is a child
        else if(child_two == 0) {
            printf("child_2 (PID %d) is calling an external program external_program.out and leaving child_2 \n", getpid());
            execl("external_program.out", NULL);//read the excel program to read in the file
        }
    }

    //if child_one process is a child
    if(child_one == 0) {
        child_one_one = fork(); //create child_one_one process in child_one process
        if(child_one_one> 0) {//if child_one_one is a parent; enter this if statement
            printf("parent (PID %d) is waiting for child_1 (PID %d) to complete before creating child_2 \n", getppid(), getpid());
            wait(NULL);//wait for child_one_one to complete its process
        }
        else if(child_one_one < 0) {//error handle if child_one_one is unsuccessful
            printf("fork unsuccessful \n");
            exit(1);
        }
        //if child_one_one is a child process
        else if(child_one_one == 0) {
            printf("child_1 (PID %d) created child_1.1 (PID %d) \n", getppid(), getpid());
        }
    }
    return 0;
}