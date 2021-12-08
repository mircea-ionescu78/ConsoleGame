#include <windows.h>
#include <iostream>

using namespace std;
int y=4;

char Map[60][120]={
“################################################## ",
“                 *                                                 *                             * ”,
“                                                                                                  * ”,
“                                                                                                  * ”,
“                 *                                                 *                             * ”,
“################################################## "};
bool endgame=true;

void gotoXY(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}.

void showmap (int u)
{
    for (int i=0;i<=6;i++)
    {
        for (int j=u;j<=u+70;j++)
        {
            cout<<Map[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int n=0;
    int jump=0;
    while (endgame==true)
    {
        gotoXY(0,0);
        showmap(n);
        n++;
        if (jump==0 && GetAsyncKeyState(VK_UP) && Map[y+1][n+3]=='#')jump=3;
        if (jump>0)
        {
          y--;jump--;
        }
        else if (Map[y+1][n+3]!='#')
        {
            y++;
        }
                cout<<endl;
        gotoXY(4,y);
        cout<<"@";
        if (Map[y][n+4]=='*')endgame=false;
        Sleep(28);
    }
}
