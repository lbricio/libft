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
     The memcpy() function copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined.  Applications in
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
     The memccpy() function copies bytes from string src to string dst.  If the character c (as converted to an unsigned char) occurs in the string
     src, the copy stops and a pointer to the byte after the copy of c in the string dst is returned.  Otherwise, n bytes are copied, and a NULL
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
     The memmove() function copies len bytes from string src to string dst.  The two strings may overlap; the copy is always done in a non-destructive
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
     The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if no such byte exists within n bytes.
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

