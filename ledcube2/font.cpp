#include "font.h"
/*
unsigned char GetByteForCharacterColumn(byte data[FONT_WIDTH], char column) {
  unsigned char ret = 0;
  for (char x = 0; x < FONT_HEIGHT; x++) {
    ret |= data[x][column] << (7-x);  
  }
  return ret;
}*/
unsigned char GetByteForCharacterColumn(char chr, char column) {
  struct font_char f = GetFontDataForCharacter(chr);
  return f.f[column];
  //return GetByteForCharacterColumn(f.f, column);
}

void populateStruct(struct font_char *p, prog_uchar c[])
{
	p->f[0] = pgm_read_byte_near(&c[0]);
	p->f[1] = pgm_read_byte_near(&c[1]);
	p->f[2] = pgm_read_byte_near(&c[2]);
	p->f[3] = pgm_read_byte_near(&c[3]);
	p->f[4] = pgm_read_byte_near(&c[4]);
}

struct font_char GetFontDataForCharacter(char chr) {
  struct font_char ret;
  switch (chr) {
    case 'A':
    case 'a':
		populateStruct(&ret, FONT_A);
		break;
	  break;
    case 'B':
    case 'b':
		populateStruct(&ret, FONT_B);
      break;
    case 'C':
    case 'c':
		populateStruct(&ret, FONT_C);
	  break;
    case 'D':
    case 'd':
		populateStruct(&ret, FONT_D);
      break;
    case 'E':
    case 'e':
		populateStruct(&ret, FONT_E);
      break;
    case 'F':
    case 'f':
		populateStruct(&ret, FONT_F);
      break;
    case 'G':
    case 'g':
		populateStruct(&ret, FONT_G);
      break;
    case 'H':
    case 'h':
		populateStruct(&ret, FONT_H);
      break;
    case 'I':
    case 'i':
		populateStruct(&ret, FONT_I);
      break;
    case 'J':
    case 'j':
		populateStruct(&ret, FONT_J);
      break;
    case 'K':
    case 'k':
		populateStruct(&ret, FONT_K);
      break;
    case 'L':
    case 'l':
		populateStruct(&ret, FONT_L);
      break;
    case 'M':
    case 'm':
		populateStruct(&ret, FONT_M);
      break;
    case 'N':
    case 'n':
		populateStruct(&ret, FONT_N);
      break;
    case 'O':
    case 'o':
		populateStruct(&ret, FONT_O);
      break;
    case 'P':
    case 'p':
		populateStruct(&ret, FONT_P);
      break;
    case 'Q':
    case 'q':
		populateStruct(&ret, FONT_Q);
      break;
    case 'R':
    case 'r':
		populateStruct(&ret, FONT_R);
      break;
    case 'S':
    case 's':
		populateStruct(&ret, FONT_S);
      break;
    case 'T':
    case 't':
		populateStruct(&ret, FONT_T);
      break;
    case 'U':
    case 'u':
		populateStruct(&ret, FONT_U);
      break;
    case 'V':
    case 'v':
		populateStruct(&ret, FONT_V);
      break;
    case 'W':
    case 'w':
		populateStruct(&ret, FONT_W);
      break;
    case 'X':
    case 'x':
		populateStruct(&ret, FONT_X);
      break;
    case 'Y':
    case 'y':
		populateStruct(&ret, FONT_Y);
      break;
    case 'Z':
    case 'z':
		populateStruct(&ret, FONT_Z);
		break;
	case ' ':
		populateStruct(&ret, FONT_SPACE);
		break;/*
    case '0':
      memcpy(&ret.f, &FONT_0[0][0], sizeof(FONT_0));
      break;
    case '1':
      memcpy(&ret.f, &FONT_1[0][0], sizeof(FONT_1));
      break;
    case '2':
      memcpy(&ret.f, &FONT_2[0][0], sizeof(FONT_2));
      break;
    case '3':
      memcpy(&ret.f, &FONT_3[0][0], sizeof(FONT_3));
      break;
    case '4':
      memcpy(&ret.f, &FONT_4[0][0], sizeof(FONT_4));
      break;
    case '5':
      memcpy(&ret.f, &FONT_5[0][0], sizeof(FONT_5));
      break;
    case '6':
      memcpy(&ret.f, &FONT_6[0][0], sizeof(FONT_6));
      break;
    case '7':
      memcpy(&ret.f, &FONT_7[0][0], sizeof(FONT_7));
      break;
    case '8':
      memcpy(&ret.f, &FONT_8[0][0], sizeof(FONT_8));
      break;
    case '9':
      memcpy(&ret.f, &FONT_9[0][0], sizeof(FONT_9));
      break;
    case '-':
      memcpy(&ret.f, &FONT_HYP[0][0], sizeof(FONT_HYP));
      break;
    case '.':
      memcpy(&ret.f, &FONT_STOP[0][0], sizeof(FONT_STOP));
      break;*/
    case '!':
     populateStruct(&ret, FONT_EXC);
      break;
	  /*
    default:
      memcpy(&ret.f, &FONT_UNKNOWN[0][0], sizeof(FONT_UNKNOWN));
      break;
   */
  }
  return ret;
}

#ifndef FONTFACE2
const bool FONT_A[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1}
};

const bool FONT_B[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,1,0}
};

const bool FONT_C[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{0,1,1}
};

const bool FONT_D[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,0}
};

const bool FONT_E[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,1},
	{1,0,0},
	{1,1,1}
};

const bool FONT_F[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,0},
	{1,0,0},
	{1,0,0}
};

const bool FONT_G[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,0,1},
	{1,0,1},
	{0,1,1}
};

const bool FONT_H[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1}
};

const bool FONT_I[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{1,1,1}
};

const bool FONT_J[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,1},
	{0,0,1},
	{0,0,1},
	{1,0,1},
	{1,1,0}
};

const bool FONT_K[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,0,1}
};

const bool FONT_L[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{1,1,1}
};

const bool FONT_M[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1},
	{1,0,1}
};

const bool FONT_N[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,1,1},
	{1,1,1},
	{1,1,1},
	{1,0,1}
};

const bool FONT_O[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{0,1,0}
};
const bool FONT_P[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,0},
	{1,0,0}
};
const bool FONT_Q[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,1,1}
};

const bool FONT_R[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,0,1}
};
const bool FONT_S[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{0,1,0},
	{0,0,1},
	{1,1,0}
};
const bool FONT_T[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};
const bool FONT_U[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,1}
};
const bool FONT_V[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{0,1,0}
};
const bool FONT_W[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,0,1}
};
const bool FONT_X[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{1,0,1}
};
const bool FONT_Y[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};
const bool FONT_Z[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,0,1},
	{0,1,0},
	{1,0,0},
	{1,1,1}
};
const bool FONT_SPACE[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

const bool FONT_0[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{0,1,0}
};

const bool FONT_1[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,1,0},
	{0,1,0},
	{0,1,0},
	{1,1,1}
};
const bool FONT_2[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{0,0,1},
	{0,1,0},
	{1,0,0},
	{1,1,1}
};
const bool FONT_3[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{0,0,1},
	{1,1,0},
	{0,0,1},
	{1,1,0}
};
const bool FONT_4[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,1},
	{0,0,1},
	{0,0,1}
};
const bool FONT_5[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,0},
	{0,0,1},
	{1,1,0}
};
const bool FONT_6[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,1,0},
	{1,0,1},
	{0,1,0}
};

const bool FONT_7[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,0,1},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};

const bool FONT_8[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{0,1,0}
};

const bool FONT_9[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{0,1,1},
	{0,0,1},
	{1,1,0}
};

const bool FONT_HYP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{1,1,1},
	{0,0,0},
	{0,0,0}
};

const bool FONT_STOP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{1,0,0}
};

const bool FONT_EXC[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{0,0,0},
	{0,1,0}
};

const bool FONT_UNKNOWN[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{0,1,0},
	{1,0,1}
};
#else

PROGMEM prog_uchar FONT_A[FONT_WIDTH] = {0x7F, 0x90, 0x90, 0x90, 0x7F };
/*
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_B[FONT_WIDTH] = { 0xFF, 0x91, 0x91, 0x91, 0x6E };
/*
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0}
*/
PROGMEM prog_uchar FONT_C[FONT_WIDTH] = { 0x7E, 0x81, 0x81, 0x81, 0x81 };
/*
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{0,1,1,1,1}
*/
PROGMEM prog_uchar FONT_D[FONT_WIDTH] = { 0xFF, 0x81, 0x81, 0x81, 0x7E };
/*
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0}
*/
PROGMEM prog_uchar FONT_E[FONT_WIDTH] = { 0xFF, 0x91, 0x91, 0x81, 0x81 };
/*
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
*/
PROGMEM prog_uchar FONT_F[FONT_WIDTH] = { 0xFF, 0x90, 0x90, 0x80, 0x80 };
/*
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0}
*/
PROGMEM prog_uchar FONT_G[FONT_WIDTH] = { 0x7E, 0x81, 0x91, 0x91, 0x9E };
/*
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
*/
PROGMEM prog_uchar FONT_H[FONT_WIDTH] = { 0xFF, 0x10, 0x10, 0x10, 0xFF };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_I[FONT_WIDTH] = { 0x81, 0x81, 0xFF, 0x81, 0x81 };
/*
    {1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
*/
PROGMEM prog_uchar FONT_J[FONT_WIDTH] = { 0x2, 0x1, 0x81, 0x81, 0xFE };
/*
	{0,0,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
*/
PROGMEM prog_uchar FONT_K[FONT_WIDTH] = { 0xFF, 0x10, 0x28, 0x44, 0x83 };
/*
	{1,0,0,0,1},
	{1,0,0,1,0},
	{1,0,1,0,0},
	{1,1,0,0,0},
	{1,0,1,0,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_L[FONT_WIDTH] = { 0xFF, 0x1, 0x1, 0x1, 0x1 };
/*
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};*/
PROGMEM prog_uchar FONT_M[FONT_WIDTH] = { 0xFF, 0x40, 0x20, 0x40, 0xFF };
/*
	{1,0,0,0,1},
	{1,1,0,1,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_N[FONT_WIDTH] = { 0xFF, 0x40, 0x20, 0x10, 0xFF };
/*
	{1,0,0,0,1},
	{1,1,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_O[FONT_WIDTH] = { 0x7E, 0x81, 0x81, 0x81, 0x7E };
/*
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
*/
PROGMEM prog_uchar FONT_P[FONT_WIDTH] = { 0xFF, 0x90, 0x90, 0x90, 0x60 };
/*
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0}
*/
PROGMEM prog_uchar FONT_Q[FONT_WIDTH] = { 0x7E, 0x81, 0x85, 0x82, 0x7D };
/*
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,0},
	{0,1,1,0,1}
*/
PROGMEM prog_uchar FONT_R[FONT_WIDTH] = { 0xFF, 0x90, 0x90, 0x98, 0x67 };
/*
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_S[FONT_WIDTH] = { 0x62, 0x91, 0x91, 0x91, 0x8E };
/*
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{0,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
*/
PROGMEM prog_uchar FONT_T[FONT_WIDTH] = { 0x80, 0x80, 0xFF, 0x80, 0x80 };
/*
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
*/
PROGMEM prog_uchar FONT_U[FONT_WIDTH] = { 0xFE, 0x1, 0x1, 0x1, 0xFE };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
*/
PROGMEM prog_uchar FONT_V[FONT_WIDTH] = { 0xFC, 0x2, 0x1, 0x2, 0xFC };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0}
*/
PROGMEM prog_uchar FONT_W[FONT_WIDTH] = { 0xFF, 0x2, 0x4, 0x2, 0xFF };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_X[FONT_WIDTH] = { 0xC7, 0x28, 0x10, 0x28, 0xC7 };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,1,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
*/
PROGMEM prog_uchar FONT_Y[FONT_WIDTH] = { 0xC0, 0x20, 0x1F, 0x20, 0xC0 };
/*
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
*/
PROGMEM prog_uchar FONT_Z[FONT_WIDTH] = { 0x87, 0x89, 0x91, 0xA1, 0xC1 };
/*
	{1,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
*/
PROGMEM prog_uchar FONT_SPACE[FONT_WIDTH] = { 0x00, 0x00, 0x00, 0x00 };
/*
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};*/
/*
PROGMEM prog_uchar FONT_0[FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,1,1},
	{1,0,1,0,1},
	{1,1,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
PROGMEM prog_uchar FONT_1[FONT_WIDTH] = {
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
};
PROGMEM prog_uchar FONT_2[FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};
PROGMEM prog_uchar FONT_3[FONT_WIDTH] = {
	{1,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,1,1,1,0}
};
PROGMEM prog_uchar FONT_4[FONT_WIDTH] = {
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,1,0,1,0},
	{1,1,1,1,1},
	{0,0,0,1,0},
	{0,0,0,1,0},
	{0,0,0,1,0},
	{0,0,0,1,0}
};
PROGMEM prog_uchar FONT_5[FONT_WIDTH] = {
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,1,1,1,0}
};
PROGMEM prog_uchar FONT_6[FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,0},
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
PROGMEM prog_uchar FONT_7[FONT_WIDTH] = {
	{1,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
};
PROGMEM prog_uchar FONT_8[FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
PROGMEM prog_uchar FONT_9[FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
PROGMEM prog_uchar FONT_HYP[FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
PROGMEM prog_uchar FONT_STOP[FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,0,0,0,0}
};*/
PROGMEM prog_uchar FONT_EXC[FONT_WIDTH] = { 0x00, 0x00, 0xFD, 0x00, 0x00 };
/*
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,0,0},
	{0,0,1,0,0}
*/

/*
PROGMEM prog_uchar FONT_UNKNOWN[FONT_WIDTH] = {
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1}
};
PROGMEM prog_uchar FONT_[FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
*/
#endif
