#include <stdio.h>
#include <windows.h>
#include<assert.h>
//char *my_strcat1(char *dest, const char *src){
//	char * ret = dest;
//
//	assert(dest);
//	assert(src);
//
//	while (*dest){
//		dest++;
//	}
//	
//	while (*src){
//		*dest++ = *src++;
//	}
//	
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	
//	char str1[20] = "Hello ";
//	char str2[] = "Gxd Blog!";
//	char *ret = my_strcat1(str1, str2);
//	printf("%s\n", ret);
//		system("pause");
//		return 0;
//	
//}

//char * Mystrcpy(char * destination, const char * source);
//{
//	char* ret = destination
//	assert(destination);
//	assert(source);
//	while (*source)
//	{
//		source++;
//	}
//	while (*destination)
//	{
//		*destination++ = *source++;
//	}
//	return  ret;
//}

int My_strlen(const char * str);
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}