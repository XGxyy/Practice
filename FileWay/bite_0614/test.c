#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main1(){
	FILE* fp = NULL;
	FILE* fpw = NULL;
	//返回类型为FILE*
	char* buf = NULL;
	int n = 0;
	fp = fopen("C:\\Users\\wangkexin\\Desktop\\1.txt", "r");
	fpw = fopen("C:\\Users\\wangkexin\\Desktop\\2.txt", "w");
	//成功返回指针，失败返回“空”
	if (fp == NULL){
		printf("fail!\n");
		return 0;
	}
	if (fpw == NULL){
		printf("fail!\n");
		return 0;
	}
	while (fgetc(fp) != EOF){
		++n;
	}//指针已经指向末尾了后面再用就是乱码
	rewind(fp);
	buf = (char*)malloc(sizeof(char)* (n + 1));
	fgets(buf, n+1, fp);
	puts(buf);
	//fgetc和fputc
	//char c;
	////都先放入文件缓冲区中 
	//while ((c = fgetc(fp)) != EOF){
	//	putchar(c);
	//	fputc(c, fpw);
	//}
	fclose(fp);
	fp = NULL;
	fclose(fpw);
	fpw = NULL;
	system("pause");
	return 0;
}

int main2(){
	FILE* fp = fopen("C:\\Users\\wangkexin\\Desktop\\1.txt", "rb");
	FILE* fpw = fopen("C:\\Users\\wangkexin\\Desktop\\2.txt", "wb");
	char* buf = NULL;
	if (fp == NULL){
		printf("fail!\n");
		return 0;
	}
	if (fpw == NULL){
		printf("fail!\n");
		return 0;
	}
	fseek(fp, 0, 2);
	int n = ftell(fp);
	rewind(fp);
	printf("%d\n", n);
	buf = (char*)malloc(sizeof(char)* n);
	fread(buf, n, 1, fp);
	fwrite(buf, n, 1, fpw);
	//int size = 10;
	//int num = 1;
	//fread(buf, size, num, fp);//size是一次读的个数，num是读的次数,他的返回值是正确读的次数
	//puts(buf);
	fclose(fp);
	fp = NULL;
	fclose(fpw);
	fpw = NULL;
	system("pause");
	return 0;
}

int main(){
	FILE* fp = fopen("C:\\Users\\wangkexin\\Desktop\\5.txt", "r");
	if (!fp ){
		perror("fail!\n");
		system("pause");
		return 0;
	}
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}