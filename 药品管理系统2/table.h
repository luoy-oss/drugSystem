#ifndef TABLE_H
#define TABLE_H

// ���Ԫ��ṹ��
typedef struct {
    int x;  // ��Ԫ�����Ͻ�x����
    int y;  // ��Ԫ�����Ͻ�y����
    int width;  // ��Ԫ����
    int height; // ��Ԫ��߶�
} TableCell;

//���Ʊ��
void drawTable(int x, int y, int rows, int columns, int cellWidth, int cellHeight);


//�������ĳ��
void lightTableAT(int x, int y, int row, int column, int cellWidth, int cellHeight, int color);

#endif
