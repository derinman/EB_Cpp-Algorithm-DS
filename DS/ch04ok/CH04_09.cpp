#include <iostream>
#define EAST  MAZE[x][y+1]  //�w�q�F�誺�۹��m
#define WEST  MAZE[x][y-1]  //�w�q��誺�۹��m
#define SOUTH MAZE[x+1][y]	//�w�q�n�誺�۹��m
#define NORTH MAZE[x-1][y]	//�w�q�_�誺�۹��m
using namespace std;
const int ExitX = 8;		//�w�q�X�f��X�y�Цb�ĤK�C
const int ExitY = 10;		//�w�q�X�f��Y�y�Цb�ĤQ��
struct list
{
	int x,y;
	struct list* next;
};
typedef struct list node;
typedef node* link;
int MAZE[10][12] = {1,1,1,1,1,1,1,1,1,1,1,1,	//�ŧi�g�c�}�C
		            1,0,0,0,1,1,1,1,1,1,1,1,
				    1,1,1,0,1,1,0,0,0,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,0,0,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,1,1,1,0,1,1,0,1,1,
					1,1,0,0,0,0,0,0,1,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,1};
link push(link stack,int x,int y);
link pop(link stack,int* x,int* y);
int chkExit(int ,int ,int,int);
int main(void)
{
	int i,j;
	link path = NULL;
	int x=1;	//�J�f��X�y��
	int y=1;    //�J�f��Y�y��
	cout<<"[�g�c�����|(0������)]"<<endl; //�L�X�g�c�����|��
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			cout<<MAZE[i][j]<<" ";
		cout<<endl;
	}
	while(x<=ExitX&&y<=ExitY)
	{
		MAZE[x][y]=2;
		if(NORTH==0)
		{
			x -= 1;
			path=push(path,x,y);
		}
		else if(SOUTH==0)
		{
			x+=1;
			path=push(path,x,y);
		}
		else if(WEST==0)
		{
			y-=1;
			path=push(path,x,y);
		}
		else if(EAST==0)
		{
			y+=1;
			path=push(path,x,y);
		}
		else if(chkExit(x,y,ExitX,ExitY)==1) //�ˬd�O�_����X�f�F
			break;
		else
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		}
	}
	cout<<"[�ѹ����L�����|(2������)]"<<endl; //�L�X�ѹ������g�c�᪺���|��
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			cout<<MAZE[i][j]<<" ";
		cout<<endl;
	}    
    return 0;
}
link push(link stack,int x,int y)
{
	link newnode;
	newnode = new node;
	if(!newnode)
	{
		cout<<"Error!�O����t�m����!"<<endl;
		return NULL;
	}
	newnode->x=x;
	newnode->y=y;
	newnode->next=stack;
	stack=newnode;
    return stack;
}
link pop(link stack,int* x,int* y)
{
	link top;
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;
		*x=top->x;
		*y=top->y;
		delete top;
		return stack;
	}
	else
		*x=-1;
	return stack;
}
int chkExit(int x,int y,int ex,int ey)
{
	if(x==ex&&y==ey)
	{
		if(NORTH==1||SOUTH==1||WEST==1||EAST==2)
			return 1;
		if(NORTH==1||SOUTH==1||WEST==2||EAST==1)
			return 1;
		if(NORTH==1||SOUTH==2||WEST==1||EAST==1)
			return 1;
		if(NORTH==2||SOUTH==1||WEST==1||EAST==1)
			return 1;
    }
	return 0;
}