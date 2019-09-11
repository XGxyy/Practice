#include <iostream>
using namespace std;

//1、声明一个扑克牌类，拥有方法：传入花色和点数生成扑
//克牌、打印扑克牌。
//2、声明一个玩家类，每人拥有18张扑克牌。拥有方法：增
//加手牌（摸牌）、展示手牌，其中展示手牌要求降序排序展示。
//完成程序：
//1、随机生成18张扑克牌，当做一个玩家的手牌。
//2、用54张不同的扑克牌构成牌堆，发给3个玩家。

enum{
	SPADES,//黑
	HEARTS,//红
	CLUBS,//梅
	DIAMONDS,//方
	JOKER//王
};

class Poker{
	int m_point;
	int m_type;
public:
	Poker() :
		m_point(0),
		m_type(0){}
	//防止隐式类型转换的关键字
	explicit Poker(int point, char type) :
		m_point(point),
		m_type(type){}

	void makePoker(int point, int type){
		m_point = point;
		m_type = type;
		if (m_type == JOKER){
			m_point += 13;
		}
	}

	void outputPoker(){
		char* type[5] = { "黑桃", "红桃", "梅花", "方片", "" };
		char* point[16] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };
		printf("%s %s,", type[m_type], point[m_point]);
	}
#if 1
	bool cmpPoker(Poker tmp){
		return (m_point < tmp.m_point) || (m_point == tmp.m_point && m_type > tmp.m_type);
	}

	bool isEff(){
		if (m_type == JOKER && (m_point == 14 || m_point == 15))
			return true;
		if ((unsigned int)m_type > 3 || (unsigned int)m_point - 1 > 13){
			return false;
		}

		return true;
	}
#endif
};

class Player{
	Poker m_HandCard[18];
	int m_size;
public:
	Player() :m_size(0){}

	void getCard(Poker newCard){
		int i;
		for (i = m_size; i > 0 && m_HandCard[i - 1].cmpPoker(newCard); i--){
			m_HandCard[i] = m_HandCard[i - 1];
		}
		m_HandCard[i] = newCard;
		m_size++;
	}

	void showCard(){
		for (auto& i : m_HandCard){
			i.outputPoker();
		}
		putchar('\n');
	}

};

void test();
int randNum(Poker* cardHeap);






