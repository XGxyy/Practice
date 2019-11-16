//三、设计一个日期类，包含以下功能：
//1、只能通过传入年月日初始化。
//2、可以加上一个数字n，返回一个该日期后推n天之后的日期。
#include "Date.h"

static uint getMonthDay(int year, uint month){
	if (month == 0 || month > 12){
		return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11){
		return 30;
	}
	else if (month == 2){
		return 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}
	else{
		return 31;
	}
}

int getLeapNum(int sy, int ey){
	int tmp = sy % 4;
	if (sy % 4){
		sy += (4 - tmp);
	}
	return (ey - sy) / 4 + 1;
}

Date Date :: operator + (uint delay)const{
	Date res = *this;
	uint tmp;
#if 1
	int numy = delay / 365;
	int numd = delay % 365;
	int flag = 0;

	if (res.m_month > 2){
		flag = 1;
	}
	int leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);
	while (numd < leapnum){
		numy--;
		leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);
		numd += 365;
	}

	numd -= leapnum;
	
	res.m_year += numy;
	delay = numd;
#endif

	tmp = getMonthDay(res.m_year, res.m_month);
	while (delay >= tmp){
		delay -= tmp;
		res.m_month++;
		if (res.m_month > 12){
			res.m_month = 1;
			res.m_year++;
		}
		tmp = getMonthDay(res.m_year, res.m_month);
	}

	res.m_day += delay;
	if (res.m_day > tmp){
		res.m_month++;
		res.m_day -= tmp;
	}
	if (res.m_month > 12){
		res.m_month = 1;
		res.m_year++;
	}
	return res;
}

ostream & operator << (ostream &os, Date &d){
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}
