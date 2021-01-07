#include <Windows.h>
#include <iostream>

using namespace std;

struct vec2d {
    int x, y;
};

void Line(HDC dc, vec2d a, vec2d b) {
    MoveToEx(dc, a.x, a.y, NULL);
    LineTo(dc, b.x, b.y);
}

vec2d GetMousePos(HWND console) {
    vec2d out;
    POINT p;
    GetCursorPos(&p);
    out.x = p.x; 
    out.y = p.y;
    return out;
}

int main() {
    HWND console = GetConsoleWindow();
    HDC dc = GetDC(console);
    // SelectObject(dc, CreatePen(PS_SOLID, 1, RGB(255,255,255)) );

    RECT client;
    GetClientRect(console, &client);

    while (1) {
        InvalidateRect(console, &client, TRUE);
        Line(dc, {0,0}, GetMousePos(console));

    }
}