# libft

> o proposito desse readme é apresentar um breve resumo de cada função
> para que eu possa revisar no futuro. a ideia inicial é apresentar a
> versão do manual e alguns comentários logo abaixo.


## Part 1 - Libc functions

### ft_memset
```c
SYNOPSIS
     #include <string.h>

     void *
     memset(void *b, int c, size_t len);

DESCRIPTION
     The memset() function writes len bytes of value c 
     (converted to an unsigned char) to the string b.

RETURN VALUES
     The memset() function returns its first argument.
```
`memset()` preencherá os primeiros `n` bytes da memória apontados por `s` com o byte `c`. note que um `byte` tem `256` valores possíveis (`0` a `255` ou em binário: `00000000` a `11111111`) portanto a convencional usar o tipo `unsigned char` para essa representação, já que seu alcance é idêntico ao de um `byte`.


### ft_bzero
```c
SYNOPSIS
     #include <strings.h>

     void
     bzero(void *s, size_t n);

DESCRIPTION
     The bzero() function writes n zeroed bytes to the string s.
     If n is zero, bzero() does nothing.
```
preenche os primeiro n bytes da string s com zero.

### ft_memcpy
```c
SYNOPSIS
     #include <string.h>

     void *
     memcpy(void *restrict dst, const void *restrict src, size_t n);

DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area dst.
     If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.
```
copia n bytes de src(string fonte) para dst(string destinatária), se dst não tiver espaço suficiente retornará null(0). 

### ft_memccpy
```c
SYNOPSIS
     #include <string.h>

     void *
     memccpy(void *restrict dst, const void *restrict src, int c, size_t n);

DESCRIPTION
     The memccpy() function copies bytes from string src to string dst.  
     If the character c (as converted to an unsigned char) occurs in the string
     src, the copy stops and a pointer to the byte after the copy of c 
     in the string dst is returned.  Otherwise, n bytes are copied, and a NULL
     pointer is returned.

     The source and destination strings should not overlap, as the behavior is undefined.
```
copia bytes da string source para destiny, 

se o caractere c for encontrado em src -> a string source para de copiar imediatamente, o caractere c não é copiado, e a função retornará um ponteiro para o primeiro caractere logo após c

caso o caractere c não seja encontrado em src -> a cópia continuará até n bytes e o retorno da função será nulo.

essa string é útil por exemplo para ler um texto e transformar cada palavra em 
uma string diferente usando espaço como delimitador.

### ft_memmove
```c
SYNOPSIS
     #include <string.h>

     void *
     memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
```
copia len bytes da string source para destiny, de uma forma mais segura que memcpy. 

na função, atribui o conteúdo das strings a outras strings temporárias no escopo da função e usei o método de comparar as posições relativas na memória para evitar ovelap, foi bem complicadinho de entender, mas basicamente serve pra ver se é melhor copiar e colar do começo para o fim ou do fim para o começo, para evitar que uma maior invada os endereços de memória da menor e tenhamos resultados indesejados.

### ft_memchr
```c
SYNOPSIS
     #include <string.h>

     void *
     memchr(const void *s, int c, size_t n);

DESCRIPTION
     The memchr() function locates the first occurrence of c 
     (converted to an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, 
     or NULL if no such byte exists within n bytes.
```
procura pela primeira ocorrência do caractere c e retorna um ponteiro para esse caractere, se percorrer n posições e não encontrar retorna (NULL).


### ft_memcmp
```c
SYNOPSIS
     #include <string.h>

     int
     memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical, 
     otherwise returns the difference between the first two differing bytes
     (treated as unsigned char values, so that '\200' is greater than '\0', for example).  
     Zero-length strings are always identical.  This behavior is not required by C and
     portable code should only depend on the sign of the returned value.
```
compara byte a byte das duas strings até o n-ésimo byte, caso eles sejam idênticos até o n-ésimo byte retornará nulo, caso algum byte seja diferente retornará a diferença(subtração simples do caractere de s1 - s2) entre seu códigos ascii dos caracteres.

### ft_strlen
```c
SYNOPSIS
     #include <string.h>

     size_t
     strlen(const char *s);

     size_t
     strnlen(const char *s, size_t maxlen);

DESCRIPTION
     The strlen() function computes the length of the string s.  
     The strnlen() function attempts to compute the length of s, 
     but never scans beyond the first maxlen bytes of s.

RETURN VALUES
     The strlen() function returns the number of characters that precede 
     the terminating NUL character.  The strnlen() function returns either
     the same result as strlen() or maxlen, whichever is smaller.
```
retorna a largura de uma string (quantidade de caracteres posteriores ao caractere nulo).


### ft_strlcpy and ft_strlcat
```c
SYNOPSIS
     #include <string.h>

     size_t
     strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

     size_t
     strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings with the
     same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer and 
     guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  It will append at most dstsize 
     - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in practice
     this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal handler 
     safety (snprintf(3) is not entirely safe on some systems), the fol-
     lowing two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat() functions return the total length
     of the string they tried to create.  For strlcpy() that means the
     length of src.  For strlcat() that means the initial length of dst plus the length of src.
```
strlcpy copia de src para dst (diferentemente de strcpy é feito um teste antes comparando o tamanho das strings, para evitar resultados indesejados) e em seguida retorna o tamanho de source. strlcat retorna o tamanho da string que tentamos criar, e realiza a concatenação somente se se a primeira string tiver espaço suficiente (contando com o nulo). ¹dstsize é o tamanho desejado da string destiny no final, contando com o cartere nulo.

### ft_strchr and ft_strrchr
```c
SYNOPSIS
     #include <string.h>

     char *
     strchr(const char *s, int c);

     char *
     strrchr(const char *s, int c);

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a char)
     in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is '\0', 
     the functions locate the terminating '\0'.

     The strrchr() function is identical to strchr(), except it locates 
     the last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character,
     or NULL if the character does not appear in the string.
```

### ft_strnstr
```c
SYNOPSIS
     #include <string.h>

     char *
     strstr(const char *haystack, const char *needle);

     char *
     strcasestr(const char *haystack, const char *needle);

     char *
     strnstr(const char *haystack, const char *needle, size_t len);

     #include <string.h>
     #include <xlocale.h>

     char *
     strcasestr_l(const char *haystack, const char *needle, locale_t loc);

DESCRIPTION
     The strstr() function locates the first occurrence of the null-terminated 
     string needle in the null-terminated string haystack.

     The strcasestr() function is similar to strstr(), but ignores the 
     case of both strings.

     The strnstr() function locates the first occurrence of the null-terminated
     string needle in the string haystack, where not more than len charac-
     ters are searched.  Characters that appear after a `\0' character are not searched. 
     Since the strnstr() function is a FreeBSD specific API, it should only be 
     used when portability is not a concern.

     While the strcasestr() function uses the current locale, the strcasestr_l()
     function may be passed a locale directly. See xlocale(3) for more information.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs nowhere
     in haystack, NULL is returned; otherwise a pointer to the first char-
     acter of the first occurrence of needle is returned.
```
procurando agulha em um palheiro (needle = agulha, haystack = palheiro). essa função serve para procurar uma string dentro de outra string, caso a string seja encontrada é retornado um endereço para o começo dela, caso não seja encontrada returna nulo, caso a string a ser procurada seja vazia retorna o endereço de haystrack. ¹a função só pesquisa em haystack até len bytes. ²se deduz que a string needle existir vai estar sempre no fim de haystack já que a função não procura pelos caracteres após o primeiro '\0' encontrado e a string é estritamente terminada com '\0'.

### ft_strncmp
```c
SYNOPSIS
     #include <string.h>

     int
     strcmp(const char *s1, const char *s2);

     int
     strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the
     null-terminated strings s1 and s2.

     The strncmp() function compares not more than n characters.  Because strncmp() 
     is designed for comparing strings rather than binary data, charac-
     ters that appear after a `\0' character are not compared.

RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than, equal to,
     or less than 0, according as the string s1 is greater than, equal to, or less than
     the string s2.  The comparison is done using unsigned characters, 
     so that `\200' is greater than `\0'.
```

### ft_atoi
```c
SYNOPSIS
     #include <stdlib.h>

     int
     atoi(const char *str);

     #include <xlocale.h>

     int
     atoi_l(const char *str, locale_t loc);

DESCRIPTION
     The atoi() function converts the initial portion of the string pointed 
     to by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l() function
     may be passed a locale directly. See xlocale(3) for more information.

IMPLEMENTATION NOTES
     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

     The strtol() and strtol_l() functions are recommended instead of atoi()
     and atoi_l() functions, especially in new code.
```
### ft_isalpha
```c
SYNOPSIS
     #include <ctype.h>

     int
     isalpha(int c);

DESCRIPTION
     The isalpha() function tests for any character for which isupper(3) 
     or islower(3) is true.  The value of the argument must be representable 
     as an unsigned char or the value of EOF.

     In the ASCII character set, this includes the following characters 
     (preceded by their numeric values, in octal):

     101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
     106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
     113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
     120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
     125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
     132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
     145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
     152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
     157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
     164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
     171 ``y''     172 ``z''

RETURN VALUES
     The isalpha() function returns zero if the character tests false 
     and returns non-zero if the character tests true.
```
### ft_isdigit
```c
SYNOPSIS
     #include <ctype.h>

     int
     isdigit(int c);

     int
     isnumber(int c);

DESCRIPTION
     The isdigit() function tests for a decimal digit character.
     Regardless of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''

     The isnumber() function behaves similarly to isdigit(), but may 
     recognize additional characters, depending on the current locale setting.

     The value of the argument must be representable as an unsigned char or
     the value of EOF.

RETURN VALUES
     The isdigit() and isnumber() functions return zero if the character 
     tests false and return non-zero if the character tests true.
```
### ft_isalnum
```c
SYNOPSIS
     #include <ctype.h>

     int
     isalnum(int c);

DESCRIPTION
     The isalnum() function tests for any character for which isalpha(3) or 
     isdigit(3) is true.  The value of the argument must be representable 
     as an unsigned char or the value of EOF.

     In the ASCII character set, this includes the following characters 
     (preceded by their numeric values, in octal):

     060 ``0''     061 ``1''     062 ``2''     063 ``3''     064 ``4''
     065 ``5''     066 ``6''     067 ``7''     070 ``8''     071 ``9''
     101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
     106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
     113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
     120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
     125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
     132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
     145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
     152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
     157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
     164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
     171 ``y''     172 ``z''

RETURN VALUES
     The isalnum() function returns zero if the character tests false 
     and returns non-zero if the character tests true.
```
### ft_isascii
```c
SYNOPSIS
     #include <ctype.h>

     int
     isascii(int c);

DESCRIPTION
     The isascii() function tests for an ASCII character, which is any
     character between 0 and octal 0177 inclusive.
```
### ft_isprint
```c
SYNOPSIS
     #include <ctype.h>

     int
     isprint(int c);

DESCRIPTION
     The isprint() function tests for any printing character, including space (` ').
     The value of the argument must be representable as an unsigned char or 
     the value of EOF.

     In the ASCII character set, this includes the following characters
     (preceded by their numeric values, in octal):

     040 (space)   041 ``!''     042 ``"''     043 ``#''     044 ``$''
     045 ``%''     046 ``&''     047 ``'''     050 ``(''     051 ``)''
     052 ``*''     053 ``+''     054 ``,''     055 ``-''     056 ``.''
     057 ``/''     060 ``0''     061 ``1''     062 ``2''     063 ``3''
     064 ``4''     065 ``5''     066 ``6''     067 ``7''     070 ``8''
     071 ``9''     072 ``:''     073 ``;''     074 ``<''     075 ``=''
     076 ``>''     077 ``?''     100 ``@''     101 ``A''     102 ``B''
     103 ``C''     104 ``D''     105 ``E''     106 ``F''     107 ``G''
     110 ``H''     111 ``I''     112 ``J''     113 ``K''     114 ``L''
     115 ``M''     116 ``N''     117 ``O''     120 ``P''     121 ``Q''
     122 ``R''     123 ``S''     124 ``T''     125 ``U''     126 ``V''
     127 ``W''     130 ``X''     131 ``Y''     132 ``Z''     133 ``[''
     134 ``\''     135 ``]''     136 ``^''     137 ``_''     140 ```''
     141 ``a''     142 ``b''     143 ``c''     144 ``d''     145 ``e''
     146 ``f''     147 ``g''     150 ``h''     151 ``i''     152 ``j''
     153 ``k''     154 ``l''     155 ``m''     156 ``n''     157 ``o''
     160 ``p''     161 ``q''     162 ``r''     163 ``s''     164 ``t''
     165 ``u''     166 ``v''     167 ``w''     170 ``x''     171 ``y''
     172 ``z''     173 ``{''     174 ``|''     175 ``}''     176 ``~''

RETURN VALUES
     The isprint() function returns zero if the character tests false
     and returns non-zero if the character tests true.
```
`OCTAL` 040 para `DECIMAL` é 32. A base octal funciona assim: 000,001,002,...006,007,010,011,012... números de 0 a 7 (oito algarismos distintos), 
enquanto a decimal seria 0 a 9(10 algarismos distintos).

### ft_toupper
```c
SYNOPSIS
     #include <ctype.h>

     int
     toupper(int c);

     #include <ctype.h>
     #include <xlocale.h>

     int
     toupper_l(int c, locale_t loc);

DESCRIPTION
     The toupper() function converts a lower-case letter to the corresponding upper-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the toupper() function uses the current locale, the toupper_l() function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is a lower-case letter, the toupper() function returns the corresponding upper-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
```
### ft_tolower
```c
SYNOPSIS
     #include <ctype.h>

     int
     tolower(int c);

     #include <ctype.h>
     #include <xlocale.h>

     int
     tolower_l(int c, locale_t loc);

DESCRIPTION
     The tolower() function converts an upper-case letter to the corresponding lower-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the tolower() function uses the current locale, the tolower_l() function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is an upper-case letter, the tolower() function returns the corresponding lower-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
```

### ft_calloc
```c
SYNOPSIS
     #include <stdlib.h>

     void *
     calloc(size_t count, size_t size);

     void
     free(void *ptr);

     void *
     malloc(size_t size);

     void *
     realloc(void *ptr, size_t size);

     void *
     reallocf(void *ptr, size_t size);

     void *
     valloc(size_t size);

DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate memory.  
     The allocated memory is aligned such that it can be used
     
     void *
     reallocf(void *ptr, size_t size);

     void *
     valloc(size_t size);
     
DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate memory.  
     The allocated memory is aligned such that it can be used
     for any data type, including AltiVec- and SSE-related types.  The free() function 
     frees allocations that were created via the preceding allocation functions.

     The malloc() function allocates size bytes of memory and returns a pointer 
     to the allocated memory.

     The calloc() function contiguously allocates enough space for count objects 
     that are size bytes of memory each and returns a pointer to the allo-
     cated memory.  The allocated memory is filled with bytes of value zero.

     The valloc() function allocates size bytes of memory and returns a pointer 
     to the allocated memory.  The allocated memory is aligned on a page boundary.

     The realloc() function tries to change the size of the allocation pointed to
     by ptr to size, and returns ptr.  If there is not enough room to
     enlarge the memory allocation pointed to by ptr, realloc() creates a new 
     allocation, copies as much of the old data pointed to by ptr as will fit
     to the new allocation, frees the old allocation, and returns a pointer 
     to the allocated memory.  If ptr is NULL, realloc() is identical to a call
     to malloc() for size bytes.  If size is zero and ptr is not NULL, a new, 
     minimum sized object is allocated and the original object is freed.  When
     extending a region allocated with calloc(3), realloc(3) does not guarantee
     that the additional memory is also zero-filled.

     The reallocf() function is identical to the realloc() function, except that 
     it will free the passed pointer when the requested memory cannot be
     allocated.  This is a FreeBSD specific API designed to ease the problems 
     with traditional coding styles for realloc causing memory leaks in
     libraries.

     The free() function deallocates the memory allocation pointed to by ptr. 
     If ptr is a NULL pointer, no operation is performed.

RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), and valloc() 
     functions return a pointer to allocated memory.  If there is an error, they
     return a NULL pointer and set errno to ENOMEM.

     For realloc(), the input pointer is still valid if reallocation failed.  
     For reallocf(), the input pointer will have been freed if reallocation
     failed.

     The free() function does not return a value.
```
### ft_strdup
```c
SYNOPSIS
     #include <string.h>

     char *
     strdup(const char *s1);

     char *
     strndup(const char *s1, size_t n);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1, 
     does the copy, and returns a pointer to it.  The pointer may subse-
     quently be used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is
     set to ENOMEM.

     The strndup() function copies at most n characters from the string s1
     always NUL terminating the copied string.
```
## Part 2 - Additional functions

### ft_substr

![image](https://user-images.githubusercontent.com/81334995/119757153-ec057400-be7a-11eb-91c1-4ba08168228b.png)

### ft_strjoin
![image](https://user-images.githubusercontent.com/81334995/119757194-faec2680-be7a-11eb-86d4-c18d68ba8aa1.png)


### ft_strtrim
![image](https://user-images.githubusercontent.com/81334995/119757213-05a6bb80-be7b-11eb-8115-fc9fb4469544.png)


### ft_split
![image](https://user-images.githubusercontent.com/81334995/119757249-10f9e700-be7b-11eb-97e2-48a9e1d89745.png)

### ft_itoa
![image](https://user-images.githubusercontent.com/81334995/119757343-338c0000-be7b-11eb-939d-a45c5f42d349.png)


### ft_strmapi
![image](https://user-images.githubusercontent.com/81334995/119757361-3981e100-be7b-11eb-929a-025dbc2d2354.png)


### ft_putchar_fd
![image](https://user-images.githubusercontent.com/81334995/119757385-41418580-be7b-11eb-8195-14e0b278c775.png)


### ft_putstr_fd
![image](https://user-images.githubusercontent.com/81334995/119757400-48689380-be7b-11eb-8e2c-230e45b46f4c.png)


### ft_putendl_fd
![image](https://user-images.githubusercontent.com/81334995/119757423-4f8fa180-be7b-11eb-870f-7506f80d443c.png)


### ft_putnbr_fd
![image](https://user-images.githubusercontent.com/81334995/119757440-55858280-be7b-11eb-836c-2b333a5f4d16.png)

## Part 3 - Bonus functions

### ft_lstnew
![image](https://user-images.githubusercontent.com/81334995/119757468-5fa78100-be7b-11eb-8fbe-1e56e66e8276.png)

### ft_lstadd_front
![image](https://user-images.githubusercontent.com/81334995/119757488-6635f880-be7b-11eb-92a2-c57cc976cce1.png)

### ft_lstsize
![image](https://user-images.githubusercontent.com/81334995/119757508-6c2bd980-be7b-11eb-9c4a-05e9f1b4679f.png)

### ft_lstlast
![image](https://user-images.githubusercontent.com/81334995/119757538-7352e780-be7b-11eb-87fb-55661d77db8d.png)

### ft_lstadd_back
![image](https://user-images.githubusercontent.com/81334995/119757561-7b128c00-be7b-11eb-9152-1baddee19530.png)

### ft_lstdelone
![image](https://user-images.githubusercontent.com/81334995/119757575-81086d00-be7b-11eb-8417-86719df0c862.png)

### ft_lstclear
![image](https://user-images.githubusercontent.com/81334995/119757591-8796e480-be7b-11eb-900d-d29f32c48cc8.png)

### ft_lstiter
![image](https://user-images.githubusercontent.com/81334995/119757608-8d8cc580-be7b-11eb-9fd8-ae9c63d3619b.png)

### ft_lstmap
![image](https://user-images.githubusercontent.com/81334995/119757621-9382a680-be7b-11eb-9635-8ea97b02a4d6.png)
