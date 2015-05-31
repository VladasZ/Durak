#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define RAND rand()%36

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
		if (!n) {// пустая карта
		
			gotoxy(pos, row);
			cout << "    " << endl;
			gotoxy(pos, row + 1);
			cout << "    " << endl;
			gotoxy(pos, row + 2);
			cout << "    " << endl;
			gotoxy(pos, row + 3);
			cout << "    " << endl;
			return 0;
		}

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
	//	gotoxy(pos, row+4);
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

void tableCls(){

	for (int i = 0; i < 15; i++){
		gotoxy(0, 4 + i); cout << "                                                          ";
	}

}

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
		tableCls();
		int shift = 0;
		for (int i = 0; i < cardLeft; i++){

			table[i].displayCard(15 + i * 2, 8 + shift);

			if (!shift){ shift = 2; continue; }
			shift = 0;

		}


	}



};

Table table;

void showDeck(){
	tableCls();
	int card = 0;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 9; j++){
			deck.deck[card].displayCard(j*4+10, i*4+4);
			card++;
		}
	}
}

class Player{
public:
	Card hand[35];
	int pos;
	int cardLeft = 0;

	Player (int a){
		pos = a;
		takeCard(); 
		sortHand();
	}

	void takeOneCard(){
		hand[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}
	void takeCard(){
		while (cardLeft < 6) takeOneCard();
	}
	void showHand(){

		for (int i = 0; i < 6; i++){
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


		void dropCard(int n){
			table.table[table.cardLeft] = hand[n];
			hand[n].n = 0;
			for (int i = n; i < cardLeft-1 - n; i++){
				hand[i] = hand[i + 1];
				if (i == cardLeft - 2) hand[i+1].n = 0;
			}
		table.cardLeft++;
		cardLeft--;

		table.display();
		showHand();
	}


};

Player player=0, player2=20;

void control(){

	char a = getch();

	switch (a){
	case'0':
		showDeck();
		break;
	case'1':
		player.showHand();
		break;
	case'2':
		player2.showHand();
		break;
	case'3':
		table.display();
		break;
	case'4':
		player.dropCard(0);
		break;
	case'5':
		player2.dropCard(0);
		break;
	case'6':
		tableCls();
		break;
	default:

		break;
	}

}



void main(){
	


	control();
	main();
	
	
}

