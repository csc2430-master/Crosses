const int NUMBER_OF_ROWS = 20;
const int NUMBER_OF_COLUMNS = 20;

struct Location {
	int row;
	int col;
};

struct Canvas {
	char chars[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
};

void InitCanvas(Canvas& canvas);
bool PlaceCross(Canvas& canvas, const Location& center, int horiz, int vert, char ch);
void DisplayCross(const Canvas& C);
