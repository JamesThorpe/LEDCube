#ifndef VSBUILD
#include "Arduino.h"
#else
#include <Windows.h>
#endif
#include "font.h"

unsigned char GetByteForCharacterColumn(bool data[FONT_HEIGHT][FONT_WIDTH], char column) {
  unsigned char ret = 0;
  for (char x = 0; x < FONT_HEIGHT; x++) {
    ret |= data[x][column] << (7-x);  
  }
  return ret;
}
unsigned char GetByteForCharacterColumn(char chr, char column) {
  struct font_char f = GetFontDataForCharacter(chr);
  return GetByteForCharacterColumn(f.f, column);
}

struct font_char GetFontDataForCharacter(char chr) {
  struct font_char ret;
  switch (chr) {
    case 'A':
    case 'a':
      memcpy(&ret.f, &FONT_A[0][0], sizeof(FONT_A));
      break;
    case 'B':
    case 'b':
      memcpy(&ret.f, &FONT_B[0][0], sizeof(FONT_B));
      break;
    case 'C':
    case 'c':
      memcpy(&ret.f, &FONT_C[0][0], sizeof(FONT_C));
      break;
    case 'D':
    case 'd':
      memcpy(&ret.f, &FONT_D[0][0], sizeof(FONT_D));
      break;
    case 'E':
    case 'e':
      memcpy(&ret.f, &FONT_E[0][0], sizeof(FONT_E));
      break;
    case 'F':
    case 'f':
      memcpy(&ret.f, &FONT_F[0][0], sizeof(FONT_F));
      break;
    case 'G':
    case 'g':
      memcpy(&ret.f, &FONT_G[0][0], sizeof(FONT_G));
      break;
    case 'H':
    case 'h':
      memcpy(&ret.f, &FONT_H[0][0], sizeof(FONT_H));
      break;
    case 'I':
    case 'i':
      memcpy(&ret.f, &FONT_I[0][0], sizeof(FONT_I));
      break;
    case 'J':
    case 'j':
      memcpy(&ret.f, &FONT_J[0][0], sizeof(FONT_J));
      break;
    case 'K':
    case 'k':
      memcpy(&ret.f, &FONT_K[0][0], sizeof(FONT_K));
      break;
    case 'L':
    case 'l':
      memcpy(&ret.f, &FONT_L[0][0], sizeof(FONT_L));
      break;
    case 'M':
    case 'm':
      memcpy(&ret.f, &FONT_M[0][0], sizeof(FONT_M));
      break;
    case 'N':
    case 'n':
      memcpy(&ret.f, &FONT_N[0][0], sizeof(FONT_N));
      break;
    case 'O':
    case 'o':
      memcpy(&ret.f, &FONT_O[0][0], sizeof(FONT_O));
      break;
    case 'P':
    case 'p':
      memcpy(&ret.f, &FONT_P[0][0], sizeof(FONT_P));
      break;
    case 'Q':
    case 'q':
      memcpy(&ret.f, &FONT_Q[0][0], sizeof(FONT_Q));
      break;
    case 'R':
    case 'r':
      memcpy(&ret.f, &FONT_R[0][0], sizeof(FONT_R));
      break;
    case 'S':
    case 's':
      memcpy(&ret.f, &FONT_S[0][0], sizeof(FONT_S));
      break;
    case 'T':
    case 't':
      memcpy(&ret.f, &FONT_T[0][0], sizeof(FONT_T));
      break;
    case 'U':
    case 'u':
      memcpy(&ret.f, &FONT_U[0][0], sizeof(FONT_U));
      break;
    case 'V':
    case 'v':
      memcpy(&ret.f, &FONT_V[0][0], sizeof(FONT_V));
      break;
    case 'W':
    case 'w':
      memcpy(&ret.f, &FONT_W[0][0], sizeof(FONT_W));
      break;
    case 'X':
    case 'x':
      memcpy(&ret.f, &FONT_X[0][0], sizeof(FONT_X));
      break;
    case 'Y':
    case 'y':
      memcpy(&ret.f, &FONT_Y[0][0], sizeof(FONT_Y));
      break;
    case 'Z':
    case 'z':
      memcpy(&ret.f, &FONT_Z[0][0], sizeof(FONT_Z));
      break;
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
      break;
    case '!':
      memcpy(&ret.f, &FONT_EXC[0][0], sizeof(FONT_EXC));
      break;
    case ' ':
      memcpy(&ret.f, &FONT_SPACE[0][0], sizeof(FONT_SPACE));
      break;
    default:
      memcpy(&ret.f, &FONT_UNKNOWN[0][0], sizeof(FONT_UNKNOWN));
      break;
   
  }
  return ret;
}

#ifndef FONTFACE2
bool FONT_A[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1}
};

bool FONT_B[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,1,0}
};

bool FONT_C[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{0,1,1}
};

bool FONT_D[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,0}
};

bool FONT_E[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,1},
	{1,0,0},
	{1,1,1}
};

bool FONT_F[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,0},
	{1,0,0},
	{1,0,0}
};

bool FONT_G[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,0,1},
	{1,0,1},
	{0,1,1}
};

bool FONT_H[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1}
};

bool FONT_I[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{1,1,1}
};

bool FONT_J[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,1},
	{0,0,1},
	{0,0,1},
	{1,0,1},
	{1,1,0}
};

bool FONT_K[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,0,1}
};

bool FONT_L[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{1,0,0},
	{1,1,1}
};

bool FONT_M[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{1,0,1},
	{1,0,1}
};

bool FONT_N[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,1,1},
	{1,1,1},
	{1,1,1},
	{1,0,1}
};

bool FONT_O[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{0,1,0}
};
bool FONT_P[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,0},
	{1,0,0}
};
bool FONT_Q[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,1,1}
};

bool FONT_R[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{1,0,1},
	{1,1,0},
	{1,0,1},
	{1,0,1}
};
bool FONT_S[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{0,1,0},
	{0,0,1},
	{1,1,0}
};
bool FONT_T[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};
bool FONT_U[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,1}
};
bool FONT_V[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{0,1,0}
};
bool FONT_W[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{1,0,1},
	{1,1,1},
	{1,0,1}
};
bool FONT_X[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{1,0,1}
};
bool FONT_Y[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};
bool FONT_Z[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,0,1},
	{0,1,0},
	{1,0,0},
	{1,1,1}
};
bool FONT_SPACE[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

bool FONT_0[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{1,1,1},
	{1,0,1},
	{0,1,0}
};

bool FONT_1[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,1,0},
	{0,1,0},
	{0,1,0},
	{1,1,1}
};
bool FONT_2[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{0,0,1},
	{0,1,0},
	{1,0,0},
	{1,1,1}
};
bool FONT_3[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,0},
	{0,0,1},
	{1,1,0},
	{0,0,1},
	{1,1,0}
};
bool FONT_4[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{1,0,1},
	{0,1,1},
	{0,0,1},
	{0,0,1}
};
bool FONT_5[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{1,0,0},
	{1,1,0},
	{0,0,1},
	{1,1,0}
};
bool FONT_6[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1},
	{1,0,0},
	{1,1,0},
	{1,0,1},
	{0,1,0}
};

bool FONT_7[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1},
	{0,0,1},
	{0,1,0},
	{0,1,0},
	{0,1,0}
};

bool FONT_8[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{0,1,0}
};

bool FONT_9[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{1,0,1},
	{0,1,1},
	{0,0,1},
	{1,1,0}
};

bool FONT_HYP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{1,1,1},
	{0,0,0},
	{0,0,0}
};

bool FONT_STOP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{1,0,0}
};

bool FONT_EXC[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0},
	{0,1,0},
	{0,1,0},
	{0,0,0},
	{0,1,0}
};

bool FONT_UNKNOWN[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,1},
	{0,1,0},
	{1,0,1},
	{0,1,0},
	{1,0,1}
};
#else

bool FONT_A[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_B[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0}
};
bool FONT_C[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{0,1,1,1,1}
};
bool FONT_D[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0}
};
bool FONT_E[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};
bool FONT_F[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0}
};
bool FONT_G[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_H[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_I[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
};
bool FONT_J[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_K[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,1,0},
	{1,0,1,0,0},
	{1,1,0,0,0},
	{1,0,1,0,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_L[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};
bool FONT_M[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,1,0,1,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_N[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,1,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_O[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_P[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0}
};
bool FONT_Q[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,0},
	{0,1,1,0,1}
};
bool FONT_R[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_S[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{0,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_T[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
};
bool FONT_U[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_V[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0}
};
bool FONT_W[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1},
	{1,0,0,0,1}
};
bool FONT_X[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,1,0,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1}
};
bool FONT_Y[FONT_HEIGHT][FONT_WIDTH] = {
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
};
bool FONT_Z[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};
bool FONT_SPACE[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
bool FONT_0[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,1,1},
	{1,0,1,0,1},
	{1,1,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_1[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
};
bool FONT_2[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
};
bool FONT_3[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,1,1,1,0}
};
bool FONT_4[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0,1,0},
	{0,0,1,1,0},
	{0,1,0,1,0},
	{1,1,1,1,1},
	{0,0,0,1,0},
	{0,0,0,1,0},
	{0,0,0,1,0},
	{0,0,0,1,0}
};
bool FONT_5[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,0},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,1,1,1,0}
};
bool FONT_6[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,0},
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_7[FONT_HEIGHT][FONT_WIDTH] = {
	{1,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
};
bool FONT_8[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_9[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
};
bool FONT_HYP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
bool FONT_STOP[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,0,0,0,0}
};
bool FONT_EXC[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,0,0},
	{0,0,1,0,0}
};
bool FONT_UNKNOWN[FONT_HEIGHT][FONT_WIDTH] = {
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,1,0,1,0},
	{1,0,1,0,1}
};
bool FONT_[FONT_HEIGHT][FONT_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
#endif