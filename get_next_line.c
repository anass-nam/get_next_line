#include "get_next_line.h"

static char	*init(t_lst *b, char *rem)
{
	ft_bzero(b, sizeof(t_lst));
	if (rem && *rem)
		return (rem);
	return (ft_strdup(""));
}

static int	check_nl(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		if (*(s + i++) == '\n')
			return (1);
	return (0);
}

static void	readline(t_lst *b, int fd)
{
	while (!check_nl(b->line))
	{
		int s;

		s = read(fd, b->buffer, BUFFER_SIZE);
		if (s > 0)
			b->line = ft_strjoin(b->line, b->buffer);
		else
			break ;
		ft_bzero(b->buffer, BUFFER_SIZE+1);
	}
}

static char	*shrink(t_lst *b)
{
	char	*rem;
	size_t		i;

	i = 0;
	while (*(b->line + i) && *(b->line + i) != '\n')
		i++;
	rem = ft_strdup((b->line + i + 1));
	ft_bzero(b->line + i + 1, ft_strlen(b->line + i + 1));
	return (rem);
}

char	*get_next_line(int fd)
{
	t_lst		box;
	static char	*rem;

	box.line = init(&box, rem);
	if (rem && !*rem)
	{
		free(rem);
	}
	rem = NULL;
	readline(&box, fd);
	if (*(box.line) <= 0)
		return (free(box.line), NULL);
	else if (box.line)
		rem = shrink(&box);
	return (box.line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY, 0100);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	return (0);
// }
