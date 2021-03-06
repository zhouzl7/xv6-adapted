#ifndef CURSOR_H
#define CURSOR_H

#include "memlayout.h"
#include "types.h"
#include "kbd.h"
#include "x86.h"

#define CRTPORT 0x3d4
#define BACKSPACE 0x100
#define INPUT_BUF 128
#define HISTORY_LOAD 10

static ushort *crt = (ushort*)P2V(0xb8000);
struct {
  char buf[INPUT_BUF];
  uint r;  // Read index
  uint w;  // Write index
  uint e;  // Edit index
  uint d;  // End index
} input;

char hisContent[HISTORY_LOAD][INPUT_BUF];
char hisLength[HISTORY_LOAD];
int hisLine, hisPos;
int firstLine, currentLine;

int cursorGetPosition();
void cursorSetPosition(int pos);
int cursorMoveLeft();
int cursorMoveRight();
#endif