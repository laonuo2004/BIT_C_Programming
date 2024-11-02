#include <stdio.h>
#include <string.h>

void substring(const char* src, int start, int length, char* dest) {
    int srcLen = strlen(src);
    if (start >= srcLen) {
        dest[0] = '\0';
        return;
    }
    
    int end = start + length;
    if (end > srcLen) {
        end = srcLen;
    }
    
    int i, j;
    for (i = start, j = 0; i < end; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
}

int main()
{
	for(int i = 1; i <= 2; i++)
	{
		char s[106] = {'\0'};
		char sub[101][101];
		scanf("%s", s);
		char *temp = s;
		int counter = 1, string = 1, flag = 0;
		while(*temp != '\0')
		{
			if(('C' == *(temp-2) && 'C' == *(temp-1) && 'C' == *temp && 'G' == *(temp+1) && 'G' == *(temp+2) && 'G' == *(temp+3)) || ('G' == *(temp-2) && 'G' == *(temp-1) && 'G' == *temp && 'C' == *(temp+1) && 'C' == *(temp+2) && 'C' == *(temp+3)))
			{
				substring(s, flag, counter,sub[string]);			
				string++;
				flag = flag + counter;
				counter = 0;
			}
			counter++;
			*temp++;
		}
		substring(s, flag, counter,sub[string]);
		for(int j = string; j >=1; j--)
		{
			printf("%s", sub[j]);
		}
		printf("\n");
	}
	return 0;
}