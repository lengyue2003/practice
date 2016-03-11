#include<stdio.h>
#include<string.h>
#define LINEMAXA 1024
#define LENGTH 6 
void display(char(*chessboard)[LENGTH]);
int valid_location(char(*chessboard)[LENGTH],char*location);
int chess_over(char(*chessboard)[LENGTH]);
void chess_rule(char(*chessboard)[LENGTH],int row,int column);
void row_change(char(*chessboard)[LENGTH],int row,int column);
void column_change(char(*chessboard)[LENGTH],int row,int column);
void oblique_up_down(char(*chessboard)[LENGTH],int row,int column);
void oblique_down_up(char(*chessboard)[LENGTH],int row,int column);
int main()
{
	int row=LENGTH;
	int column=LENGTH;
	char location[1024];
	char chessboard[row][column];
	const char comp_c='*';
	const char player_c='o';
	int player=1;
	memset(chessboard,32,LENGTH*LENGTH);
	chessboard[2][2]=player_c;
	chessboard[2][3]=comp_c;
	chessboard[3][2]=comp_c;
	chessboard[3][3]=player_c;
	display(chessboard);
	while(1){
		if(chess_over(chessboard))
			break;
		if(player==1)
			printf("Please \'o\' choose\n");
		else 
			printf("Please \'*\' choose\n");
		while(1){
			fgets(location,1024,stdin);
			printf("%s",location);
			if(valid_location(chessboard,location))
				break;
			else
				printf("Please enter the first character from \'1\' to \'6\'and the second character from \'a\' to \'f\'\n");
		}
		row=location[0]-49;
		column=location[1]-97;
		if(player==1)
			chessboard[row][column]=player_c;
		else
			chessboard[row][column]=comp_c;
		chess_rule(chessboard,row,column);
	display(chessboard);
	player=(player+1)%2;
	}
	printf("the chess is over");
	return 0;
}
void display(char(*chessboard)[LENGTH])
{
	printf("    a   b   c   d   e   f  \n");
	printf("  +---+---+---+---+---+---+\n");
	for(int i=0;i<LENGTH;i++){
		for(int j=0;j<LENGTH;j++){
			if(j==0)
				printf("%d | %c |",i+1,chessboard[i][j]);
			else
				printf(" %c |",chessboard[i][j]);
		}
		printf("\n");
		printf("  +---+---+---+---+---+---+\n");
	}
	printf("Please enter two characters.\n");
	printf("Don't choose the  used location on the chessboard\n");
	printf("such as \"2f\",\"2\" is the row and \"f\" is the column on the chessboard\n");
}
int valid_location(char(*chessboard)[LENGTH],char*location)
{
	char first_c=location[0];
	char second_c=location[1];
	int valid=0;
	if(first_c<'1'||first_c>'6')
		return valid;
	if(second_c<'a'||second_c>'f')
		return valid;
	if(chessboard[first_c-49][second_c-97]==32)
		valid=1;
	return valid;
}
int chess_over(char(*chessboard)[LENGTH])
{
	int valid_count=0;
	for(int i=0;i<LENGTH;i++)
		for(int j=0;j<LENGTH;j++)
			if(chessboard[i][j]==32)
				valid_count++;
	if(valid_count==0)
		return 1;
	else
		return 0;
}				
void chess_rule(char(*chessboard)[LENGTH],int row,int column)
{
	row_change(chessboard,row,column);
	column_change(chessboard,row,column);
	oblique_up_down(chessboard,row,column);
	oblique_down_up(chessboard,row,column);
}		
void row_change(char(*chessboard)[LENGTH],int row,int column)
{
	int left_column=column;
	int right_column=column;
	char flag=chessboard[row][column];
	if((column-1)>0)
		if(chessboard[row][column]!=chessboard[row][column-1]&&chessboard[row][column-1]!=32)
			for(int i=column-1;i>0&&chessboard[row][i-1]!=32;i--)
				if(chessboard[row][i]!=chessboard[row][i-1])
					left_column=i;
	if((column+1)<(LENGTH-1))
		if(chessboard[row][column]!=chessboard[row][column+1]&&chessboard[row][column+1]!=32)
			for(int i=column+1;i<(LENGTH-1)&&chessboard[row][i+1]!=32;i++)
				if(chessboard[row][i]!=chessboard[row][i+1])
					right_column=i;
	for(int i=left_column;i<=right_column;i++)
		chessboard[row][i]=flag;
}
void column_change(char(*chessboard)[LENGTH],int row,int column)
{
	int left_row=row;
	int right_row=row;
	char flag=chessboard[row][column];
	if((row-1)>0)
		if(chessboard[row][column]!=chessboard[row-1][column]&&chessboard[row-1][column]!=32)
			for(int i=row-1;i>0&&chessboard[i-1][column]!=32;i--)
				if(chessboard[i][column]!=chessboard[i-1][column])
					left_row=i;
	if((row+1)<(LENGTH-1))
		if(chessboard[row][column]!=chessboard[row+1][column]&&chessboard[row+1][column]!=32)
			for(int i=row+1;i<(LENGTH-1)&&chessboard[i+1][column];i++)
				if(chessboard[i][column]!=chessboard[i+1][column])
					right_row=i;
	for(int i=left_row;i<=right_row;i++)
		chessboard[i][column]=flag;
}
void oblique_up_down(char(*chessboard)[LENGTH],int row,int column)
{
	int left_row=row;
	int left_column=column;
	int right_row=row;
	int right_column=column;
	char flag=chessboard[row][column];
	if((row-1)>0&&(column-1)>0)
		if(chessboard[row][column]!=chessboard[row-1][column-1]&&chessboard[row-1][column-1]!=32)
			for(int i=row-1,j=column-1;i>0&&j>0&&chessboard[i-1][j-1]!=32;i--,j--)
				if(chessboard[i][j]!=chessboard[i-1][j-1]){
					left_row=i;
					left_column=j;
				}
	if((row+1)<(LENGTH-1)&&(column+1)<(LENGTH-1))
		if(chessboard[row][column]!=chessboard[row+1][column+1]&&chessboard[row+1][column+1]!=32)
			for(int i=row+1,j=column+1;i<(LENGTH-1)&&j<(LENGTH-1)&&chessboard[i+1][j+1]!=32;i++,j++)
				if(chessboard[i][j]!=chessboard[i+1][j+1]){
					right_row=i;
					right_column=j;
				}
	for(int i=left_row,j=left_column;i<=right_row&&j<=right_column;i++,j++)
		chessboard[i][j]=flag;
}
void oblique_down_up(char(*chessboard)[LENGTH],int row,int column)
{
	int left_row=row;
	int left_column=column;
	int right_row=row;
	int right_column=column;
	char flag=chessboard[row][column];
	if((row+1)<(LENGTH-1)&&(column-1)>0)
		if(chessboard[row][column]!=chessboard[row+1][column-1]&&chessboard[row+1][column-1]!=32)
			for(int i=row+1,j=column-1;i<(LENGTH-1)&&j>0&&chessboard[i+1][j-1]!=32;i++,j--)
				if(chessboard[i][j]!=chessboard[i+1][j-1]){
					left_row=i;
					left_column=j;
				}
	if((row-1)>0&&(column+1)<(LENGTH-1))
		if(chessboard[row][column]!=chessboard[row-1][column+1]&&chessboard[row-1][column+1]!=32)
			for(int i=row-1,j=column+1;i>0&&j<(LENGTH-1)&&chessboard[i-1][j+1]!=32;i--,j++)
				if(chessboard[i][j]!=chessboard[i-1][j+1]){
					right_row=i;
					right_column=j;
				}
	for(int i=left_row,j=left_column;i>=right_row&&j<=right_column;i--,j++)
		chessboard[i][j]=flag;
}
