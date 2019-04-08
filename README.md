



Here is the puzzle: 

Please write a computer program in C to run on a Linux computer using the GNU compiler as part of your technical skills assessment.



Puzzle Description:

- A comma-delimited file has two columns: timeA, timeB.

- Both columns are times in hh:mm [a|p]m (hh = 1-12, mm = 0-59) or ISO format (YYYY-MM-DD hh24:mm).

- Times could be in either format, but for any given row the times will be in the same format.



Write a program to read the file:

- For each line report the time that is earlier. Assume same day for each line, and also same timezone for each time.

- The records should be displayed in the order they are in the file.

- After the initial print, print for each row, all the times that are later without reading the file again.

- The records should be displayed in reverse order of the file order.

- The program should use linked lists.

- Include any instructions necessary to build your program.



Process:

- read from fd to buffer, extract both timeA & timeB

- use strptime to convert each into a format which can be difftime'd

- store both time formats for both times in a linked list

- use difftime to print each earlier time in the list

- again using difftime, read list reversed with dates which are later

Include a makefile, helper file


	profit...


2:34 am,11:07 am
2018-10-14 23:07,2017-1-11 01:11
1:34 pm,11:07 pm
2018-12-14 13:07,2018-2-13 04:11
4:45 am,12:07 am
9:34 pm,5:07 am
2016-04-26 10:34,2015-7-11 06:11
2018-11-04 23:07,2017-1-11 05:18

