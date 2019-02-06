#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                ft_putchar(str[i]);
                i++;
        }
}

void	read_line(char *str)
{
	int 	fd;
	char	buf[1];

	fd = open(str, O_RDWR, 0);
	while ((read(fd, buf, 1)) != '\0')
	{
		if (buf[0] == '\n')
			break;
		else
			ft_putstr(buf);
	}	
                ft_putchar('\n');

}


char    *load_line(char *str)
{
        int     fd;
        char    buf[16];

        fd = open(str, O_RDWR, 0);
        while ((read(fd, buf, 1)) != '\0')
        {
                if (buf[15] == ',')
    			break;
	}
	return (*buf);
}


int main(void)
{
    time_t     now;
    struct tm  ts;
    char       buf[80];

    // Get current time
//    time(&now);

    // Format time, "hh:mm"
    ts = load_line("bee");
    strftime(buf, sizeof(buf), "%H:%M", &ts);
//    printf("%s\n", buf);
	read_line("bee");

    return 0;
}
