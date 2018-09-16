#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Board
const int NUM_ROWS = 19;
const int NUM_COLS = 19;
//Location
const int UNKNOWN = -1;
const int O = 0;
const int X = 1;
//turn
const int X_TURN = 1;
const int O_TURN = 0;

class Location {
public:
	int row; int col; int value;
};


Location board[NUM_ROWS + 1][NUM_COLS + 1];
Location tempLoc;

int turn;
void initTurn();
void newTurn();
void changeTurn();
void initBoard();
void updateBoard(Location loc);
void printBoard();
char getLocationString(int value);
Location getLocation();
bool isAvailableLocation(Location loc);
bool isFinish();
int main() {
	initTurn();
	initBoard();
	do {
		system("cls");
		printBoard();
		newTurn();
		bool check = isFinish();
	} while (!isFinish());
	printBoard();
	cout << "finish game";
	cin.get();
	cin.get();
	return 0;
}

void initTurn() {
	srand(time(NULL));
	turn = rand() % 2;
}

void newTurn() {
	// nhap toa do
	changeTurn();
	char c;
	if (turn == X_TURN) {
		c = 'X';
	}
	else if (turn == O_TURN) {
		c = 'O';
	}
	cout << "Turn of " << c << endl;
	do {
		tempLoc = getLocation();
	} while (!isAvailableLocation(tempLoc));
	updateBoard(tempLoc);
}

void changeTurn() {
	turn = (turn+1)%2;
}

void initBoard() {
	for (int row = 0; row <= NUM_ROWS; row++) {
		for (int col = 0; col <= NUM_COLS; col++) {
			board[row][col].row = row;
			board[row][col].col = col;
			board[row][col].value = UNKNOWN;
		}
	}
}

void updateBoard(Location loc) {
	board[loc.row][loc.col].value = loc.value;
}

void printBoard() {
	char startChar = 'A';
	for (int row = 0; row <= NUM_ROWS; row++) {
		for (int col = 0; col <= NUM_COLS; col++) {
			if (col == 0) {
				if (row == 0) {
					cout << "  ";
				}
				else {
					cout << (char)(startChar + row -1);
					cout << "|";
				}
			} else if (row == 0) {
				if (col < 10) {
					cout << " ";
				}
				cout << col;
				cout << "|";
			}
			else {
				cout << " ";
				cout << getLocationString(board[row][col].value);
				cout << "|";
			}
		}
		/*cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << "_";
		}*/
		cout << endl;
	}
}

char getLocationString(int value) {
	char s = ' ';
	switch (value) {
		case UNKNOWN:
			s = ' ';
			break;
		case O:
			s = 'O';
			break;
		case X:
			s = 'X';
			break;
		default:
			cout << "error: khong tim thay gia tri phu hop";
			break;
	}
	return s;
}

Location getLocation() {
	Location loc;
	cout << "nhap row, col: ";
	int start = 'A';
	char row;
	cin >> row >> loc.col;
	loc.row = row - start + 1;
	if (turn == X_TURN) {
		loc.value = X;
	}
	else if (turn == O_TURN) {
		loc.value = O;
	}
	return loc;
}

bool isAvailableLocation(Location loc) {
	return loc.row <= NUM_ROWS && loc.col <= NUM_COLS && loc.row >= 1 && loc.col >= 1 && board[loc.row][loc.col].value == UNKNOWN;
}

bool isFinish() {
	int row = tempLoc.row;
	int col = tempLoc.col;
	int val = tempLoc.value;

	//horizontal
	int left = col, right = col;
	while (board[row][left-1].value == val) {
		left--;
	}
	while (board[row][right+1].value == val) {
		right++;
	}
	//cout << "ngang" << right - left + 1 << endl;
	if (right - left + 1 == 5) {
		return true;
	}

	//vertical
	int up = row, down = row;
	while (board[up-1][col].value == val) {
		up--;
	}
	while (board[down+1][col].value == val) {
		down++;
	}
	//cout << "doc" << down - up + 1 << endl;

	if (down - up + 1 == 5) {
		return true;
	}

	//cheo 1 (tu tren xuong, tu trai qua phai)
	//vertical
	int lowR1 = row, highR1 = row;
	int lowC1 = col, highC1 = col;
	while (board[lowR1-1][lowC1-1].value == val) {
		lowR1--;
		lowC1--;
	}

	while (board[highR1+1][highC1+1].value == val) {
		highR1++;
		highC1++;
	}
	//cout << "cheo1" << lowR1 - lowC1 + 1 << endl;

	if (lowR1 - lowC1 + 1 == 5) {
		return true;
	}

	//cheo 2 (tu tren xuong, tu phai qua trai)
	//vertical
	int lowR2 = row, highR2 = row;
	int lowC2 = col, highC2 = col;
	while (board[lowR2-1][lowC2+1].value == val) {
		lowR2--;
		lowC2++;
	}

	while (board[highR2+1][highC2-1].value == val) {
		highR2++;
		highC2--;
	}

	//cout << "cheo2" << lowR2 - lowC2 + 1 << endl;
	
	if (lowR2 - lowC2 + 1 == 5) {
		return true;
	}

	return false;
}