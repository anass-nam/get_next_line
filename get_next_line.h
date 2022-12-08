#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char		*get_next_line(int fd);
//	gnl utils
size_t		ft_strdlen(const char *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, size_t start, size_t len);

typedef struct s_lst
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
}			t_lst;

#endif
