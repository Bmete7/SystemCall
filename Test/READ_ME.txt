how to use flagTest.c? 

compile with gcc command ---     gcc -o output flagTest.c

run with root privilage  --- sudo ./output

we have 3 forks in this program
first one creates the child process

and child process creates 2 new processes, which are siblings with each other
NR_mycall system call is setting the value of myFlag of each procecss in their task descriptor

if you give a process the myflag value of 1, and it tries to fork, an error is returned

if you give a process the myflag value of 1, and it tries to exit,it signals all of its siblings for killing.
i.e, a3 process, which are siblings with a2, is equaled with the myflag value of 1
when it exits, it kills its sibling, a2.
