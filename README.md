### This is a very basic implementation of something like strace in linux

This program forks and spawns a child process with the command name provided in as the command line arguments and traces the syscalls that the program makes

I made it just to learn more about how to do some things in c, there is no intention of making this a proper strace like tool that is usefull to anyone


### dependencies:
 - linux host ( only x86_64 )
 - gcc
 - make

#### Installation instruction:
 - clone the repo
 - run make
 now you have the tracer binary

 
 ### Usage
 after building the executable you can trace any command like strace for example

 `./tracer echo` would output
 
![image](https://github.com/shoccho/traCer/assets/33720947/93653699-d363-44fd-90b5-051a16bf0697)


