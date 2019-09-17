#include<stdio.h>
#include<stdlib.h>

int check_win(char* board)
{
	if((board[0] == board[1]) && (board[1] == board[2]))
		return 1;
	else if((board[3] == board[4]) && (board[4] == board[5]))
		return 1;
	else if((board[6] == board[7]) && (board[7] == board[8]))
		return 1;
	else if((board[0] == board[3]) && (board[3] == board[6]))
		return 1;
	else if((board[1] == board[4]) && (board[4] == board[7]))
		return 1;
	else if((board[2] == board[5]) && (board[5] == board[8]))
		return 1;
	else if((board[0] == board[4]) && (board[4] == board[8]))
		return 1;
	else if((board[2] == board[4]) && (board[4] == board[6]))
		return 1;
	else 
		return 0;		
}

void draw(char* board)
{
	system("cls");
	int i;
	for(i=0;i<9;i++)
	{
		if(i%3 == 0)
			printf("\n\t\t");	
			
		printf(" %c ",board[i]);
	}
}


void play()
{
	char board[9] = {'1','2','3','4','5','6','7','8','9'};
	int turn = 1,count = 0,error=0;
	
	system("cls");
	draw(board);
	
	while(count < 9)
	{
		if(error > 3)
		{
			system("cls");
			printf("\nToo many MISTAKES. GAME SUSPENDED\n");
			break;
		}
		
		fflush(stdin); 
		
		int pos=-1;
		printf("\n\nEnter Player %d Position  :   ",turn);
		
		scanf("%d",&pos);
		
		if(pos < 1 || pos > 9)
		{
			printf("\nPlease enter correct Position");
			error++;
			continue;
		}
		
		if(board[pos-1] == 'X' || board[pos-1] == '0')
		{
			printf("\nBlock already filled");
			error++;
			continue;
		}
		
		if(turn == 1)
		{
			board[pos-1] = 'X';
			turn = 2;
			count++;
		}
		else if(turn == 2)
		{
			board[pos-1] = '0';
			turn = 1;
			count++;
		}
		
		draw(board);
		
		
		if(count >= 5)
		{
			int res = check_win(board);
			if(res)
			{
				if(turn == 1)
					turn = 2;
				else
					turn = 1;
				printf("\n\n\t\tPlayer %d WON\n", turn);
				count--;  // Because player may won with no block left i.e count = 9. Otherwise conflict with draw condition
				break;
			}
		}
			
		
	}
	
	if(count == 9)
		printf("\n\n\t\tMatch Draws");
	
}

int main()
{
	char choice = 'n' ;
	
	do{
		play();
		choice = 'n';
		printf("\n\nPress Y to play again and any other key to exit\n");
		fflush(stdin);
		scanf("%c",&choice);
	}while(choice == 'y' || choice == 'Y') ;
	
}
