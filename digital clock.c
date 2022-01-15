#include <stdio.h>
#include <time.h>         //this is header file for time
#include <windows.h>

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{

    long i = 0;                      /* Loop counter              */
    clock_t now = 0;                 /* Holds initial clock time  */
    int interval = 1;                /* Seconds interval for o/p  */
    int elapsed = 0;
    int min=0,MIN=0,hrs=0,sec=0;
    int d=0,f=0;
    now = clock(); /* Get current clock time    */

    for(i = 0L ;  ; i++)
    {
        elapsed = (clock()-now)/CLOCKS_PER_SEC;

        if(elapsed>=interval)
        {
            interval += 1;
            if(elapsed%60==0)
            {
                min=elapsed/60;
                d=60*min;
                if(min%60==0)
                {
                    hrs=min/60;
                    f=60*hrs;
                }
            }
            sec=elapsed-d;
            MIN=min-f;
            if(hrs<10)
            {
                gotoxy(2,4);
                printf("0%d",hrs);
            }
            else
            {
                gotoxy(2,4);
                printf(":%d",hrs);
            }
            if(min<10)
            {
                gotoxy(4,4);
                printf(":0%d",MIN);
            }
            else
            {
                gotoxy(4,4);
                printf(":%2d",MIN);
            }

            if(sec<10)
            {
                gotoxy(7,4);
                printf(":0%d",sec);
            }
            else
            {
                gotoxy(7,4);
                printf(":%2d",sec);
            }
            gotoxy(7,7);
            printf("%dhrs:%dmin:%dsec",hrs,MIN,sec);
        }
    }

    return 0;
}
