#include <iostream>
#include <iomanip>
using namespace std;

void select (int *); //�ŧi��ܱƧǪk�Ƶ{��
void showdata (int *);//�ŧi�C�L�}�C�Ƶ{��
int main(void)
{
	int data[6]={9,7,5,3,4,6};
	cout<<"��l��Ƭ��G";
	showdata(data);
	select(data);
	return 0;
}
void showdata (int data[])
{
	for (int i=0;i<6;i++)
	    cout<<setw(3)<<data[i];
	cout<<endl;
}

void select (int data[])
{
	int smallest,temp;
	int index;
	for(int i=0;i<5;i++) //���y5��
	{   
	    smallest=data[i];
	    index=i;
		for(int j=i+1;j<6;j++)  //��i+1����_�A���5��
		{	    
			if(smallest>data[j]) //��X�̤p���� 
			{	
				smallest=data[j];
				index=j;
			}
	    }
	    //�N�̤p�����Ҧb��m�P�� i �Ӧ�m�洫 
		temp=data[index];
		data[index]=data[i];
		data[i]=temp;
		
		cout<<"�� "<<i+1<<" ���Ƨǵ��G�G";
	    for (int k=0;k<6;k++)
			cout<<setw(3)<<data[k]; //�C�L�Ƨǵ��G
	    cout<<endl;
	}
    cout<<endl;
}
