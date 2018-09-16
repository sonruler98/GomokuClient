#include <iostream>
using namespace std;
#include <windows.h>
#include <conio.h>
#define MAX 10
void print(int array[MAX][MAX]);
void play(int array[MAX][MAX]);
int isExist(int array[MAX][MAX],int i,int j);
int isWin(int array[MAX][MAX],int key,int i,int j);
int checkNgang(int array[MAX][MAX],int key,int i,int j);
int checkDoc(int array[MAX][MAX],int key,int i,int j);
int checkCheoTrai(int array[MAX][MAX],int key,int i, int j);
int checkCheoPhai(int array[MAX][MAX],int key,int i, int j);
int ktra = 0;
void choiceRestart(int arr[MAX][MAX]);
void InputArr(int a[MAX][MAX]);
void menu();
int main(int argc, char const *argv[])
{
    int array[MAX][MAX];
	char ch ;
    InputArr(array);
    menu();
    fflush(stdin);
    ch = getch();
    if(ch == '1');
    if(ch == '2'){
    	system("cls");
    	print(array);
    	while(1){
    		play(array);
    		if (ktra==1) return 0;    	
		}
	}
    if(ch == '3') return 0;
    
    
    return 0;
}
void menu(){
	char ch;
	cout<<"1. Login"<<endl;
	cout<<"2. Quick play"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Nhan 1, 2 hoac 3 de chon ... ";
}

void InputArr(int a[MAX][MAX]){
	for (int i = 0;i<MAX;i++)
	for(int j = 0; j<MAX;j++)
	a[i][j]=1;
}

void print(int array[MAX][MAX])
{
    for(int i = 0; i< MAX;i++){
        for(int j = 0;j<MAX;j++){
        	
            if (i==0||j==0);
            else {
            	cout<<" | ";
            	if (array[i][j]==1 )cout<<" ";
            	if (array[i][j]==2 ) cout<<"O";
            	if (array[i][j]==3) cout<<"X";
			}
        }
        
        cout<<endl<<endl;
    }
}

void play(int array[MAX][MAX]){
	int i, j;
	cout<<"Den luot O!"<<endl;
	cout<<"Nhap toa do quan 'o': ";
	cin>>i>>j;
	while(isExist(array,i,j)!=0){
		cout<<"Nhap lai toa do: ";
		cin>>i>>j;
	}
	array[i][j] = 2;
	system("cls");
	print(array);
	if (isWin(array,2,i,j)) {
		cout<<"O thang!!"<<endl;
		choiceRestart(array);
		return;
	}
	cout<<"Den luot X!"<<endl;
	cout<<"Nhap toa do quan 'x': ";
	cin>>i>>j;
	while(isExist(array,i,j)!=0){
		cout<<"Nhap lai toa do: ";
		cin>>i>>j;
	}
	array[i][j] = 3;
	system("cls");
	print(array);
	if (isWin(array,2,i,j)) {
		cout<<"X thang!!";
		choiceRestart(array);
		return;
	}
}

void choiceRestart(int arr[MAX][MAX]){
	char ch;
	cout<<"Press 'R' to restart or 'Q' to quit ... ";
	fflush(stdin);
	ch = getch();
	if(ch=='r'|| ch == 'R') {
		system("cls");
		InputArr(arr);
		print(arr);
		ktra=0;
	}
	else ktra = 1;
}

int isExist(int array[MAX][MAX],int i, int j){
	if (array[i][j] != 1) return 1;
	else return 0;
}

int isWin(int array[MAX][MAX],int key,int i, int j){
	if(checkNgang(array,key,i,j)==5||checkDoc(array,key,i,j)==5||checkCheoTrai(array,key,i,j)==5||checkCheoPhai(array,key,i,j)==5) return 1;
	else return 0;
}

int checkNgang(int a[MAX][MAX],int key,int i,int j){
	int dem=0;
	//Kiem tra ben phai
	while(a[i][j]==key){
		j++;
		dem++;
	}
	j =j- dem-1;
	while(a[i][j]==key){
		j--;
		dem++;
	}
	return dem;
}

int checkDoc(int a[MAX][MAX],int key,int i,int j){
	int dem=0;
	while(a[i][j]==key){
		i++;
		dem++;
	}
	i = i - dem -1;
	while(a[i][j]==key){
		i--;
		dem++;
	}
	return dem;
}

int checkCheoTrai(int a[MAX][MAX],int key,int i,int j){
	int dem=0;
	while(a[i][j]==key){
		i++;
		j++;
		dem++;
	}
	i = i - dem - 1;
	j = j - dem  -1;
	while(a[i][j]==key){
		i--;
		j--;
		dem++;
	}
	return dem;
}

int checkCheoPhai(int a[MAX][MAX],int key,int i,int j){
	int dem=0;
	while(a[i][j]==key){
		i++;
		j--;
		dem++;
	}
	i = i - dem - 1;
	j = j - dem  - 1;
	while(a[i][j]==key){
		i--;
		j++;
		dem++;
	}
	return dem;
}
