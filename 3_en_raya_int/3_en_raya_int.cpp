#include<stdio.h>
#include<ctime>
#include <cstdlib>
#define N 3

void ReadMove (char board [][N]);
void MakeMove (char board [][N]);
void DisplayBoard (char board [][N]);
int CheckWinner (char board [][N]);

int main (void)
{
	char board [N][N];
	int i,j,k,n,l=0,looser=0,tie=0,winner=0;

	srand(time(0));
	printf("Welcome to the 3 in a row game. Beat me if you can and you can proudly call yourself the"
			" best 3-in-a-row-game-player in the world.\nHere is the board:");
	printf("\n ___ ___ ___ ");
	for(i=0,k=1;i<N;i++){ //Show board positions
		printf("\n|");
		for(j=0;j<N;j++){
			printf(" %d |", k);
			k++;
		}
		printf("\n ___ ___ ___ ");
	}
	do{
		for(i=0;i<N;i++){ //initialize board
			for(j=0;j<N;j++){
				board[i][j]=' ';
			}
		}
		n=rand()%2;
		i=n;
		for(k=0;i<9+n&&k==0;i++){ //Play game
			if(i%2==0){
				MakeMove (board);
			}else{
				ReadMove (board);
			}
			DisplayBoard (board);
			k=CheckWinner(board);
		}
		if(k==0){
			printf("\nHmmm... That was tie!");
			tie++;
		}else if(k<0){
			winner++;
		}else{
			looser++;
		}
		printf("\nVictories: %d    Failures: %d    Ties: %d", winner, looser, tie);
		printf("\nDo you want to play again? If so, type '1':");
		scanf("%d", &l);
	}while(l==1);
	printf("I see.. You are scared!!! Muahahahaha!!!!");
	scanf("%d", &l);
	return 0;
}

void MakeMove (char board [][N])
{
	int i;
	int j;
	int n;
	
	n=0;
	for(i=0;i<3&&n==0;i++){ //Check if possible win
		if(board[i][0]+board[i][1]+board[i][2]=='O'+'O'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[i][j]==' '){
					board[i][j]='O';
					n++;
				}
			}
		}else if(board[0][i]+board[1][i]+board[2][i]=='O'+'O'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][i]==' '){
					board[j][i]='O';
					n++;
				}
			}
		}
		
	}
	if(n==0){
		if(board[0][0]+board[1][1]+board[2][2]=='O'+'O'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][j]==' '){
					board[j][j]='O';
					n++;
				}
			}
		}
	}
	if(n==0){
		if(board[2][0]+board[1][1]+board[0][2]=='O'+'O'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][2-j]==' '){
					board[j][2-j]='O';
					n++;
				}
			}
		}
	}
	for(i=0;i<3&&n==0;i++){ //Check if possible loose
		if(board[i][0]+board[i][1]+board[i][2]=='X'+'X'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[i][j]==' '){
					board[i][j]='O';
					n++;
				}
			}
		}else if(board[0][i]+board[1][i]+board[2][i]=='X'+'X'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][i]==' '){
					board[j][i]='O';
					n++;
				}
			}
		}
		
	}
	if(n==0){
		if(board[0][0]+board[1][1]+board[2][2]=='X'+'X'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][j]==' '){
					board[j][j]='O';
					n++;
				}
			}
		}
	}
	if(n==0){
		if(board[2][0]+board[1][1]+board[0][2]=='X'+'X'+' '){
			for(j=0;j<3&&n==0;j++){
				if(board[j][2-j]==' '){
					board[j][2-j]='O';
					n++;
				}
			}
		}
	}
	if(n==0){ //random movement
		do{
			n=rand()%9;
			i=n/3;
			j=(n+3)%3;
		}while(board[i][j]!=' ');
		
		board[i][j]='O';
	}
	return ;
}

void DisplayBoard (char board [][N])
{
	int i;
	int j;
	
	printf("\n ___ ___ ___ ");
	for(i=0;i<N;i++){
		printf("\n|");
		for(j=0;j<N;j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n ___ ___ ___ ");
	}
	
	
	return ;
}

void ReadMove (char board [][N])
{
	int i;
	int j;
	int n;
	
	do{
		printf("\nWhere will you move next? Choose a number from 1 to 9 in order to choose an empty square:");
		scanf("%d", &n);
		n--;
		i=n/3;
		j=(n+3)%3;
	}while((n<0)||(n>8)||(board[i][j]!=' '));
	board[i][j]='X';
	
	return ;
}

int CheckWinner (char board [][N])
{
	int k;
	int i;
	int j;
	int a;
	
	k=0;
	if(board[0][0]+board[1][1]+board[2][2]=='X'+'X'+'X'){
		printf("\nDammit!!! You won!");
		k--;
	}else if(board[0][0]+board[1][1]+board[2][2]=='O'+'O'+'O'){
		printf("\nMuahahaha!!! I win!");
		k++;
	}
	
	if(board[0][2]+board[1][1]+board[2][0]=='X'+'X'+'X'&&k==0){
		printf("\nDammit!!! You won!");
		k--;
	}else if(board[0][2]+board[1][1]+board[2][0]=='O'+'O'+'O'&&k==0){
		printf("\nMuahahaha!!! I win!");
		k++;
	}
	
	for(i=0;i<3&&k==0;i++){
		a=0;
		for(j=0;j<3;j++){
			a+=board[i][j];
		}
		if(a=='X'+'X'+'X'){
			printf("\nDammit!!! You won!");
			k--;
		}else if(a=='O'+'O'+'O'){
			printf("\nMuahahaha!!! I win!");
			k++;
		}
	}
	
	
	
	for(j=0;j<3&&k==0;j++){
		a=0;
		for(i=0;i<3;i++){
			a+=board[i][j];
		}
		if(a=='X'+'X'+'X'){
			printf("\nDammit!!! You won!");
			k--;
		}else if(a=='O'+'O'+'O'){
			printf("\nMuahahaha!!! I win!");
			k++;
		}
	}
	
	return k;
}

