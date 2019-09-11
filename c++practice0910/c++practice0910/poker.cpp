#include "poker.h"
#include <ctime>

int randNum(Poker* cardHeap){
	int tmp = rand() % 54;
	while (1){
		if (cardHeap[tmp].isEff()){}
	}
}