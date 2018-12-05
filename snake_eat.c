#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMove(int, int);
void put_money(void);
void gameover(void);

char map[12][12]=
	{"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"};

int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int snakeLength=5;

int main()
{
	put_money();
	int ch;
	int counter1, counter2;
	for(counter1=0;counter1<12;counter1++)
		for(counter2=0;counter2<12;counter2++)
		{
			printf("%c", map[counter1][counter2]);
			if(counter2==11)
				printf("\n");
		}
	while(scanf("%c", &ch)!=EOF)
	{
		switch(ch)
		{
			case 'a':snakeMove(-1,0);break;
			case 'd':snakeMove(1,0);break;
			case 'w':snakeMove(0,-1);break;
			case 's':snakeMove(0,1);break;
		}
	}
}
void snakeMove(int x, int y)
{
	if(x==1)
	{
		if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1]+1]=='X' || map[snakeY[snakeLength-1]][snakeX[snakeLength-1]+1]=='*')
			gameover();
		else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1]+1]=='$')
		{
			snakeLength++;
			snakeX[snakeLength-1]=snakeX[snakeLength-2]+1;
			snakeY[snakeLength-1]=snakeY[snakeLength-2];
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
			map[snakeY[snakeLength-2]][snakeX[snakeLength-2]]='X';
			put_money();
			int counter1, counter2;
			for(counter1=0;counter1<12;counter1++)
				for(counter2=0;counter2<12;counter2++)
				{
					printf("%c", map[counter1][counter2]);
					if(counter2==11)
						printf("\n");
				}
		}
		else
		{
			map[snakeY[0]][snakeX[0]]=' ';
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='X';
			int counter;
			for(counter=0;counter<snakeLength-1;counter++)
			{
				snakeX[counter]=snakeX[counter+1];
				snakeY[counter]=snakeY[counter+1];
			}
			snakeX[snakeLength-1]=snakeX[snakeLength-1]+1;
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
			int counter1, counter2;
			for(counter1=0;counter1<12;counter1++)
				for(counter2=0;counter2<12;counter2++)
				{
					printf("%c", map[counter1][counter2]);
					if(counter2==11)
						printf("\n");
				}
		}
	}
	if(x==-1)
	{
		if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1]-1]=='X' || map[snakeY[snakeLength-1]][snakeX[snakeLength-1]-1]=='*')
			gameover();
		else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1]-1]=='$')
		{
			snakeLength++;
			snakeX[snakeLength-1]=snakeX[snakeLength-2]-1;
			snakeY[snakeLength-1]=snakeY[snakeLength-2];
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
			map[snakeY[snakeLength-2]][snakeX[snakeLength-2]]='X';
			put_money();
			int counter1, counter2;
			for(counter1=0;counter1<12;counter1++)
				for(counter2=0;counter2<12;counter2++)
				{
					printf("%c", map[counter1][counter2]);
					if(counter2==11)
						printf("\n");
				}
		}
		else
		{
			map[snakeY[0]][snakeX[0]]=' ';
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='X';
			int counter;
			for(counter=0;counter<snakeLength-1;counter++)
			{
				snakeX[counter]=snakeX[counter+1];
				snakeY[counter]=snakeY[counter+1];
			}
			snakeX[snakeLength-1]=snakeX[snakeLength-1]-1;
			map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
			int counter1, counter2;
			for(counter1=0;counter1<12;counter1++)
				for(counter2=0;counter2<12;counter2++)
				{
					printf("%c", map[counter1][counter2]);
					if(counter2==11)
						printf("\n");
				}
		}
	}
	else
	{
		if(y==1)
		{
			if(map[snakeY[snakeLength-1]+1][snakeX[snakeLength-1]]=='X' || map[snakeY[snakeLength-1]+1][snakeX[snakeLength-1]]=='*')
				gameover();
			else if(map[snakeY[snakeLength-1]+1][snakeX[snakeLength-1]]=='$')
			{
				snakeLength++;
				snakeX[snakeLength-1]=snakeX[snakeLength-2];
				snakeY[snakeLength-1]=snakeY[snakeLength-2]+1;
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
				map[snakeY[snakeLength-2]][snakeX[snakeLength-2]]='X';
				put_money();
				int counter1, counter2;
				for(counter1=0;counter1<12;counter1++)
					for(counter2=0;counter2<12;counter2++)
					{
						printf("%c", map[counter1][counter2]);
						if(counter2==11)
							printf("\n");
					}
			}
			else
			{
				map[snakeY[0]][snakeX[0]]=' ';
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='X';
				int counter;
				for(counter=0;counter<snakeLength-1;counter++)
				{
					snakeX[counter]=snakeX[counter+1];
					snakeY[counter]=snakeY[counter+1];
				}
				snakeY[snakeLength-1]=snakeY[snakeLength-1]+1;
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
				int counter1, counter2;
				for(counter1=0;counter1<12;counter1++)
					for(counter2=0;counter2<12;counter2++)
					{
						printf("%c", map[counter1][counter2]);
						if(counter2==11)
							printf("\n");
					}
			}
		}
		else if(y==-1)
		{
			if(map[snakeY[snakeLength-1]-1][snakeX[snakeLength-1]]=='X' || map[snakeY[snakeLength-1]-1][snakeX[snakeLength-1]]=='*')
				gameover();
			else if(map[snakeY[snakeLength-1]-1][snakeX[snakeLength-1]]=='$')
			{
				snakeLength++;
				snakeX[snakeLength-1]=snakeX[snakeLength-2];
				snakeY[snakeLength-1]=snakeY[snakeLength-2]-1;
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
				map[snakeY[snakeLength-2]][snakeX[snakeLength-2]]='X';
				put_money();
				int counter1, counter2;
				for(counter1=0;counter1<12;counter1++)
					for(counter2=0;counter2<12;counter2++)
					{
						printf("%c", map[counter1][counter2]);
						if(counter2==11)
							printf("\n");
					}
			}
			else
			{
				map[snakeY[0]][snakeX[0]]=' ';
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='X';
				int counter;
				for(counter=0;counter<snakeLength-1;counter++)
				{
					snakeX[counter]=snakeX[counter+1];
					snakeY[counter]=snakeY[counter+1];
				}
				snakeY[snakeLength-1]=snakeY[snakeLength-1]-1;
				map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]='H';
				int counter1, counter2;
				for(counter1=0;counter1<12;counter1++)
					for(counter2=0;counter2<12;counter2++)
					{
						printf("%c", map[counter1][counter2]);
						if(counter2==11)
							printf("\n");
					}
			}
		}
	}
}
void gameover()
{
	printf("Game over.\n");
}
void put_money()
{
	int x,y;
	int flag1, flag2;
	for(;flag1!=1;)
	{
		flag1=1;
		x=rand()%10+1;
		int counter1;
		for(counter1=0;counter1<snakeLength;counter1++)
		{
			if(snakeX[counter1]==x)
			{
				flag1=0;
				break;
			}
		}
	}
	for(;flag2!=1;)
	{
		flag2=1;
		y=rand()%10+1;
		int counter2;
		for(counter2=0;counter2<snakeLength;counter2++)
		{
			if(snakeY[counter2]==y)
			{
				flag2=0;
				break;
			}
		}
	}
	map[y][x]='$';
}
