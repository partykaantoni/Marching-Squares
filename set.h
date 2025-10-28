
typedef struct {
	int indices[4];
	int values[4];
	int all;
} Square;

int a(int r, int c, int cols) {
	return r * cols + c;
}

void segmentSquare(int res, int* tab) {
	int len = 4 + 2 * res;
	int size = len * len;
	int halfLen = len / 2;
	
	for (int r = 0; r < len; r++) {
		for (int c = 0; c < len; c++) {
			int value = 9;
			
			if (r < halfLen) { // Upper half 0, 1, 4, 5
				if (c % len < halfLen) { // Left up 0, 4
					
					if (c < halfLen - r) value = 0;
					else value = 4;
					
				} else { // Right up 1,5
					
					if (c >= halfLen + r) value = 1;
					else value = 5;
				
					
				}
			} else { // Lower half 3, 2, 7, 6
				
				if (c % len < halfLen) {// Left down 3,7
					
					if (c <= r - halfLen) value = 3;
					else value = 7;
					
				} else { // Right down 6, 2
					
					if (c + r < len + halfLen -1) value = 6;
					else value = 2;
					
				}
			}
			tab[a(r,c, len)] = value;
		}
	}
}

void setup(int* allPoints, Square* allSquares, int cols, int rows, int size, int squares) {
	// set points
	for (int i = 0; i < size; i++) {
		allPoints[i] = rand() % 2;
	}
			
	
	for (int r = 0; r < rows - 1; r++) {
		for (int c = 0; c < cols - 1; c++) {
			int squareIndex = r * (cols - 1) + c;
			int indexU = r * (cols) + c;
			int indexD = (r + 1) * (cols) + c;
			int tempTab[4] = {indexU, indexU + 1,
			indexD + 1, indexD};
		
			int sum = 0;
			int count = 0;
			
			for (int i = 0; i < 4; i++) {
				allSquares[squareIndex].indices[i] = tempTab[i];
				allSquares[squareIndex].values[i] = allPoints[tempTab[i]];
				count += allPoints[tempTab[i]];
				sum += (i + 1) * allPoints[tempTab[i]];
			}
			int v;
			if (count > 2) v = 1;
			else if (count < 2) v = 0;
			else if (sum == 4 || sum == 6) v = 1;
			else v = 2;
			allSquares[squareIndex].all = v;
		}
	}
}