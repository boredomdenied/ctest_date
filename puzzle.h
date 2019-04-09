#ifndef PARSETIME_H
# define PARSETIME_H
# define _XOPEN_SOURCE 700
# define ERROR -1
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/get_next_line.h"

typedef struct		s_date
{
	char			*time_b;
	struct s_date	*next;
}					t_date;
#endif
