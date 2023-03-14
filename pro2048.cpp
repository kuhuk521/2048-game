#include <iostream>
#include <math.h>
#include <algorithm>
#include <conio.h>
#include <ctime>
using namespace std;

void up(int a[4][4]){

    int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}


void down(int a[4][4]){

    int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}


}

void right(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void left(int a[4][4]){
    int l1,r1;

    for(int i=0;i<4;i++){
        l1=i; r1=0;
        for(int j=1;j<4;j++){
            if(a[i][j]!=0){
                if(a[i][j-1]==0 || a[i][j-1]==a[i][j]){
                    if(a[l1][r1]==a[i][j]){
                        a[l1][r1]*=2;
                        a[i][j]=0;
                    }

                    else{
                        if(a[l1][r1]==0){
                            a[l1][r1]=a[i][j];
                            a[i][j]=0;
                        }
                        else{
                            a[l1][++r1]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else
                r1++;
            }
        }
   }



}

int compare(int a[4][4], int temp[4][4]){

    int flag=1;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]!=temp[i][j]){
                flag=0;
                break;
            }
        }
    }
    return flag;
}

void add(int a[4][4]){

    int l1, r1;
    srand(time(0));

    while(1){
        l1=rand()%4;
        r1=rand()%4;

        if(a[l1][r1]==0){
            a[l1][r1]=pow(2,l1%2+1);
            break;
        }
    }

}

int check(int a[4][4]){
    
    int flag=0, flag1=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]==0){
                flag=1;
                break;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j]){
                flag1=1;
                break;
            }
        }
    }

    if(flag || flag1)
    return 1;

    return 0;
}

void print(int a[4][4]){

    cout<<endl<<"\t\tPress Esc key to quit the game";
    cout<<endl<<endl<<endl<<endl;

    for(int i=0;i<4;i++){
        cout<<"\t\t\t\t-----------------\n\t\t\t\t";
        for(int j=0;j<4;j++){
            if(a[i][j]!=0){
                cout<<"| "<<a[i][j]<<" ";
            }
            else{
                cout<<"|   ";
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"\t\t\t\t-----------------\n";
}

int main(){
    cout<<"\t\t\t\tWelcome to the game\t\t\t\t"<<endl<<endl;
    cout<<"\t\t\t\tThe Rules of the game are simple, use left, right, up or down arrow keys to\n\t\t\t\tmerge similar blocks"<<endl;
    cout<<"\t\t\t\tPress any key to continue"<<endl;

    getch();
    system("cls");
    srand(time(0));

    int a1, a2, b1, b2;

    a1=rand()%4;
    a2=rand()%4;

    while(1){
        b1=rand()%4;
        b2=rand()%4;

        if(a1!=b1 && a2!=b2){
            break;
        }
    }

    int a[4][4]={0}, temp[4][4]={0};

    a[a1][a2]=2;
    a[b1][b2]=4;

    print(a);

    while(1){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                temp[i][j]=a[i][j];
            }
        }

        int ch=getch();
        system("cls");

        if(ch==72)
        up(a);

        if(ch==80)
        down(a);

        if(ch==75)
        left(a);

        if(ch==77)
        right(a);

        if(ch==27)
        break;

        if(!compare(temp,a))
        add(a);

        print(a);

        if(!check(a)){
            cout<<endl<<"\t\t\t\tGAME OVER!"<<endl<<endl;
            getch();
            break;
        }
    }
    return 0;
}

