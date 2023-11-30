#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
#endif

typedef struct	s_node
{
	char		*content;
	struct s_node	*next;
}
node;

#endif