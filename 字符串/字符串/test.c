//1.实现strcpy
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//char* My_strcpy(char* des, const char* str){
//	char* ret = des;
//	assert(des != NULL);
//	assert(str != NULL);
//	while (*des++ = *str++){
//		;
//	}
//	return ret;
//}



//char* My_strstr(char* des, const char* str){
//	assert(des);  
//	assert(str);     
//	char *cp = (char*)des;   
//	char *substr = (char *)str;   
//	char *s1 = NULL;   
//	if (*str == '\0')   
//		return NULL;    
//	while (*cp){
//		s1 = cp;  
//		substr = str;      
//		while (*s1 && *substr && (*s1 == *substr)){
//			s1++;         
//			substr++;
//		}
//		if (*substr == '\0')
//			return cp;       
//		cp++;
//	}
//}

//int My_strcmp(char* des, const char* str){
//	int ret = 0;      
//	assert(des != NULL);
//	assert(str != NULL);
//	while (!(ret = *(unsigned char *)des - *(unsigned char *)str) && *str) 
//		++des, ++str;
//
//	if (ret < 0) ret = -1;
//	else if (ret > 0)
//		ret = 1;
//	return ret;
//}
//
//void* My_memcpy(void* des, const void* str, int num){
//	char* ret = des;
//	assert(des != NULL);
//	assert(str != NULL);
//	while (num--){
//		*(char*)des = *(char*)str;
//		des = (char*)des + 1;
//		str = (char*)str + 1;
//	}
//	return ret;
//}
//
//void* My_memmove(void* des, const void* str, int num){
//	void * ret = des;
//	if (des <= str || (char *)des >= ((char *)str + num)) {
//		while (num--) { 
//			*(char *)des = *(char *)str;
//			des = (char *)des + 1; 
//			str = (char *)str + 1; 
//		} 
//	}
//	else {
//		des = (char *)des + num - 1; 
//		str = (char *)str + num - 1;
//	while (num--) { 
//		*(char *)des = *(char *)str; 
//		des = (char *)des - 1; 
//		str = (char *)str - 1; 
//	}
//	}
//	return(ret);
//}

char* My_strcat(char* des, const char* str){
	char *ret = des;
	assert(des != NULL);
	assert(str != NULL);
	while (*des){
		des++;
	}
	while ((*des++ = *str++)){
		;
	}
	return ret;
}

int main(){
	char des[10] = "abcd";
	char str[] = "qwer";
	//printf("%s\n", My_strcat(des, str));
	printf("%s\n", strcat(des, str));
	system("pause");
	return 0;
}
//2.实现strcat
//3.实现strstr
//4.实现strchr
//5.实现strcmp
//6.实现memcpy
//7.实现memmove