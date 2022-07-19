# Sudo

## sudo 설치

sudo를 설치하기 위해 root 계정으로 변경한다.

```
$ su
```

```
$ su -
```
위의 방법 둘 중에 하나를 선택하여 입력한다.

apt 명령어를 사용하여 sudo를 설치한다.

```
$ apt install sudo
```

```
$ apt-get install sudo
```
위의 방법 둘 중에 하나를 선택하여 입력한다.

sudo가 잘 설치되었는지 확인하기 위해 다음의 명령어를 입력한다.

```
$ dpkg -l | grep sudo
```

## sudo group에 user 추가시키기

```
$ adduser <username> sudo
```

```
$ usermod -aG sudo <username>
```

위의 두 방법 중 하나를 선택하여 입력하면 sudo라는 이름을 가진 group에 username이라는 user가 추가된다.

sudo group에 제대로 추가되었는지 확인하기 위해서 다음과 같은 방법을 사용한다.

```
$ getent group sudo
```

아니면 다음과 같이 username이 포함된 모든 그룹들을 열람할 수도 있다.

```
$ groups <username>
```

## sudo 명령어 설정 변경하기

>ref : https://www.sudo.ws/docs/man/1.8.18/sudoers.man/#SUDOERS_OPTIONS

~(root)경로에서 다음의 명령어로 sudoers에 진입한다.

```
$ sudo visudo
```

- 이 명령어를 root directory에 입력한다면 저절로 `/etc/sudoers`로 진입하여 sudo의 설정을 변경할 수 있다.
- 다른 방법으로는 그냥 `/etc` directory에서 sudoers파일을 `sudo vi sudoers`로 열어 편집할 수 있다.
	- 이 방법은 읽기 전용이므로 편집하는데 욕이 많이 나올 것이다.

sudoers 파일에 진입했다면 다음의 코드를 추가하면 된다.

```
Defaults	env_reset
```
- sudo 명령어가 실행될 때 부여되는 작은 환경(environment)이라고 생각하면 된다.
	- 이 환경에는 `TERM`, `PATH`, `HOME`, `MAIL`, `SHELL`, `LOGNAME`, `USER`, `USERNAME`, `SUDO_*` 변수가 포함되어 있다.
- secure_path 기능이 sudoers에 같이 설정되어 있다면, 그 값은 `PATH`에 사용될 것이다.

```
Defaults	mail_badpass
```
- sudo 명령어를 사용하려는 사용자가 password를  계속 틀린다면 mailto로 설정되어 있는 사용자에게 메일을 보내는 기능을 하는 설정이다.

```
Defaults	passwd_tries=3
```
- 비밀번호 시도 횟수를 3번으로 변경

```
Defaults	authfail_message="authentication fail"
```
- 로그인이 실패했을 경우 나오는 메세지 설정

```
Defaults	badpass_message="password fail"
```
- 비밀번호가 틀렸을 경우 나오는 메세지 설정

```
Defaults	iolog_dir="/var/log/sudo/"
```
- I/O log, 즉 로그인에 사용된 input과 output을 저장할 경로를 설정
- log_input과 log_output이 설정되어 있거나 이들이 command line으로 쳤을 경우에만 활성화된다.

>ref : https://www.beyondtrust.com/docs/privilege-management/unix-linux/admin/logging/io-logs.htm


```
Defaults	log_input
```
- 이 설정은 input이 일어났을 시에 iolog에 input의 정보를 입력하는 기능 켜주는 설정이다.

```
Defaults	log_output
```
- 이 설정은 output 일어났을 시에 iolog에 output의 정보를 입력하는 기능 켜주는 설정이다.

```
Defaults	requiretty
```
- requiretty 기능을 켜주는 구문이다.
	- requiretty
		- requiretty 기능이 있다면, sudo는 로그인 되어있는 상태의 터미널 세션에서만 사용할 수 있다.
		- 이 기능은 다른 daemon 또는 cronjob과 같은 다른 프로세스 또는 webserver 플러그인으로부터 sudo를 보호한다.
			- ssh 기능 또한 로그인 되어있지 않으면 사용할 수 없다.
>ref : https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi

```
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

- secure_path
	- secure_path는 sudo 명령어가 실행될 때마다 사용되는 경로이다.
	- 신뢰가 가지 않는 사용자가 sudo를 사용하는 경우에 일어날 불상사를 대비하고자 먼저 sudo 명령어가 실행되는 경로를 설정해서 그 경로에서만 sudo가 실행되게끔 만들어주는 설정이다.


## sudoer가 잘 작동하는지 확인

```
$ cd /var/log/sudo
```
- iolog_dir로 설정한 경로로 이동을 하는 명령어이다.
- 만약 directory가 없다면 다음의 명령어로 만들어주자.

```
$ mkdir /var/log/sudo
```
- 이곳은 사용자가 sudo 명령어를 사용했을 경우 log가 변하는 것을 확인할 수 있는 directory이다.

앞에 기록한 것처럼 새로운 user를 생성해서 sudo group에 포함시켜도 괜찮고, 원래 포함시켰던 user로 test해봐도 괜찮다.

```
su - <username>
```
이나

```
login <username>
```
으로 로그인한 뒤에 `sudo apt-get update`등의 임의의 sudo 명령어를 사용하자.

sudoers 설정을 알맞게 하고, sudo 명령어를 사용했다면, `/var/log/sudo/00/00/01`이나 02, 03 등의 directory에 있는 log의 내용이 갱신된 것을 확인할 수 있다.

