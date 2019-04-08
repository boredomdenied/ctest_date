#include "parsetime.h"

int		add_dates(t_date **list, char *time_b)
{
	t_date *head;

	head = *list;
	if (!(*list = (t_date*)malloc(sizeof(t_date))))
		return (ERROR);
	(*list)->time_b = time_b;
	(*list)->next = head;
	head = *list;
	return (1);
}

void	print_reverse(t_date **list)
{
	while (*list)
	{
		printf("%s\n", (*list)->time_b);
		(*list) = (*list)->next;
	}
}

void	process_dates(char **dates, t_date **list)
{
	struct tm	tms = {0};
	struct tm	tme = {0};
	time_t		tts;
	time_t		tte;
	double		diff_t;

	if (dates[0][1] != ':' && dates[0][2] != ':')
	{
		strptime(dates[0], "%Y-%m-%d %H:%M", &tms);
		strptime(dates[1], "%Y-%m-%d %H:%M", &tme);
	}
	else
	{
		strptime(ft_strjoin("02", dates[0]), "%d%I:%M %p", &tms);
		strptime(ft_strjoin("02", dates[1]), "%d%I:%M %p", &tme);
	}
	tts = mktime(&tms);
	tte = mktime(&tme);
	diff_t = difftime(tts, tte);
	diff_t > 0 ? printf("%s\n", dates[1])
		: printf("%s\n", dates[0]);
	diff_t > 0 ? add_dates(list, dates[0])
		: add_dates(list, dates[1]);
}

int		main(int ac, char **av)
{
	char		*line = NULL;
	int			fd;
	char		**dates;
	t_date		*list;

	if (ac == 2 && (fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			dates = ft_strsplit(line, ',');
			process_dates(dates, &list);
		}
		printf("\n");
		print_reverse(&list);
		close(fd);
	}
	else
	{
		printf("Please place file at root and call it's name as argument");
		printf(" ex: ./parsetime records\n");
		return (ERROR);
	}
	return (0);
}
