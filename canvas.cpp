#include <iostream>
#include "canvas.h"

using namespace std;

void DisplayCountRow();

void InitCanvas(Canvas& canvas) {
	for (int row = 0; row < NUMBER_OF_ROWS; row++) {
		for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
			canvas.chars[row][col] = ' ';
		}
	}
}

bool PlaceCross(Canvas& canvas, const Location& center, int horiz, int vert, char ch) {
	// Check if fits within the canvas
	if (center.col - horiz < 0 || center.col + horiz >= NUMBER_OF_COLUMNS) {
		return false;
	}
	if (center.row - vert < 0 || center.row + vert >= NUMBER_OF_ROWS) {
		return false;
	}

	// Check that we are not covering another cross
	for (int col = center.col - horiz; col <= center.col + horiz; col++) {
		if (canvas.chars[center.row][col] != ' ') {
			return false;
		}
	}
	for (int row = center.row - vert; row <= center.row + vert; row++) {
		if (canvas.chars[row][center.col] != ' ') {
			return false;
		}
	}

	// OK, mark the cross shape on the canvas
	for (int col = center.col - horiz; col <= center.col + horiz; col++) {
		canvas.chars[center.row][col] = ch;
	}
	for (int row = center.row - vert; row <= center.row + vert; row++) {
		canvas.chars[row][center.col] = ch;
	}
	return true;
}

void DisplayCross(const Canvas& C) {
	DisplayCountRow();
	for (int row = 0; row < NUMBER_OF_ROWS; row++) {
		cout << row % 10;
		for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
			cout << C.chars[row][col];
		}
		cout << row % 10 << '\n';
	}
	DisplayCountRow();
}

void DisplayCountRow() {
	cout << ' ';
	for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
		cout << col % 10;
	}
	cout << '\n';
}