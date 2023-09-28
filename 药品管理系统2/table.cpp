#include <graphics.h>
#include <string>
#include "auxiliaryFunction.h"
#include "table.h"

void drawTable(int x, int y, int rows, int columns, int cellWidth, int cellHeight) {
    if (rows == 0 || columns == 0) return;
    int tableWidth = columns * cellWidth;
    int tableHeight = rows * cellHeight;
    setlinecolor(WHITE);
    rectangle(x, y, x + tableWidth, y + tableHeight);       //绘制表格外框

    for (int i = 1; i < columns; i++) {
        line(x + i * cellWidth, y, x + i * cellWidth, y + tableHeight);
    }

    for (int i = 1; i < rows; i++) {
        line(x, y + i * cellHeight, x + tableWidth, y + i * cellHeight);
    }
}

void lightTableAT(int x, int y, int row, int column, int cellWidth, int cellHeight,int color) {
    if (row <= 0 || column <= 0) return;

    int linex1 = x;
    int liney1 = y + (row - 1) * cellHeight;
    int linex2 = x + column * cellWidth;
    int liney2 = y + row * cellHeight;
    setlinecolor(color);
    
    line(x, y + (row - 1) * cellHeight, x + column * cellWidth, y + (row - 1) * cellHeight);
    line(x, y + row * cellHeight, x + column * cellWidth, y + row * cellHeight);
    for (int i = 0; i <= column; i++) {
        line(x + i * cellWidth, liney1, x + i * cellWidth, liney2);
    }

}
