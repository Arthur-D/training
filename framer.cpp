#include <iostream>
#include <time.h>
using namespace std;
     
#define WIDTH 20
#define HEIGHT 20
     
bool board[WIDTH][HEIGHT];
bool lefttoright = true;
       
void clearBoard () {
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			board[w][h] = false;
		}
	}
}

void draw () {
	for (int a = 0; a != 5; a++) {
		cout << "\n";
	}
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			if (board[w][h] == true) {
				cout << '*';
			}
			else {
				cout << '.';
			}
			cout << "\n";
		}
	}
}

void logic () {
	bool previous_board[WIDTH][HEIGHT];
	if (lefttoright == true) {
        for (int h = 0; h < HEIGHT; h++) {
            for (int w = 0; w < WIDTH; w++) {
                previous_board[w][h] = board[w][h];
            }
        }
	}
	else {
		for (int h = HEIGHT; h < 0; h--) {
	        for (int w = WIDTH; w < 0; w--) {
	            previous_board[w][h] = board[w][h];
			}
		}
	}
	clearBoard();
	if (lefttoright == true) {
		for (int h = 0; h < HEIGHT; h++) {
			for (int w = 0; w < WIDTH; w++) {
				if (previous_board[w][h] == true) {
					if (w+1 < WIDTH) {
						board[w+1][h] = true;
					}
					else {
						lefttoright = false;
					}
				}
			}
		}
	}    
	else {
		for (int h = HEIGHT; h > 0; h--) {
			for (int w = WIDTH; w > 0; w--) {
				if (previous_board[w][h] == true) {
					if (w-1 > 0) {
						board[w-1][h] = true;
					}
					else {
						lefttoright = false;
					}
				}
			}
		}
	}
}

void sleep () {
	int milisec = 500; // length of time to sleep, in miliseconds
	struct timespec req = {0};
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;
	nanosleep(&req, (struct timespec *)NULL);
}
 
int main () {
	clearBoard ();
	board[0][HEIGHT/2] = true;
	while(true) {
		draw ();
		logic ();
		sleep ();
	}
	return 0;
}
