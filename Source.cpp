#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

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
	void displayCard(int pos, int row){
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
	}

};

class Deck{
public:
	Card deck[36];
	Deck(){
		int cardN = 0;
		for (int i = 3; i < 7; i++){
			for (int j = 6; j < 15; j++, cardN++){
				deck[cardN].n = j;
				deck[cardN].m = i;
			}
		}



	};

	void displayDeck(){
		int card = 0;
		
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 9; j++){
				deck[card].displayCard(j, i);
				card++;
			}
		}
	};

};

void main(){
	Deck deck;

	deck.displayDeck();


}

/*
__
|♥5|
|__|

*/