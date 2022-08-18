#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void input_matrix(int*,int);
void print_matrix(int*,int);
void game_intro(int*, char*);
void the_game(char*);
void date_time();

int main()
{
    int length;
    int random_array[16];
    char Player_name[25];
    char input;
    input_matrix(random_array,16); //Getting the random numbers between 1 to 15 in random_array through the input_matrix function declared above.

    system("Color 4F");  // function call for changing the console background to RED and text to Bright white.

    printf("\n ");

    date_time();

    printf("\n\n\t\t\t* * * * * * * WELCOME TO THE \"NUMBER JUMBLE\" GAME * * * * * * *\n\n\n\n ENTER THE PLAYER NAME: ");
    fflush(stdin);
    fgets(Player_name,25,stdin); //Getting the player name.
    length=strlen(Player_name);
    Player_name[length-1]='\0'; // Removing the newline character from string.
    strupr(Player_name); // Converting string to UPPER case.

    system("cls");

    game_intro(random_array, Player_name);  // calling the function to display game introduction and game rules to the user.

    printf("\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE OR PRESS 'e' TO EXIT... ");

    input=getch();  // taking input if the user wants to continue or quit after knowing about the game.

    if (input=='e' || input=='E')
        {
            system("cls");
            printf("\n\tTHANK YOU !!");
            Sleep(2000);
            exit(0);
        }


    system("cls");

    the_game(Player_name); // calling the game function with player name as the argument.

    return 0;
}


void game_intro(int *p, char *name)
{
    int win_matrix[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    int i,j;

    system("Color 4F");

    printf("\n ");

    date_time();

    printf("\n\n\t\t******** WELCOME %s TO THE \"NUMBER JUMBLE\" GAME ********\n\n  BEFORE WE BEGIN, LET'S UNDERSTAND ABOUT THE GAME:",name);

    printf("\n\n  1. YOU WILL BE GIVEN A 4X4 MATRIX HAVING NUMBERS FROM 1 TO 15 IN JUMBLED FASHION. Eg:\n\n\t");

    print_matrix(p,15);

    printf("\n\n     YOU HAVE TO CONVERT THE \"NUMBER JUMBLE MATRIX\" INTO THE ARRANGED MATRIX AS SHOWN BELOW TO \"WIN\" THE GAME:\n\n\t");

    print_matrix(win_matrix,15);

    printf("\n\n  2. USE THE FOLLOWING KEYS TO MOVE THE NUMBERS IN THE EMPTY POSITION. YOU CAN MOVE ONLY 1 NUMBER AT A TIME.");
    printf("\n\n\t MOVE UP\t: BY 'w' KEY \n\n\t MOVE DOWN\t: BY 'z' KEY \n\n\t MOVE RIGHT\t: BY 'd' KEY \n\n\t MOVE LEFT\t: BY 'a' KEY");
    printf("\n\n  3. MOST IMPORTANT!! YOU HAVE ONLY 10 MOVES TO COMPLETE THIS TASK. ELSE, YOU \"LOSE\".");
    printf("\n\n  4. TO EXIT THE GAME PRESS 'E' or 'e', AT ANY TIME DURING THE GAME.");
    printf("\n\n\n   LET'S BEGIN, ALL THE BEST!!");

    printf("\n\n");
}

void input_matrix(int *ptr, int size)
{

    int x;
    int count;
    int i=0;

    srand(time(NULL));

    for(count=0;count<size;count++)
    {
        ptr[count]=((rand()%15)+1);
    }

    while(i<15)
    {
        int r=((rand()%15)+1);

        for (x = 0; x < i; x++)
        {
            if(ptr[x]==r)
            {
                break;
            }
        }
        if(x==i)
        {
            ptr[i++]=r;
        }
    }

}

void print_matrix(int *ptr, int blnk_pos)
{
    int p;

    system("Color 4F");

    while(p<16)
    {


        printf("|");

        if(p!=blnk_pos)
        {
            if(ptr[p]<10)
                printf("%d ",*(ptr+p));
            else
                printf("%d",*(ptr+p));
        }
        else
            printf("  ");


        if(p==3||p==7||p==11||p==15)
            printf("|\n\t");

        p++;
    }
}

void date_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date and time: %d-%02d-%02d %02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
}

void the_game(char *name)
{
    int array[16];
    int moves=10;
    char input,a;
    int cursor=15;

    input_matrix(array,16); //again taking random number between 1 to 15 in array.

    system("Color 4F");

    while(1)
    {

        date_time();

        printf("\n\n  PLAYER %s, YOUR NO. OF MOVES LEFT - %d\n\n\t",name,moves);

        printf("-------------\n\t");

        print_matrix(array,cursor);

        printf("-------------");

        printf("\n\n  FOR LEFT DIRECTION\t: PRESS 'a' KEY \n  FOR RIGHT DIRECTION\t: PRESS 'd' KEY \n  FOR UP DIRECTION\t: PRESS 'w' KEY \n  FOR DOWN DIRECTION\t: PRESS 'z' KEY ");
        input=getch();
        switch(input)
        {
            case 'a':

                if(cursor==0||cursor==4||cursor==8||cursor==12)
                    break;
                else
                {
                    cursor+=-1;
                    moves--;
                    array[cursor+1]=array[cursor];

                }
                break;

            case 'd':
                if(cursor==3||cursor==7||cursor==11||cursor==15)
                    break;
                else
                {
                    cursor+=1;
                    moves--;
                    array[cursor-1]=array[cursor];

                }
                break;

            case 'w':
                if(cursor==0||cursor==1||cursor==2||cursor==3)
                    break;
                else
                {
                    cursor+=-4;
                    moves--;
                    array
                    [cursor+4]=array[cursor];

                }
                break;

            case 'z':
                if(cursor==12||cursor==13||cursor==14||cursor==15)
                    break;
                else
                {
                    cursor+=4;
                    moves--;
                    array[cursor-4]=array[cursor];

                }
                break;

            case 'e':
                system("cls");
                printf("\n\tTHANK YOU FOR PLAYING THE GAME!!");
                Sleep(2000);
                exit(0);

            default:
                printf("\n\n  INVALID KEY PRESSES!! PLEASE CHECK !! CAPSLOCK SHOULD BE OFF!!");

        }

        if(moves<1)
        {
            system("cls");

            printf("\n ");
            date_time();

            printf("\n\n\n\t  !! YOU LOST !!\n\n\n   DO YOU WANT TO PLAY IT AGAIN?\n\n\n   PRESS 'y' TO PLAY AGAIN\n\n\n\t\tOR \n\n\n   PRESS ANY OTHER KEY TO EXIT.\n");
            a=getch();
                switch(a)
                {
                    case'y':
                        system("cls");
                        the_game(name);
                        break;

                    default:

                        system("cls");
                        printf("\n\tTHANK YOU FOR PLAYING THE GAME!!");
                        Sleep(2000);
                        exit(0);
                }
        }

    system("cls");

    }

}

