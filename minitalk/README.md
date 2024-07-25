```
███    ███ ██ ███    ██ ██     ████████  █████  ██      ██   ██ 
████  ████ ██ ████   ██ ██        ██    ██   ██ ██      ██  ██  
██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██      █████   
██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██      ██  ██  
██      ██ ██ ██   ████ ██        ██    ██   ██ ███████ ██   ██ 
```

## get started :
```
cd /minitalk
make
./server
(in another terminal)
./client <pid printed by server> "message"
```

### 1. What is a SIGNAL ?
- A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to this process.
- A signal is basically a form of inter-process communication (IPC), that is used to notify a process about an event or a condition that has occured.
- There are fix set of signals that can be sent to a process. signal are identified by integers.
Signal number have symbolic names. For example SIGCHLD is number of the signal sent to the parent process when child terminates.

- Examples:
```
#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */
```

### pid (process id) :
- `Process ID Range:` Process IDs are typically assigned by the operating system when a process is created. They are positive integers ranging from 1 to a maximum value determined by the system's architecture and configuration. The maximum PID value can vary between systems but is often limited by the size of the PID data type (e.g., 16-bit, 32-bit, or 64-bit).

- `PID 0:` PID 0 is reserved for the scheduler process, also known as the "swapper" or "scheduler process." This process is responsible for managing system resources and scheduling tasks.

- `PID 1:` PID 1 is typically assigned to the init process, which is the first process started by the kernel during system boot. The init process is responsible for starting and managing other processes, including system services and daemons.

- `Negative PIDs:` Negative values are not used to represent processes in Unix-like systems. If you attempt to use a negative value as a process ID, it would be interpreted as an error or an invalid PID. 

- we use the function getpid() to get the process id.
```
 pid_t pid = getpid();
```

### 2. Kill(): `to send a signal`
- Kill() is system call has two arguments, the pid(process ID) and the signal(signal number), we can use it to send the signal we want to the process we want which is identified by a pid.

### 3. Sigaction or Signal() ? `both are used to catch a signal, handle it. but sigaction is more advanced utility`
#### Sigaction :
- The sigaction structure specifies how to handle a signal.
- Signal handlers and actions are defined for the process and affect all threads in the process. For example, if one thread ignores a signal, then all threads ignore the signal.
The `sa_mask` field indicates any signals that should be blocked while the signal handler is being executed.
The `sa_flags` field determines a number of different things, but the important ones are whether we get the extended information (SA_SIGINFO ) and whether system calls that were interrupted by the signal are automatically restarted (SA_RESTART), The alternative is that the interrupted system calls will fail, so restarting them is obviously a better approach.
The `sa_handler` and sa_sigaction properties of the sigaction interchangeably to handle the sig_handler()function.
The sigaction function handler has a prototype that provides the signal number, information about the signal delivery, and information about the thread context.

- The function `sigaction()` : Examine or specify the action associated with a signal.
```int sigaction(int sig, const struct sigaction * act, struct sigaction * oact);```
- `sig` :
The signal number (defined in <signal.h>). For more information, see “POSIX and QNX Neutrino signals” in the documentation for SignalAction().
If the signal terminates a process, the cleanup of the terminated process occurs by default at the priority of the thread that sent the signal. As a QNX Neutrino extension, if you OR the SIG_TERMER_NOINHERIT flag (defined in <signal.h>) into sig, the cleanup occurs at the priority of the thread that received the signal.
- `act` :
NULL, or a pointer to a sigaction structure that specifies how you want to modify the action for the given signal.
- `oact` :
NULL, or a pointer to a sigaction structure that the function fills with information about the current action for the signal.

- Returns :
0 = Success.
-1 = An error occurred (errno is set).

### Signal() :
- this function is a very basic function to catch signals, it takes also two arguments, the signal(signal number) we want to catch, and the function/handler that will be called once the signal is caught .

### Pause() :
- In C, the function pause() typically suspends the calling process until a signal is received. The loop while (true) pause(); creates an infinite loop that continuously suspends the process until a signal is received.

```
while (true)
    pause();
```

`while (true)`: This sets up an infinite loop because the condition true is always true.
`pause()`: This function causes the calling process to sleep until a signal is received. The process will remain suspended until a signal interrupts the execution of pause().

### Resources :
- [Link 1](https://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html)
- https://www.math.stonybrook.edu/~ccc/dfc/dfc/signals.html#:~:text=A%20signal%20is%20a%20message,send%20it%20a%20SIGHUP%20signal
- https://www.tutorialspoint.com/unix/unix-signals-traps.htm
- https://en.wikipedia.org/wiki/C_signal_handling
- the linux programming interface (book)

### How Minitalk works ?
check this article : https://m4nnb3ll.medium.com/first-time-to-work-with-signals-minitalk-a-42-the-network-project-8bae32237975
