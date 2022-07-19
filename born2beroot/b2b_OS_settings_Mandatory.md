- [Sudo](#sudo)
	- [sudo 설치](#sudo-설치)
	- [sudo group에 user 추가시키기](#sudo-group에-user-추가시키기)
	- [sudo 명령어 설정 변경하기](#sudo-명령어-설정-변경하기)
	- [sudoer가 잘 작동하는지 확인](#sudoer가-잘-작동하는지-확인)
- [UFW](#ufw)
- [SSH](#ssh)
	- [SSH 설치](#ssh-설치)
	- [SSH 설정 변경](#ssh-설정-변경)
- [Password Policy](#password-policy)
- [새로운 Group 생성](#새로운-group-생성)
- [Monitoring.sh](#monitoringsh)
- [Cron](#cron)

---

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

---

# UFW

`su -`로 root 계정으로 로그인 하고 ufw를 설치하자.

```
$ sudo apt install ufw -y
```

설치가 제대로 되었는지 확인하기 위해서 다음의 명령어 중 하나를 입력

```
$ dpkg -l | grep ufw
```

```
$ ufw status verbose
```

설치가 완료되었다면 방화벽을 가동시킨다.

```
$ sudo ufw enable
```

방화벽이 가동되었으므로 우리가 SSH에 사용하는 4242 포트를 허가해줘야 한다.

```
$ sudo ufw allow 4242
```

---

# SSH

## SSH 설치

무료인 openssh-server를 설치

```
$ sudo apt install openssh-server
```

설치가 완료되었다면 확인을 해봐야한다.

```
$ dpkg -l | grep ssh
```

## SSH 설정 변경

SSH 설정 파일을 변경해야한다.

```
$ sudo visudo /etc/ssh/sshd_config
```

SSH 초기 포트를 사용하지 않고 4242 포트를 사용하기 위해 내용을 변경해줘야 한다.

```
#Port 22

Port 4242
```
- #을 지워주고 22를 4242로 변경

```
#PermitRootLogin progibit-password

PermitRootLogin no
```
- #을 지워주고 내용 변경

설정을 완료했으면 저장하고, 

```
$ systemctl restart ssh
$ systemctl status ssh
```
- ssh를 재시동하고, 상태를 확인

설정 변경이 완료되었으면, 

```
$ hostname -I
```
로 Guest IP에 입력할 IP를 확인한다.

이제 VM을 save가 아닌 완전 종료를 시킨다. (Power off the machine)
- 꼭 종료를 시켜야 한다.
  - 종료를 시켜야 VM의 network setting을 변경할 수 있다.

Tools를 누르면 여러 메뉴를 볼 수 있는데 Network에서 Create를 눌러주면 `vboxnet0`라는 Host IP가 하나 생긴다. 이제 이 IP가 SSH의 호스트가 될 것이다.

Setting으로 가서 Network를 누르면 여러 Adapter들이 나오는데 우리는 1과 2만 변경시킬 것이다.

Adater1
- `Advanced`를 눌러서 Port Forwarding을 클릭한다.
- 오른쪽에 보면 초록색 아이콘이 있는데 이 아이콘을 눌러서 새로운 forwarding rule을 생성하자.
  - Host IP : `192.168.56.1`
  - Host Port : `4242`
  - Guest IP : `10.0.2.15`
  - Guest Port : `4242`
- 모두 완료했으면 OK

Adapter2
- Enable Network Adapter를 클릭해서 Attached to를 Host-only Adapter로 바꿔준다.
- Name : vboxnet0
- Adapter2는  Host만의 Adapter
- OK

>현재 상황은 내 맥이 host이고 VM이 guest이다. 지금까지의 설정을 완료했다면, 맥의 터미널에 `ifconfig`를 입력해보자. 그러면 방금 VM에서 정의한 host IP가 저장되어 있는 것을 알 수 있다.

이제 맥의 터미널을 켜서 다음의 명령어를 입력하자

```
ssh <username>@192.168.56.1 -p 4242 
```
- 4242 포트를 호스트에 연결시킨다는 의미이다.
- 명령어가 제대로 작동되었다면 이제 맥은 ssh의 호스트이다.
  - root계정으로는 당연히 불가능하다.
- 제대로 작동하지 않고 `IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!`의 에러가 나타난다면, 맥의 터미널에서 다음의 명령어들을 실행시키자

```
cd
cd .ssh/
rm -rf known_hosts
```

---

# Password Policy

password 정책을 변경해보자

```
sudo visudo /etc/login.defs 
```

편집모드로 들어가서 다음과 같이 수치를 변경한다.

```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
- `PASS_MAX_DAYS`
  - 비밀번호의 최대 수명
- `PASS_MIN_DAYS`
  - 비밀번호의 최소 수명
- `PASS_WARN_AGE`
  - 비밀번호의 최대 수명이 거의 다했음을 알려주는 일 수
  - 최대 수명에서 빼기
>ref : https://man7.org/linux/man-pages/man5/login.defs.5.html#:~:text=The%20%2Fetc%2Flogin.,probably%20result%20in%20undesirable%20operation

비밀번호의 퀄리티를 위해서 libpam-pwquality를 설치하자.

```
sudo apt install libpam-pwquality
```
- libpam-pwquality
  - 비밀번호의 퀄리티를 체크해주는 함수와 질 좋은 랜덤 비밀번호를 생성할 수 있는 함수를 제공한다.

설치가 잘 되었는지 확인

```
dpkg -l | grep libpam-pwquality
```

이제 libpam-pwquality의 설정을 변경해보자

```
sudo visudo /etc/pam.d/common-password 
```

간단하게 `retry=3` 문장 뒤에 다음의 내용을 추가해주면 된다.

```
minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username enforce_for_root difok=7
```
- `minlen = 10`
  - 비밀번호의 최소 길이 10
- `ucredit=-1`
  - 최소한 대문자(uppercase) 한 개 포함
- `dcredit=-1`
  - 최소한 숫자(decimal) 한 개 포함
- `maxrepeat=3`
  - 연속되는 문자 최대 3개까지 가능
- `reject_username`
  - 비밀번호에 username 포함 금지
- `difok=7`
  - 비밀번호를 변경할 때 원래의 비밀번호에서 최소한 7개는 변경이 되어야 한다는 설정
- `enforce_for_root`
  - root 계정에도 동일한 비밀번호 정책을 적용

설정을 모두 완료했다면

```
$ passwd -e <username>
```
- 이 명령어를 입력하면 username의 비밀번호를 바로 expire(만료)시킨다.
  - 아마 조건에 맞지 않으면 바로 변경하거나 나중에 변경하라고 할 수도 있다.

---

# 새로운 Group 생성

```
$ sudo addgroup user42
```
위의 명령어로 새로운 그룹을 생성하고, 기존 유저를 그룹에 포함 시키려면 다음의 명령어 둘 중 하나를 사용하면 된다.

```
$ sudo adduser <username> user42
```

```
$ sudo usermod -aG user42 <username>
```

잘 실행되었는지 확인까지 하자

```
$ getent group user42
```

---

# Monitoring.sh

현재 VM의 상태를 나타내는 파일이다.
- root directory에 직접 입력해야함

```
apt-get -y install sysstat
vi /root/monitoring.sh

아래 내용 그대로 입력. 틈틈히 저장하고 출력 확인하면서 만들 것.

printf "#Architecture: "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
df -a -BM | grep /dev/map | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -a -BM | grep /dev/map | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("
df -a -BM | grep /dev/map | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

printf "#Last boot: "
who -b | awk '{printf $3" "$4"\n"}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who | wc -l

printf "#Network: IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"
```

---

# Cron

cron은 linux의 업무자동화 기능을 담당하고 있ㅅ다.

```
$ sudo crontab -u root -e
```
- crontab file을 root 계정으로 편집할 것이란 명령어이다.
- 편집모드로 들어가기 전에 editor를 선택하라고 하는데, 그냥 easiest가 표시된 것을 골라주자.

편집모드에 들어가면 맨 밑에 `# m h  dom mon dow   command`가 있을텐데, 이 바로 밑에 한 줄을 추가해준다.

```
*/10 * * * * sh /root/monitoring.sh | wall
```
- *
  - 모든 때를 의미한다.
  - 위와 같이 m부분에만 `*/10`을 입력하면, 매일 매시간 command 부분이 실행될 것인데, 10분에 한 번씩 실행될 것이라는 의미이다.
  - 만약 1분에 한 번씩으로 변경하려면 `*/10`을 `*/1`로 변경만 해주면 된다.
- 만약 *을 쓰지 않고 특정 정수를 입력한다면 24:00 시간을 적용시켜 그 시간에만 명령어가 실행된다.
  - 매일 2am에 실행되게 하려면 
  - `0 2 * * * `으로 시간 부분을 입력해주면 된다.

설정을 완료했다면 잘 입력됐는지 확인해보자.

```
$ sudo crontab -u root -l
```
- root 계정으로 설정된 crontab file을 볼 수 있게 해주는 명령어이다.
>ref : https://linuxhint.com/crontab_in_linux/