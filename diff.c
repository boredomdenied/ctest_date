#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/*
int main(void)
{

const char *time_detailsA = "11:35 am";
const char *time_detailsB = "11:35 pm";

struct tm tmA = {0};
struct tm tmB = {0};

strptime(time_detailsA, "%I:%M %p", &tmA);
strptime(time_detailsB, "%I:%M %p", &tmB);
time_t t = mktime(&tmA);  // t is now your desired time_t
time_t s = mktime(&tmB);  // t is now your desired time_t


printf("Difference is %.2f seconds\n", difftime(s,t));

}
*/


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



double	difftime_ampm(char *A, char *B)
{


struct tm tmA = {0};
struct tm tmB = {0};

strptime(A, "%F %R", &tmA);
strptime(B, "%F %R", &tmB);
time_t t = mktime(&tmA);  // YYYY-MM-DD hh24:mm
time_t s = mktime(&tmB);  // t is now your desired time_t

	return (difftime(s,t));
}


int main(void)
{

char *time_detailsA = "2001-08-21 14:35";
char *time_detailsB = "2001-08-21 15:35";
double diff;

diff=difftime_ampm(time_detailsA, time_detailsB);

printf("Difference is %.2f seconds\n", diff);

	return (0);
}










/*
void convert_iso8601(const char *time_string, int ts_len, struct tm *tm_data)
{
  tzset();

  char temp[64];
  memset(temp, 0, sizeof(temp));
  strncpy(temp, time_string, ts_len);

  struct tm ctime;
  memset(&amp;ctime, 0, sizeof(struct tm));
  strptime(temp, "%FT%T%z", &amp;ctime);

  long ts = mktime(&amp;ctime) - timezone;
  localtime_r(&amp;ts, tm_data);
}

int main()
{
  char date[] = "2006-03-28T16:49:29.000Z";
  struct tm tm;
  memset(&amp;tm, 0, sizeof(struct tm));
  convert_iso8601(date, sizeof(date), &amp;tm);

  char buf[128];
  strftime(buf, sizeof(buf), "Date: %a, %d %b %Y %H:%M:%S %Z", &amp;tm);
  printf("%sn", buf);
}
*/
