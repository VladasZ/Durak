#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Card{

public:
	int n;
	char m;
	//♥♦♣♠
	void displayCard(){
		cout << " __" << endl;
		cout << '|' << (char)m << " |" << endl;
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
		cout << "|__|" << endl;
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
		for (int i = 0; i < 36; i++){
			deck[i].displayCard();
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