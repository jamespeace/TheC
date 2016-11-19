#include<stdio.h>
#define MAX 1000

char line[MAX + 1]; 

int getlines(void);

int main(void)
{
	int len, t, next;			 /* t == line's position.
								  * next == a basic unit of
								  * 		FOLDLENGTH.  */
	int location, spaceholder;	 /* location == arr's position.
								  * spaceholder == the position
								  * of space in the arr.  */
	const int FOLDLENGTH = 7; /* The max length of a line */
	char arr[FOLDLENGTH + 2];
	while((len = getlines()) > 0) {
		if(len - 1 <= FOLDLENGTH) {
			printf("%s", line);
		}

		else {
				/* if this is an extra long line then we
				 * loop through it replacing a space nearest
				 * to the foldarea with a newline.
				 * 			*/
			t = 0;
			location = 0;
			next = 1;
			spaceholder = 0;
			while(t < len) {
				arr[location] = line[t];
				if(line[t] == ' ')
					spaceholder = location;
				if(next == FOLDLENGTH) {
					if(spaceholder == 0) {
						arr[++location] = '\n';
						next = 0;
					}else {
						arr[spaceholder] = '\n';
						next = location - spaceholder;
					}
					arr[++location] = '\0';
					printf("%s", arr);
					location = -1;
					spaceholder = 0;
				}
				location++;
				t++;
				next++;
			}
			arr[location] = '\0';
			printf("%s", arr);
		}
	}
	return 0;
}

int getlines(void)
{
	int i;
	char c;
	i = 0;
	while((c = getchar()) != EOF && c != '\n')
	{
		line[i++] = c;	
	}
	line[i++] = '\n';
	line[i] = '\0';
	return i;
}
