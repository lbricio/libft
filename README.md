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
`memset()` preencherá os primeiros `n` bytes da memória apontados por `s` com o byte `c`. note que um `byte` tem `256` valores possíveis (`0` a `255` ou em binário: `00000000` a `11111111`) portanto a convencional usar o tipo `unsigned char` para essa representação, já que seu alcance é igualmente de um `byte`.


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
     (treated as unsigned char values, so that `\200' is greater than `\0', for example).  
     Zero-length strings are always identical.  This behavior is not required by C and
     portable code should only depend on the sign of the returned value.
```

### ft_strlen
```c
SYNOPSIS
     #include <string.h>

     size_t
     strlen(const char *s);

     size_t
     strnlen(const char *s, size_t maxlen);

DESCRIPTION
     The strlen() function computes the length of the string s.  The strnlen() function attempts to compute the length of s, but never scans beyond the
     first maxlen bytes of s.

RETURN VALUES
     The strlen() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns either the same
     result as strlen() or maxlen, whichever is smaller.
```


### ft_strlcpy
```c
SYNOPSIS
     #include <string.h>

     size_t
     strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
     The strlcpy() functions copy strings with the same input parameters and output result as snprintf(3). strlcpy() are
     designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3).

     strlcpy() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not entirely safe on some systems), the fol-
     lowing two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() function return the total length of the string that we tried to create.  For strlcpy() that means the
     length of src.
```
### ft_strlcat
```c
SYNOPSIS
     size_t
     strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
     The strlcat() function concatenate strings with the same input parameters and output result as snprintf(3). strlcat are
     designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncat(3).

     strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcat() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not entirely safe on some systems), the fol-
     lowing two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), strlcat() functions return the total length of the string that we tried to create. 
     For strlcat() that means the initial length of dst plus the length of src.
```
### ft_strchr
```c
SYNOPSIS
     #include <string.h>

     char *
     strchr(const char *s, int c);

     char *
     strrchr(const char *s, int c);

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the functions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character, or NULL if the character does not appear in the string.
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```
### ft_
```c
```

> calma veloz que eu ainda não terminei o projeto.

