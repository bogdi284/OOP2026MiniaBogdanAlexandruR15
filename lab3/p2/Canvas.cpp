#include <iostream>
#include <math.h>
#include "Canvas.h"

Canvas::Canvas (int width , int height) {
    this->width = width ;
    this->height = height ;
    grid = new char*[height] ;
    for (int i = 0 ; i < height ; i++) {
        grid[i] = new char[width];
        for (int j = 0 ; j < width ; j++) {
            grid[i][j] = ' ';
        }
    }
}
Canvas::~Canvas() {
    for (int i = 0 ; i < height ; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}
void Canvas::SetPoint (int x , int y , char ch) {
    if (x>=0 && x<width && y>=0 && y<height) {
        grid[y][x] = ch;
    }
}
void Canvas::DrawLine (int x1 , int y1 , int x2 , int y2 , char ch) {
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int sx = (x1 < x2) ? 1 : -1 ;
    int sy = (y1 < y2) ? 1 : -1 ;
    int err = dx - dy;

    while (true) {
        SetPoint (x1 , y1 , ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2* err;
        if(e2 > -dy) {
            err = err - dy ;
            x1 = x1 + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}
void Canvas::DrawCircle (int x , int y , int ray , char ch) {
    int cx = ray , cy = 0;
    int err = 0;
    while (cx>=cy) {
        SetPoint(x+cx , y+cy , ch);
        SetPoint(x+cy , y+cx , ch);
        SetPoint(x-cy , y+cx , ch);
        SetPoint(x-cx , y+cy , ch);
        SetPoint(x-cx , y-cy , ch);
        SetPoint(x-cy , y-cx , ch);
        SetPoint(x+cy , y-cx , ch);
        SetPoint(x+cx , y-cy , ch);
        if (err <=0) {
            cy++;
            err += 2*cy+1;
        }
        else {
            cx--;
            err -= 2*cx+1;
        }
    }
}
void Canvas::FillCircle (int x , int y , int ray , char ch) {
    for (int dy = -ray ; dy <= ray ; dy++) {
        for (int dx = - ray ; dx<=ray ; dx++) {
            if (dx*dx+dy*dy <= ray * ray) {
                SetPoint(x+dx , y+dy , ch);
            }
        }
    }
}
void Canvas::DrawRect(int left , int top , int right , int bottom , char ch) {
    DrawLine (left , top , right ,top , ch);
    DrawLine (left , bottom , right , bottom , ch);
    DrawLine (left , top , left , bottom , ch);
    DrawLine (right , top , right , bottom ,ch);
}
void Canvas::FillRect (int left , int top , int right , int bottom , char ch) {
    for (int i = top ; i<=bottom ; i++) {
        for (int j = left ; j<= right ; j++) {
            SetPoint(i , j , ch);
        }
    }
}
void Canvas::Print() {
    for (int i = 0 ; i< height ; i++) {
        for (int j = 0 ; j< width ; j++) {
            std::cout<<grid[i][j];
        }
        std::cout<<'\n';
    }
}
void Canvas::Clear() {
    for (int i = 0 ; i < height ; i++) {
        for (int j = 0 ; j < width ; j++) {
            grid[i][j] = ' ';
        }
    }
}