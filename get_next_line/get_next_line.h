#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
#endif

typedef struct	t_node
{
	char			*content;
	struct t_node	*next;
}
node;

char	*get_next_line(int fd);
void	ft_list(node **stash, int fd);
void	ft_append(node **stash, char *buf);
char	*ft_line(node *stash);
void	ft_leftover(node **stash);
int		ft_newline(node *stash);
int		count_to_newline(node *stash);
node 	*ft_last_node(node *stash);
void	ft_strcpy(node *stash, char *next_line);
void	ft_dealloc(node **stash, node *clean, char *buf);

#endif