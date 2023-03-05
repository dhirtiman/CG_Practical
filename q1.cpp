#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, (char *)"");

    int x, y, x1, y1, x2, y2, p, dx, dy;

    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x2, &y2);

    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    putpixel(x, y, 2);

    p = (2 * dy - dx);

    while (x <= x2)
    {

        if (p < 0)
        {
            x = x + 1;
            p = 2 * x - dx;
        }
        else
        {
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy;
        }
        putpixel(x, y, 7);
    }

    getch();
    closegraph();
    return 0;
}
