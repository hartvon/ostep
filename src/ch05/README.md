# 05 Interlude: Process API

***5.1 The fork() System Call***

```c
pid_t fork(void)
```
- 用于创建新进程，新创建的子进程不会从 `main()` 函数开始执行，而是直接从 `fork()` 系统调用返回，就好像是它自己调用了 `fork()`。
- 父进程获得的返回值是新创建子进程的 PID，而子进程获得的返回值是 0。
- 输出不是确定的（deterministic），CPU 调度程序（scheduler）决定了某个时刻哪个进程被执行。

***5.2 Adding wait() System Call***

```c
pid_t wait(int *__stat_loc)
__pid_t waitpid(pid_t __pid, int *__stat_loc, int __options)
```
- 由父进程调用，延迟自己的执行，直到子进程执行完毕

***5.3 Finally, the exec() System Call***

```c
int execl(const char *pathname, const char *arg, ...
                       /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ...
                /* (char  *) NULL */);
int execle(const char *pathname, const char *arg, ...
                /*, (char *) NULL, char *const envp[] */);
int execv(const char *pathname, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
                char *const envp[]);
```

上述exec系列函数底层都是通过 `execve()` 系统调用实现
```c
int execve(const char *pathname, char *const argv[], char *const envp[]);
```

- 让子进程执行与父进程不同的程序，对 `exec()` 的成功调用永远不会返回。

  > `exec()` 会从可执行程序中加载代码和静态数据，并用它覆写自己的代码段（以及静态数据），堆、栈及其他内存空间也会被重新初始化。然后操作系统就执行该程序，将参数通过 argv 传递给该进程。

  > `exec()` 并没有创建新进程，而是直接将当前运行的程序替换为不同的运行程序。

***5.4 Why? Motivating the API***

- 以 UNIX shell 举例：这给了 shell 在 fork 之后 exec 之前运行代码的机会。

  > shell 也是一个用户程序，它首先显示一个提示符（prompt），然后等待用户输入。你可以向它输入一个命令（一个可执行程序的名称及需要的参数），大多数情况下，shell 可以在文件系统中找到这个可执行程序，调用 `fork()` 创建新进程，并调用 `exec()` 的某个变体来执行这个可执行程序，调用 `wait()` 等待该命令完成。子进程执行结束后，shell 从 `wait()` 返回并再次输出一个提示符，等待用户输入下一条命令。

***5.5 Other Parts of the API***

- `kill`
- `ps`
- `top`
- ...

***5.6 Summary***

Keep going!

---
***The Creux of The Problem***

- **如何创建并控制进程**

    > 操作系统应该提供怎样的进程来创建及控制接口？如何设计这些接口才能既方便又实用？
