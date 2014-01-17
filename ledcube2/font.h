#pragma once
#ifndef FONT_HDR
#define FONT_HDR

#define FONTFACE

#ifndef FONTFACE2
	#define FONT_HEIGHT 5
	#define FONT_WIDTH 3
#else
	#define FONT_HEIGHT 8
	#define FONT_WIDTH 5
#endif

struct font_char {
   bool f[FONT_HEIGHT][FONT_WIDTH];
};

extern struct font_char GetFontDataForCharacter(char chr);
extern unsigned char GetByteForCharacterColumn(bool* data, char column);
extern unsigned char GetByteForCharacterColumn(char chr, char column);

extern const bool FONT_A[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_B[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_C[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_D[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_E[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_F[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_G[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_H[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_I[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_J[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_K[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_L[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_M[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_N[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_O[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_P[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_Q[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_R[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_S[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_T[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_U[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_V[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_W[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_X[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_Y[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_Z[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_SPACE[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_0[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_1[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_2[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_3[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_4[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_5[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_6[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_7[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_8[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_9[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_HYP[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_STOP[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_EXC[FONT_HEIGHT][FONT_WIDTH];
extern const bool FONT_UNKNOWN[FONT_HEIGHT][FONT_WIDTH];

#endif

/*


bool FONT_B[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};





*/
