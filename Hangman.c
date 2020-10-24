#include<stdio.h>
#include<stdlib.h>
#define pn printf("\n")

/*
basic HANGMAN GAME using C language.
option to play 4, 5 or 6 letter word hangman
in each option you have to clear 3 levels in order to win
words are given statically and can be changed in line 52
*/

char ch[10],count=-1;
//print line function 1
void pln(){
	int i;
	for(i=0;i<40;i++)
	printf("_");
}
//print line function 2
void pln2(){
	int xy;
	for(xy=0;xy<10;xy++)
		printf("_");
}
//function to draw hangman
void draw(int x){
	char a[53]={' ','-','-','-','-','-','-','\n',' ','|',' ',' ',' ',' ','|','\n',' ','|',' ',' ',' ',' ','O','\n',' ','|',' ',' ',' ','.','|','/','\n',' ','|',' ',' ',' ',' ','|','\n',' ','|',' ',' ',' ','/',' ','.','\n','-','-','-'};
	int i,n=92,b[8]={14,22,30,29,31,39,46,48},c[53]={0};
	for(i=7;i>=x;i--)
	c[b[i]]=1;
	pn;pn;
	for(i=0;i<53;i++){
		if(c[i]==0){
		if(i==29||i==48)
		printf("%c",n);
		else
		printf("%c",a[i]);
		}
		else
		printf(" ");
	}pn;pn;
	//prints all the letters entered
	printf("Letters completed: ");
	for(i=0;i<=count;i++){
		printf("%c ",ch[i]);
	}
	pn;
	pln();
	pn;
}

void hangman(int y){
	//4-letter words for 3 levels each
	char a[3][4]={"sand","roar","blue"};
	//5-letter words for 3 levels each
	char b[3][5]={"apple","river","lucky"};
	//6-letter words for 3 levels each
    char c[3][6]={"coffee","energy","scheme"};
    char s[4],gb;
    int x=0,i=0,j,p=0,q=0,m=0,xy;
    //logic
    if(y==2){
    	for(i=0;i<3;i++)
    	for(j=0;j<5;j++)
    	a[i][j]=b[i][j];
	}
    else if(y==3){
    	for(i=0;i<3;i++)
    	for(j=0;j<6;j++)
    	a[i][j]=c[i][j];
	}
    y=y+3;
	for(i=0;i<3;i++){
		system("cls");
		printf("\t\t\tLevel-%d\n\n",i+1);
		x=0;
		for(j=0;j<y;j++){
			s[j]='_';
			printf("%c ",s[j]);
		}pn;pn;
	    while(x<8){
	    	count++;
	        printf("\nEnter a letter:");
	        fflush(stdin);
	        scanf("%c",&ch[count]);pn;
	        p=0;
	        q=0;
	        for(j=0;j<y;j++){
	            if(a[i][j]==ch[count]){
	            	s[j]=ch[count];
	            	printf("%c ",ch[count]);
	            	p++;
	            }
	            else
	            printf("%c ",s[j]);
	        }
	        for(j=0;j<y;j++){
	        	if(s[j]=='_')
	        	q=1;
			}
	        if(p==0)
	        	x++;
	        draw(x);
	        if(q==0)
			break;
	        m+=p;	        
	    }
	    //cheking if you lost
	    if(x>=8){
	    printf("\nYou Lose\nGood luck next time\n");
	    break;
		}
		//printing score
		pn;
		pln2();
		pn;pn;
		printf("SCORE : %d",m);pn;
		pln2();
		pn;
		count=-1;
		//checking if you win or cleared a level
		if(i==2)
		printf("\nCONGRATULATIONS !! You Win");
		else{
		printf("\nYou cleared Level-%d",i+1);
		printf("\npress enter to continue");
	    fflush(stdin);
		scanf("%c",&gb);
		}
	}
	//choice after loSsing or winning to go back to menu or exit
	printf("\nenter 1 to go back 2 to exit ");
	scanf("%d",&q);
	if(q==1)
	return;	
	else
	exit(0);
}

int main(){
	int y;
	while(y<4){
		system("cls");
		printf("-----HANGMAN-----");pn;pn;
		printf("1. 4-letter words\n2. 5-letter words\n3. 6-letter words\n4. Exit\n");pn;
		printf("enter a option:");
    	scanf("%d",&y);
    	hangman(y);
	}
    return 0;
}
