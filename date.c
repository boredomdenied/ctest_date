#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


void push(struct Node** head_ref, char *before, char *after);
void printBefore(struct Node* node);
void printAfter(struct Node* node);


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

/*

double  difftime_iso(char *A, char *B)
{


struct tm tmA = {0};
struct tm tmB = {0};

strptime(A, "%I:%M %p", &tmA);
strptime(B, "%F %I:%M %p", &tmB);
time_t t = mktime(&tmA);  // YYYY-MM-DD hh24:mm
time_t s = mktime(&tmB);  // t is now your desired time_t

        return (difftime(s,t));
}

double  difftime_ampm(char *A, char *B)
{


struct tm tmA = {0};
struct tm tmB = {0};

strptime(A, "%F %R", &tmA);
strptime(B, "%F %R", &tmB);
time_t t = mktime(&tmA);  // YYYY-MM-DD hh24:mm
time_t s = mktime(&tmB);  // t is now your desired time_t

        return (difftime(s,t));
}

*/



char    *file_to_array(char *str)
{
        int     i;
        int     fd;
	char	buf[1];
        struct stat buffer;

	i = 0;
	
	/* find file size */
        fd = open(str, O_RDWR, 0);
	fstat(fd, &buffer);
	off_t size = buffer.st_size;
	close(fd);
	
	/* allocate memory to array */
	char	*file=malloc(sizeof(off_t) * size);
        
	/* populate array with file characters */
        fd = open(str, O_RDWR, 0);
	while ((read(fd, buf, 1)) != '\0')
                        file[i++] = buf[0];
  	close(fd);
	return (file);
}

void	dates_to_list(char *str)
{
	int 	i;
	int	j;
	char	before[17];
	char	after[17];
	struct Node* head = NULL;

        i = 0;
        j = 0;

	// read array containing file data
	while (str[i] != '\0')
	{
		
		j = 0;
		// read 'before'
		while (str[i] != ',')
		{
			before[j++] = str[i++];	
		}
		before[j] = '\0';
		// skip if space exists between dates
		if (str[i] == ' ')
			++i;
		// read 'after'
		while (str[i] != '\n')
		{
			j = 0;
			after[j++] = str[i++];
		}

		if (str[i] == '\n')
		{
			after[j] = '\0';
			push(&head, before, after);
			i++;
		}
	}
        printBefore(head);
        printAfter(head);

}

char	find_format(char *str)
{
	while (*str != '\n')
	{
		if (*str == 'm')
			return ('m');
		str++;
	}
	return ('i');
}

int main(void)
{
	char	*str = (file_to_array("beye"));
	
	dates_to_list(str);
	//	char fmt = find_format(str);
//	printf("%s", str);
    return 0;
}
