#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);

typedef struct s_lst
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
}			t_lst;

#endif
