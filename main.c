

const unsigned int white = 0xFFFFFFFF;
const unsigned int black = 0;

inline short inRange(int idx, int width, int height) {
	return idx >= 0 && idx < width * height;
}

inline short checkNeighborIdx(unsigned int* boardRead, int index, int width, int height) {
	if (inRange(index, width, height)) {
		return boardRead[index] == white;
	}
	return 0;
}

inline unsigned short countNeighbors(unsigned int* boardRead, int index, int width, int height) {
	unsigned short ret = 0;

	ret += checkNeighborIdx(boardRead, index + 1, width, height);
	ret += checkNeighborIdx(boardRead, index - 1, width, height);

	ret += checkNeighborIdx(boardRead, index - width, width, height);
	ret += checkNeighborIdx(boardRead, (index - width) + 1, width, height);
	ret += checkNeighborIdx(boardRead, (index - width) - 1, width, height);

	ret += checkNeighborIdx(boardRead, index + width, width, height);
	ret += checkNeighborIdx(boardRead, (index + width) + 1, width, height);
	ret += checkNeighborIdx(boardRead, (index + width) - 1, width, height);

	return ret;
}

//Board is of length in bytes width * height * 4. Every pixel is 4 bytes, rgba, 0-255 obv
__declspec(dllexport) void tickLifeOnBoard(void* boardReadVoid, void* boardWriteVoid, int width, int height) {
	unsigned int* boardRead = (unsigned int*)boardReadVoid;
	unsigned int* boardWrite = (unsigned int*) boardWriteVoid;

	for (int q = 0; q < width * height; q++) {
		unsigned short neighborCount = countNeighbors(boardRead, q, width, height);
		if (neighborCount == 3) {
			boardWrite[q] = white;
		} else if (neighborCount == 2 && boardRead[q] == white) {
			boardWrite[q] = white;
		} else {
			boardWrite[q] = black;
		}
	}

}


