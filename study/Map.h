#ifndef __MAP_H__
#define __MAP_H__

#define MAP_SIZE 30
#define EMPTY 0
#define WALL 1


typedef int MData;

void map_clear(MData (*arr)[MAP_SIZE]);
void draw_map(MData (*arr)[MAP_SIZE]);
void drawMainMap(MData(*map)[MAP_SIZE]);
void gotoxy(int x, int y);

#endif
