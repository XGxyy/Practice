#pragma once
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Date{
	int m_year;
	uint m_month;
	uint m_day;

	//uint getMonthDay();
public:
	Date(int y, uint m, uint d) :
		m_year(y),
		m_month(m),
		m_day(d){

	}

	Date operator +(uint delay) const;
	friend ostream& operator << (ostream& os, Date& d);
};