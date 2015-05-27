#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

#define RAND rand() / 920


int randomCard(){
	
	return rand() / 920;
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Card{
	
public:
	int n;
	char m;
	//♥♦♣♠
	int displayCard(int pos, int row){
		if (!n) return 0;

		gotoxy(pos * 4, row*4);
		cout << " __" << endl;
		gotoxy(pos * 4, row * 4+1);
		cout << '|' << (char)m << " |" << endl;
		gotoxy(pos * 4, row * 4+2);
		cout << '|';
		if (n < 10) cout << n << ' ';
		if (n == 10) cout << "10";
		else{
			switch (n)
			{
			case 11:
				cout << "J ";
				break;
			case 12:
				cout << "Q ";
				break;
			case 13:
				cout << "K ";
				break;
			case 14:
				cout << "A ";
				break;
			}

		}
		cout << '|' << endl;
		gotoxy(pos * 4, row * 4+3);
		cout << "|__|" << endl;
		gotoxy(pos * 4, row * 4+4);
		return 0;
	}

};

class Deck{
public:
	Card deck[36];
	int cardLeft = 35;
	
	Deck(){ ////////////////////////////////// конструктор колоды
		
		int cardN = 0;
		for (int i = 3; i < 7; i++){
			for (int j = 6; j < 15; j++, cardN++){
				deck[cardN].n = j;
				deck[cardN].m = i;
			}
		}


		Card temp, *foo, *bar; ///////////////////// тасовка колоды
		for (int i = 0; i < 5000000; i++){
			foo = &deck[RAND];
			bar = &deck[RAND];

			temp = *foo;

			*foo = *bar;
			*bar = temp;


		}
	};

	/*Deck(int foo){
		
		cardLeft = 0;

	};*/

};

Deck deck;

void showDeck(){
	int card = 0;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 9; j++){
			deck.deck[card].displayCard(j, i);
			card++;
		}
	}
}

class Player{
public:
	Card hand[35];
	int cardLeft = 0;
	void takeCard(){
		hand[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}

	void showHand(int pos){

		for (int i = 0; i < cardLeft; i++){
			hand[i].displayCard(i+3, pos);
		}

	}
};

void main(){
	srand(time(NULL));
	Player player;

	player.takeCard();
	player.takeCard();
	player.takeCard();
	player.takeCard();
	player.takeCard();
	player.takeCard();

	showDeck();
	player.showHand(5);
	
}

