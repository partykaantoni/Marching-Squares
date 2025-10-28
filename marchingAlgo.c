#include <stdio.h>
#include <stdlib.h>

#include "disp.h"
#include "set.h"

void setHash(int* hash, int* val, int state) {
	for (int i = 0; i < 4; i++) {
		int A = val[i];
		hash[i] = A;
		if (state != 2) hash[i + 4] = state;
		else hash[i + 4] = A;
	}
}

int min(int a, int b) {
	if (a >= b) return b;
	return a;
}

int max(int a, int b) {
	if (a >= b) return a;
	return b;
}

void setScreen(int* screen, int* look, int rows, int cols, int side) {
	int ind;
	int uBound = max(rows, cols);
	screen[0] = 0;
	for (int i = 1; i < uBound; i++) {
		
		screen[i] = look[(i - 1) % (side - 1) + 1];
		if (i >= rows) continue;
		screen[i * cols] = look[((i - 1) % (side - 1) +1) * side];
	}
	
	int rt, ct;
	
	for (int r = 1; r < rows; r++) {
		for (int c = 1; c < cols; c++) {
			rt = (r - 1) % (side - 1) + 1;
			ct = (c - 1) % (side - 1) + 1;
			screen[a(r, c, cols)] = look[a(rt, ct, side)];
			
		}
	}
	
	printScreen(screen, cols, cols * rows);
}

void sS(int* screen, int* look, Square* squares, int scR, int scC, int sqR, int sqC, int side) {
	for ( int i = 0; i < scR * scC; i++) {
		screen[i] = 9;
	}
	int hash[8];
	int index = 0;
	int cStart, rStart, start, rt, ct;
	for (int r = 0; r < sqR; r++) {
		for (int c = 0; c < sqC; c++) {
			setHash(hash, squares[index].values, squares[index].all);
			rStart = r * (side - 1);
			cStart = c * (side - 1);
			
			if (r == 0) {
				if (c == 0) screen[0] = hash[look[0]];
				cStart = c * (side - 1);
				for (int i = 1; i < side; i++) {
					screen[a(0, cStart + i, scC)] = hash[look[i]];
					//hash[look[i]];
				}
			}
			if (c == 0) {
				rStart = r * (side - 1);
				for (int i = 1; i < side; i++) {
					screen[a(rStart + i, 0, scC)] = hash[look[side * i]];
				}
			}
			
			for (int tRow = 1; tRow < side; tRow++) {
				for (int tCol = 1; tCol < side; tCol++) {
					screen[a(rStart + tRow, cStart + tCol, scC)] = hash[look[a(tRow, tCol, side)]];
				}
			}
			index++;
		}
	}
	printScreen(screen, scC, scR * scC);
}

void makeSquare(Square s, int* look, int len) {
	
	int hash[8];
	setHash(hash, s.values, s.all);
	int size = len * len;
	int sq[size];
	
	for (int i = 0; i < size; i++) {
		sq[i] = hash[look[i]];
	}
	//printArray(look, len, size);
	//pr(s.all);
	int t = s.values[2];
	s.values[2] = s.values[3];
	s.values[3] = t;
	
	printArray(s.values, 2, 4);
	printf("\n");
	printHash(hash);
	printf("\n");
	printArray(sq, len, size);
	printf("\n====================\n");
	
}

int main() {
	// Amount of points
	int rows = 17;
	int cols = 17;
	
	// Squares are 2 * res + 4 side length
	int res = 6;

    int size = (cols + 1) * (rows + 1);
	int squares = (cols ) * (rows );
	int len = 4 + 2 * res;
	
	int lookUp[len * len];
	segmentSquare(res, lookUp);
	int allPoints[size];
	Square allSquares[squares];
	
	setup(allPoints, allSquares, cols + 1, rows + 1, size, squares);
	
	int insideLen = len - 1;
	int sRows = insideLen * rows + 1;
	int sCols = insideLen * cols + 1;
	int sSize = sRows * sCols;
	
	showPointsGrid(allPoints, cols + 1, size);
	
	//printArray(lookUp, len, len * len);
	int screen[sSize];
	int cockk = 4;
	//printArray(allSquares[cockk].values, 4, 4);
	//printArray(allSquares[cockk].indices, 4, 4);
	
	sS(screen, lookUp, allSquares, sRows, sCols, rows, cols, len);
	
	
	return 0;
}