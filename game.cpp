#include "TXLib.h"

int main()
{
    int x = 0, y = 200;
    txCreateWindow(800, 600);


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();

        if (GetAsyncKeyState(VK_LEFT))
        {
            x -= 40;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            x += 40;
        }

        txSetFillColor(TX_RED);
        txCircle(x, y, 80);
        txSleep(10);
    }

    return 0;
}
