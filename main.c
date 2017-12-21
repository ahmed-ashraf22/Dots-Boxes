#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <dos.h>
#include <dir.h>
void firstShape1(int gameh1[3][2],int gamev1[2][3],int n);
void initial1(int squ1[2][2],int winner1[2][2]);
void initial2(int movh1[3][2],int movv1[2][3]);
void initial3(int reh1[3][2],int rev1[2][3]);
void firstShape(int gameh[6][5],int gamev[5][6],int n);
void initial4(int gameh[6][5],int movh[6][5],int movv[5][6],int gamev[5][6]);
void initial5(int squ[5][5],int winner[5][5]);
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int i,j,t,l,a,b,g,x,x2,y,y2;
    char n = 79;
    char c = 178;
    char m = 178;
    int stateH[6][5] = {{0}};
    int stateV[5][6] = {{0}};
    int urh[6][5] = {0};
    int urv [5][6] = {0};
    int reh[6][5];
    int rev[5][6];
    int p = 0;
    int r = 0;
    int f3 = 0;
    int f4 = 0;
    int f5 = 0;
    int s = 1;
    int f10 = 0;
    int f11 = 0;
    int f12 = 0;
    int f13 = 0;
    int f15 = 0;
    int f20 = 0;
    int flag3 = 0;
    int player1Sc = 0;
    int player2Sc = 0;
    char firstElem[10];
    char secElem[10];
//shape 6x6
    int movh [6][5];
    int movv [5][6];
    int moves1 = 0;
    int moves2 = 0;
    int player1t = 1;
    int winner[5][5];
    int squ[5][5];
    int gamev[5][6];
    int gameh[6][5];
//shape 3x3
    int stateH1[3][2] = {{0}};
    int stateV1[2][3] = {{0}};
    int urh1[3][2] = {0};
    int urv1 [2][3] = {0};
    char player1n[1000];
    char player2n[1000];
    int movh1 [3][2];
    int movv1 [2][3];
    int moves11 = 0;
    int moves21 = 0;
    int reh1[3][2];
    int rev1[2][3];
    int squ1[2][2];
    int winner1[2][2];
    int gameh1[3][2] = {0};
    int gamev1[2][3] = {0};
//computer 3x3
    int newStateh1[3][2];
    int newStatev1[2][3];
    int movh21 [3][2];
    int movv21 [2][3];
    int winner21[2][2];
//computer 6x6
    int newStateh[6][5];
    int newStatev[5][6];
    int movh2 [6][5];
    int movv2 [5][6];
    int winner2[5][5];

initial1(squ1,winner1);
initial2(movh1,movv1);
initial3(reh1,rev1);
initial5(squ,winner);
initial4(gameh,movh,movv,gamev);


printf("1- Human VS Human.\n2- Human VS Computer.\n");
scanf("%d",&a);

system("cls");

if(a == 1){
    printf("1- Shape 3 x 3.\n2- Shape  6 x 6.\n");
    scanf("%d",&b);

system("cls");

if(b == 1){
    printf("PLAYER 1 NAME :");
    fgets(player1n,1000,stdin);
    while(player1n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER 1 NAME :");
    fgets(player1n,1000,stdin);
    }
    i = strlen(player1n)-1;
    while( i > 20){
    printf("Error!\nPLAYER 1 NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player1n,1000,stdin);
    i = strlen(player1n)-1;
    }
    if( player1n[ i ] == '\n')
    player1n[i] = '\0';
    printf("PLAYER 2 NAME :");
    fgets(player2n,1000,stdin);
    while(player2n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER 2 NAME :");
    fgets(player2n,20,stdin);
    }
    i = strlen(player2n)-1;
    while( i > 20){
    printf("Error!\nPLAYER 2 NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player2n,1000,stdin);
    i = strlen(player2n)-1;
    }
    if( player2n[ i ] == '\n')
    player2n[i] = '\0';
    system("cls");



    int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                %s\n\n",player2n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d",player2Sc);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                    ");

    firstShape1(gameh1,gamev1,n);

    while(s)
    {



        if(player1t == 1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%s 's Turn\n",player1n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);

            f3 = 0;
            f13 = 0;
            f15 = 0;
            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                   if(r == 0){
                            f13 = 1;
                            player1t = 1;
                        }
            else{
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(reh1[i][j] == r){
                            gameh1[i][j] = 1;
                            stateH1[i][j] = 1;
                            movh1[i][j] = 1;
                            p++;
                            urh1[i][j] = p;
                            r-=1;
                            f3 = 1;
                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                f5 = 0;
                for(i = 0;i < 2;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 3;j++){
                        if(rev1[i][j] == r){
                            gamev1[i][j] = 1;
                            stateV1[i][j] = 1;
                            p++;
                            urv1[i][j] = p;
                            r-=1;
                            movv1[i][j] = 1;
                            f5 = 1;
                            break;
                        }

                    }
                    if(f5 == 1){
                            break;
                        }
                }
                player1t=0;

for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV1[i][j+1] == 1)&&(stateV1[i][j] == 1)&&(stateH1[i][j] == 1)&&(stateH1[i+1][j] == 1)) && squ1[i][j] == 0)
                        {
                            squ1[i][j] = 1;
                            if(winner1[i][j] == 0){
                                player1Sc += 1;
                                winner1[i][j] = 1;
                                player1t = 1;
                            }

                        }
                    }
                }


                    }
            }
            else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                if(p == 0){
                    f15 = 1;
                    player1t = 1;
                }
                else{
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(urh1[i][j] == p){
                            gameh1[i][j] = 0;
                            stateH1[i][j] = 0;
                            urh1[i][j] = 0;
                            r++;
                            reh1[i][j] = r;
                            p-=1;
                            f3 = 1;
                            movh1[i][j] = 0;

                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                for(i = 0;i < 2;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 3;j++){
                        if(urv1[i][j] == p){
                            gamev1[i][j] = 0;
                            stateV1[i][j] = 0;
                            urv1[i][j] = 0;
                            r++;
                            rev1[i][j] = r;
                            p-=1;
                            movv1 [i][j] = 0;
                            f4 = 1;
                            break;
                        }
                    }
                    if(f4 == 1){
                        break;
                    }
                }
player1t=0;
for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV1[i][j+1] == 0)||(stateV1[i][j] == 0)||(stateH1[i][j] == 0)||(stateH1[i+1][j] == 0)) && squ1[i][j] == 1)
                        {
                            squ1[i][j] = 0;
                            if(winner1[i][j] == 2){
                                player2Sc -= 1;
                                winner1[i][j] = 0;
                                player1t = 0;
                            }
                            else{
                                player1Sc-=1;
                                winner1[i][j] = 0;
                                player1t = 1;
                            }
                        }
                    }
                }
              }
            }
else{
            if(((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')) && firstElem[2] == '\0')
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(firstElem[2] != '\0' || ((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if((((secElem[0] == 0)||(secElem[0] == '1')||(secElem[0] == '2'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2'))) && secElem[2] == '\0')
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')) || secElem[2] != '\0')
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            int r1,r2;
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(x2 > y2)
                {
                    r1 = y2;
                    y2 = x2;
                    x2 = r1;
                }
            if(x > y)
                {
                    r2 = y;
                    y = x;
                    x = r2;
                }
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 1;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 1;
            }
            else if(firstElem[0] == secElem[0])
            {

                if(stateH1[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gameh1[x][x2] = 1;
                stateH1[x][x2] = 1;
                p++;
                urh1[x][x2] = p;
                movh1[x][x2] = 1;
            }
            }
            else if(firstElem[1] == secElem[1])
            {

                if(stateV1[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gamev1[x][x2] = 1;
                stateV1[x][x2] = 1;
                p++;
                urv1[x][x2] = p;
                movv1 [x][x2] = 1;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 4; l++)
            {
                for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if((stateV1[i][j+1] == 1)&&(stateV1[i][j] == 1)&&(stateH1[i][j] == 1)&&(stateH1[i+1][j] == 1) && squ1[i][j] == 0)
                        {
                            squ1[i][j] = 1;
                            if(squ1[i][j] == 1)
                            {
                                winner1[i][j] = 1;
                                player1Sc += 1;
                                player1t = 1;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 0;
                            }


                        }
                        else
                        {
                            player1t = 0;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 1;

    }
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            reh1[i][j] = 20;
            rev1[j][i] = 20;
        }
    }
    r = 0;
}
        }
        }
        else
        {

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("%s 's Turn\n",player2n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);
            //convert char to int

           f3 = 0;
           f13 = 0;
           f4 = 0;
           f15 = 0;
            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                    if(r == 0){
                            f13 = 1;
                            player1t = 0;
                        }
            else{
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(reh1[i][j] == r){
                            gameh1[i][j] = 1;
                            stateH1[i][j] = 1;
                            p++;
                            urh1[i][j] = p;
                            movh1[i][j] = 2;
                            r-=1;
                            f3 = 1;

                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                f5 = 0;
                for(i = 0;i < 2;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 3;j++){
                        if(rev1[i][j] == r){
                            gamev1[i][j] = 1;
                            stateV1[i][j] = 1;
                            p++;
                            urv1[i][j] = p;
                            r-=1;
                            movv1[i][j] = 2;
                            f5 = 1;
                            break;

                        }

                    }
                    if(f5 == 1){
                            break;
                        }
                }
                player1t=1;
for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV1[i][j+1] == 1)&&(stateV1[i][j] == 1)&&(stateH1[i][j] == 1)&&(stateH1[i+1][j] == 1)) && squ1[i][j] == 0)
                        {
                            squ1[i][j] = 1;
                            if(winner1[i][j] == 0){
                                player2Sc += 1;
                                winner1[i][j] = 2;
                                player1t = 0;
                            }

                        }
                    }
                }
            }
                    }
            else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                if(p == 0){
                    f15 = 1;
                    player1t = 0;
                }
                else{
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(urh1[i][j] == p){
                            gameh1[i][j] = 0;
                            stateH1[i][j] = 0;
                            urh1[i][j] = 0;
                            r++;
                            reh1[i][j] = r;
                            p-=1;
                            f3 = 1;
                            movh1[i][j] = 0;

                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                for(i = 0;i < 2;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 3;j++){
                        if(urv1[i][j] == p){
                            gamev1[i][j] = 0;
                            stateV1[i][j] = 0;
                            urv1[i][j] = 0;
                            r++;
                            rev1[i][j] = r;
                            p-=1;
                            movv1 [i][j] = 0;
                            f4 = 1;
                            break;
                        }

                    }
                    if(f4 == 1){
                        break;
                    }
                }
player1t=1;
for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV1[i][j+1] == 0)||(stateV1[i][j] == 0)||(stateH1[i][j] == 0)||(stateH1[i+1][j] == 0)) && squ1[i][j] == 1)
                        {
                            squ1[i][j] = 0;
                            if(winner1[i][j] == 2){
                                player2Sc -= 1;
                                winner1[i][j] = 0;
                                player1t = 0;
                            }
                            else{
                                player1Sc-=1;
                                winner1[i][j] = 0;
                                player1t = 1;
                            }
                        }
                    }
                }
              }
            }
else{

            if(((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')) && firstElem[2] == '\0')
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(firstElem[2] != '\0' || ((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if((((secElem[0] == 0)||(secElem[0] == '1')||(secElem[0] == '2'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2'))) && secElem[2] == '\0')
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')) || secElem[2] != '\0')
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }

            int r1,r2;
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(x2 > y2)
                {
                    r1 = y2;
                    y2 = x2;
                    x2 = r1;
                }
            if(x > y)
                {
                    r2 = y;
                    y = x;
                    x = r2;
                }
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 0;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 0;
            }
            else if(firstElem[0] == secElem[0])
            {

                if(stateH1[x][x2] == 1){
                    player1t = 0;
                    f10 = 1;
                }
                else{
                gameh1[x][x2] = 1;
                stateH1[x][x2] = 1;
                p++;
                urh1[x][x2] = p;
                movh1[x][x2] = 2;
            }
            }
            else if(firstElem[1] == secElem[1])
            {

                if(stateV1[x][x2] == 1){
                    player1t = 0;
                    f10 = 1;
                }
                else{
                gamev1[x][x2] = 1;
                stateV1[x][x2] = 1;
                p++;
                urv1[x][x2] = p;
                movv1 [x][x2] = 2;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 4; l++)
            {
                for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if((stateV1[i][j+1] == 1)&&(stateV1[i][j] == 1)&&(stateH1[i][j] == 1)&&(stateH1[i+1][j] == 1) && squ1[i][j] == 0)
                        {
                            squ1[i][j] = 1;
                            if(squ1[i][j] == 1)
                            {
                                winner1[i][j] = 2;
                                player2Sc += 1;
                                player1t = 0;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 1;
                            }


                        }
                        else
                        {
                            player1t = 1;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 0;

    }

    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            reh1[i][j] = 20;
            rev1[j][i] = 20;
        }
    }
    r = 0;
}
}
}



        system("cls");

   /*     for(i = 0;i < 2;i++){
            for(j = 0;j < 2;j++){
                printf("%d ",squ1[i][j]);
            }
            printf("\n");
        }
        for(i = 0;i < 3;i++){
            for(j = 0;j < 2;j++){
                printf("%d ",urh1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(i = 0;i < 2;i++){
            for(j = 0;j < 3;j++){
                printf("%d ",urv1[i][j]);
            }
            printf("\n");
        }

for(i = 0;i < 3;i++){
            for(j = 0;j < 2;j++){
                printf("%d ",gameh1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(i = 0;i < 2;i++){
            for(j = 0;j < 3;j++){
                printf("%d ",gamev1[i][j]);
            }
            printf("\n");
        }


*/
flag3 = 0;
for(i = 0;i < 2;i++){
    for(j = 0;j < 2;j++){
        if(squ1[i][j] == 0){
            flag3 = 1;
        }
    }
}
if(flag3 == 1){
    s = 1;
}
else{
    s = 0;
}
moves11 = 0;
moves21 = 0;
int g;
for(i = 0;i < 3;i++){
    for(j = 0;j < 2;j++){
        if(movv1[j][i] == 1){
            moves11++;

        }
        if(movh1[i][j] == 1){
            moves11++;

        }
        if(movv1[j][i] == 2){
            moves21++;

        }
        if(movh1[i][j] == 2){
            moves21++;

        }
    }
}



   int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                %s\n\n",player2n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d\n\n",player2Sc);
    printf("                    MOVES : %d",moves11);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        MOVES : %d",moves21);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                    ");

        for(j = 0; j < 2; j++)
        {
            if(gameh1[0][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                                    ");


        for(i = 0; i < 3; i++)
        {
            if(gamev1[0][0] == 1)
            {
                if((squ1[0][0] == 1)||(squ1[0][0] > 1))
                {
                    printf("|");
                    if(winner1[0][0] == 1)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    }
                    printf("%c%c%c%c%c",m,m,m,m,m);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("|     ");
                }

            }
            if(gamev1[0][1] == 1)
            {
                if(gamev1[0][0] == 1)
                {
                    printf("|");

                }
                else
                {
                    printf("      |");
                }
            }
            if(gamev1[0][2] == 1)
            {
                if((squ1[0][1] == 1)||(squ1[0][1] > 1))
                {
                    if(gamev1[0][1] == 1)
                    {
                        if(winner1[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("%c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");

                    }
                    else if((gamev1[0][0] != 1)&&(gamev1[0][0] != 1))
                    {
                        if(winner1[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("       %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if ((gamev1[0][0] == 1)&&(gamev1[0][1] != 1))
                    {
                        if(winner1[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf(" %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }



                }


                else
                {
                    if(gamev1[0][1] == 1)
                    {

                        printf("     |");
                    }
                    else if((gamev1[0][0] != 1)&&(gamev1[0][0] != 1))
                    {
                        printf("            |");
                    }
                    else if ((gamev1[0][0] == 1)&&(gamev1[0][1] != 1))
                    {
                        printf("      |");
                    }
                }

            }
           printf("\n");
        printf("                                    ");
    }

        for(j = 0; j < 2; j++)
        {
            if(gameh1[1][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                                    ");
        for(i = 0; i < 3; i++)
        {
            if(gamev1[1][0] == 1)
            {
                if((squ1[1][0] == 1)||(squ1[1][0] > 1))
                {
                    printf("|");
                    if(winner1[1][0] == 1)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    }
                    printf("%c%c%c%c%c",m,m,m,m,m);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("|     ");
                }

            }
            if(gamev1[1][1] == 1)
            {
                if(gamev1[1][0] == 1)
                {
                    printf("|");

                }
                else
                {
                    printf("      |");
                }
            }
            if(gamev1[1][2] == 1)
            {
                if((squ1[1][1] == 1)||(squ1[1][1] > 1))
                {
                    if(gamev1[1][1] == 1)
                    {
                        if(winner1[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("%c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if((gamev1[1][0] != 1)&&(gamev1[1][0] != 1))
                    {
                        if(winner1[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("       %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if ((gamev1[1][0] == 1)&&(gamev1[1][1] != 1))
                    {
                        if(winner1[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf(" %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }



                }

                else
                {
                    if(gamev1[1][1] == 1)
                    {

                        printf("     |");
                    }
                    else if((gamev1[1][0] != 1)&&(gamev1[1][0] != 1))
                    {
                        printf("            |");
                    }
                    else if ((gamev1[1][0] == 1)&&(gamev1[1][1] != 1))
                    {
                        printf("      |");
                    }
                }

            }
            printf("\n");
            printf("                                    ");
        }
        for(j = 0; j < 2; j++)
        {
            if(gameh1[2][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n\n",n);
        printf("                                    ");





    }


}
else if(b == 2){
    printf("PLAYER 1 NAME :");
    fgets(player1n,1000,stdin);
    while(player1n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER 1 NAME :");
    fgets(player1n,1000,stdin);
    }
    i = strlen(player1n)-1;
    while( i > 20){
    printf("Error!\nPLAYER 1 NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player1n,1000,stdin);
    i = strlen(player1n)-1;
    }
    if( player1n[ i ] == '\n')
    player1n[i] = '\0';
    printf("PLAYER 2 NAME :");
    fgets(player2n,1000,stdin);
    while(player2n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER 2 NAME :");
    fgets(player2n,20,stdin);
    }
    i = strlen(player2n)-1;
    while( i > 20){
    printf("Error!\nPLAYER 2 NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player2n,1000,stdin);
    i = strlen(player2n)-1;
    }
    if( player2n[ i ] == '\n')
    player2n[i] = '\0';
    system("cls");


int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                %s\n\n",player2n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d",player2Sc);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                           ");

firstShape(gameh,gamev,n);

int flag3;
while(s){
        if(player1t == 1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%s 's Turn\n\n",player1n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);

            f4 = 0;
            f3 = 0;
            f13 = 0;
            f15 = 0;
            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                    if(r == 0){
                            f13 = 1;
                            player1t = 1;
                        }
            else{
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(reh[i][j] == r){
                            gameh[i][j] = 1;
                            stateH[i][j] = 1;
                            movh[i][j] = 1;
                            p++;
                            urh[i][j] = p;
                            r-=1;
                            f3 = 1;
                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                f5 = 0;
                for(i = 0;i < 5;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 6;j++){
                        if(rev[i][j] == r){
                            gamev[i][j] = 1;
                            stateV[i][j] = 1;
                            p++;
                            urv[i][j] = p;
                            r-=1;
                            movv[i][j] = 1;
                            f5 = 1;
                            break;
                        }

                    }
                    if(f5 == 1){
                            break;
                        }
                }
                player1t=0;

for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1)) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(winner[i][j] == 0){
                                player1Sc += 1;
                                winner[i][j] = 1;
                                player1t = 1;
                            }

                        }
                    }
                }


                    }
            }
            else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                    if(p == 0){
                        f15 = 1;
                        player1t = 1;
                    }
                    else{
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(urh[i][j] == p){
                            gameh[i][j] = 0;
                            stateH[i][j] = 0;
                            movh[i][j] = 0;
                            urh[i][j] = 0;
                            r++;
                            reh[i][j] = r;
                            p-=1;
                            f3 = 1;


                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                for(i = 0;i < 5;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 6;j++){
                        if(urv[i][j] == p){
                            gamev[i][j] = 0;
                            stateV[i][j] = 0;
                            urv[i][j] = 0;
                            r++;
                            rev[i][j] = r;
                            p-=1;
                            movv[i][j] = 0;
                            f4 = 1;
                            break;
                        }
                    }
                    if(f4 == 1){
                        break;
                    }
                }
                player1t=0;


for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 0)||(stateV[i][j] == 0)||(stateH[i][j] == 0)||(stateH[i+1][j] == 0) )&& squ[i][j] == 1)
                        {
                            squ[i][j] = 0;
                            if(winner[i][j] == 2){
                                player2Sc -= 1;
                                winner[i][j] = 0;
                                player1t = 0;
                            }
                            else{
                                player1Sc-=1;
                                winner[i][j] = 0;
                                player1t = 1;
                            }
                        }
                    }
                }
            }
            }

else{
            if(firstElem[2] == '\0' && ((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2')||(firstElem[0] == '3')||(firstElem[0] == '4')||(firstElem[0] == '5'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')||(firstElem[1] == '3')||(firstElem[1] == '4')||(firstElem[1] == '5')))
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(firstElem[2] != '\0' || ((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2')&&(firstElem[0] != '3')&&(firstElem[0] != '4')&&(firstElem[0] != '5'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')&&(firstElem[1] != '3')&&(firstElem[1] != '4')&&(firstElem[1] != '5')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if(secElem[2] == '\0' && ((secElem[0] == '0')||(secElem[0] == '1')||(secElem[0] == '2')||(secElem[0] == '2')||(secElem[0] == '4')||(secElem[0] == '5'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2')||(secElem[1] == '3')||(secElem[1] == '4')||(secElem[1] == '5')))
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(secElem[2] != '\0' || ((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2')&&(secElem[0] != '3')&&(secElem[0] != '4')&&(secElem[0] != '5'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')&&(secElem[1] != '3')&&(secElem[1] != '4')&&(secElem[1] != '5')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }


            int r1;
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 1;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 1;
            }
            else if(firstElem[0] == secElem[0])
            {
                if(x2 > y2)
                {
                    r = y2;
                    y2 = x2;
                    x2 = r;
                }

                if(stateH[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gameh[x][x2] = 1;
                stateH[x][x2] = 1;
                p++;
                urh[x][x2] = p;
                movh[x][x2] = 1;
                            }
            }
            else if((firstElem[1] == secElem[1]))
            {
                if(x > y)
                {
                    r1 = y;
                    y = x;
                    x = r1;
                }
                if(stateV[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gamev[x][x2] = 1;
                stateV[x][x2] = 1;
                p++;
                urv[x][x2] = p;
                movv[x][x2] = 1;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 25; l++)
            {
                for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 1;
                                player1Sc += 1;
                                player1t = 1;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 0;
                            }


                        }
                        else
                        {
                            player1t = 0;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 1;

    }
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            reh[i][j] = 20;
            rev[j][i] = 20;
        }
    }
    r = 0;
}
}
    }

    else{


               SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("%s 's Turn\n\n",player2n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);
            //convert char to int

           f3 = 0;
           f13 = 0;
           f4 = 0;
           f15 = 0;
            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                    if(r == 0){
                            f13 = 1;
                            player1t = 0;
                        }
            else{
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(reh[i][j] == r){
                            gameh[i][j] = 1;
                            stateH[i][j] = 1;
                            p++;
                            urh[i][j] = p;
                            movh[i][j] = 2;
                            r-=1;
                            f3 = 1;

                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                f5 = 0;
                for(i = 0;i < 5;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 6;j++){
                        if(rev[i][j] == r){
                            gamev[i][j] = 1;
                            stateV[i][j] = 1;
                            p++;
                            urv[i][j] = p;
                            r-=1;
                            movv[i][j] = 2;
                            f5 = 1;
                            break;

                        }

                    }
                    if(f5 == 1){
                            break;
                        }
                }
                player1t=1;
for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1)) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(winner[i][j] == 0){
                                player2Sc += 1;
                                winner[i][j] = 2;
                                player1t = 0;
                            }

                        }
                    }
                }
            }
                    }
            else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                if(p == 0){
                    f15 = 1;
                    player1t = 0;
                }
                else{
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(urh[i][j] == p){
                            gameh[i][j] = 0;
                            stateH[i][j] = 0;
                            r++;
                            urh[i][j] = 0;
                            reh[i][j] = r;
                            p-=1;
                            f3 = 1;
                            movh[i][j] = 0;

                            break;
                        }

                    }
                    if(f3 == 1){
                            break;
                        }
                }
                for(i = 0;i < 5;i++){
                    if(f3 == 1){
                        break;
                    }
                    for(j = 0;j < 6;j++){
                        if(urv[i][j] == p){
                            gamev[i][j] = 0;
                            stateV[i][j] = 0;
                            urv[i][j] = 0;
                            r++;
                            rev[i][j] = r;
                            p-=1;
                            movv [i][j] = 0;
                            f4 = 1;
                            break;
                        }
                    }
                    if(f4 == 1){
                        break;
                    }
                }
player1t=1;
for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 0)||(stateV[i][j] == 0)||(stateH[i][j] == 0)||(stateH[i+1][j] == 0)) && squ[i][j] == 1)
                        {
                            squ[i][j] = 0;
                            if(winner[i][j] == 2){
                                player2Sc -= 1;
                                winner[i][j] = 0;
                                player1t = 0;
                            }
                            else{
                                player1Sc-=1;
                                winner[i][j] = 0;
                                player1t = 1;
                            }
                        }
                    }
                }
              }
            }

else{
            if(firstElem[2] == '\0' && ((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2')||(firstElem[0] == '3')||(firstElem[0] == '4')||(firstElem[0] == '5'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')||(firstElem[1] == '3')||(firstElem[1] == '4')||(firstElem[1] == '5')))
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(firstElem[2] != '\0' || ((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2')&&(firstElem[0] != '3')&&(firstElem[0] != '4')&&(firstElem[0] != '5'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')&&(firstElem[1] != '3')&&(firstElem[1] != '4')&&(firstElem[1] != '5')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if(secElem[2] == '\0' && ((secElem[0] == '0')||(secElem[0] == '1')||(secElem[0] == '2')||(secElem[0] == '2')||(secElem[0] == '4')||(secElem[0] == '5'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2')||(secElem[1] == '3')||(secElem[1] == '4')||(secElem[1] == '5')))
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(secElem[2] != '\0' || ((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2')&&(secElem[0] != '3')&&(secElem[0] != '4')&&(secElem[0] != '5'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')&&(secElem[1] != '3')&&(secElem[1] != '4')&&(secElem[1] != '5')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }

          int r1,r2;
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(x2 > y2)
                {
                    r1 = y2;
                    y2 = x2;
                    x2 = r1;
                }
            if(x > y)
                {
                    r2 = y;
                    y = x;
                    x = r2;
                }
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 0;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 0;
            }
            else if(firstElem[0] == secElem[0])
            {

                if(stateH[x][x2] == 1){
                    player1t = 0;
                    f10 = 1;
                }
                else{
                gameh[x][x2] = 1;
                stateH[x][x2] = 1;
                p++;
                urh[x][x2] = p;
                movh[x][x2] = 2;
            }
            }
            else if(firstElem[1] == secElem[1])
            {

                if(stateV[x][x2] == 1){
                    player1t = 0;
                    f10 = 1;
                }
                else{
                gamev[x][x2] = 1;
                stateV[x][x2] = 1;
                p++;
                urv[x][x2] = p;
                movv [x][x2] = 2;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 25; l++)
            {
                for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 2;
                                player2Sc += 1;
                                player1t = 0;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 1;
                            }


                        }
                        else
                        {
                            player1t = 1;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 0;

    }
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            reh[i][j] = 0;
            rev[j][i] = 0;
        }
    }
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            reh[i][j] = 20;
            rev[j][i] = 20;
        }
    }
    r = 0;
}
}
}


    system("cls");
int g;
flag3 = 0;
for(i = 0;i < 5;i++){
    for(j = 0;j < 5;j++){
        if(squ[i][j] == 0){
            flag3 = 1;
        }
    }
}
if(flag3 == 1){
    s = 1;
}
else{
    s = 0;
}
moves1 = 0;
moves2 = 0;
for(i = 0;i < 6;i++){
    for(j = 0;j < 5;j++){
        if(movv[j][i] == 1){
            moves1++;

        }
        if(movh[i][j] == 1){
            moves1++;

        }
        if(movv[j][i] == 2){
            moves2++;

        }
        if(movh[i][j] == 2){
            moves2++;

        }
    }
}


int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                %s\n\n",player2n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d\n\n",player2Sc);
    printf("                    MOVES : %d",moves1);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        MOVES : %d",moves2);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                           ");
for(j = 0;j < 5;j++){
            if(gameh[0][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[0][0] >= 1){
            if(gamev[0][0] == 1){
            printf("|");
            if(winner[0][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[0][0] == 1){
            printf("|     ");

        }
        }

        if(gamev[0][1] == 1){

                if(gamev[0][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[0][1] >= 1){
            if(gamev[0][2] == 1){
                if(gamev[0][1] == 1){
                    if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[0][0] != 1)&&(gamev[0][1] != 1)){
                        if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1)){
                        if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[0][2] == 1){
                if(gamev[0][1] == 1){
                    printf("     |");
        }
                else if((gamev[0][0] != 1)&&(gamev[0][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[0][2] >= 1){
        if(gamev[0][3] == 1){

                if(gamev[0][2] == 1){
                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][2] != 1)&&(gamev[0][1] == 1)){

                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){

               if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[0][3] == 1){

                if(gamev[0][2] == 1){
                    printf("     |");
                }
                if((gamev[0][2] != 1)&&(gamev[0][1] == 1)){
                    printf("           |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("            |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[0][3] >= 1){
            if(gamev[0][4] == 1){
            if(gamev[0][3] == 1){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][3] != 1)&&(gamev[0][2] == 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[0][4] == 1){
            if(gamev[0][3] == 1){
                    printf("     |");
                }
                if((gamev[0][3] != 1)&&(gamev[0][2] == 1)){
                    printf("           |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                 |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                  |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                        |");
                }

        }
        }
           if(squ[0][4] >= 1){
            if(gamev[0][5] == 1){
                if(gamev[0][4] == 1){
                      if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[0][4] != 1)&&(gamev[0][3] == 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][2] == 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                        if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                        if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[0][5] == 1){
                if(gamev[0][4] == 1){
                     printf("     |");
                }

                if((gamev[0][4] != 1)&&(gamev[0][3] == 1)){
                    printf("           |");
                }
                if((gamev[0][2] == 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                 |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                       |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }

    for(j = 0;j < 5;j++){
            if(gameh[1][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");
   for(i = 0;i < 3;i++){
        if(squ[1][0] >= 1){
            if(gamev[1][0] == 1){
            printf("|");
            if(winner[1][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[1][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[1][1] == 1){
                if(gamev[1][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[1][1] >= 1){
            if(gamev[1][2] == 1){
                if(gamev[1][1] == 1){
                    if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[1][0] != 1)&&(gamev[1][1] != 1)){
                        if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1)){
                        if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[1][2] == 1){
                if(gamev[1][1] == 1){
                    printf("     |");
        }
                else if((gamev[1][0] != 1)&&(gamev[1][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[1][2] >= 1){
        if(gamev[1][3] == 1){

                if(gamev[1][2] == 1){
                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][2] != 1)&&(gamev[1][1] == 1)){

                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){

               if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[1][3] == 1){

                if(gamev[1][2] == 1){
                    printf("     |");
                }
                if((gamev[1][2] != 1)&&(gamev[1][1] == 1)){
                    printf("           |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("            |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[1][3] >= 1){
            if(gamev[1][4] == 1){
            if(gamev[1][3] == 1){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][3] != 1)&&(gamev[1][2] == 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[1][4] == 1){
            if(gamev[1][3] == 1){
                    printf("     |");
                }
                if((gamev[1][3] != 1)&&(gamev[1][2] == 1)){
                    printf("           |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                 |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                  |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[1][4] >= 1){
            if(gamev[1][5] == 1){
                if(gamev[1][4] == 1){
                      if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[1][4] != 1)&&(gamev[1][3] == 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][2] == 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                        if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                        if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[1][5] == 1){
                if(gamev[1][4] == 1){
                     printf("     |");
                }

                if((gamev[1][4] != 1)&&(gamev[1][3] == 1)){
                    printf("           |");
                }
                if((gamev[1][2] == 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                 |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                       |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }

for(j = 0;j < 5;j++){
            if(gameh[2][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[2][0] >= 1){
            if(gamev[2][0] == 1){
            printf("|");
            if(winner[2][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[2][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[2][1] == 1){
                if(gamev[2][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[2][1] >= 1){
            if(gamev[2][2] == 1){
                if(gamev[2][1] == 1){
                    if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[2][0] != 1)&&(gamev[2][1] != 1)){
                        if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[2][0] == 1)&&(gamev[2][1] != 1)){
                        if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[2][2] == 1){
                if(gamev[2][1] == 1){
                    printf("     |");
        }
                else if((gamev[2][0] != 1)&&(gamev[2][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[2][0] == 1)&&(gamev[2][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[2][2] >= 1){
        if(gamev[2][3] == 1){

                if(gamev[2][2] == 1){
                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][2] != 1)&&(gamev[2][1] == 1)){

                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){

               if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[2][3] == 1){

                if(gamev[2][2] == 1){
                    printf("     |");
                }
                if((gamev[2][2] != 1)&&(gamev[2][1] == 1)){
                    printf("           |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("            |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[2][3] >= 1){
            if(gamev[2][4] == 1){
            if(gamev[2][3] == 1){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][3] != 1)&&(gamev[2][2] == 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[2][4] == 1){
            if(gamev[2][3] == 1){
                    printf("     |");
                }
                if((gamev[2][3] != 1)&&(gamev[2][2] == 1)){
                    printf("           |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                 |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                  |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[2][4] >= 1){
            if(gamev[2][5] == 1){
                if(gamev[2][4] == 1){
                      if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[2][4] != 1)&&(gamev[2][3] == 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][2] == 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                        if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                        if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[2][5] == 1){
                if(gamev[2][4] == 1){
                     printf("     |");
                }

                if((gamev[2][4] != 1)&&(gamev[2][3] == 1)){
                    printf("           |");
                }
                if((gamev[2][2] == 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                 |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                       |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }
for(j = 0;j < 5;j++){
            if(gameh[3][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[3][0] >= 1){
            if(gamev[3][0] == 1){
            printf("|");
            if(winner[3][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[3][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[3][1] == 1){
                if(gamev[3][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[3][1] >= 1){
            if(gamev[3][2] == 1){
                if(gamev[3][1] == 1){
                    if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[3][0] != 1)&&(gamev[3][1] != 1)){
                        if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[3][0] == 1)&&(gamev[3][1] != 1)){
                        if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[3][2] == 1){
                if(gamev[3][1] == 1){
                    printf("     |");
        }
                else if((gamev[3][0] != 1)&&(gamev[3][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[3][0] == 1)&&(gamev[3][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[3][2] >= 1){
        if(gamev[3][3] == 1){

                if(gamev[3][2] == 1){
                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][2] != 1)&&(gamev[3][1] == 1)){

                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){

               if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[3][3] == 1){

                if(gamev[3][2] == 1){
                    printf("     |");
                }
                if((gamev[3][2] != 1)&&(gamev[3][1] == 1)){
                    printf("           |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("            |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[3][3] >= 1){
            if(gamev[3][4] == 1){
            if(gamev[3][3] == 1){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][3] != 1)&&(gamev[3][2] == 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[3][4] == 1){
            if(gamev[3][3] == 1){
                    printf("     |");
                }
                if((gamev[3][3] != 1)&&(gamev[3][2] == 1)){
                    printf("           |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                 |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                  |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[3][4] >= 1){
            if(gamev[3][5] == 1){
                if(gamev[3][4] == 1){
                      if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[3][4] != 1)&&(gamev[3][3] == 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][2] == 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                        if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                        if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[3][5] == 1){
                if(gamev[3][4] == 1){
                     printf("     |");
                }

                if((gamev[3][4] != 1)&&(gamev[3][3] == 1)){
                    printf("           |");
                }
                if((gamev[3][2] == 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                 |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                       |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");

    }
    for(j = 0;j < 5;j++){
            if(gameh[4][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");
    for(i = 0;i < 3;i++){
        if(squ[4][0] >= 1){
            if(gamev[4][0] == 1){
            printf("|");
            if(winner[4][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[4][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[4][1] == 1){
                if(gamev[4][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[4][1] >= 1){
            if(gamev[4][2] == 1){
                if(gamev[4][1] == 1){
                    if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[4][0] != 1)&&(gamev[4][1] != 1)){
                        if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[4][0] == 1)&&(gamev[4][1] != 1)){
                        if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[4][2] == 1){
                if(gamev[4][1] == 1){
                    printf("     |");
        }
                else if((gamev[4][0] != 1)&&(gamev[4][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[4][0] == 1)&&(gamev[4][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[4][2] >= 1){
        if(gamev[4][3] == 1){

                if(gamev[4][2] == 1){
                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][2] != 1)&&(gamev[4][1] == 1)){

                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){

               if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[4][3] == 1){

                if(gamev[4][2] == 1){
                    printf("     |");
                }
                if((gamev[4][2] != 1)&&(gamev[4][1] == 1)){
                    printf("           |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("            |");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[4][3] >= 1){
            if(gamev[4][4] == 1){
            if(gamev[4][3] == 1){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][3] != 1)&&(gamev[4][2] == 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[4][4] == 1){
            if(gamev[4][3] == 1){
                    printf("     |");
                }
                if((gamev[4][3] != 1)&&(gamev[4][2] == 1)){
                    printf("           |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                 |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                  |");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[4][4] >= 1){
            if(gamev[4][5] == 1){
                if(gamev[4][4] == 1){
                      if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[4][4] != 1)&&(gamev[4][3] == 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][2] == 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                        if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                        if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[4][5] == 1){
                if(gamev[4][4] == 1){
                     printf("     |");
                }

                if((gamev[4][4] != 1)&&(gamev[4][3] == 1)){
                    printf("           |");
                }
                if((gamev[4][2] == 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                 |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                       |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                              |");
                }

            }

        }

        printf("\n");
        printf("                           ");

    }
    for(j = 0;j < 5;j++){
            if(gameh[5][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n\n",n);
        printf("                           ");
    }



}
else{
    while(b != 1 && b != 2){
        printf("invalid input!");
        scanf("%d",&b);
        system("cls");
    }
}

}



else if(a == 2){
    printf("1- Shape 3 x 3.\n2- Shape  6 x 6.\n");
    scanf("%d",&b);
    system("cls");
if(b == 1){
        printf("PLAYER NAME :");
    fgets(player1n,1000,stdin);
    while(player1n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER NAME :");
    fgets(player1n,1000,stdin);
    }
    i = strlen(player1n)-1;
    while( i > 20){
    printf("Error!\nPLAYER NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player1n,1000,stdin);
    i = strlen(player1n)-1;
    }
    if( player1n[ i ] == '\n')
    player1n[i] = '\0';
    system("cls");

    initial1(squ,winner);
    initial2(movh,movv);
    initial3(reh,rev);

    int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                Computer\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d",player2Sc);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                    ");

    firstShape1(gameh,gamev,n);
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            newStateh1[i][j] = 0;
            newStatev1[j][i] = 0;
        }
    }

    while(s)
    {



        if(player1t == 1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%s 's Turn\n",player1n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);
            f3 = 0;
            f13 = 0;
            f15 = 0;
            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                    if(r == 0){
                            f13 = 1;
                            player1t = 1;
                        }
            else{
    p++;
                f3 = 0;
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(reh[i][j] == r){
                            gameh[i][j] = 1;
                            stateH[i][j] = 1;
                            if(movh21[i][j] == 1){
                                movh[i][j] = 1;
                            }
                            else{
                                movh[i][j] = 2;
                            }
                            urh[i][j] = p;

                        }

                    }

                }
                f5 = 0;
                for(i = 0;i < 2;i++){
                    for(j = 0;j < 3;j++){
                        if(rev[i][j] == r){
                            gamev[i][j] = 1;
                            stateV[i][j] = 1;
                            urv[i][j] = p;
                            if(movv21[i][j] == 1){
                                movv[i][j] = 1;
                            }
                            else{
                                movv[i][j] = 2;
                            }

                        }

                    }

                }
                player1t=1;

for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1)) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(winner[i][j] == 0){
                                    if(winner21[i][j] == 1){
                                        player1Sc += 1;
                                        winner[i][j] = 1;
                                        player1t = 1;
                                    }
                                    else{
                                        player2Sc += 1;
                                        winner[i][j] = 2;
                                        player1t = 1;
                                    }

                            }

                        }
                    }
                }
                r--;


                    }
            }
            else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                    if(p == 0){
                    f15 = 1;
                    player1t = 1;
                }
            else{
                    r++;
                for(i = 0;i < 3;i++){
                    for(j = 0;j < 2;j++){
                        if(urh[i][j] == p){
                            gameh[i][j] = 0;
                            stateH[i][j] = 0;
                            movh[i][j] = 0;
                            urh[i][j] = 0;
                            reh[i][j] = r;
                            f3 = 1;


                        }

                    }

                }
                for(i = 0;i < 2;i++){

                    for(j = 0;j < 3;j++){
                        if(urv[i][j] == p){
                            gamev[i][j] = 0;
                            stateV[i][j] = 0;
                            rev[i][j] = r;
                            urv[i][j] = 0;
                            movv[i][j] = 0;

                        }
                    }

                }
                player1t=1;
                p--;


for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV[i][j+1] == 0)||(stateV[i][j] == 0)||(stateH[i][j] == 0)||(stateH[i+1][j] == 0) )&& squ[i][j] == 1)
                        {
                            squ[i][j] = 0;
                            if(winner[i][j] == 2){
                                player2Sc -= 1;
                                winner[i][j] = 0;

                            }
                            else{
                                player1Sc-=1;
                                winner[i][j] = 0;
                                player1t = 1;

                            }
                        }
                    }
                }
            }

            }

else{
        p++;
            if(((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')) && firstElem[2] == '\0')
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(firstElem[2] != '\0' || ((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')))
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if((((secElem[0] == 0)||(secElem[0] == '1')||(secElem[0] == '2'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2'))) && secElem[2] == '\0')
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')) || secElem[2] != '\0')
                {
                    printf("PLEASE ENTER TWO NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }

            int r1,r2;
            if(x2 > y2)
                {
                    r1 = y2;
                    y2 = x2;
                    x2 = r1;
                }
            if(x > y)
                {
                    r2 = y;
                    y = x;
                    x = r2;
                }
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 1;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 1;
            }
            else if(firstElem[0] == secElem[0])
            {


                if(stateH[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gameh[x][x2] = 1;
                stateH[x][x2] = 1;
                newStateh1[x][x2] = 1;
                urh[x][x2] = p;
                movh[x][x2] = 1;
                movh21[x][x2] = 1;
                            }
            }
            else if((firstElem[1] == secElem[1]))
            {

                if(stateV[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gamev[x][x2] = 1;
                stateV[x][x2] = 1;
                newStatev1[x][x2] = 1;
                urv[x][x2] = p;
                movv[x][x2] = 1;
                movv21[x][x2] = 1;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 4; l++)
            {
                for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 1;
                                winner21[i][j] = 1;
                                player1Sc += 1;
                                player1t = 1;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 0;
                            }


                        }
                        else
                        {
                            player1t = 0;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 1;

    }
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            reh[i][j] = 20;
            rev[j][i] = 20;
        }
    }
    r = 0;
}
        }

        }
        else
        {
int comTurn;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Computer Turn\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            //convert char to int
int flag;
flag = 0;
comTurn = 1;

for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(((stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&& squ[i][j] == 0))
                        {   if(stateH[i][j] == 0){
                                gameh[i][j] = 1;
                                stateH[i][j] = 1;
                                urh[i][j] = p;
                                movh[i][j] = 2;
                                movh21[i][j] = 2;
                                comTurn = 0;
                                                       }
                            else if(stateV[i][j] == 0){
                                gamev[i][j] = 1;
                                stateV[i][j] = 1;
                                movv[i][j] = 2;
                                movv21[i][j] = 2;
                                urv[i][j] = p;
                                comTurn = 0;
                            }
                            else if(stateV[i][j+1] == 0){
                                gamev[i][j+1] = 1;
                                stateV[i][j+1] = 1;
                                movv[i][j+1] = 2;
                                movv21[i][j+1] = 2;
                                urv[i][j+1] = p;
                                comTurn = 0;

                            }
                            else if(stateH[i+1][j] == 0){
                                gameh[i+1][j] = 1;
                                stateH[i+1][j] = 1;
                                urh[i+1][j] = p;
                                movh[i+1][j] = 2;
                                movh21[i+1][j] = 2;
                                comTurn = 0;

                            }


                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 2;
                                winner21[i][j] = 2;
                                player2Sc += 1;
                                player1t = 0;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 1;
                            }


                        }

                        else
                        {
                            player1t = 1;
                        }
                    }

                }
    if(flag == 1){
    player1t = 0;

    }
    int f6,f7,f8,f9;
    f6 = 0;
    f7 = 0;
    f8 = 0;
    f9 = 0;
    while(comTurn){
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            if(newStateh1[i][j] == 1){
                    if(stateH[i+1][j] == 0){
                        stateH[i+1][j] = 1;
                        gameh[i+1][j] = 1;
                        urh[i+1][j] = p;
                        movh[i+1][j] = 2;
                        movh21[i+1][j] = 2;
                        f8 = 1;
                    }
        }

        }
    }

/*if(f8 == 1 || f9 == 1){

}*/
for(i = 0;i < 2;i++){
        for(j = 0;j < 3;j++){
            if(newStatev1[i][j] == 1 ){
                    if(stateV[i][j+1] == 0){
                        stateV[i][j+1] = 1;
                        gamev[i][j+1] = 1;
                        urv[i][j+1] = p;
                        movv[i][j+1] = 2;
                        movv21[i][j+1] = 2;
                        f6 = 1;
                    }

        }

        }
    }


    if(f6 == 0 && f8 == 0){
f7 = 0;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
                if(stateH[i+1][j] == 0){
                    stateH[i+1][j] = 1;
                    gameh[i+1][j] = 1;
                    urh[i+1][j] = p;
                    movh[i+1][j] = 2;
                    movh21[i+1][j] = 2;
                    f7 = 1;
                    break;
            }
        }
        if(f7 == 1){
            break;
        }
    }

    /*if(f7 == 0){

        for(i = 0;i < 2;i++){
        for(j = 0;j < 3;j++){
                if(stateV[i][j+1] == 0){
                    stateV[i][j+1] = 1;
                    gamev[i][j+1] = 1;
                    urv[i][j+1] = p;
                    movv[i][j+1] = 2;
                    movv21[i][j+1] = 2;
                    f7 = 1;
                    break;
            }
        }
        if(f7 == 1){
            break;
        }
    }
    }*/

    }
    comTurn = 0;

    }



   if(player1t == 1){
        for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            newStateh1[i][j] = 0;
            newStatev1[j][i] = 0;
        }
    }
   }

            //Displaying the state



}

        system("cls");


flag3 = 0;
for(i = 0;i < 2;i++){
    for(j = 0;j < 2;j++){
        if(squ[i][j] == 0){
            flag3 = 1;
        }
    }
}
if(flag3 == 1){
    s = 1;
}
else{
    s = 0;
}
moves1 = 0;
moves2 = 0;
int g;
for(i = 0;i < 3;i++){
    for(j = 0;j < 2;j++){
        if(movv[j][i] == 1){
            moves1++;

        }
        if(movh[i][j] == 1){
            moves1++;

        }
        if(movv[j][i] == 2){
            moves2++;

        }
        if(movh[i][j] == 2){
            moves2++;

        }
    }
}



   int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                Computer\n\n",player2n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d\n\n",player2Sc);
    printf("                    MOVES : %d",moves1);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        MOVES : %d",moves2);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                    ");

        for(j = 0; j < 2; j++)
        {
            if(gameh[0][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                                    ");


        for(i = 0; i < 3; i++)
        {
            if(gamev[0][0] == 1)
            {
                if((squ[0][0] == 1)||(squ[0][0] > 1))
                {
                    printf("|");
                    if(winner[0][0] == 1)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    }
                    printf("%c%c%c%c%c",m,m,m,m,m);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("|     ");
                }

            }
            if(gamev[0][1] == 1)
            {
                if(gamev[0][0] == 1)
                {
                    printf("|");

                }
                else
                {
                    printf("      |");
                }
            }
            if(gamev[0][2] == 1)
            {
                if((squ[0][1] == 1)||(squ[0][1] > 1))
                {
                    if(gamev[0][1] == 1)
                    {
                        if(winner[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("%c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");

                    }
                    else if((gamev[0][0] != 1)&&(gamev[0][0] != 1))
                    {
                        if(winner[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("       %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1))
                    {
                        if(winner[0][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf(" %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }



                }


                else
                {
                    if(gamev[0][1] == 1)
                    {

                        printf("     |");
                    }
                    else if((gamev[0][0] != 1)&&(gamev[0][0] != 1))
                    {
                        printf("            |");
                    }
                    else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1))
                    {
                        printf("      |");
                    }
                }

            }
           printf("\n");
        printf("                                    ");
    }

        for(j = 0; j < 2; j++)
        {
            if(gameh[1][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                                    ");
        for(i = 0; i < 3; i++)
        {
            if(gamev[1][0] == 1)
            {
                if((squ[1][0] == 1)||(squ[1][0] > 1))
                {
                    printf("|");
                    if(winner[1][0] == 1)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    }
                    printf("%c%c%c%c%c",m,m,m,m,m);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("|     ");
                }

            }
            if(gamev[1][1] == 1)
            {
                if(gamev[1][0] == 1)
                {
                    printf("|");

                }
                else
                {
                    printf("      |");
                }
            }
            if(gamev[1][2] == 1)
            {
                if((squ[1][1] == 1)||(squ[1][1] > 1))
                {
                    if(gamev[1][1] == 1)
                    {
                        if(winner[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("%c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if((gamev[1][0] != 1)&&(gamev[1][0] != 1))
                    {
                        if(winner[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf("       %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }
                    else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1))
                    {
                        if(winner[1][1] == 1)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        printf(" %c%c%c%c%c",m,m,m,m,m);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf("|");
                    }



                }

                else
                {
                    if(gamev[1][1] == 1)
                    {

                        printf("     |");
                    }
                    else if((gamev[1][0] != 1)&&(gamev[1][0] != 1))
                    {
                        printf("            |");
                    }
                    else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1))
                    {
                        printf("      |");
                    }
                }

            }
            printf("\n");
            printf("                                    ");
        }
        for(j = 0; j < 2; j++)
        {
            if(gameh[2][j] == 1)
            {
                printf("%c-----",n);
            }
            else
            {
                printf("%c     ",n);
            }
        }
        printf("%c\n\n",n);
        printf("                                    ");





    }

}
else if(b == 2){
    printf("PLAYER NAME :");
    fgets(player1n,1000,stdin);
    while(player1n[0]=='\n'){
    printf("Please Enter Your Name :)\n\nPLAYER NAME :");
    fgets(player1n,1000,stdin);
    }
    i = strlen(player1n)-1;
    while( i > 20){
    printf("Error!\nPLAYER NAME \"Maximum Name Consists Of 20 Characters\" :");
    fgets(player1n,1000,stdin);
    i = strlen(player1n)-1;
    }
    if( player1n[ i ] == '\n')
    player1n[i] = '\0';
    system("cls");


int g;
int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                Computer\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d",player2Sc);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                           ");

firstShape(gameh,gamev,n);



int s = 1;
int flag3;
while(s){

            if(player1t == 1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%s 's Turn\n",player1n);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if(f10 == 1){
                printf("Error!\nThis Line is Already Existed\n");
            }
            else if(f11 == 1){
                printf("Error!\nPlease Enter Different Elements\n");
            }
            else if(f13 == 1){
                printf("You Cannot Make Redo Before Making Undo!\n");
            }
            else if(f12 == 1){
                printf("Error!\nPlease Enter Series Elements\n");
            }
            else if(f15 == 1){
                printf("You Cannot Make Undo Before Playing!\n");
            }
            printf("Enter the first element:");
            scanf("%s",firstElem);

            f3 = 0;
            f13 = 0;
            f4 = 0;
            f20 = 0;
            f15 = 0;
            f12 = 0;

            if(firstElem[0] == 'r' && firstElem[1] == '\0'){
                    if(r == 0){
                            f13 = 1;
                            player1t = 1;
                        }
            else{
    p++;
                f3 = 0;
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(reh[i][j] == r){
                            gameh[i][j] = 1;
                            stateH[i][j] = 1;
                            if(movh2[i][j] == 1){
                                movh[i][j] = 1;
                            }
                            else{
                                movh[i][j] = 2;
                            }
                            urh[i][j] = p;

                        }

                    }

                }
                f5 = 0;
                for(i = 0;i < 5;i++){
                    for(j = 0;j < 6;j++){
                        if(rev[i][j] == r){
                            gamev[i][j] = 1;
                            stateV[i][j] = 1;
                            urv[i][j] = p;
                            if(movv2[i][j] == 1){
                                movv[i][j] = 1;
                            }
                            else{
                                movv[i][j] = 2;
                            }

                        }

                    }

                }
                player1t=1;

for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1)) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(winner[i][j] == 0){
                                    if(winner2[i][j] == 1){
                                        player1Sc += 1;
                                        winner[i][j] = 1;
                                        player1t = 1;
                                    }
                                    else{
                                        player2Sc += 1;
                                        winner[i][j] = 2;
                                        player1t = 1;
                                    }

                            }

                        }
                    }
                }
                r--;


                    }
            }
           else if(firstElem[0] == 'u' && firstElem[1] == '\0'){
                    if(p == 0){
                    f15 = 1;
                    player1t = 1;
                }
            else{
                    r++;
                for(i = 0;i < 6;i++){
                    for(j = 0;j < 5;j++){
                        if(urh[i][j] == p){
                            gameh[i][j] = 0;
                            stateH[i][j] = 0;
                            movh[i][j] = 0;
                            urh[i][j] = 0;
                            reh[i][j] = r;
                            f3 = 1;


                        }

                    }

                }
                for(i = 0;i < 5;i++){

                    for(j = 0;j < 6;j++){
                        if(urv[i][j] == p){
                            gamev[i][j] = 0;
                            stateV[i][j] = 0;
                            rev[i][j] = r;
                            urv[i][j] = 0;
                            movv[i][j] = 0;

                        }
                    }

                }
                player1t=1;
                p--;


for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j+1] == 0)||(stateV[i][j] == 0)||(stateH[i][j] == 0)||(stateH[i+1][j] == 0) )&& squ[i][j] == 1)
                        {
                            squ[i][j] = 0;
                            if(winner[i][j] == 2){
                                player2Sc -= 1;
                                winner[i][j] = 0;

                            }
                            else{
                                player1Sc-=1;
                                winner[i][j] = 0;
                                player1t = 1;

                            }
                        }
                    }
                }
            }

            }
else{
        p++;
            if(((firstElem[0] == '0')||(firstElem[0] == '1')||(firstElem[0] == '2')||(firstElem[0] == '3')||(firstElem[0] == '4')||(firstElem[0] == '5'))&&((firstElem[1] == '0')||(firstElem[1] == '1')||(firstElem[1] == '2')||(firstElem[1] == '3')||(firstElem[1] == '4')||(firstElem[1] == '5')))
            {
                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            else
            {
                while(((firstElem[0] != '0')&&(firstElem[0] != '1')&&(firstElem[0] != '2')&&(firstElem[0] != '3')&&(firstElem[0] != '4')&&(firstElem[0] != '5'))||((firstElem[1] != '0')&&(firstElem[1] != '1')&&(firstElem[1] != '2')&&(firstElem[1] != '3')&&(firstElem[1] != '4')&&(firstElem[1] != '5')))
                {
                    printf("PLEASE ENTER NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the first element:");
                    scanf("%s",firstElem);
                }

                x = firstElem[0] - '0';
                x2 = firstElem[1] - '0';
            }
            printf("Enter the second element:");
            scanf("%s",secElem);
             if(((secElem[0] == '0')||(secElem[0] == '1')||(secElem[0] == '2')||(secElem[0] == '2')||(secElem[0] == '4')||(secElem[0] == '5'))&&((secElem[1] == '0')||(secElem[1] == '1')||(secElem[1] == '2')||(secElem[1] == '3')||(secElem[1] == '4')||(secElem[1] == '5')))
            {
                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }
            else
            {
                while(((secElem[0] != '0')&&(secElem[0] != '1')&&(secElem[0] != '2')&&(secElem[0] != '3')&&(secElem[0] != '4')&&(secElem[0] != '5'))||((secElem[1] != '0')&&(secElem[1] != '1')&&(secElem[1] != '2')&&(secElem[1] != '3')&&(secElem[1] != '4')&&(secElem[1] != '5')))
                {
                    printf("PLEASE ENTER NUMBERS FROM 0 TO 2!\n");

                    printf("Enter the second element:");
                    scanf("%s",secElem);
                }

                y = secElem[0] - '0';
                y2 = secElem[1] - '0';
            }

           int r2,r1;
           if(x2 > y2)
                {
                    r1 = y2;
                    y2 = x2;
                    x2 = r1;
                }
            if(x > y)
                {
                    r2 = y;
                    y = x;
                    x = r2;
                }
            f10 = 0;
            f11 = 0;
            f12 = 0;
            if(firstElem[0] == secElem[0] && firstElem[1] == secElem[1]){
                f11 = 1;
                player1t = 1;
            }
            else if((y2 > x2+1 || y > x+1)||(y2 == x2+1 && y == x+1)){
                f12 = 1;
                player1t = 1;
            }
            else if(firstElem[0] == secElem[0])
            {


                if(stateH[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gameh[x][x2] = 1;
                stateH[x][x2] = 1;
                newStateh[x][x2] = 1;
                urh[x][x2] = p;
                movh[x][x2] = 1;
                movh2[x][x2] = 1;
                            }
            }
            else if((firstElem[1] == secElem[1]))
            {

                if(stateV[x][x2] == 1){
                    player1t = 1;
                    f10 = 1;
                }
                else{
                gamev[x][x2] = 1;
                stateV[x][x2] = 1;
                newStatev[x][x2] = 1;
                urv[x][x2] = p;
                movv[x][x2] = 1;
                movv2[x][x2] = 1;
            }
            }
            //Displaying the state
int flag;
flag = 0;
if(f10 == 0 && f11 == 0 && f12 == 0){
            for(l = 0; l <= 25; l++)
            {
                for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)
                        {
                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 1;
                                winner2[i][j] = 1;
                                player1Sc += 1;
                                player1t = 1;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 0;
                            }


                        }
                        else
                        {
                            player1t = 0;
                        }
                    }

                }
            }
            if(flag == 1){
        player1t = 1;

    }
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            reh[i][j] = 20;
            rev[j][i] = 20;
        }
    }
    r = 0;
}
        }

        }
   else
        {
int comTurn;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Computer Turn\n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            //convert char to int
int flag;
flag = 0;
comTurn = 1;

for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(((stateV[i][j] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateH[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i+1][j] == 1) && squ[i][j] == 0)||((stateV[i][j+1] == 1)&&(stateV[i][j] == 1)&&(stateH[i][j] == 1)&& squ[i][j] == 0))
                        {   if(stateH[i][j] == 0){
                                gameh[i][j] = 1;
                                stateH[i][j] = 1;
                                urh[i][j] = p;
                                movh[i][j] = 2;
                                movh2[i][j] = 2;
                                comTurn = 0;
                                                       }
                            else if(stateV[i][j] == 0){
                                gamev[i][j] = 1;
                                stateV[i][j] = 1;
                                movv[i][j] = 2;
                                movv2[i][j] = 2;
                                urv[i][j] = p;
                                comTurn = 0;
                            }
                            else if(stateV[i][j+1] == 0){
                                gamev[i][j+1] = 1;
                                stateV[i][j+1] = 1;
                                movv[i][j+1] = 2;
                                movv2[i][j+1] = 2;
                                urv[i][j+1] = p;
                                comTurn = 0;

                            }
                            else if(stateH[i+1][j] == 0){
                                gameh[i+1][j] = 1;
                                stateH[i+1][j] = 1;
                                urh[i+1][j] = p;
                                movh[i+1][j] = 2;
                                movh2[i+1][j] = 2;
                                comTurn = 0;

                            }


                            squ[i][j] = 1;
                            if(squ[i][j] == 1)
                            {
                                winner[i][j] = 2;
                                winner2[i][j] = 2;
                                player2Sc += 1;
                                player1t = 0;
                                flag = 1;
                            }

                            else
                            {
                                player1t = 1;
                            }


                        }

                        else
                        {
                            player1t = 1;
                        }
                    }

                }
    if(flag == 1){
    player1t = 0;

    }
    int f6,f7,f8,f9;
    f6 = 0;
    f7 = 0;
    f8 = 0;
    f9 = 0;
    while(comTurn){
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            if(newStateh[i][j] == 1){
                    if(stateH[i+1][j] == 0){
                        stateH[i+1][j] = 1;
                        gameh[i+1][j] = 1;
                        urh[i+1][j] = p;
                        movh[i+1][j] = 2;
                        movh2[i+1][j] = 2;
                        f8 = 1;
                    }
        }

        }
    }

/*if(f8 == 1 || f9 == 1){

}*/
for(i = 0;i < 5;i++){
        for(j = 0;j < 6;j++){
            if(newStatev[i][j] == 1 ){
                    if(stateV[i][j+1] == 0){
                        stateV[i][j+1] = 1;
                        gamev[i][j+1] = 1;
                        urv[i][j+1] = p;
                        movv[i][j+1] = 2;
                        movv2[i][j+1] = 2;
                        f6 = 1;
                    }

        }

        }
    }


    if(f6 == 0 && f8 == 0){
f7 = 0;
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
                if(stateH[i+1][j] == 0){
                    stateH[i+1][j] = 1;
                    gameh[i+1][j] = 1;
                    urh[i+1][j] = p;
                    movh[i+1][j] = 2;
                    movh2[i+1][j] = 2;
                    f7 = 1;
                    break;
            }
        }
        if(f7 == 1){
            break;
        }
    }

    if(f7 == 0){

        for(i = 0;i < 5;i++){
        for(j = 0;j < 6;j++){
                if(stateV[i][j+1] == 0){
                    stateV[i][j+1] = 1;
                    gamev[i][j+1] = 1;
                    urv[i][j+1] = p;
                    movv[i][j+1] = 2;
                    movv2[i][j+1] = 2;
                    f7 = 1;
                    break;
            }
        }
        if(f7 == 1){
            break;
        }
    }
    }

    }
    comTurn = 0;

    }



   if(player1t == 1){
        for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
            newStateh[i][j] = 0;
            newStatev[j][i] = 0;
        }
    }
   }

            //Displaying the state



}


    system("cls");
int g;
moves1 = 0;
moves2 = 0;
for(i = 0;i < 6;i++){
    for(j = 0;j < 5;j++){
        if(movv[j][i] == 1){
            moves1++;

        }
        if(movh[i][j] == 1){
            moves1++;

        }
        if(movv[j][i] == 2){
            moves2++;

        }
        if(movh[i][j] == 2){
            moves2++;

        }
    }
}

int spaces = strlen(player1n)-1;
    printf("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %s",player1n);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                                Computer\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("                    SCORE : %d",player1Sc);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        SCORE : %d\n\n",player2Sc);
    printf("                    MOVES : %d",moves1);
    for (i = 0;i < spaces;i++){
        printf(" ");
    }
    printf("                        MOVES : %d",moves2);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                           ");
for(j = 0;j < 5;j++){
            if(gameh[0][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[0][0] >= 1){
            if(gamev[0][0] == 1){
            printf("|");
            if(winner[0][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[0][0] == 1){
            printf("|     ");

        }
        }

        if(gamev[0][1] == 1){

                if(gamev[0][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[0][1] >= 1){
            if(gamev[0][2] == 1){
                if(gamev[0][1] == 1){
                    if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[0][0] != 1)&&(gamev[0][1] != 1)){
                        if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1)){
                        if(winner[0][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[0][2] == 1){
                if(gamev[0][1] == 1){
                    printf("     |");
        }
                else if((gamev[0][0] != 1)&&(gamev[0][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[0][2] >= 1){
        if(gamev[0][3] == 1){

                if(gamev[0][2] == 1){
                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][2] != 1)&&(gamev[0][1] == 1)){

                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){

               if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                if(winner[0][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[0][3] == 1){

                if(gamev[0][2] == 1){
                    printf("     |");
                }
                if((gamev[0][2] != 1)&&(gamev[0][1] == 1)){
                    printf("           |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("            |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[0][3] >= 1){
            if(gamev[0][4] == 1){
            if(gamev[0][3] == 1){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][3] != 1)&&(gamev[0][2] == 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    if(winner[0][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[0][4] == 1){
            if(gamev[0][3] == 1){
                    printf("     |");
                }
                if((gamev[0][3] != 1)&&(gamev[0][2] == 1)){
                    printf("           |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                 |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                  |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                        |");
                }

        }
        }
           if(squ[0][4] >= 1){
            if(gamev[0][5] == 1){
                if(gamev[0][4] == 1){
                      if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[0][4] != 1)&&(gamev[0][3] == 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][2] == 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                        if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                        if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    if(winner[0][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[0][5] == 1){
                if(gamev[0][4] == 1){
                     printf("     |");
                }

                if((gamev[0][4] != 1)&&(gamev[0][3] == 1)){
                    printf("           |");
                }
                if((gamev[0][2] == 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                 |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                       |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }

    for(j = 0;j < 5;j++){
            if(gameh[1][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");
   for(i = 0;i < 3;i++){
        if(squ[1][0] >= 1){
            if(gamev[1][0] == 1){
            printf("|");
            if(winner[1][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[1][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[1][1] == 1){
                if(gamev[1][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[1][1] >= 1){
            if(gamev[1][2] == 1){
                if(gamev[1][1] == 1){
                    if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[1][0] != 1)&&(gamev[1][1] != 1)){
                        if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1)){
                        if(winner[1][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[1][2] == 1){
                if(gamev[1][1] == 1){
                    printf("     |");
        }
                else if((gamev[1][0] != 1)&&(gamev[1][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[1][2] >= 1){
        if(gamev[1][3] == 1){

                if(gamev[1][2] == 1){
                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][2] != 1)&&(gamev[1][1] == 1)){

                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){

               if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                if(winner[1][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[1][3] == 1){

                if(gamev[1][2] == 1){
                    printf("     |");
                }
                if((gamev[1][2] != 1)&&(gamev[1][1] == 1)){
                    printf("           |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("            |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[1][3] >= 1){
            if(gamev[1][4] == 1){
            if(gamev[1][3] == 1){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][3] != 1)&&(gamev[1][2] == 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    if(winner[1][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[1][4] == 1){
            if(gamev[1][3] == 1){
                    printf("     |");
                }
                if((gamev[1][3] != 1)&&(gamev[1][2] == 1)){
                    printf("           |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                 |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                  |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[1][4] >= 1){
            if(gamev[1][5] == 1){
                if(gamev[1][4] == 1){
                      if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[1][4] != 1)&&(gamev[1][3] == 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][2] == 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                        if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                        if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    if(winner[1][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[1][5] == 1){
                if(gamev[1][4] == 1){
                     printf("     |");
                }

                if((gamev[1][4] != 1)&&(gamev[1][3] == 1)){
                    printf("           |");
                }
                if((gamev[1][2] == 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                 |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                       |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }

for(j = 0;j < 5;j++){
            if(gameh[2][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[2][0] >= 1){
            if(gamev[2][0] == 1){
            printf("|");
            if(winner[2][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[2][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[2][1] == 1){
                if(gamev[2][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[2][1] >= 1){
            if(gamev[2][2] == 1){
                if(gamev[2][1] == 1){
                    if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[2][0] != 1)&&(gamev[2][1] != 1)){
                        if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[2][0] == 1)&&(gamev[2][1] != 1)){
                        if(winner[2][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[2][2] == 1){
                if(gamev[2][1] == 1){
                    printf("     |");
        }
                else if((gamev[2][0] != 1)&&(gamev[2][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[2][0] == 1)&&(gamev[2][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[2][2] >= 1){
        if(gamev[2][3] == 1){

                if(gamev[2][2] == 1){
                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][2] != 1)&&(gamev[2][1] == 1)){

                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){

               if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                if(winner[2][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[2][3] == 1){

                if(gamev[2][2] == 1){
                    printf("     |");
                }
                if((gamev[2][2] != 1)&&(gamev[2][1] == 1)){
                    printf("           |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("            |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[2][3] >= 1){
            if(gamev[2][4] == 1){
            if(gamev[2][3] == 1){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][3] != 1)&&(gamev[2][2] == 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    if(winner[2][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[2][4] == 1){
            if(gamev[2][3] == 1){
                    printf("     |");
                }
                if((gamev[2][3] != 1)&&(gamev[2][2] == 1)){
                    printf("           |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                 |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                  |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[2][4] >= 1){
            if(gamev[2][5] == 1){
                if(gamev[2][4] == 1){
                      if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[2][4] != 1)&&(gamev[2][3] == 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][2] == 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                        if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                        if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    if(winner[2][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[2][5] == 1){
                if(gamev[2][4] == 1){
                     printf("     |");
                }

                if((gamev[2][4] != 1)&&(gamev[2][3] == 1)){
                    printf("           |");
                }
                if((gamev[2][2] == 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                 |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                       |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");
    }
for(j = 0;j < 5;j++){
            if(gameh[3][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");


    for(i = 0;i < 3;i++){
        if(squ[3][0] >= 1){
            if(gamev[3][0] == 1){
            printf("|");
            if(winner[3][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[3][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[3][1] == 1){
                if(gamev[3][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[3][1] >= 1){
            if(gamev[3][2] == 1){
                if(gamev[3][1] == 1){
                    if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[3][0] != 1)&&(gamev[3][1] != 1)){
                        if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[3][0] == 1)&&(gamev[3][1] != 1)){
                        if(winner[3][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[3][2] == 1){
                if(gamev[3][1] == 1){
                    printf("     |");
        }
                else if((gamev[3][0] != 1)&&(gamev[3][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[3][0] == 1)&&(gamev[3][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[3][2] >= 1){
        if(gamev[3][3] == 1){

                if(gamev[3][2] == 1){
                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][2] != 1)&&(gamev[3][1] == 1)){

                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){

               if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                if(winner[3][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[3][3] == 1){

                if(gamev[3][2] == 1){
                    printf("     |");
                }
                if((gamev[3][2] != 1)&&(gamev[3][1] == 1)){
                    printf("           |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("            |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[3][3] >= 1){
            if(gamev[3][4] == 1){
            if(gamev[3][3] == 1){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][3] != 1)&&(gamev[3][2] == 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    if(winner[3][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[3][4] == 1){
            if(gamev[3][3] == 1){
                    printf("     |");
                }
                if((gamev[3][3] != 1)&&(gamev[3][2] == 1)){
                    printf("           |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                 |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                  |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[3][4] >= 1){
            if(gamev[3][5] == 1){
                if(gamev[3][4] == 1){
                      if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[3][4] != 1)&&(gamev[3][3] == 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][2] == 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                        if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                        if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    if(winner[3][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[3][5] == 1){
                if(gamev[3][4] == 1){
                     printf("     |");
                }

                if((gamev[3][4] != 1)&&(gamev[3][3] == 1)){
                    printf("           |");
                }
                if((gamev[3][2] == 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                 |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                       |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                              |");
                }


            }

        }
        printf("\n");
        printf("                           ");

    }
    for(j = 0;j < 5;j++){
            if(gameh[4][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");
    for(i = 0;i < 3;i++){
        if(squ[4][0] >= 1){
            if(gamev[4][0] == 1){
            printf("|");
            if(winner[4][0] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
            printf("%c%c%c%c%c",c,c,c,c,c);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        }
        else{
        if(gamev[4][0] == 1){
            printf("|     ");

        }
        }
        if(gamev[4][1] == 1){
                if(gamev[4][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(squ[4][1] >= 1){
            if(gamev[4][2] == 1){
                if(gamev[4][1] == 1){
                    if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

        }
                else if((gamev[4][0] != 1)&&(gamev[4][1] != 1)){
                        if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                else if ((gamev[4][0] == 1)&&(gamev[4][1] != 1)){
                        if(winner[4][1] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf(" %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }
        }
        else{
        if(gamev[4][2] == 1){
                if(gamev[4][1] == 1){
                    printf("     |");
        }
                else if((gamev[4][0] != 1)&&(gamev[4][0] != 1)){
                    printf("            |");
                }
                else if ((gamev[4][0] == 1)&&(gamev[4][1] != 1)){
                    printf("      |");
                }

        }
        }
        if(squ[4][2] >= 1){
        if(gamev[4][3] == 1){

                if(gamev[4][2] == 1){
                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][2] != 1)&&(gamev[4][1] == 1)){

                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){

               if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("       %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                if(winner[4][2] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


                }
        else{
        if(gamev[4][3] == 1){

                if(gamev[4][2] == 1){
                    printf("     |");
                }
                if((gamev[4][2] != 1)&&(gamev[4][1] == 1)){
                    printf("           |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("            |");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("                  |");
                }

        }
        }
        if(squ[4][3] >= 1){
            if(gamev[4][4] == 1){
            if(gamev[4][3] == 1){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][3] != 1)&&(gamev[4][2] == 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("             %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    if(winner[4][3] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");
                }

        }


        }
        else{
        if(gamev[4][4] == 1){
            if(gamev[4][3] == 1){
                    printf("     |");
                }
                if((gamev[4][3] != 1)&&(gamev[4][2] == 1)){
                    printf("           |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                 |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                  |");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                        |");
                }

        }
        }
        if(squ[4][4] >= 1){
            if(gamev[4][5] == 1){
                if(gamev[4][4] == 1){
                      if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                     printf("%c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                     printf("|");

                }

                if((gamev[4][4] != 1)&&(gamev[4][3] == 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("      %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][2] == 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                        if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("            %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                        if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                  %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                   %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }
                 if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    if(winner[4][4] == 1){
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            }
                    printf("                         %c%c%c%c%c",c,c,c,c,c);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("|");

                }


            }
        }
        else{
             if(gamev[4][5] == 1){
                if(gamev[4][4] == 1){
                     printf("     |");
                }

                if((gamev[4][4] != 1)&&(gamev[4][3] == 1)){
                    printf("           |");
                }
                if((gamev[4][2] == 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                 |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                       |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                        |");
                }
                 if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                              |");
                }

            }

        }

        printf("\n");
        printf("                           ");

    }
    for(j = 0;j < 5;j++){
            if(gameh[5][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n\n",n);
        printf("                           ");
    }



}
else{
    while(b != 1 && b != 2){
        printf("invalid input!");
        scanf("%d",&b);
        system("cls");
    }
}
}


else{
    while(a != 1 && a != 2){
        printf("invalid input!");
        scanf("%d",&a);
        system("cls");
    }
}





    return 0;
}
void firstShape(int gameh[6][5],int gamev[5][6],int n){
int i,j;
for(j = 0;j < 5;j++){
            if(gameh[0][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);


    for(i = 0;i < 3;i++){
        if(gamev[0][0] == 1){
            printf("|     ");

        }
        if(gamev[0][1] == 1){
                if(gamev[0][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(gamev[0][2] == 1){
                if(gamev[0][1] == 1){
                    printf("     |");
        }
                else if((gamev[0][0] != 1)&&(gamev[0][1] != 1)){
                    printf("            |");
                }
                else if ((gamev[0][0] == 1)&&(gamev[0][1] != 1)){
                    printf("      |");
                }

        }
        if(gamev[0][3] == 1){
                if(gamev[0][2] == 1){
                    printf("     |");
                }
                if((gamev[0][2] != 1)&&(gamev[0][1] == 1)){
                    printf("           |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("                 |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)){
                    printf("                  |");
                }

        }
        if(gamev[0][4] == 1){
            if(gamev[0][3] == 1){
                    printf("     |");
                }
                if((gamev[0][3] != 1)&&(gamev[0][2] == 1)){
                    printf("           |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                 |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                  |");
                }
                if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)){
                    printf("                        |");
                }

        }
            if(gamev[0][5] == 1){
                if(gamev[0][4] == 1){
                     printf("     |");
                }

                if((gamev[0][4] != 1)&&(gamev[0][3] == 1)){
                    printf("           |");
                }
                if((gamev[0][2] == 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                 |");
                }
                if((gamev[0][1] == 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                       |");
                }
                if((gamev[0][0] == 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                              |");
                }
                 if((gamev[0][0] != 1)&&(gamev[0][1] != 1)&&(gamev[0][2] != 1)&&(gamev[0][3] != 1)&&(gamev[0][4] != 1)){
                    printf("                               |");
                }


            }
        printf("\n");
        printf("                           ");

    }

    for(j = 0;j < 5;j++){
            if(gameh[1][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");

   for(i = 0;i < 3;i++){
        if(gamev[1][0] == 1){
            printf("|     ");

        }
        if(gamev[1][1] == 1){
                if(gamev[1][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(gamev[1][2] == 1){
                if(gamev[1][1] == 1){
                    printf("     |");
        }
                else if((gamev[1][0] != 1)&&(gamev[1][1] != 1)){
                    printf("            |");
                }
                else if ((gamev[1][0] == 1)&&(gamev[1][1] != 1)){
                    printf("      |");
                }

        }
        if(gamev[1][3] == 1){
                if(gamev[1][2] == 1){
                    printf("     |");
                }
                if((gamev[1][2] != 1)&&(gamev[1][1] == 1)){
                    printf("           |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("                 |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)){
                    printf("                  |");
                }

        }
        if(gamev[1][4] == 1){
            if(gamev[1][3] == 1){
                    printf("     |");
                }
                if((gamev[1][3] != 1)&&(gamev[1][2] == 1)){
                    printf("           |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                 |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                  |");
                }
                if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)){
                    printf("                        |");
                }

        }
        if(gamev[1][5] == 1){
                if(gamev[1][4] == 1){
                     printf("     |");
                }

                if((gamev[1][4] != 1)&&(gamev[1][3] == 1)){
                    printf("           |");
                }
                if((gamev[1][2] == 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                 |");
                }
                if((gamev[1][1] == 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                       |");
                }
                if((gamev[1][0] == 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                              |");
                }
                 if((gamev[1][0] != 1)&&(gamev[1][1] != 1)&&(gamev[1][2] != 1)&&(gamev[1][3] != 1)&&(gamev[1][4] != 1)){
                    printf("                               |");
                }


            }
        printf("\n");
        printf("                           ");

    }

for(j = 0;j < 5;j++){
            if(gameh[2][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);


    for(i = 0;i < 3;i++){
        if(gamev[2][0] == 1){
            printf("|     ");

        }
        if(gamev[2][1] == 1){
                if(gamev[2][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(gamev[2][2] == 1){
                if(gamev[2][1] == 1){
                    printf("     |");
        }
                else if((gamev[2][0] != 1)&&(gamev[2][1] != 1)){
                    printf("            |");
                }
                else if ((gamev[2][0] == 1)&&(gamev[2][1] != 1)){
                    printf("      |");
                }

        }
        if(gamev[2][3] == 1){
                if(gamev[2][2] == 1){
                    printf("     |");
                }
                if((gamev[2][2] != 1)&&(gamev[2][1] == 1)){
                    printf("           |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("                 |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)){
                    printf("                  |");
                }

        }
        if(gamev[2][4] == 1){
            if(gamev[2][3] == 1){
                    printf("     |");
                }
                if((gamev[2][3] != 1)&&(gamev[2][2] == 1)){
                    printf("           |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                 |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                  |");
                }
                if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)){
                    printf("                        |");
                }

        }
        if(gamev[2][5] == 1){
                if(gamev[2][4] == 1){
                     printf("     |");
                }

                if((gamev[2][4] != 1)&&(gamev[2][3] == 1)){
                    printf("           |");
                }
                if((gamev[2][2] == 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                 |");
                }
                if((gamev[2][1] == 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                       |");
                }
                if((gamev[2][0] == 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                              |");
                }
                 if((gamev[2][0] != 1)&&(gamev[2][1] != 1)&&(gamev[2][2] != 1)&&(gamev[2][3] != 1)&&(gamev[2][4] != 1)){
                    printf("                               |");
                }


            }
        printf("\n");
        printf("                           ");

    }
for(j = 0;j < 5;j++){
            if(gameh[3][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");



    for(i = 0;i < 3;i++){
        if(gamev[3][0] == 1){
            printf("|     ");

        }
        if(gamev[3][1] == 1){
                if(gamev[3][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(gamev[3][2] == 1){
                if(gamev[3][1] == 1){
                    printf("     |");
        }
                else if((gamev[3][0] != 1)&&(gamev[3][1] != 1)){
                    printf("            |");
                }
                else if ((gamev[3][0] == 1)&&(gamev[3][1] != 1)){
                    printf("      |");
                }

        }
        if(gamev[3][3] == 1){
                if(gamev[3][2] == 1){
                    printf("     |");
                }
                if((gamev[3][2] != 1)&&(gamev[3][1] == 1)){
                    printf("           |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("                 |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)){
                    printf("                  |");
                }

        }
        if(gamev[3][4] == 1){
            if(gamev[3][3] == 1){
                    printf("     |");
                }
                if((gamev[3][3] != 1)&&(gamev[3][2] == 1)){
                    printf("           |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                 |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                  |");
                }
                if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)){
                    printf("                        |");
                }

        }
        if(gamev[3][5] == 1){
                if(gamev[3][4] == 1){
                     printf("     |");
                }

                if((gamev[3][4] != 1)&&(gamev[3][3] == 1)){
                    printf("           |");
                }
                if((gamev[3][2] == 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                 |");
                }
                if((gamev[3][1] == 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                       |");
                }
                if((gamev[3][0] == 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                              |");
                }
                 if((gamev[3][0] != 1)&&(gamev[3][1] != 1)&&(gamev[3][2] != 1)&&(gamev[3][3] != 1)&&(gamev[3][4] != 1)){
                    printf("                               |");
                }


            }
        printf("\n");
        printf("                           ");


    }
    for(j = 0;j < 5;j++){
            if(gameh[4][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n",n);
        printf("                           ");

    for(i = 0;i < 3;i++){
        if(gamev[4][0] == 1){
            printf("|     ");

        }
        if(gamev[4][1] == 1){
                if(gamev[4][0] == 1){
                        printf("|");

        }else{
            printf("      |");
        }
        }
        if(gamev[4][2] == 1){
                if(gamev[4][1] == 1){
                    printf("     |");
        }
                else if((gamev[4][0] != 1)&&(gamev[4][1] != 1)){
                    printf("            |");
                }
                else if ((gamev[4][0] == 1)&&(gamev[4][1] != 1)){
                    printf("      |");
                }

        }
        if(gamev[4][3] == 1){
                if(gamev[4][2] == 1){
                    printf("     |");
                }
                if((gamev[4][2] != 1)&&(gamev[4][1] == 1)){
                    printf("           |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("                 |");
                }
                if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)){
                    printf("                  |");
                }

        }
        if(gamev[4][4] == 1){
            if(gamev[4][3] == 1){
                    printf("     |");
                }
                if((gamev[4][3] != 1)&&(gamev[4][2] == 1)){
                    printf("           |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                 |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                  |");
                }
                if((gamev[4][0] != 1)&&(gamev[3][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)){
                    printf("                        |");
                }

        }
        if(gamev[4][5] == 1){
                if(gamev[1][4] == 1){
                     printf("     |");
                }

                if((gamev[4][4] != 1)&&(gamev[4][3] == 1)){
                    printf("           |");
                }
                if((gamev[4][2] == 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                 |");
                }
                if((gamev[4][1] == 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                       |");
                }
                if((gamev[4][0] == 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                              |");
                }
                 if((gamev[4][0] != 1)&&(gamev[4][1] != 1)&&(gamev[4][2] != 1)&&(gamev[4][3] != 1)&&(gamev[4][4] != 1)){
                    printf("                               |");
                }


            }
        printf("\n");
        printf("                           ");


    }
    for(j = 0;j < 5;j++){
            if(gameh[5][j] == 1){
                printf("%c-----",n);
            }
            else{
                printf("%c     ",n);
            }
        }
        printf("%c\n\n",n);
        printf("                           ");



}

void firstShape1(int gameh1[3][2],int gamev1[2][3],int n){
int i,j;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
for(j = 0; j < 2; j++)
    {

        if(gameh1[0][j] == 1)
        {
            printf("%c-----",n);
        }
        else
        {
            printf("%c     ",n);
        }
    }

    printf("%c",n);
    printf("\n");
    printf("                                    ");


    for(i = 0; i < 3; i++)
    {
        if(gamev1[0][0] == 1)
        {
            printf("|     ");

        }
        if(gamev1[0][1] == 1)
        {
            if(gamev1[0][0] == 1)
            {
                printf("|");

            }
            else
            {
                printf("      |");
            }
        }
        if(gamev1[0][2] == 1)
        {
            if(gamev1[0][1] == 1)
            {
                printf("     |");
            }
            else if((gamev1[0][0] != 1)&&(gamev1[0][0] != 1))
            {
                printf("            |");
            }
            else if ((gamev1[0][0] == 1)&&(gamev1[0][1] != 1))
            {
                printf("      |");
            }

        }
        printf("\n");
        if(i == 1 )
            {
         printf("                                    ");
    }
        else if(i == 0){
         printf("                                    ");
        }
        else{
         printf("                                    ");
        }
    }


    for(j = 0; j < 2; j++)
    {
        if(gameh1[1][j] == 1)
        {
            printf("%c-----",n);
        }
        else
        {
            printf("%c     ",n);
        }
    }
    printf("%c\n",n);
    printf("                                    ");
    for(i = 0; i < 3; i++)
    {
        if(gamev1[1][0] == 1)
        {
            printf("|     ");


        }
        if(gamev1[1][1] == 1)
        {
            if(gamev1[0][0] == 1)
            {
                printf("|");

            }
            else
            {
                printf("      |");
            }
        }
        if(gamev1[1][2] == 1)
        {
            if(gamev1[1][1] == 1)
            {
                printf("     |");
            }
            else if((gamev1[2][0] != 1)&&(gamev1[1][0] != 1))
            {
                printf("            |");
            }
            else if ((gamev1[1][0] == 1)&&(gamev1[1][1] != 1))
            {
                printf("      |");
            }

        }
        printf("\n");
        printf("                                    ");
    }
    for(j = 0; j < 2; j++)
    {
        if(gameh1[2][j] == 1)
        {
            printf("%c-----",n);
        }
        else
        {
            printf("%c     ",n);
        }
    }
    printf("%c\n\n",n);
    printf("                                    ");



}
void initial1(int squ1[2][2],int winner1[2][2]){
    int i,j;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            squ1[i][j] = 0;
            winner1[i][j] = 0;
        }
    }


}
void initial2(int movh1[3][2],int movv1[2][3]){
    int i,j;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            movh1[i][j] = 0;
            movv1[j][i] = 0;
        }
    }

}
void initial3(int reh1[3][2],int rev1[2][3]){
    int i,j;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 2;j++){
            reh1[i][j] = 20;
            rev1[j][i] = 20;
        }
    }

}
void initial4(int gameh[6][5],int movh[6][5],int movv[5][6],int gamev[5][6]){
    int i,j;
    for(i = 0;i < 6;i++){
        for(j = 0;j < 5;j++){
        gameh[i][j] = 0;
        movh[i][j] = 0;
        gamev[j][i] = 0;
        movv[j][i] = 0;

    }
    }
    }
void initial5(int squ[5][5],int winner[5][5]){
int i,j;
for(i = 0;i < 5;i++){
        for(j = 0;j < 5;j++){
            squ[i][j] = 0;
            winner[i][j] = 0;
        }
    }
}
