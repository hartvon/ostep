# 02 Introduction to Operating Systems

虚拟化（virtualization）：操作系统将物理（physical）资源（如处理器、内存或磁盘）转换为更通用、更强大且更易于使用的虚拟形式。

> 虚拟化让许多程序运行（从而共享 CPU），让许多程序可以同时访问自己的指令和数据（从而共享内存），让许多程序访问设备（从而共享磁盘等）。

***2.1 Virtualizing the CPU***

- 虚拟化 CPU（virtualizing the CPU）：将单个 CPU（或其中一小部分）转换为看似无限数量的 CPU，从而让许多程序看似同时运行。

***2.2 Virtualizing Memery***

- 虚拟化内存（virtualizing memory）：每个进程访问自己的私有虚拟地址空间（virtual address space），操作系统以某种方式映射到机器的物理内存上。

***2.3 Concurrency***

- 并发（Concurrency）：指代一系列问题，这些问题在同时（并发地）处理很多事情时出现且必须解决。

***2.4 Persistence***
- 持久性（persistency）：使用硬件和软件来存储数据以防止断电或系统崩溃时内存中的所有数据丢失。

***2.5 Design Goals***

- 虚拟化（virtualize）
- 抽象（abstraction）
- 高性能（performance）
- 保护（protection）
- 可靠性（reliability）
- ...

***2.6 Some History***

  「早期操作系统：只是一些库」 --> 「超越库：保护」 --> 「多道程序时代」 --> 「摩登时代」

***2.7 Summary***

Now get to work!

---
***The Creux of The Problem***

1. **如何将资源虚拟化**
   > 操作系统通过哪些机制和策略来实现虚拟化？操作系统如何有效地实现虚拟化？需要哪些硬件支持？

2. **如何构建正确的并发程序**
    > 如果同一个内存空间中有很多并发执行的线程， 如何构建一个正确工作的程序？操作系统需要什么原语？硬件应该提供哪些机制？我们如何利用它们来解决并发问题？

3. **如何持久地存储数据**
    > 文件系统是操作系统的一部分， 负责管理持久的数据。持久性需要哪些技术才能正确地实现？需要哪些机制和策略才能高性能地实现？面对硬件和软件故障， 可靠性如何实现？