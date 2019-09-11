#include <iostream>
using namespace std;

//1������һ���˿����࣬ӵ�з��������뻨ɫ�͵���������
//���ơ���ӡ�˿��ơ�
//2������һ������࣬ÿ��ӵ��18���˿��ơ�ӵ�з�������
//�����ƣ����ƣ���չʾ���ƣ�����չʾ����Ҫ��������չʾ��
//��ɳ���
//1���������18���˿��ƣ�����һ����ҵ����ơ�
//2����54�Ų�ͬ���˿��ƹ����ƶѣ�����3����ҡ�

enum{
	SPADES,//��
	HEARTS,//��
	CLUBS,//÷
	DIAMONDS,//��
	JOKER//��
};

class Poker{
	int m_point;
	int m_type;
public:
	Poker() :
		m_point(0),
		m_type(0){}
	//��ֹ��ʽ����ת���Ĺؼ���
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
		char* type[5] = { "����", "����", "÷��", "��Ƭ", "" };
		char* point[16] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };
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






