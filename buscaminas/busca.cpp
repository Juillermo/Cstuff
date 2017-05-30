#include<stdio.h>
#include<ctime>
#include <cstdlib>
#include<ctype.h>
#define N 26

void DisplayField(int field[][N],int size1,int size2, int covered[][N],int mines,int x);
void SetMines(int field[][N],int size1,int size2,int mines);
void SetNumbers(int field[][N], int size1,int size2,int covered[][N]);
int Click(int field[][N],int size1,int size2,int covered[][N]);
void Check0(int field[][N],int size1,int size2, int covered[][N],char x, int y);
int CheckWin(int field[][N],int size1,int size2, int covered[][N],int mines, int *XX);
int Menu(int *size1,int *size2);

int main (void)
{
	int size1,size2,field[N][N],covered[N][N],k,mines,x=0;
	char p;
	
	do{
		mines=Menu(&size1,&size2);
		srand(time(0));
		SetMines(field, size1,size2,mines);
		SetNumbers(field, size1,size2,covered);
		DisplayField(field, size1,size2,covered,mines,x);
		do{
			k=Click(field,size1,size2,covered);
			if(k==0){
				k+=CheckWin(field,size1,size2,covered,mines,&x);
			}
			DisplayField(field,size1,size2,covered,mines,x);
		}while(k==0);
		if(k==1){
			printf("\n\nBOOOOM!!!!\n\n");
		}else{
			printf("\n\nCongratulations!! You are a great minesweeper ;)");
		}
		printf("\n\nDo you want to play again? Y/N\n");
		scanf(" %c", &p);
		p=tolower(p);
	}while(p=='y');
	return 0;
}

void DisplayField(int field[][N],int size1,int size2,int covered[][N],int mines,int x)
{
	int i;
	int j;
	
	printf("\n\n ");
	
	for(i=0;i<size2;i++){
		printf(" %2d", i+1);
	}
	
	for(i=0;i<size1;i++){
		printf("\n\n%c", i+'A');
		for(j=0;j<size2;j++){
			if(covered[i][j]==1){
				if(field[i][j]=='*'){
					printf("  *");
				}else{
					printf("  %d", field[i][j]);
				}
			}else if(covered[i][j]==0){
				printf("   ");
			}else{
				printf("  X");
			}
		}
	}
	printf("        Mines left: %d",mines-x);
	return ;
}

void SetMines(int field[][N],int size1,int size2,int mines)
{
	
	int i;
	int j;
	int location;
	int x;
	int y;
	
	for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			field[i][j]=0;
		}
	}
	
	for(i=0;i<mines;i++){
		location=rand()%(size1*size2);
		x=location/size2;
		y=location%size2;
		if(field[x][y]!='*'){
			field[x][y]='*';
		}else{
			i--;
		}
	}
	return ;
}

void SetNumbers(int field[][N], int size1,int size2,int covered[][N])
{
	int i;
	int j;
	int k;
	int l;
	int m;
	
	for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			if(field[i][j]!='*'){
				m=0;
				for(k=i-1;k<=i+1;k++){
					for(l=j-1;l<=j+1;l++){
						if(k>=0&&l>=0&&k<size1&&l<size2){
							if((k!=i||l!=j)&&field[k][l]=='*'){
								m++;
							}
						}
					}
				}
				field[i][j]=m;
			}
		}
	}
	
	for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			covered[i][j]=0;
		}
	}
	return ;
}

int Click(int field[][N],int size1,int size2,int covered[][N])
{
	char x;
	int y;
	char t;
	int k=0;
	int m;
	int n;
	
	do{
		printf("\n\nType D if you want to discover the Slot. For marking the place as a mine, type X: ");
		scanf(" %c",&t);
		t=toupper(t);
	}while(t!='D'&&t!='X');
	printf("Where will you click next?\nCharacter: ");
	scanf(" %c", &x);
	x=toupper(x);
	while(x<'A'||x>='A'+size1){
		printf("The letter must be between A and %c: ", 'A'+size1-1);
		scanf(" %c", &x);
		x=toupper(x);
	}
	printf("Number: ");
	scanf("%d", &y);
	while(y<1||y>size2){
		printf("The number just can be between 1 and %d: ", size2);
		scanf("%d", &y);
	}
	x-='A';
	y--;
	if(t=='D'){
		if(covered[x][y]!=1){
			covered[x][y]=1;
			if(field[x][y]==0){
				Check0(field,size1,size2,covered,x,y);
			}else if(field[x][y]=='*'){
				k++;
			}
		}else{
			for(m=x-1;m<=x+1;m++){
				for(n=y-1;n<=y+1;n++){
					if(m>=0&&n>=0&&m<size1&&n<size2&&covered[m][n]==0){
						covered[m][n]=1;
						if(field[m][n]==0){
							Check0(field,size1,size2,covered,m,n);
						}else if(field[m][n]=='*'){
							k++;
						}
					}
				}
			}
		}
	}else if(covered[x][y]==0){
		covered[x][y]=-1;
	}else{
		printf("\nMark could not be put.");
	}
	
	return k;
}

void Check0(int field[][N],int size1,int size2, int covered[][N],char x, int y)
{
	char k;
	int l;
	
	for(k=x-1;k<=x+1;k++){
		for(l=y-1;l<=y+1;l++){
			if(k>=0&&l>=0&&k<size1&&l<size2&&covered[k][l]==0){
				covered[k][l]=1;
				if(field[k][l]==0){
					Check0(field,size1,size2,covered,k,l);
				}
			}
		}
	}

	return ;
}

int CheckWin(int field[][N],int size1,int size2, int covered[][N],int mines,int *XX)
{
	int k=0;
	int i;
	int j;
	int l=0;
	int x=0;
	
	for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			if(covered[i][j]==0){
				l++;
			}else if(covered[i][j]==-1){
				x++;
			}
		}
	}
	*XX=x;
	if(l==0&&mines==x){
		k+=2;
	}
	
	return k;
}

int Menu(int *size1,int *size2)
{
	int mines;
	int k;
	
	printf("\n\n             Welcome to the Pussy-Minesweeper!!!\n");
	printf("\n\nHow good are you at detecting and destroying mines?\n");
	printf("1- Beginner (yes, I am quite a stupid noobie)\n");
	printf("2- Advanced (I know what happen if you rightclick a slot)\n");
	printf("3- Expert (playing without right and left click each time is a waste of time)");
	printf("\n4- Godlike (I am so good that I will choose my own parameters, thanks)");
	printf("\nChoose 1,2,3 or 4: ");
	scanf("%d",&k);
	do{
		switch(k){
		case 1:
			mines=10;
			*size1=9;
			*size2=9;
			break;
		case 2:
			mines=40;
			*size1=16;
			*size2=16;
			break;
		case 3:
			mines=99;
			*size1=19;
			*size2=26;
			break;
		case 4:
			printf("Set the height of the board: ");
			scanf("%d", size1);
			while(*size1<1||*size1>N){
				printf("Height must be lower than %d: ", N);
				scanf("%d", size1);
			}
			printf("Set the lenght of the board: ");
			scanf("%d", size2);
			while(*size2<1||*size2>N){
				printf("Length must be lower than %d: ", N);
				scanf("%d", size2);
			}
			printf("How many mines will this Minesweeper have? ");
			scanf("%d",&mines);
			while(mines<=0||mines>=(*size1)*(*size2)){
				printf("Type a posible number of mines (lower than %d), please: ", (*size1)*(*size2));
				scanf("%d",&mines);
			}
			break;
		default:
			printf("1,2,3,4, there aren't more options: ");
			scanf("%d",&k);
		}
	}while(k<1||k>4);
	return mines;
}
