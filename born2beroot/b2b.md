# 프로젝트 조건

- X.org 설치 금지
- 다른 그래픽 서버를 사용할 수 없다.

# partitioning with an encrypted LVM
- LVM volume을 열기 위해서는 encryption key를 매번 reboot할 때마다 입력해야 한다.
  - encryption key는 잘 유지해야 한다. 절대로 찾기 불가능

# Apparmor
- Apparmor is a Mandatory Access Control framework. When enabled, Apparmor confines programs arrcording to a set of rules that specify what files a given program can access.
- This proactive approach helps protect the system against both known and unknown vulnerabilities

# LVM(Local Volume Manager for Linux operating system)
- LVM provides a higher-level view of the distk storage on a computer system than the traditional view of disks and partitions.
  - gives flexibility in allocating storage to applicant and users.
- Storage volumes created under the control of the LVM 
  - can be resized and moved around almost at will.

# Volume
- logical drive(e.g. hard drive)
  - has a single file system and is usually on a single partition

# apt vs aptitude
>ref: https://www.fosslinux.com/43884/apt-vs-aptitude.htm#:~:text=The%20first%20difference%20you%20will,by%20both%20of%20the%20tools.

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


