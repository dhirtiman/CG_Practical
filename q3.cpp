using namespace std;
#include <graphics.h>
#include <iostream>
#include <conio.h>
float x1, yi, x2, y2, wx1, wyi, wx2, wy2, m;
int gd, gm;
int main()
{
    
    cout << "\nEnter the clip window coordinates : ";
    cin >> wx1 >> wyi >> wx2 >> wy2;
    cout << "\nEnter the line end points : ";
    cin >> x1 >> yi >> x2 >> y2;
    m = (y2 - yi) / (x2 - x1);
    int gd=DETECT,gm;
    initgraph(&gd, &gm, (char*)"");
    cout << "\n\n\t\t\t\tBefore Clipping";
    rectangle(wx1, wyi, wx2, wy2);
    line(x1, yi, x2, y2);
    getch();
    closegraph();
    if (x1 < wx1)
    {
        yi = yi + (wx1 - x1) * m;
        x1 = wx1;
    }
    if (x2 > wx2)
    {
        y2 = y2 - (x2 - wx2) * m;
        x2 = wx2;
    }
    if (y2 > wy2)
    {
        x2 = x2 - ((y2 - wy2) / m);
        y2 = wy2;
    }
    if (yi < wyi)
    {
        x1 = x1 + (wyi - yi) / m;
        yi = wyi;
    }
    if (x2 < wx1)
    {
        y2 = y2 + (wx1 - x2) * m;
        x2 = wx1;
    }
    if (x1 > wx2)
    {
        yi = yi - (x1 - wx2) * m;
        x1 = wx2;
    }
    if (y2 < wyi)
    {
        x2 = x2 + ((wyi - y2) / m);
        y2 = wyi;
    }
    if (yi > wy2)
    {
        x1 = x1 - ((yi - wy2) / m);
        yi = wy2;
    }

    initgraph(&gd, &gm, (char*)"");
    cout << "\n\n\t\t\t\tAfter Clipping";
    rectangle(wx1, wyi, wx2, wy2);
    line(x1, yi, x2, y2);
    getch();
    return 0;
}