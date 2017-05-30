#include<stdio.h>
#define M 6
#define N 7

void DisplayBoard(int board[][N]);
void TakeTurn(int board[][N], int p);
int CheckWinner(int board[][N]);

int main (void)
{
	int board[M][N], i, j, p=0, w=0;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			board[i][j]=0;
		}
	}
	printf("This is the Connect-4 Game, the best game ever. Player 1 has circles and player 2 crosses.");
	DisplayBoard(board);
	do{
		TakeTurn(board, p%2);
		DisplayBoard(board);
		w=CheckWinner(board);
		p++;
	}while(w==0);
	if(w==1){
		printf("\n\n------Player 1 wins!!!------");
	}else{
		printf("\n\n------Player 2 wins!!!------");
	}
	scanf("%d",&i);
	return 0;
}

void DisplayBoard(int board[][N])
{
	int i, j;
	
	for(i=0;i<M;i++){
		printf("\n\n");
		for(j=0;j<N;j++){
			printf("  ");
			if(board[i][j]==1){
				printf("O");
			}else if(board[i][j]==-1){
				printf("X");
			}else{
				printf(" ");
			}
		}
	}
	printf("\n\n");
	for(i=1;i<=N;i++){
		printf("  %d", i);
	}
	
	
	return ;
}

void TakeTurn(int board[][N], int p)
{
	int i, c, l=0;
	
	printf("\n\nPlayer %d, is your turn. Choose the column you will place your token: ", p+1);
	do{
		scanf("%d", &c);
		while(c<1||c>7){
			printf("Columns go from 1 to 7. Enter it again, please:");
			scanf("%d", &c);
		}
		c--;
		for(i=N-1;i>=0&&l==0;i--){
			if(board[i][c]==0&&p==0){
				board[i][c]=1;
				l++;
			}else if(board[i][c]==0&&p==1){
				board[i][c]=-1;
				l++;
			}
		}
		if(l==0){
			printf("\nThat column is completed! Choose another one: ");
		}
	}while(l==0);
	
	return ;
}

int CheckWinner(int board[][N])
{
	int w=0, i, j, l=0, k=0, f, h;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(board[i][j]==1){
				l++;
				k=0;
			}else if(board[i][j]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}
	for(j=0;j<M;j++){
		for(i=0;i<N;i++){
			if(board[i][j]==1){
				l++;
				k=0;
			}else if(board[i][j]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}

	for(f=0;f<3;f++){
		for(h=0;h<4+f;h++){
			if(board[3+f-h][h]==1){
				l++;
				k=0;
			}else if(board[3+f-h][h]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}
	for(f=0;f<3;f++){
		for(h=0;h<6-f;h++){
			if(board[5-h][1+f+h]==1){
				l++;
				k=0;
			}else if(board[5-h][1+f+h]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}
	for(f=0;f<3;f++){
		for(h=0;h<4+f;h++){
			if(board[3+f-h][6-h]==1){
				l++;
				k=0;
			}else if(board[3+f-h][6-h]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}
	for(f=0;f<3;f++){
		for(h=0;h<6-f;h++){
			if(board[5-h][5-h-f]==1){
				l++;
				k=0;
			}else if(board[5-h][5-h-f]==-1){
				k++;
				l=0;
			}else{
				l=0;
				k=0;
			}
			if(l==4){
				w=1;
			}else if(k==4){
				w=-1;
			}
		}
		k=0;
		l=0;
	}
	return w;
}
