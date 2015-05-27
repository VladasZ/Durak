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

		gotoxy(pos, row);
		cout << " __" << endl;
		gotoxy(pos, row+1);
		cout << '|' << (char)m << " |" << endl;
		gotoxy(pos, row+2);
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
		gotoxy(pos, row+3);
		cout << "|__|" << endl;
		gotoxy(pos, row+4);
		return 0;
	}

};

class Deck{
public:
	Card deck[36];
	int cardLeft = 35;
	
	Deck(){ ////////////////////////////////// конструктор колоды
		srand(time(NULL));
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

	void takeOneCard(){
		hand[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}
	void takeCard(){
		while (cardLeft < 6) takeOneCard();
	}
	void showHand(int pos){

		for (int i = 0; i < cardLeft; i++){
			hand[i].displayCard(i*4+12, pos);
		}

	}
		void sortHand(){
		for (int i = 0; i < cardLeft-1; i++){
			for (int j = 0; j < cardLeft-1; j++){

				if (hand[j].n > hand[j + 1].n){

					Card temp = hand[j];
					hand[j] = hand[j + 1];
					hand[j + 1] = temp;

				}

			}
		}
	}

		Player(){
			takeCard();
			sortHand();
		}


};

class Table{

public:
	Card table[35];
	int cardLeft = 0;

	void takeOneCard(){
		table[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}
	void takeCard(){
		while (cardLeft < 6) takeOneCard();
	}

	void display(){

		int shift = 0;
		for (int i = 0; i < cardLeft; i++){

			table[i].displayCard(15+i*2, 8 + shift);

			if (!shift){ shift = 2; continue; }
			shift = 0;

		}


	}



};

void main(){

	Player player,player2;
	Table table;
	table.takeCard();
	table.display();

	

	player2.showHand(0);
	player.showHand(20);

	
	
}

