# Project 2
**Course:** COP4610: Operating Systems  
**Due Date:** Monday, March 23rd, 2026, at 11:59pm  

## Project Objectives
- Gain hands-on experience with system calls.  
- Explore kernel programming and kernel modules.  
- Enhance knowledge of concurrency and synchronization in the Linux kernel.  
- Implement a scheduling algorithm for an elevator system.  

## Group Members
- [Noah Seay]: [njs23c@fsu.edu]  
- [Member Name]: [School Email]  
- [Member Name]: [School Email]  

## Division of Labor
### System Call Tracing
- **Responsibilities:** [Description]  
- **Assigned to:** [Noah Seay]  

### Timer Kernel Module
- **Responsibilities:** [Description]  
- **Assigned to:** [Member(s)]  

#### Adding System Calls
- **Responsibilities:** [Description]  
- **Assigned to:** [Noah Seay + Amadou Landoure]  

#### Kernel Compilation
- **Responsibilities:** [Description]  
- **Assigned to:** [Member(s)]  

#### Threads
- **Responsibilities:** [Description]  
- **Assigned to:** [Member(s)]  

#### Linked List
- **Responsibilities:** [Description]  
- **Assigned to:** [Noah Seay]  

#### Mutexes
- **Responsibilities:** [Description]  
- **Assigned to:** [Member(s)]  

#### Scheduling Algorithm
- **Responsibilities:** [Description]  
- **Assigned to:** [Noah Seay + Lucas Compton + Amadou Landoure]  

## File Listing
```
cop4610-project2/
│
├── part1/
│   ├── empty.c
│   ├── empty.trace
│   ├── part1.c
│   ├── part1.trace
│   └── Makefile
│
├── part2/
│   ├── src/
│   └── Makefile
│
├── part3/
│   ├── src/
│   ├── Makefile
│   ├── syscalls.c
│   └── Makefile
│
└── README.md
```
- **part1:** Contains system call tracing files  
- **part2:** Contains timer kernel module source files  
- **part3:** Contains elevator kernel module and system calls  

## How to Compile & Execute

### Requirements
- Compiler: `gcc`  
- Kernel Version: Linux kernel 6.16.x  

### Part 1: System Call Tracing
**Compilation**
```bash
cd part1
gcc -o empty empty.c
gcc -o part1 part1.c
```
**Execution**
```bash
strace -o empty.trace ./empty
strace -o part1.trace ./part1
```

### Part 2: Timer Kernel Module
**Compilation**
```bash
cd part2
make
```
**Insert Module**
```bash
sudo insmod my_timer.ko
```
**View Output**
```bash
cat /proc/timer
```
**Remove Module**
```bash
sudo rmmod my_timer
```

### Part 3: Elevator Kernel Module
**Compile Modified Kernel**
```bash
make menuconfig
make -j$(nproc)
sudo make modules_install
sudo make install
sudo reboot
```
**Verify Kernel Installation**
```bash
uname -r
```
**Test System Calls**
```bash
cd part3
make
sudo insmod syscalls.ko
./test_syscalls
```
**Compile Elevator Module**
```bash
cd part3
make
```
**Insert Elevator Module**
```bash
sudo insmod elevator.ko
```
**View Elevator Status**
```bash
cat /proc/elevator
```
**Remove Elevator Module**
```bash
sudo rmmod elevator
```
**Test Elevator**
```bash
./consumer --start
./producer [number_of_passengers]
./consumer --stop
```

## Development Log
**Each member records their contributions here.**

[Member 1]  
| Date       | Work Completed / Notes |
|-----------|-----------------------|
| YYYY-MM-DD | [Description]         |
| YYYY-MM-DD | [Description]         |

[Member 2]  
| Date       | Work Completed / Notes |
|-----------|-----------------------|
| YYYY-MM-DD | [Description]         |
| YYYY-MM-DD | [Description]         |

[Member 3]  
| Date       | Work Completed / Notes |
|-----------|-----------------------|
| YYYY-MM-DD | [Description]         |
| YYYY-MM-DD | [Description]         |

## Meetings
| Date       | Attendees         | Topics Discussed | Outcomes / Decisions |
|-----------|-----------------|-----------------|--------------------|
| YYYY-MM-DD | [Names]         | [Discussion]    | [Outcome]           |
| YYYY-MM-DD | [Names]         | [Discussion]    | [Outcome]           |

## Bugs
[Describe any known bugs or write “No known bugs”]  

## Extra Credit
[If applicable]  

## Considerations
- All source files are organized into their required directories  
- No binaries or compiled kernel modules are included in the repository


