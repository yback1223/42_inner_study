- [](#)

# 

![](img/2022-07-18-16-46-15.png)

Virtual Box를 실행시켜 New를 눌러 새로운 VM을 생성한다.
- Machine Folder는 goinfre로 설정해야 설치가 진행된다.
  - 용량이 크기 때문
- Linux Debian 64비트로 설정


![](img/2022-07-18-16-49-16.png)

프로젝트 중에 RAM의 영향을 받는 과정이 없으므로 default 값인 1024로 설정한다.

![](img/2022-07-18-16-49-49.png)

VM에 하드 디스크를 할당해주는 단계이다. 
- 우리는 새로운 VM을 만들고 있기 때문에 가운데 "Create a virtual hard disk now"를 체크한다.


![](img/2022-07-18-16-50-04.png)

![](img/2022-07-18-16-50-19.png)

위의 두 개는 그냥 엔터를 눌러준다.

![](img/2022-07-18-16-51-30.png)

Bonus 과제를 진행하기 위해서는 8GB 이상의 용량이 할당되어야 한다.
- 과제에서는 30GB를 할당했지만, 그렇게 될 경우에는 폴더 전체를 옮기는 시간이 너무 길어진다.
	- 반만 할당했다. 노상관
- Create를 눌러주면 VM이 생성된다.


![](img/2022-07-18-16-55-21.png)

VM의 Settings에 들어가서 Storage 설정을 바꿔준다.
- Controller:IDE 부분의 CD를 클릭
	- Attribute에서 Optical Drive의 CD를 클릭해서 전에 다운 받아놓은 debian iso 파일을 선택한다.
- OK


---


![](img/2022-07-18-16-56-36.png)

- 과제에서는 Graphic 설정을 사용하지 말라고 했으므로, Install을 선택한다.

![](img/2022-07-18-16-57-08.png)


English 선택

![](img/2022-07-18-16-57-35.png)

Other를 선택하면 대륙을 선택할 수 있다.
- Asia를 선택하고 Korea, Republic of를 선택


![](img/2022-07-18-16-58-51.png)

당연하게 한글로 진행할 수 없으므로 대체 언어를 선택할 수 있게 해주는데, 익숙한 미국 영어를 선택한다.

![](img/2022-07-18-16-59-09.png)

미국식 영어 선택

![](img/2022-07-18-16-59-58.png)

hostname은 매우 중요하다. 
- 과제에서 부여한 rule에 따라서 intra ID 에 42를 붙여서 설정한다.


![](img/2022-07-18-17-00-13.png)

웹 서버를 만드는 것이 아니니까 Domain name은 Pass

![](img/2022-07-18-17-00-36.png)

![](img/2022-07-18-17-00-58.png)

root 계정에 대한 비밀번호를 설정하는 부분이다.
- 여기서 비밀번호를 설정하지 않고 빈칸으로 남겨둔다면, root 계정은 sudo를 사용할 수 없고, root 계정 이후의 첫 사용자가 root의 모든 권한을 부여 받는다.
	- 그러므로 무조건 비밀번호를 빈 칸으로 남겨두지 말자.
	- 첫 사용자는 다음 부분에서 바로 만들어진다.


![](img/2022-07-18-17-02-08.png)

root 계정 외의 새로운 첫 사용자를 여기서 만든다.
- 여기에서는 진짜 자신의 이름을 요구한다.
	- 나중에 시스템에서 이메일 같은 것을 보낼 때 이 이름을 사용해서 보낸다는데 잘은 모르겠다.
- 과제를 위해 그냥 intra ID를 적어주자.


![](img/2022-07-18-17-02-22.png)

사용자의 닉네임을 설정하는 단계이다.
- 앞의 full name에 쓴 문자열을 그대로 가져와서 친절하게 자동으로 채워준다.
	- 그냥 엔터를 눌러주면 된다.


![](img/2022-07-18-17-02-38.png)

![](img/2022-07-18-17-02-55.png)

사용자의 비밀번호 설정

![](img/2022-07-18-17-03-36.png)

Bonus 과제에서는 여러 저장소들을 직접 만들어줘야 하므로 Manual을 선택한다.

![](img/2022-07-18-17-04-02.png)

아까 Virtual Box에서 설정한 용량이 부여된 저장소를 선택해준다.
- 어차피 `SCSI (0,0,0) (sda) = 17.8 GB ATA VBOX HARDDISK`와 비슷한 것을 선택해준다.
- 이제 이 저장소를 과제에서 요구한 것에 따라 분할할 것이다.


![](img/2022-07-18-17-04-15.png)

진짜 이 Harddisk를 partition(분할)할 것인지 물어본다.
- 무조건 YES


![](img/2022-07-18-17-04-37.png)

디스크를 부트를 위한 부분과 logical 부분으로 나눌것이다.

![](img/2022-07-18-17-05-06.png)

새로운 파티션을 생성할 것이다.

![](img/2022-07-18-17-05-58.png)

boot을 위한 공간은 그렇게 많이 필요하지 않으므로 500MB 정도만 주자.

![](img/2022-07-18-17-06-10.png)

방금 용량을 할당한 공간은 primary partition으로 설정해줄 것이다.
- primary partition
	- primary partition은 OS를 설치할 수 있는 공간을 말한다.
	- OS가 설치된 primary partition은 컴퓨터가 실행되기 시작할 때 OS를 처음으로 실행시키는 역할을 한다.

	- 물론 OS가 설치되지 않는 primary partition도 존재할 수 있다.
		- 그냥 처음으로 분할된 partition을 primary partition이라고 부르는 것이다.
>ref : https://www.sciencedirect.com/topics/computer-science/primary-partition#:~:text=A%20primary%20partition%20is%20a,starts%20to%20load%20the%20OS

![](img/2022-07-18-17-06-20.png)

Primary partition으로 설정했으므로 Beginning을 선택해주자.
- 당연히 end는 아닐테니까...


![](img/2022-07-18-17-06-54.png)

아까도 말했던 것처럼 primary partition은 boot시에 OS를 처음으로 실행시켜 주는 부분이니 Mount Point설정을 boot로 선택해준다.

![](img/2022-07-18-17-07-07.png)

![](img/2022-07-18-17-08-01.png)

![](img/2022-07-18-17-08-16.png)

Mount Point 설정을 마쳤다면 Done setting up the partition으로 해당 partition의 설정을 마친다.

![](img/2022-07-18-17-08-40.png)

그림을 보면 primary partition이 잘 생성된 것을 확인할 수 있다.

이제 다른 자잘한 부분들을 나눠주기 위해 나머지 부분을 설정하러 가보자.
- Free space를 선택하자.


![](img/2022-07-18-17-09-11.png)

새로운 partition을 생성하자.

![](img/2022-07-18-17-09-26.png)

primary partition을 제외한 모든 부분을 사용할 것이므로 max를 적어준다.
- 남은 모든 용량을 사용할 수 있다.


![](img/2022-07-18-17-09-53.png)

Primary partition을 제외한 모든 부분을 Logical partition으로 사용할 것이다.
- Logical partition
	- processor, memory, storage 등의 resource를 각각의 목적에 맞게, 그리고 효율적으로 OS를 사용하기 위해서 나눠 놓은 공간이다.
>ref : https://www.techtarget.com/whatis/definition/logical-partition-LPAR#:~:text=A%20logical%20partition%20(LPAR)%20is,system%20instance%20and%20application%20s


![](img/2022-07-18-17-10-21.png)

Logical partition을 다시 사용 목적에 맞게 분할할 것이므로, Logical partition의 Mount point를 none으로 설정해준다.

![](img/2022-07-18-17-10-50.png)

이제 Logical partition의 설정은 끝

![](img/2022-07-18-17-11-22.png)

생성한 primary partition과 logical partition을 보호하기 위해 암호화를 진행하자.

![](img/2022-07-18-17-11-45.png)

위의 창은 암호화를 진행하면 더 이상 암호화된 디스크의 partition의 설정은 변경할 수 없다고 한다.
- 어차피 과제용이다. YES

![](img/2022-07-18-17-12-00.png)

암호화된 디스크 공간을 생성할 것이다.

![](img/2022-07-18-17-12-21.png)

logical partition을 사용해서 여러 암호화된 공간을 생성할 것이기 때문에 밑의 옵션을 선택해준다.

![](img/2022-07-18-17-12-52.png)

![](img/2022-07-18-17-13-04.png)

Finish를 눌러서 종료

![](img/2022-07-18-17-13-29.png)

partition을 초기화하겠다는 내용인데, 어차피 아무것도 하지 않은 상태이기 때문에 과감하게 YES를 눌러준다.


![](img/2022-07-18-17-21-14.png)

![](img/2022-07-18-17-21-29.png)

![](img/2022-07-18-17-28-02.png)

![](img/2022-07-18-17-28-16.png)

비밀번호를 설정해주고 설정을 마물리한다.

![](img/2022-07-18-17-31-26.png)

그림을 보면 logical partition을 분할할 수 있는 Encryted volume이 생성된 것을 확인할 수 있다.

이제 분할을 하기 위해 `Configure the Logical Volume Manager`를 선택한다.

![](img/2022-07-18-17-32-11.png)

이 볼륨에 대한 설정을 더 이상 바꿀 수 없게 된다고 한다. YES

![](img/2022-07-18-17-32-26.png)

Volume group을 만들어서 이 안을 세세하게 분할할 것이다.

![](img/2022-07-18-17-33-41.png)

이름을 부여해주고

![](img/2022-07-18-17-34-03.png)

Logical partition을 분할할 것이니 선택해주고

![](img/2022-07-18-17-34-33.png)

Volume group 생성을 완료한다.

![](img/2022-07-18-17-35-01.png)

이제 여기에 다음과 같이 bonus 과제에 나온 여러 저장소를 만들어 넣을 것이다.
- Create logical volume을 선택
	- 본격적으로 volume group을 분할할 것이다.

![](img/2022-07-18-22-00-13.png)

![](img/2022-07-18-17-35-15.png)

사용할 group을 선택


![](img/2022-07-18-17-35-38.png)

bonus 과제에서 요구하는 저장소 이름을 적어준다.

![](img/2022-07-18-17-36-07.png)

과제에서는 30GB라는 너무 과한 용량을 요구하고 있지만, 우리는 반만 할당했으므로 모든 저장소의 공간을 비례하게 줄여서 할당한다.

![](img/2022-07-18-17-36-31.png)

저장소 생성을 완료하면 Logical volume이 늘어난 것을 확인할 수 있을 것이다.

![](img/2022-07-18-17-52-57.png)

root, home, swap, var, svr, tmp, var-log
- 위의 7개의 logical volume을 생성하고 finish를 눌러준다.

![](img/2022-07-18-17-53-11.png)

이제 이 창에서 모든 volume의 mount point를 설정할 것이다.

home, root, srv, var, tmp
- 다음과 같이 해당 저장소의 `#1 용량` 부분을 클릭
- Use as : do not use 를 선택해서 해당 partition을 어떻게 사용할 것인지 선택할 것이다.
	- Ext4 file system을 선택하면 Mount point를 설정할 수 있다.
	- 해당 저장소에 해당하는 Mount point를 선택하자.

swap
- 다음과 같이 해당 저장소의 `#1 용량` 부분을 클릭
- Use as : do not use 를 선택하면 중간쯤에 swap area가 있다. 선택

var-log
- 다음과 같이 해당 저장소의 `#1 용량` 부분을 클릭
- Use as : do not use 를 선택해서 해당 partition을 어떻게 사용할 것인지 선택할 것이다.
- Mount point에서 Enter manually를 선택하고, 직접 `/var/log`를 입력한다.

![](img/2022-07-18-17-53-42.png)

![](img/2022-07-18-17-53-53.png)

![](img/2022-07-18-17-54-09.png)

![](img/2022-07-18-17-54-37.png)

![](img/2022-07-18-17-54-48.png)

![](img/2022-07-18-17-55-14.png)

![](img/2022-07-18-17-57-20.png)

![](img/2022-07-18-17-57-38.png)

![](img/2022-07-18-17-59-02.png)

![](img/2022-07-18-17-59-33.png)

![](img/2022-07-18-17-59-45.png)

![](img/2022-07-18-18-00-11.png)

![](img/2022-07-18-18-00-38.png)

이렇게 모든 저장소의 설정을 완료했으면 Finish

![](img/2022-07-18-18-01-12.png)

YES

![](img/2022-07-18-18-03-20.png)

NO

![](img/2022-07-18-18-03-31.png)

![](img/2022-07-18-18-03-44.png)

![](img/2022-07-18-18-03-56.png)

빈칸

![](img/2022-07-18-18-04-32.png)

NO

![](img/2022-07-18-18-05-02.png)

부가적인 확장파일들을 설치할건지 물어보는 것인데, 과제와는 아무 상관이 없으므로 모두 해제 시키고 엔터를 눌러주자.

![](img/2022-07-18-18-05-56.png)

GRUB이라는 멀티부트로더인데, 리눅스 환경에서 가장 많이 사용하는 부트로더이다.
- 부트로더
  - 리눅스가 부팅되기까지 부팅의 전과정을 진행하는 부팅전문프로그램이다.
>ref : https://m.blog.naver.com/dudwo567890/130158001734

![](img/2022-07-18-20-39-34.png)

이제까지 모든 설정 과정을 진행했던 하드디스크를 선택해준다.

![](img/2022-07-18-18-07-10.png)

끝

![](img/2022-07-18-20-40-37.png)

![](img/2022-07-18-20-41-13.png)

루트 계정을 만든 직후에 생성한 첫 사용자 계정 정보를 입력하면 된다.