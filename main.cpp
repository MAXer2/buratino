#include "TXLib.h"

void risovat_buratino(int x, int y, HDC buratino);
void risovat_moneta(int x, int y, HDC moneta);
void risovat_panel(HDC panel, int monetok_s_soboi, int monetok_v_kopilke);
void risovat_kopilka(HDC kopilka);
void risovat_prepyatstvir(int x_prep,int y_prep);
 //void fon(HDC FON);
int main()
{
    txCreateWindow (1000,1000);


 int x_prep = 20;
    int y_prep =205;
    int x = 5;

    int y = 5;
    int speed = 8;
    int monetok_s_soboi = 0;
    int monetok_v_kopilke = 0;
    int razmer_ekran= 1000;

     //HDC FON = txLoadImage("FON.bmp");


    HDC moneta = txLoadImage("moneta.bmp");
    int moneta_x = random(razmer_ekran);
    int moneta_y = random(razmer_ekran);

    int i;
    HDC buratino2 = txLoadImage("buratino2.bmp");
    HDC buratino_niz = txLoadImage("buratinopered.bmp");
    HDC buratino_verh = txLoadImage("buratinozad.bmp");
    HDC kopilka = txLoadImage("kopilka.bmp");
    HDC buratino = txLoadImage("buratino.bmp");
    HDC panel = txLoadImage("panel.bmp");
    HDC kartinka;
    txBegin();
    while (x < 20000)
    {
        txClear();
 //fon(FON);

        risovat_kopilka(kopilka);
 risovat_moneta(moneta_x, moneta_y, moneta);
        risovat_panel(panel, monetok_s_soboi, monetok_v_kopilke);
        txSetFillColor (TX_WHITE);

          for(x_prep=20; x_prep<=1000;x_prep=x_prep+3){
          txClear();
           risovat_kopilka(kopilka);
 risovat_moneta(moneta_x, moneta_y, moneta);
        risovat_panel(panel, monetok_s_soboi, monetok_v_kopilke);
        txSetFillColor (TX_WHITE);
        risovat_prepyatstvir(x_prep,y_prep);






        //f1
        if (GetAsyncKeyState(VK_LEFT)&& x > 0)
        {
            kartinka = buratino2;
            x -= speed;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && x < 1000-156)
        {
            kartinka = buratino;
            x += speed;
        }
        else
        {
            kartinka = buratino;

        }

        if (GetAsyncKeyState(VK_UP)&& y > 0)
        {
            kartinka = buratino_verh;

            y -= speed;
        }
        else if (GetAsyncKeyState(VK_DOWN) && y < 1000)
        {
           kartinka = buratino_niz;

            y += speed;
        }

risovat_buratino(x, y, kartinka);

       //Собрал монету
        if (abs (x - moneta_x) + abs (y - moneta_y) < 150 && monetok_s_soboi<=4 && monetok_v_kopilke <5)
        {
            if (monetok_s_soboi <= 5)
            {

                moneta_x = random(1000);
                moneta_y = random(1000);
                monetok_s_soboi = monetok_s_soboi + 1;
            }
        }

        //Отнес в копилку
        if (abs (x - 650) + abs (y - 650) < 150 )
        {
            if (monetok_s_soboi <=5)
            {
                monetok_v_kopilke = monetok_v_kopilke + monetok_s_soboi;
                monetok_s_soboi = 0;
            }
            }


        txSleep(20);

         }



      txSleep(20);
    }
    txEnd();
    return 0;
}

void risovat_buratino(int x, int y, HDC buratino) {
    txTransparentBlt (txDC(), x, y, 140, 140, buratino, 0, 0, TX_WHITE);
}

void risovat_moneta(int x, int y, HDC moneta){
    txTransparentBlt (txDC(), x, y, 156, 157, moneta,0, 0, TX_WHITE);
}
void risovat_panel(HDC panel, int monetok_s_soboi, int monetok_v_kopilke) {
    txBitBlt (txDC(), 0, 0, 1000, 1000, panel,0, 0);

    char monetok_s_soboi_stroka[100];
    sprintf(monetok_s_soboi_stroka, "%d", monetok_s_soboi);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(230, 5, monetok_s_soboi_stroka);

    char monetok_v_kopilke_stroka[100];
    sprintf(monetok_v_kopilke_stroka, "%d", monetok_v_kopilke);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(930, 5, monetok_v_kopilke_stroka);
}
 void risovat_kopilka(HDC kopilka){
   txTransparentBlt (txDC(), 650, 650, 230, 158, kopilka, 0, 0, TX_WHITE);
 }

void risovat_prepyatstvir(int x_prep,int y_prep){
txSetColor(TX_BLACK,6);
txCircle(x_prep,y_prep,25);
}

void dvigenie_nazad(int x_prep,int y_prep, HDC kopilka,int moneta_x,int moneta_y,HDC moneta,HDC panel,int monetok_s_soboi,int monetok_v_kopilke){
 txClear();
           risovat_kopilka(kopilka);
 risovat_moneta(moneta_x, moneta_y, moneta);
        risovat_panel(panel, monetok_s_soboi, monetok_v_kopilke);
        txSetFillColor (TX_WHITE);
        risovat_prepyatstvir(x_prep,y_prep);
}
