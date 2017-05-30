#include<stdio.h>
#include<ctime>
#include <cstdlib>
#define M 10
#define N 10

void DisplayBoard(char board[][N], int t);
void AdvanceTime(char board[][N],int board_of_time[][N]);
void CheckSurviving(char board[][N],int board_of_time[][N],int i, int j);
void Judgement(char board[][N],int board_of_time[][N]);
void InitializeVirus(char board[][N],int board_of_time[][N]);

int main (void)
{
	char board[M][N];
	int board_of_time[M][N], t=0;
	char x='b';
	
	srand(time(0));
	InitializeVirus(board,board_of_time);
	printf("\n");
	DisplayBoard(board, t);
	scanf(" %c",&x);
	while(x!='a'){
		t++;
		printf("\n\n");
		AdvanceTime(board,board_of_time);
		DisplayBoard(board, t);
		scanf(" %c",&x);
	}
	
	return 0;
}

void DisplayBoard(char board[][N], int t)
{
	int i,j, h=0;
	
	for(i=0;i<M;i++){
		printf("- ");
		for(j=0;j<N;j++){
			printf("%c ", board[i][j]);
			if(board[i][j]=='O'){
				h++;
			}
		}
		printf("\n");
	}
	for(i=0;i<=N;i++){
		printf("- ");
	}
	printf("\nCurrent number of virus: %d       Instant number %d\n", h, t);
	return ;
}

void AdvanceTime(char board[][N],int board_of_time[][N])
{
	int i, j;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			CheckSurviving(board,board_of_time,i,j);
		}
	}
	Judgement(board,board_of_time);
	return ;
}

void CheckSurviving(char board[][N],int board_of_time[][N],int i, int j)
{
	int m, n, h=0;
	
	for(m=i-1;m<=i+1;m++){
		for(n=j-1;n<=j+1;n++){
			if((m!=i||n!=j)&&m>=0&&n>=0&&m<M&&n<N&&board[m][n]=='O'){
				h++;
			}
		}
	}
	
	if(h<3||h>5){
		board_of_time[i][j]=0;
	}else if(board_of_time[i][j]<10){
		board_of_time[i][j]++;
	}else{
		board_of_time[i][j]=0;
	}
	return ;
}

void Judgement(char board[][N],int board_of_time[][N])
{
	int i,j;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(board_of_time[i][j]==0){
				board[i][j]=' ';
			}else{
				board[i][j]='O';
			}
		}
	}
	
	return ;
}

void InitializeVirus(char board[][N],int board_of_time[][N])
{
	int i, j, h, n;
	
	printf("Enter the porcentage of virus you want to start with: ");
	scanf("%d", &n);
	while(n<0||n>100){
		printf("In my house porcentages goes from 0 to 100: ");
		scanf("%d", &n);
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			h=rand()%101;
			if(h<=n){
				board[i][j]='O';
			}else{
				board[i][j]=' ';
			}
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(board[i][j]=='O'){
				board_of_time[i][j]=1;
			}else{
				board_of_time[i][j]=0;
			}
		}
	}
	
	return ;
}
