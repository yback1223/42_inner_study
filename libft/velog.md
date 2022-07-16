- [ft_atoi.c](#ft_atoic)
- [ft_bzero.c](#ft_bzeroc)
- [ft_calloc.c](#ft_callocc)
- [ft_isalnum.c](#ft_isalnumc)
- [ft_isalpha.c](#ft_isalphac)
- [ft_isascii.c](#ft_isasciic)
- [ft_isdigit.c](#ft_isdigitc)
- [ft_isprint.c](#ft_isprintc)
- [ft_itoa.c](#ft_itoac)
- [ft_lstadd_back.c](#ft_lstadd_backc)
- [ft_lstadd_front.c](#ft_lstadd_frontc)
- [ft_lstdelone.c](#ft_lstdelonec)
- [ft_lstclear.c](#ft_lstclearc)
- [ft_lstiter.c](#ft_lstiterc)
- [ft_lstlast.c](#ft_lstlastc)
- [ft_lstnew.c](#ft_lstnewc)
- [ft_lstmap.c](#ft_lstmapc)
- [ft_lstsize.c](#ft_lstsizec)
- [ft_memchr.c](#ft_memchrc)
- [ft_memcmp.c](#ft_memcmpc)
- [ft_memcpy.c](#ft_memcpyc)
- [ft_memmove.c](#ft_memmovec)
- [ft_memset.c](#ft_memsetc)
- [ft_putchar_fd.c](#ft_putchar_fdc)
- [ft_putendl_fd.c](#ft_putendl_fdc)
- [ft_putnbr_fd.c](#ft_putnbr_fdc)
- [ft_putstr_fd.c](#ft_putstr_fdc)
- [ft_split.c](#ft_splitc)
- [ft_strchr.c](#ft_strchrc)
- [ft_strdup.c](#ft_strdupc)
- [ft_strdup.c](#ft_strdupc-1)
- [ft_strjoin.c](#ft_strjoinc)
- [ft_strlcat.c](#ft_strlcatc)
- [ft_strlcpy.c](#ft_strlcpyc)
- [ft_strlen.c](#ft_strlenc)
- [ft_strmapi.c](#ft_strmapic)
- [ft_strcmp.c](#ft_strcmpc)
- [ft_strnstr.c](#ft_strnstrc)
- [ft_strrchr.c](#ft_strrchrc)
- [ft_strtrim.c](#ft_strtrimc)
- [ft_substr.c](#ft_substrc)


---

# ft_atoi.c

```c
int	ft_atoi(const char *str)
```

문자열 str을 숫자로 변형시키는 함수이다.
- 보통 ascii 함수는 숫자가 max나 min을 넘어가면 오버플로우로 인해서 숫자가 계속 순환하는데 이 프로젝트에서 원하는 atoi 함수는 오버플로우는 따로 처리를 해줘야 테스터 통과를 받을 수 있다.
  - 숫자가 max값보다 크다면 -1을 출력해야 한다.
  - 숫자가 min값보다 작다면 0을 출력해야 한다.

---

# ft_bzero.c

```c
void	ft_bzero(void *s, size_t n)
```

s 배열을 n 사이즈만큼 0으로 채우는 함수이다.
- 나중에 나올 memset함수로 대체가능하다.

---

# ft_calloc.c

```c
void	*ft_calloc(size_t count, size_t size)
```

count와 size의 곱 만큼의 크기를 메모리 할당한 포인터를 반환하는 함수이다.
- calloc은 count와 size에 unsigned long의 max값이 들어갔을 때 널을 반환하게 만들어야 한다.
  - 하지만 errno함수를 구현하거나 사용할 수 없으므로 널을 반환하지 않게 하려면 이 이유를 들어 방어를 하면 된다.
- 메모리를 할당했다면, 그 메모리를 모두 0으로 채워 초기화 해야 한다.
  - bzero를 활용하면 깔끔하다.

---

# ft_isalnum.c

```c
int	ft_isalnum(int c)
```

파라미터 c가 알파벳이거나 숫자이면 1을 반환, 아니면 0을 반환하는 함수이다.

---

# ft_isalpha.c

```c
int	ft_isalpha(int c)
```

파라미터 c가 알파벳이라면 1을 반환, 아니면 0을 반환하는 함수이다.

---

#  ft_isascii.c

```c
int	ft_isascii(int c)
```

파라미터 c가 ascii 코드 값이라면 1을 반환, 아니면 0을 반환하는 함수이다.
- ascii 코드 : 0 ~ 127

---

# ft_isdigit.c

```c
int	ft_isdigit(int c)
```

파라미터 c가 숫자라면 1을 반환, 아니면 0을 반환하는 함수이다.

---

# ft_isprint.c

```c
int	ft_isprint(int c)
```

파라미터 c가 printable ascii 코드라면 1을 반환, 아니면 0을 반환하는 함수이다.
- printable ascii 코드 : 32 ~ 126

---

# ft_itoa.c

```c
char	*ft_itoa(int n)
```

파라미터 n 값을 ascii 코드 값으로 변형시키는 함수이다.
- 쉽게 생각하면 숫자를 문자열로 나타내는 함수
- 반환 값으로 무조건 동적 할당을 한 포인터를 반환해야 한다.
  - 0일 때는 그냥 0을 반환하면 된다고 생각할 수 있지만, 이 함수에서는 동적 할당을 한 포인터를 반환해줘야 한다.

---

# ft_lstadd_back.c

```c
void	ft_lstadd_back(t_list **lst, t_list *new)
```

lst의 맨 마지막 노드에 new 노드를 추가해주는 함수이다.
- lst가 존재한다면 lst의 맨 마지막 노드의 next로 new를 대입해주면 된다.
- lst가 널이라면 new가 lst의 첫 노드가 되면 된다.

---

# ft_lstadd_front.c

```c
void	ft_lstadd_front(t_list **lst, t_list *new)
```

lst의 첫 노드의 앞에 new를 붙여서 new가 lst의 첫 노드가 되게 만드는 함수이다.
- 단순하게 new의 next에 lst의 주소를 대입해주면 된다.
  - 여기서 new를 lst의 첫 주소로 만드는 것을 잊으면 안된다.

---

# ft_lstdelone.c

```c
void	ft_lstdelone(t_list *lst, void (*del)(void*))
```

del함수를 이용해서 lst의 content를 삭제시키고 free 함수로 lst를 완전히 소멸시킨다.

---

# ft_lstclear.c

```c
void	ft_lstclear(t_list **lst, void (*del)(void*))
```

lst를 기점으로 이어지는 모든 list를 del함수를 이용해 제거하는 함수이다.
- while문을 돌려서 lstdelone 함수를 모든 list에 적용시켜 제거한다.
- tmp를 이용해 lst->next를 받아서 제거후에 lst에 다시 대입해주는 방법으로 접근

---

# ft_lstiter.c

```c
void	ft_lstiter(t_list *lst, void (*f)(void *))
```

lst의 모든 content에 f함수를 적용시키는 함수이다.

---

# ft_lstlast.c

```c
t_list	*ft_lstlast(t_list *lst)
```

lst의 마지막 노드를 반환하는 함수이다.
- 만약 while문의 인자로 lst->next를 넣는다면 마지막 노드의 하나 전의 노드를 반환하므로 주의해야 한다.

---

# ft_lstnew.c

```c
t_list	*ft_lstnew(void *content)
```

어디에도 이어지지 않은 새로운 list를 생성하는 함수이다.
- malloc 함수를 이용해서 메모리를 할당해준 list를 생성한다.

---

# ft_lstmap.c

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```

새로운 노드를 f함수를 이용해서 계속 생성하는 함수인데, 중간에 할당이 잘못 된다면 del 함수를 사용해서 모든 list를 제거하고 널을 반환하는 함수이다.
- 새로운 노드를 생성하는 함수로는 ft_lstnew를 쓰면된다.
- list를 제거하는 함수는 ft_lstclear를 사용한다.

---

# ft_lstsize.c

```c
int	ft_lstsize(t_list *lst)
```

lst의 size를 구하는 함수

---

# ft_memchr.c

```c
void	*ft_memchr(const void *s, int c, size_t n)
```

포인터 s에서 n만큼의 사이즈 동안 c가 나오는지 확인하는 함수이다.
- c가 처음 나오는 주소를 반환한다.
  - 반환 타입은 (void *)로 맞춰줘야 한다.

---

# ft_memcmp.c

```c
int	ft_memcmp(const void *s1, const void *s2, size_t n)
```

포인터 s1과 s2의 동일성을 판단하는 함수이다.
- s1과 s2가 같다면 0을 반환
- s1과 s2가 다르다면 다른 지점에서의 ascii 코드 값의 차를 반환

---

# ft_memcpy.c

```c
void	*ft_memcpy(void *dst, const void *src, size_t n)
```

src에서 사이즈 n만큼 dst에 복사를 하는 함수이다.
- src와 dst가 겹치지 않아야 한다.
  - 쉽게 생각해서 src와 dst가 다르면 되는 것이다.
    - src != dst

---

# ft_memmove.c

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
```

src를 dst에 len만큼 복사하는 함수이다.
- memcpy와 달리 겹쳐도 된다.
- src와 dst가 아예 겹치지 않는다면 그냥 복사해도 된다.
- src와 dst가 겹치는 부분에 따라서 분기문을 작성해야 한다.
  - dst의 뒷 부분이 src와 겹칠 경우
    - src의 앞에서부터 복사한다.
  - dst의 앞 부분이 src와 겹칠 경우
    - src의 뒤에서부터 복사한다.

---

# ft_memset.c

```c
void	*ft_memset(void *b, int c, size_t len)
```

포인터 b를 c로 len만큼 채워주는 함수이다.
- c를 unsigned char로 변경시켜줘야 한다.
  - memset은  1바이트마다 데이터를 넣어준다.
  - 만약 ft_memset(arr, 1, 3)을 한다면 arr[0]은 [00000000000000010000000100000001]을 10진수로 바꾼 값이 나올 것이다.
    - 이처럼 바이트로 접근해서 풀어야 한다.

---

# ft_putchar_fd.c

```c
void	ft_putchar_fd(char c, int fd)
```

write 함수를 사용해서 c를 출력하는 함수이다.
- fd는 음수 불가

---

# ft_putendl_fd.c

```c
void	ft_putendl_fd(char *s, int fd)
```

문자열을 출력하고 개행문자까지 출력해주는 함수이다.

---

# ft_putnbr_fd.c

```c
void	ft_putnbr_fd(int n, int fd)
```

정수 n을 문자열로 출력해주는 함수이다.
- -2147483648은 그냥 출력해주는 것이 좋다.
- 재귀를 사용하면 편하다.

---

# ft_putstr_fd.c

```c
void	ft_putstr_fd(char *s, int fd)
```

문자열을 write 함수를 써서 그대로 출력해주면 된다.

---

# ft_split.c

```c
char	**ft_split(char const *s, char c)
```

구분자 c를 이용해서 문자열 s를 나눠주면 된다.

---

# ft_strchr.c

```c
char	*ft_strchr(const char *s, int c)
```

포인터 s에서 c를 찾아내어 그 주소를 반환하는 함수
- c가 널이라면 포인터 s에서 널을 찾으면 된다.
  - s가 널이라면 그냥 널의 주소를 반환
  - s가 문자열이라면 문자열의 마지막 부분인 널의 주소를 반환

---

# ft_strdup.c

```c
char	*ft_strdup(const char *s1)
```

새로운 포인터를 선언해 메모리를 동적 할당시켜 s1을 복사해 반환하는 함수

---

# ft_strdup.c

```c
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
```

s 포인터의 모든 요소에 f 함수를 적용시켜주는 함수이다.

---

# ft_strjoin.c

```c
char	*ft_strjoin(char const *s1, char const *s2)
```

s1과 s2를 이어주는 함수이다.

---

# ft_strlcat.c

```c
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
```

dst 뒤에 src를 붙이는 함수이다.
- 세 가지의 경우를 생각해야 한다.
  - dstsize > dst의 사이즈 + src의 사이즈
    - 모든 문자열을 합치고, 반환 값으로 dst의 사이즈 + src의 사이즈를 반환한다.
  - dstsize < dst의 사이즈 + src의 사이즈
    - dst에 붙일 수 있는 src를 최대한 붙이고, 반환값으로 dstsize + src의 사이즈를 반환한다.
  - dstsize < dst의 사이즈
    - dst에 아무런 변형도 일으키지 않고, 반환값으로 dst의 사이즈 + src의 사이즈를 반환한다.

---

# ft_strlcpy.c

```c
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
```

src를 dst에 size만큼 복사하는 함수이다.
- 반환값은 언제나 src의 길이이다.

---

# ft_strlen.c

```c
size_t	ft_strlen(const char *s)
```

단순하게 s의 길이를 측정하는 함수이다.

---

# ft_strmapi.c

```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
```

포인터 s의 모든 요소들에 f 함수를 적용시켜 새로 메모리를 할당한 포인터에 대입해 반환시켜주는 함수이다.

---

# ft_strcmp.c

```c
int	ft_strncmp(const char *s1, const char *s2, size_t n)
```

s1과 s2를 n만큼 비교하는 함수이다.
- 둘이 같다면 0을 반환, 다르다면 처음으로 다른 부분의 ascii 코드값의 차를 반환한다.

---

# ft_strnstr.c

```c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
```

haystack에서 needle을 찾는 함수이다.
- 사이즈는 len만큼만 비교를 한다.
  - 만약 사이즈가 needle의 사이즈보다 작을 경우에는 널을 반환한다.
- haystack이 존재하고 len이 needle의 사이즈 이상이라면 haystack에서 needle이 있는지 찾고, 만약 있다면 동일한 부분의 첫 haystack 주소를 반환한다.

---

# ft_strrchr.c

```c
char	*ft_strrchr(const char *s, int c)
```

s에서 c를 찾아 그 s상의 주소를 반환하는 함수
- 찾지 못한다면 널을 반환한다.

---

# ft_strtrim.c

```c
char	*ft_strtrim(char const *s1, char const *set)
```

set에 있는 요소를 s1에서 찾아 제거시킨 후에 남은 포인터의 부분을 반환하는 함수이다.

---

# ft_substr.c

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
```

s 포인터의 start 부분부터 len만큼 자른 포인터를 반환하는 함수이다.