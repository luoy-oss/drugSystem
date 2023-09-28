#ifndef TABLE_H
#define TABLE_H

// 表格单元格结构体
typedef struct {
    int x;  // 单元格左上角x坐标
    int y;  // 单元格左上角y坐标
    int width;  // 单元格宽度
    int height; // 单元格高度
} TableCell;

//绘制表格
void drawTable(int x, int y, int rows, int columns, int cellWidth, int cellHeight);


//高亮表格某行
void lightTableAT(int x, int y, int row, int column, int cellWidth, int cellHeight, int color);

#endif
