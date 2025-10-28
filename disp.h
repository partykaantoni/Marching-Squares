

void pr(int a) {
	printf("%d\n", a);
}

void printScreen(int* screen, int cols, int size) {
	for (int i = 0; i < size; i++) {
		if (i && i % cols == 0) printf("\n");
		if (screen[i]) printf("#");
		else printf(" ");
	}
}

void printHash(int* hash) {
	printf("%d     %d\n  %d %d   \n  %d %d   \n%d     %d\n", hash[0], hash[1], hash[4], hash[5], hash[7], hash[6], hash[3], hash[2]);
}

void printLine(int cols) {
	printf("\n#");
	for (int i = 1; i < cols; i++) {
		printf("   #");
	}
	printf("\n");
}

void showPointsGrid(int* tab, int cols, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", tab[i]);
		if (i == size - 1) break;
		if ((i + 1) % cols == 0) printLine(cols);	
	    else printf("# ");
	}
	printf("\n\n");
}

void showPoints(int* tab, int cols, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", tab[i]);
		if (i == size - 1) break;
		if ((i + 1) % cols == 0) printf("\n");
	}
}

void printArray(int* tab, int cols, int size) {
	for (int i = 0; i < size; i++) {
		if (i && i % cols == 0) printf("\n");
		printf("%d ", tab[i]);
	}
	printf("\n");
}