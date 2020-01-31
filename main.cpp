#include <iostream>
#include <string>
#include "canvas.h"

using namespace std;

const int NUMBER_OF_ATTEMPTS = 10;





bool AddCross(Canvas& C, char ch) {
	Location center;
	int vert;
	int horiz;
	string discard;
	
	cout << "Enter row and column of center: ";
	cin >> center.row;
	cin >> center.col;
	cout << "Enter vertical length above and below center: ";
	cin >> vert;
	cout << "Enter horizontal length left and right of center: ";
	cin >> horiz;
	getline(cin, discard);
	if (PlaceCross(C, center, horiz, vert, ch)) {
		cout << "Cross placed successfully" << endl;
		return true;
	}
	else {
		cout << "Unable to place cross" << endl;
		return false;
	}
}

bool RandomCross(Canvas& C, char ch) {
	Location center;
	int vert;
	int horiz;

	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++) {
		center.row = rand() % NUMBER_OF_ROWS;
		center.col = rand() % NUMBER_OF_COLUMNS;
		vert = 1 + rand() % 4;
		horiz = 1 + rand() % 4;
		if (PlaceCross(C, center, horiz, vert, ch)) {
			cout << "Cross placed successfully" << endl;
			return true;
		}
	}
	cout << "Unable to place cross after " << NUMBER_OF_ATTEMPTS << " attempts" << endl;
	return false;
}

int main() {
	string command;
	Canvas C;
	char ch;

	InitCanvas(C);

	ch = 'A';
	cout << "Enter M - manually add cross, R - random add cross, D - display canvas: ";
	while (getline(cin, command) && command.length() > 0) {
		switch (command[0]) {
		case 'M':
			if (AddCross(C, ch)) {
				ch++;
			}
			break;
		case 'R':
			if (RandomCross(C, ch)) {
				ch++;
			}
			break;
		case 'D':
			DisplayCross(C);
			break;
		default:
			cout << "Unrecognized command, ";
			break;
		}
		cout << "Enter M - manually add cross, R - random add cross, D - display canvas: ";
	}
}