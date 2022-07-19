# Apparmor

- Apparmor is a Mandatory Access Control system which is a kernel enhancement to confine programs to a limited set of resources.
- Linux security module that protects an OS and its applications from security threats.
- to bind access control attributes to programs rather than to users.
- This proactive approach helps protect the system against both known and unknown vulnerabilities

# LVM(Local Volume Manager for Linux operating system)

- LVM provides a higher-level view of the distk storage on a computer system than the traditional view of disks and partitions.
  - gives flexibility in allocating storage to applicant and users.
- Storage volumes created under the control of the LVM can be resized and moved around almost at will.
- 3 concepts that LVM manages
  - Volume Groups
    - a named collection of physical and logical volumes
  - Physical Volumes
    - disks
    - block devices that provide the space to store logical volumes
  - Logical Volums
    - partitions
    - hold a file system
- snapshots
  - can not do without LVM
  - it allows you to freeze an existing Logical Volume in time, at any moment, even while the system is running.
  - you can continue to use the original volume normally
  - you can use this to get a consistent filesystem image to back up, without shutting down the system.
  - you can use it to save the state of the system, so that you can later return to that state.
  - To create a snapshot of the bar Logical Volume and name it snap.
 ```sudo lvcreate -s -n snap -L 5g foo/bar```
  - this will create a snapshot named snap of the original Logical Volume bar and allocate 5GB of space for it.
 >ref : <https://wiki.ubuntu.com/Lvm>

# Volume

- logical drive(e.g. hard drive)
  - has a single file system and is usually on a single partition

# apt vs aptitude

>ref: <https://www.fosslinux.com/43884/apt-vs-aptitude.htm#:~:text=The%20first%20difference%20you%20will,by%20both%20of%20the%20tools>.

- popular tools when it comes to handling packages
  - search, removal, installation of packages

## What is APT?

Advanced Packaging Tool

- open source tool
- designed to handle software installation and removal
- cmd line tool
- to use apt
  - need to provide the package name
  - the package shoul have its sources specified in the '/etc/apt/sources.list'
    - it should contain all the dependencies list that the package needs to install automatically
    - when using apt command, it will not only download and install the required dependencies
      - user doesn't need to worry about the package dependencies.

## What is Aptitude?

Ncurses and command-line based front-end to numerous Apt libraries.

- Ncurses(new curses)
  - programming library providing an API, allowing the programmerr to write text-based user interfaces(TUI)
  - optimizes screen changes, in order to reduce latency experieced when using remote Unix shell.

Advanced Packaging Tool

- front-end tool
  - gives users access to the UI to access functionallity
- `sudo apt install aptitude`
- can emulate most of the apt-get's command line.

## Difference between APT and Aptitude

level

- APT : lower-level package manager
  - can be used in other highe-lv package manageer
- Aptitude : high-lv package manager

functionality offered by both of the tools

- Aptitude offers better functionality compared to apt-get
  - Aptitude contains the functionalities of apt-get, apt-mark and apt-cache
  - Aptitude can be used for more functionality
    - package search
    - setting package installation

Both are capable of providing the necessary means to do package management. However, if you are loocking for a feature-rich approach, Aptitude is better.

- feature-rich
  - when a software has many options and functional capabilities
  - but when it is overly feature-rich
    - feature creep
    - software bloat

# SELinux

Security-Enhanced Linus

- a security architecture for Linux systems that allows administrators to have more control over who can access the system.
- When an application or process, known as a subject, makes a request to access an object, like a file, SELinux checks with an access vector cache(AVC), where permissions are cached for subjects and objects.
- if SELinux is unable to make a dicision about access based on the cached permissions, it sends the security context of the app or process and the file.
  - Securityy context is applied from the SELinux policy DB.
  - Permission is then granted or denied.

# SSH

SSH is a software package that enables secure system administration and file transfers over insecure networks

## The SSH protocol

The SSH protocol

- a method for secure remote login from one computer to another
- a secure alternative to the non-protected login protocols and insecure file transfer methods.
- uses to secure the connection between a client and a server.
  - all protected against attacks in the network
    - user authentication
    - commands
    - output
    - file transfers

## How does SSH Work?

>ref : <https://phoenixnap.com/kb/ssh-to-connect-to-remote-server-linux-or-windows>

two things to establish an SSH connection

- a SSH client
  - an aplication you install ont the computer
    - you will use to connect another computer or a server
  - the client uses the provided remote host information to initiate the connection
    - if the credentials are verified, established the encrypted connection
- the corresponding server-side component
  - SSH daemon
    - constantly listening to a specific TCP/IP port for possible client connection requests.
    - once a client initiates a connection, the SSH daemon will respond with the software and the protocol versions it supports and the two will exchange their identification data.
      - if the provided credentials are correct, SSH creates a new session for the appropriate environment.

## How to enable an SSH connection

to enable an SSH connection

- you need to make sure they(client, server component) are installed on the local and the remote machine, respectively.
  - OpenSSH

## How to install an OpenSSH Client

Many Linux distributions already have an SSH client

To check if the client is available on your Linux-based system

1. Load an SSH terminal
2. Type SSH
3. if the client is installed, you will receive a response like this

```
username@host:~$ ssh

usage: ssh [-1246AaCfGgKkMNnqsTtVvXxYy] [-b bind_address] [-c cipher_spec]
[-D [bind_address:]port] [-E log_file] [-e escape_char]
[-F configfile] [-I pkcs11] [-i identity_file]
[-J [user@]host[:port]] [-L address] [-l login_name] [-m mac_spec] [-O ctl_cmd] [-o option] [-p port] [-Q query_option] [-R address] [-S ctl_path] [-W host:port] [-w local_tun[:remote_tun]]
[user@]hostname [command]

username@host:~$
```

- this means that you are ready to remotely connect to a physical or virtual machine
  - if it is not
    - you will have to install the OpenSSH client

To install OpenSSH client

```
sudo apt-get install openssh-client
```

From now on, you are able to SSH into any machine with the server-side application on it.

## How to install an OpenSSH Server

In oreder to accept SSH connections, a machine needs to have the server-side part of the SSH software toolkit.

To check if OpenSSH server is available one the system of the remote computer that needs to accept SSH connections.

```
ssh localhost
```

- the systems without the SSH server installed the response will look like this

```
username@host:~$ ssh localhost
ssh: connect to host localhost port 22: Connection refused username@host:~$Copied!
```

- if the above is the case

```
sudo apt-get install openssh-server ii.
```

- the required support files will be installed

To check if the SSH server is running on the machine

```
sudo service ssh status
```

When the SSH service is now running

```
username@host:-$ sudo service ssh status
• ssh.service - OpenBSD Secure Shell server
Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enab
Active: active (running) since Fr 2018-03-12 10:53:44 CET; 1min 22s ago Process: 1174 ExecReload=/bin/kill -HUP $MAINPID (code=exited, status=0/SUCCES
Main PID: 3165 (sshd)
```

another way to test if the OpenSSH server is installed.

```
username@host:~$ ssh localhost

The authenticity of host 'localhost (127.0.0.1)' can't be established. ECDSA key fingerprint is SHA256:9jqmhko9Yo1EQAS1QeNy9xKceHFG5F8W6kp7EX9U3Rs. Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'localhost' (ECDSA) to the list of known hosts.

username@host:~$
```

## How to connect via SSH

Open the SSH terminal on your machine and run the following command

```
ssh your_username@host_ip_address
```

If the computer you are trying to remotely connect to is on the same network

- it is best to use private IP instead of the public IP address
  - otherwise, you will have to use the public IP address only
- make sure
  - correct TCP port
  - correct port forwarding settings
- default port for SSH is 22

```
username@machine:~$ ssh phoenixnap@185.52.53.222 –p7654 

phoenixnap@185.52.53.222’s password:
The authenticity of host '185.52.53.222 (185.52.53.222)' can't be established. ECDSA key fingerprint is SHA256:9lyrpzo5Yo1EQAS2QeHy9xKceHFH8F8W6kp7EX2O3Ps. Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added ' 185.52.53.222' (ECDSA) to the list of known hosts.

username@host:~$
```

- if it works
  - you are now able to manage and control a remote machine using your terminal

# TTY

>ref : <https://itsfoss.com/what-is-tty-in-linux/>

Teletypewriter

When it comes to Linux

- TTY is an abstract device in Linux and Unix.
  - sometimes it refers to a physical input device such as a serial port
  - sometimes it refers to a virtual TTY where it allows users to interact with the system

TTY

- a subsystem in Linux and Unix
  - makes process management, line editingm and session management possible at the kernel level through TTY drivers.
- whenever you launch a terminal emulator or use any kind of shell in your system
  - it interacts with virtual TTYs

## How to access TTY in Linux?

You can TTY screen by using following keyboard shortcuts.

```
CTRL + ALT + F1 – Lockscreen
CTRL + ALT + F2 – Desktop Environment
CTRL + ALT + F3 – TTY3
CTRL + ALT + F4 – TTY4
CTRL + ALT + F5 – TT5
CTRL + ALT + F6 – TTY6
```

- you can access up to six TTYs in total
  - first two shortcuts point to the lock screen and desktop environment
  - with the rest of the shortcuts, you can get command-line interface

When you type in TTY in your terminal emulator, it will print name of the terminal connected to the standard input, as described by the man page.

- in other words, to know the TTY number you are connected to, just type in TTY.

`who`

- If there are multiple users connected to the Linux machine remotely, you can use `who` command to check what other users are connected to.

---

# CPU(Physical processor) vs vCPU(Virtual processor)

## What is a vCPU?

vCPU

- the abbreviation for virtual centralized processing unit.
- a portion or sare of the underlying, physical CPU that is assigned to a particular virtual machine.

Terms related to virtual servers

- Hypervisor
  - software used to create and run virtual machines
  - hypervisors are smart enough to allocate resources whether a single vCPU or numerous vCPUs.
- Socket
  - a socket is an array of pins that hold a processor in place and connect the motherboard to the available processing power.
  - the number of sockets is determined by the capacity of the motherboard.
- Thread
  - a path of execution within a process
  - a process contains one or more threads
    - difference between a process and a thread
      - threads within the same process run in shared memory space
      - processes run in seperate memory spaces
- Physical Core
  - processing units
  - a single physical core may correspond to one or more logical cores.
- Logical Core
  - A logical core makes it possible for a single physical core to perform two or more actions simultaneously.
  - made the concept of hyper-threading(HTT) possible
    - Hyper-threading
      - intel's proprietary simultaneous multithreading implementation and was used to improve parallization of computations performed on x86 microprocessors
      - important to virtualization
        - made it possible for the CPU to work on two tasks simultaneously.

## How Does a vCPU work?

Hypervisor

- controls virtual servers and their resource allocation.
- uses a portion of the physical CPU computing resources.
- allocates the portion to a vCPU which is assigned to a specific VM.

## The math behind calculating vCPU

(Threads x Cores) x Physical CPU = Number vCPU

### Examplee calculation of vCPU & Cores

(16 Threads x 8 Cores) x 1 CPU = 128 vCPU

---

# MAC(Medium Access Control)

MAC

- a sublayer of the data link layer(DLL) of the open system interconnections(OSI) reference model for data transmission.
- responsible for flow control and multiplexing for transmission medium.
  - flow control
    - the management of the data flow between computers or devices or between nodes in a network
      - so that the data can be handled at an efficient pace.
    - too much data arriving before a device can handle it causes data overflow.
  >ref : <https://www.techtarget.com/whatis/definition/flow-control>
  - multiplexing
    - a technique used to combine and send the multiple data streams over a single medium.
      - the process of combining the data streams is known as multiplexing
      - the hardware used for multiplexing is known as a multiplexer(MUX).
        - many-to-one
    - why multiplexing?
      - the transmission medium is used to send the signal from sender to receiver.
        - the medium can only have one signal at a time
        - when multiple signals share the common medium, there is a possibility of collision
          - multiplexing concept is used to avoid such collision
    - multiplexing techniques
      - Frequency-division Multiplexing(FDM)
      - Wavelength Division Multiplexing(WDM)
      - Time Division Multiplexing(TDM)
  >ref : <https://www.javatpoint.com/multiplexing-in-computer-network>
- controls the transmission of data packets via remotely shared channels
- it sends data over the network interface card.
- functions of MAC layer
  - performs multiple access resolutions when more than one data frame is to be transmitted.
    - it determines the channel access methods for transmission
  - performs collision resolution and initiating retransmission in case of collisions
  - generates the frame check sequences and thus contributes to protection against transmission errors.
    - frame check sequences(FCS)
      - refers to the extra bits and characters added to data packets for error detection and control
      - Network data is transmitted in frames.
        - each frame is comprised of bits of data appended to the header
          - the header holds basic information such as source and destination media access control (MAC) and application
        - when data is transmitted in a frame, a specific FCS is added to the frame's data bits.
      - The source calculates the FCS prior to sending a frame, which is verified and compared at the destination.
      - if the FCS data matches, the transmission is considered successful.
      - if the FCS data doesn't match, the data frame is automatically discarded due to error.
   >ref : <https://www.techopedia.com/definition/24793/frame-check-sequence#:~:text=Frame%20Check%20Sequence-,What%20Does%20Frame%20Check%20Sequence%20Mean%3F,data%20is%20transmitted%20in%20frames>.
- MAC addresses
  - a unique identifier allotted to a network interface controller(NIC) of a device.
    - NIC
      - a circuit board installed in a computer that provides a dedicated network connection to the computer.
      - allows communications between computers connected via local area network(LAN) as well as communications over large-scale network through Internet Protocol(IP).
      - is both a physical layer and a data link layer device
   >ref : <https://www.tutorialspoint.com/what-is-network-interface-card-nic>
  - it is used as a network address for data transmission within a network segment like Ethernet, Wi-Fi and Bluetooth.
  - is assigned to a network adapter at the time of manufacturing.
  - e.g.) 00:0A:89:5B:F0:11

>ref : <https://www.tutorialspoint.com/medium-access-control-sublayer-mac-sublayer>

---

# UFW (Uncomplicated Firewall)

ufw provides a user friendly way to create an IPv4 or IPv6 host-based firewall

- by default, UFW is disabled
- easy to use
- is available by default in all Ubuntu installations after 8.04LTS.

>ref : <https://help.ubuntu.com/community/UFW>

---

# Linux kernel

the core of the OS

the main component of a Linux OS and is the core interface between a computer's hardware and its processes.

- it exists within the OS and controls all the major functions of the hardware.

## What the kernel does

Memory management

- keep track of how much memory is used to stroe what, and where

Process management

- Determine which processes can use the CPU, when, and for how long

Device drivers

- Act as mediator between the hardware and processes

System calls and security

- Receive requests for service from the processes

Kernel interacts with the aplications through a system call interface(SCI).

---

