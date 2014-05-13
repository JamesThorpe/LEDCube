#pragma once
#ifndef FONT_HDR
#define FONT_HDR

#ifndef VSBUILD  
#include "Arduino.h"
#else
#include <Windows.h>
#include "..\ard.h"
#endif
#define FONTFACE2

#ifndef FONTFACE2
	#define FONT_HEIGHT 5
	#define FONT_WIDTH 3
#else
	#define FONT_HEIGHT 8
	#define FONT_WIDTH 5
#endif

struct font_char {
   byte f[FONT_WIDTH];
};

extern struct font_char GetFontDataForCharacter(char chr);
extern unsigned char GetByteForCharacterColumn(bool* data, char column);
extern unsigned char GetByteForCharacterColumn(char chr, char column);

extern PROGMEM prog_uchar FONT_A[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_B[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_C[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_D[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_E[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_F[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_G[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_H[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_I[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_J[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_K[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_L[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_M[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_N[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_O[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_P[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_Q[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_R[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_S[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_T[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_U[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_V[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_W[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_X[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_Y[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_Z[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_SPACE[FONT_WIDTH];
extern PROGMEM prog_uchar FONT_EXC[FONT_WIDTH];
/*
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
extern const bool FONT_UNKNOWN[FONT_HEIGHT][FONT_WIDTH];
*/
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
