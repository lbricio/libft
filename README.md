# libft
> calma veloz que eu ainda não terminei o projeto.

o proposito desse readme é apresentar um breve resumo de cada função
para que eu possa revisar no futuro. a ideia inicial é apresentar a
versão do manual e alguns comentários logo abaixo.

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
memset() preencherá os primeiros `n` bytes da memória apontados por `s` 
com o byte `c`. note que um byte tem 256 valores possíveis (0 a 255 ou
em binário: 00000000 a 11111111) portanto a convenção é usar `unsigned char`, 
já que seu alcance é de um byte(8 bits ou 2^8 valores possíveis).


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



