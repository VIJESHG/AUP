# Advanced UNIX Programing

Below is the list of some of system programs that I have written while doing my academic assignments:  

 1. **File I/O (Lab1)**
   - Implement `lseek` behaviour using system calls like `open(), close(), read(), write(), creat() etc.`.
 
 2. **Files and Directories (Lab2)**
   - Use of APIs like `opendir(), file stat structure, readdir(), mkdir(), chmod(), chdir(), etc.`. 
   - Implementation of  `realpath()` behaviour file stat structure information and other APIs available.
   - Create a shared directory for usage with a purpose that any user (not super user) can create new files in this directory, but only the owner can delete his own files and everyone else can read all files.
 
 3. **File I/O & File Stat (Lab3)**
   - Using `dup()` function redirect `stdin` to file1 and `stdout` to file2. Read a line using `scanf` and
`write` the same using `printf`. Verify the contents of both files. 
   - `stat()` function behaviour.
   - Understanding `umask()` function.
 
 4. **Process Environment (Lab4)**
   - Understanding `environment variables`, adding and removing `environment variables`.
   - Observing variable states after calling `setjmp() and longjmp()`.
 
 5. **Process Control (Lab5)**
   - A program to demostate, A child process inherits real `user id`, `real group id`, `effective user id` and `effective group id` of the parent process, while `process id` and `parent process id` are not.
   - A program to Verify whether it is possible for a child process to handle a file opened by its parent
Immediately after the `fork()` call.
   - Child and Parent behaviour after calling `fork()`.
 
 6. **Process Control-Threding (Lab6)**
   - Write A program to take input from user for number of files to be scanned and word to be
searched. write a multi threaded program to search the files and return pattern if found.
   - A program to find number of CPUs, create that many threads and attach those
threads to CPUs.
   - 
 
 7. **Process Control-Inheritance (Lab7)**
   - Program to demostrate, the child `exec` call inherits the file descriptors of parent if `Close_on_exec` is not set.
   - Creating different processes using `fork()` for commands read from file.
   - Use of `SETUID` for managing permissions.
 
 8. **Process Control-Waiting (Lab8)**
   - Understanding `wait()` system call.
   - Call `fork()`. Let the child create a new session. Verify that the child becomes the process group
leader and it does not have a controlling terminal.
   - A program to verify that a parent process can change the process `group ID` of one of
its children before the child performs an `exec()`, but not afterward.
 
 9. **Signals (Lab9)***
   - Playing with different signal mechanisms.
 
