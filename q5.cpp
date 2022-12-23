using namespace std;

#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>
float x1, yi, x2, y2, x3, y3, x, y, rx1, ryi, rx2, ry2, rx3, ry3, t, vx1, vyi, vx2, vy2, vx3, vy3;
float w1 = 5, w2 = 5, w3 = 635, w4 = 465, v1 = 425, v2 = 75, v3 = 550, v4 = 250;
int gd, gm, ch;
void original();
void triangle(float, float, float, float, float, float);
void rotate(float, float, float);

int main()
{

    cout << "\n\t\t ***** 2D Geometric Transformations *****";
    cout << "\n\n Enter the coordinates of triangle (x1,yi,x2,y2,x3, y3): \n";
    cin >> x1 >> yi >> x2 >> y2 >> x3 >> y3;
    original();
    closegraph();
    do
    {
        cout << "\n\n Choose any one Transformation : ";
        cout << "\n\t 1.Translation \n\t 2.Rotation \n\t 3.Scaling \n\t 4.Reflection";
        cout << "\n\t 5.Shearing \n\t 6.Window-Viewport";
        cout << "\n\n Enter your choice : \t";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n Enter the translation factors (x,y): \t\t";
            cin >> x >> y;
            original();
            triangle(x1 + x, yi + y, x2 + x, y2 + y, x3 + x, y3 + y);
            closegraph();
            break;
        case 2:
            cout << "\n Enter the angle of rotation : \t\t";
            cin >> t;
            cout << "\n Enter the reference point of rotation (rx,ry) : \t";
            cin >> x >> y;
            original();
            rotate(t, x, y);
            closegraph();
            break;
        case 3:
            cout << "\n Enter the scaling factors (x,y): \t\t";
            cin >> x >> y;
            original();
            triangle(x1 * x, yi * y, x2 * x, y2 * y, x3 * x, y3 * y);
            closegraph();
            break;
        case 4:
            original();
            rotate(180, x2, y2);
            closegraph();
            break;
        case 5:
            cout << "\n Enter the Shear Value : \t\t";
            cin >> x;
            original();
            triangle(x1, yi, x2 + x, y2, x3, y3);
            closegraph();
            break;
        case 6:
            initgraph(&gd, &gm, (char*) "");
            rectangle(w1, w2, w3, w4);
            outtextxy(300, 10,(char*) "Window Port");
            triangle(x1, yi, x2, y2, x3, y3);
            x = (v3 - v1) / (w3 - w1);
            y = (v4 - v2) / (w4 - w2);
            vx1 = v1 + floor(((x1 - w1) * x) + 0.5);
            vyi = v2 + floor(((yi - w2) * y) + 0.5);
            vx2 = v1 + floor(((x2 - w1) * x) + 0.5);
            vy2 = v2 + floor(((y2 - w2) * y) + 0.5);
            vx3 = v1 + floor(((x3 - w1) * x) + 0.5);
            vy3 = v2 + floor(((y3 - w2) * y) + 0.5);
            rectangle(v1, v2, v3, v4);
            outtextxy(450, 85,(char*) "View Port");
            triangle(vx1, vyi, vx2, vy2, vx3, vy3);
            closegraph();
        }
    } while (ch <= 6);
    getch();
    return 0;
}
void original()
{
    initgraph(&gd, &gm, (char*)"");
    triangle(x1, yi, x2, y2, x3, y3);
}
void triangle(float x1, float yi, float x2, float y2, float x3, float y3)
{
    line(x1, yi, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, yi);
    getch();
}
void rotate(float t, float rx, float ry)
{
    t = t * (3.14 / 180);
    rx1 = rx + (x1 - rx) * cos(t) - (yi - ry) * sin(t);
    ryi = ry + (x1 - rx) * sin(t) + (yi - ry) * cos(t);
    rx2 = rx + (x2 - rx) * cos(t) - (y2 - ry) * sin(t);
    ry2 = ry + (x2 - rx) * sin(t) + (y2 - ry) * cos(t);
    rx3 = rx + (x3 - rx) * cos(t) - (y3 - ry) * sin(t);
    ry3 = ry + (x3 - rx) * sin(t) + (y3 - ry) * cos(t);
    triangle(rx1, ryi, rx2, ry2, rx3, ry3);
}
