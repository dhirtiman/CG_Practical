using namespace std;
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>
int gd, gm, i, ch1, ch2;
double x1, x2, yi, y2, x, y, z, theta, temp, temp1;
void draw(double[20][3]);

int main()
{
    do
    {
        double edge[20][3] = {100, 0, 0,
                              100, 100, 0,
                              0, 100, 0,
                              0, 100, 100,
                              0, 0, 100,
                              0, 0, 0,
                              100, 0, 0,
                              100, 0, 100,
                              100, 100, 100,
                              100, 100, 100,
                              100, 100, 100,
                              100, 100, 0,
                              100, 100, 100,
                              100, 100, 100,
                              100, 100, 100,
                              0, 100, 100,
                              0, 100, 0,
                              0, 0, 0,
                              0, 0, 100,
                              100, 0, 100};

        cout << "Choose any one 3D Transformation : ";
        cout << "\n\t1. Translation ";
        cout << "\n\t2. Rotation ";
        cout << "\n\t3. Scaling ";
        cout << "\nEnter your choice : \t";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            cout << "\nEnter the translation factors(tx,ty,tz) : \t";
            cin >> x >> y >> z;
            draw(edge);
            for (i = 0; i < 20; i++)
            {
                edge[i][0] += x;
                edge[i][1] += y;
                edge[i][2] += z;
            }
            draw(edge);
            break;
        case 2:
            cout << "\n\n\t1.Rotation about X Axis ";
            cout << "\n\t2. Rotation about Y Axis ";
            cout << "\n\t3. Rotation about Z Axis ";
            cout << "\nEnter your choice : \t";
            cin >> ch2;
            cout << "\n\nEnter the angle of rotation : \t";
            cin >> theta;
            theta = (theta * 3.14) / 180;
            switch (ch2)
            {
            case 1:
                draw(edge);
                for (i = 0; i < 20; i++)
                {
                    temp = edge[i][1];
                    temp1 = edge[i][2];
                    edge[i][1] = temp * cos(theta) - temp1 * sin(theta);
                    edge[i][2] = temp * sin(theta) + temp1 * cos(theta);
                }
                draw(edge);
                break;
            case 2:
                draw(edge);
                for (i = 0; i < 20; i++)
                {
                    temp = edge[i][0];
                    temp1 = edge[i][2];
                    edge[i][0] = temp * cos(theta) + temp1 * sin(theta);
                    edge[i][2] = -temp * sin(theta) + temp1 * cos(theta);
                }
                draw(edge);
                break;
            case 3:
                draw(edge);
                for (i = 0; i < 20; i++)
                {
                    temp = edge[i][0];
                    temp1 = edge[i][1];
                    edge[i][0] = temp * cos(theta) - temp1 * sin(theta);
                    edge[i][1] = temp * sin(theta) + temp1 * cos(theta);
                }
                draw(edge);
                break;
            }
            break;
        case 3:
            cout << "\n\nEnter the scaling factors (sx,sy,sz) : \t";
            cin >> x >> y >> z;
            draw(edge);
            for (i = 0; i < 20; i++)
            {
                edge[i][0] *= x;
                edge[i][1] *= y;
                edge[i][2] *= z;
            }
            draw(edge);
            break;
        }
    } while (ch1 < 10);
    return 0;
}
void draw(double edge[20][3])
{
    initgraph(&gd, &gm, (char*)"");
    line(320, 240, 320, 25);
    line(320, 240, 550, 240);
    line(320, 240, 150, 410);
    for (int i = 0; i < 19; i++)
    {
        x1 = edge[i][0] + edge[i][2] * (cos(2.3562));
        yi = edge[i][1] - edge[i][2] * (sin(2.3562));
        x2 = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
        y2 = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
        line(x1 + 320, 240 - yi, x2 + 320, 240 - y2);
    }
    getch();
    closegraph();
}
