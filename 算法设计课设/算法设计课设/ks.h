#ifndef _KS_H_
#define _KS_H_

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 10000000
#define CLASS 6
#define GROUPONE 10

#define FM 20
typedef struct shop{
	int ID;
	int NUM;
	int TruePrice;
}Shop;

typedef struct Stroy{
	Shop data[CLASS];
	int KIND;
}Stroy;

int num[1000];
int project[5][5] = { 0 };//用二维数组存特价方案

#endif