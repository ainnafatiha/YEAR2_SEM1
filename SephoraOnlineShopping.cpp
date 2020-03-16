#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <ctime>
#define SIZE 5

using namespace std;

int q[SIZE],front=0,rear=0;

//product name 14space
const int s=4;
string cardnum; 
//bath&body 
string BWName[s]= {"Mano Badesco  ","Cora Organic  ","Sephora       ","Phylosophy    "};
int BWPrice[s]={58,145,30,110};
string HCName[s]= {"Caudallie     ","Tomford Beauty","Burts Bees    ","S.C.          "};
int HCPrice[s]={65,229,81,28};
//make up
string FName[s]= {"Lancome F.    ","Marc Jacob F. ","Huda Beauty F.","Sephora F.    "};
int FPrice[s]={175,207,200,71};
string BName[s]= {"Benefit B.    ","Anastasia B.  ","Zoeva B.      ","Sephora B.    "};
int BPrice[s]={105,145,75,51};
string EBName[s]= {"Benefit EB.   ","Anastasia EB. ","Sephora B.    ","Pixie EB.     "};
int EBPrice[s]={171,110,71,99};
string ELName[s]= {"Tarte EL.     ","Sephora EL.   ","Anastasia EL. ","Marc Jacob EL."};
int ELPrice[s]={165,56,85,117};
string LSName[s]= {"Tarte LS.     ","Sephora LS.   ","3CE LS.       ","Givenchy LS.  "};
int LSPrice[s]={47,60,80,159};
string LLName[s]= {"S.C. LL.      ","Marc Jacob LL.","Benefit LL.   ","Tarte LL.     "};
int LLPrice[s]={42,103,105,71};

string all[32]={"Mano Badesco  ","Cora Organic  ","Sephora       ","Phylosophy    ",
				"Caudallie     ","Tomford Beauty","Burts Bees    ","S.C.          ",
				"Lancome F.    ","Marc Jacob F. ","Huda Beauty F.","Sephora F.    ",
				"Benefit B.    ","Anastasia B.  ","Zoeva B.      ","Sephora B.    ",
				"Benefit EB.   ","Anastasia EB. ","Sephora B.    ","Pixie EB.     ",
				"Tarte EL.     ","Sephora EL.   ","Anastasia EL. ","Marc Jacob EL.",
				"Tarte LS.     ","Sephora LS.   ","3CE LS.       ","Givenchy LS.  ",
				"S.C. LL.      ","Marc Jacob LL.","Benefit LL.   ","Tarte LL.     "};

string buy[2]={};
int price[2]={};
/***QUEUE & admin***/
	void enqueue() // add stock
	{
		int no;
		if (rear==SIZE && front==0)
			cout<<"queue is full";
		else
		{
			cout<<"Enter the stock:\n";
			cin>>no;
			q[rear]=no-1;
		}
		rear++;
	}
	
	void dequeue() //remove item
	{

			int no,i;
			if (front==rear)
				cout<<"stock is empty";
			else
			{
				no=q[front];
				front++;
				cout<<"\n"<<all[no]<<" - removed from the stock\n";
			}
	}
	
	void displayQueue() //display item that add or delete just now
	{
		int i,temp=front;
		if (front==rear)
			cout<<"the stock is empty \n";
		else
		{
			cout<<"\n Item in the stock:\n";
			for(i=temp;i<rear;i++)
			{
				cout<<i+1<<" "<<all[q[i]]<<endl;
			}
		}
	}
	

/**************************************************/
void dateTime() //show date and time
{
    time_t t = time(NULL);
  	tm* timePtr = localtime(&t);
  
  	cout << "Date :  " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
  	cout << "Time :  " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
 
}

void login(int z) //after choose either admin or guest, then enter password to login
{
	char a;
	int counter=0;
	string pswd;
	
	do
	{
		cout<<"\nEnter password to login\n";
		cout<<"Password: ";
		cin>>pswd;
	
		try
		{
			if (z==1)
			{
				if (pswd != "qwer")		//guest password
				throw 0; break;
			}
			if (z==2)
			{
				if (pswd != "asdf") 	//admin password
				throw 0; break;
			}
		}		
		catch (int x)
		{
			cout<<"\nInvalid password !\n";
			counter++;
			if (counter == 3) 
			{
				cout<<"Wrong password too many times\nThe program will exited!";
				exit(0);
			}
		}
	}while (counter <3);
}

void divider() //to arrange the menu
{
	for (int i=0; i<36;i++)
	{
		cout<<"=";
	}
	cout<<endl;
}

void show() //show menu for admin to add
{
	divider();
	cout<<"Choose the item you wish to add\n";
	divider();
	for (int f=0;f<32;f++)
	{
		cout<<f+1<<")"<<all[f]<<"\t";
		
		if( (f+1)%4==0)
			cout<<endl;
	}
}
/*********************************/
void display() //to show what had customer choose to buy
{
	int a = 0;
	system("CLS");
	divider();
	cout<<"=---------------Cart---------------=\n";
	divider();
	cout<<endl;
	for (int k=0; k<2 ; k++)
	{
		cout<<k+1<<". "<<buy[k]<<"\tRM "<<price[k]<<endl;
		a += price[k];
//		cout<<"TEST: "<<a<<endl;
	}
	cout<<"TOTAL : RM "<<a;
	system("pause");
}

int countForCart=0;

void cart(int x, int y) //to save user option
{
	switch (y)
	{
		case 1 : 
		{
			buy[countForCart]=BWName[x-1]; 
			price[countForCart]=BWPrice[x-1];	
			countForCart++; break;
		}
		case 2 :
		{
			buy[countForCart]=HCName[x-1];	
			price[countForCart]=HCPrice[x-1]; 
			countForCart++; break;
		}	
		case 3 : 
		{
			buy[countForCart]=FName[x-1]; 
			price[countForCart]=FPrice[x-1];	
			countForCart++; break;
		}
		case 4 :
		{
			buy[countForCart]=BName[x-1];	
			price[countForCart]=BPrice[x-1]; 
			countForCart++; break;
		}	
		case 5 : 
		{
			buy[countForCart]=EBName[x-1]; 
			price[countForCart]=EBPrice[x-1];	
			countForCart++; break;
		}
		case 6 :
		{
			buy[countForCart]=ELName[x-1];	
			price[countForCart]=ELPrice[x-1]; 
			countForCart++; break;
		}
		case 7 : 
		{
			buy[countForCart]=LSName[x-1]; 
			price[countForCart]=LSPrice[x-1];	
			countForCart++; break;
		}
		case 8 :
		{
			buy[countForCart]=LLName[x-1];	
			price[countForCart]=LLPrice[x-1]; 
			countForCart++; break;
		}		
		
	}
}

int LL() //show lipliner menu
{
	int d;
	divider();
	cout<<"=------------Lipliner-----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<LLName[i]<<right<<setw(8)<<"RM "<<LLPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int LS() //show lipstick menu
{
	int d;
	divider();
	cout<<"=------------Lipstick-----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<LSName[i]<<right<<setw(8)<<"RM "<<LSPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int EL() //show eyeliner menu
{
	int d;
	divider();
	cout<<"=------------EyeLiner-----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<ELName[i]<<right<<setw(8)<<"RM "<<ELPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int EB() //show eyebrow menu
{
	int d;
	divider();
	cout<<"=------------Eyebrow------------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<EBName[i]<<right<<setw(8)<<"RM "<<EBPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int B() //show blusher menu
{
	int d;
	divider();
	cout<<"=------------Blusher------------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<BName[i]<<right<<setw(8)<<"RM "<<BPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int F()// show foundation menu
{
	int d;
	divider();
	cout<<"=-----------Foundation----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<FName[i]<<right<<setw(8)<<"RM "<<FPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int BW() //show body wash menu
{
	int d;
	divider();
	cout<<"=-----------Body Wash-----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<BWName[i]<<right<<setw(8)<<"RM "<<BWPrice[i]<<endl;
	}
	divider();
	cout<<"Your choice:";
	cin>>d;
	return d;
}

int HC() //show hand cream menu
{
	int d;
	cout<<"=-----------Hand Cream----------=\n";
	divider();
	cout<<"||--------Name--------||-Price-||\n";
	for (int i=0;i<s;i++)
	{
		cout<<"  "<<i+1<<". "<<HCName[i]<<right<<setw(8)<<"RM "<<HCPrice[i]<<endl;
	}
	cout<<"||--------------------||-------||\n";	
	cout<<"Your choice: ";
	cin>>d;	
	return d;
}

void itemMenu() // show item main menu -bath&body and makeup
{
	int b,c,d;
	system("CLS");
	divider();
	cout<<"=---------------ITEM---------------=\n";
	divider();
	cout<<"1. Bath & Body\n";
	cout<<"2. Makeup\n";
	cout<<"Your choice: ";
	cin>>b;
	cout<<endl;
	
	if (b==1)
	{
		divider();
		cout<<"=------------Bath & Body------------=\n";
		divider();
		cout<<"1. Body Wash\n";
		cout<<"2. Hand Cream\n";
		cout<<"Your choice: ";
		cin>>c;
		cout<<endl;
		
		if (c==1)
		{
			d=BW(); cart(d,1); 
		}
	
		if (c==2)
		{
			d=HC(); cart(d,2);
		}
			
			
	}
	
	if (b==2)
	{
		divider();
		cout<<"=--------------Makeup---------------=\n";
		divider();	
		cout<<"1. Foundation\n";
		cout<<"2. Blusher\n";
		cout<<"3. Eyebrow\n";
		cout<<"4. Eyeliner\n";
		cout<<"5. Lipstick\n";
		cout<<"6. Lipliner\n";
		cout<<"Your choice: ";
		cin>>c;
		cout<<endl;
		
		switch(c)
		{
			case 1:
			{
				d=F(); cart(d,3); break;
			}
			case 2:
			{
				d=B(); cart(d,4); break;
			}
			case 3:
			{
				d=EB(); cart(d,5); break;
			}
			case 4:
			{
				d=EL(); cart(d,6); break;
			}
			case 5:
			{
				d=LS(); cart(d,7); break;
			}
			case 6:
			{
				d=LL(); cart(d,8); break;
			}
		}
	}
	
}
/***********************/
void receipt() //show what had user paid for its purchases
{
	int am=0;
	system("CLS");
	divider();
	cout<<"=--------------Receipt--------------=\n";
	divider();
	dateTime();
	cout<<endl;
	cout<<"Card Number: **** **** **** "<<cardnum.substr(12,15);
	cout<<"\nITEM\n";
	for (int k=0;k<2 ; k++)
	{
		cout<<k+1<<". "<<buy[k]<<"\tRM "<<price[k]<<endl;
		am += price[k];
	}
	cout<<endl;
	divider();
	cout<<"TOTAL: RM "<<am<<endl;
	cout<<"=------------Thank You--------------=\n";
	divider();
	system("pause");
}

void payment() //show transaction
{
	int amount=0;
	for (int p=0;p<2;p++)
	{
		amount += price[p];
	}
	system("CLS");
	divider();
	cout<<"=--------------Payment--------------=\n";
	divider();
	cout<<"Please enter your 16-digit card number for payment.\nCard number: ";
	cin>>cardnum;
	cout<<"Your transaction will be proceeded\n";
	cout<<"Transaction with amount RM"<<amount<<" has been proceeded.\n";
	system("pause");
}

void menu1()// show main menu of guest
{
	int a, counter=0;
	do
	{
		system("CLS");
	divider();
	cout<<"=-----------Welcome Guest----------=\n";
	divider();
	cout<<"=--------SEPHORA COLLECTION--------=\n";
	divider();
	
	cout<<"1. Item\n";
	cout<<"2. Cart\n";
	cout<<"3. Payment\n";
	cout<<"4. Receipt\n";
	cout<<"5. Exit\n";
	cout<<"Your choice:";
	cin>>a;
	
	switch (a)
	{
		case 1 :
		{
			itemMenu(); break;
		}
		
		case 2:
		{
			display(); break;
		}
			
		case 3:
		{
			payment(); break;
		}
			
		case 4:
		{
			receipt(); break;
		}
			
		case 5:		
		{
			cout<<"Thank You for Choosing Sephora Collection\n";
			cout<<"See You!";
			exit(0);
		}	
	}
	}while ((a>1)&&(a<4));
}


void menu2() // show main menu of admin
{
	int ch;
	
	while(1)
	{
		system("CLS");
		cout<<"\n Update Available Stock: ";
		cout<<"\n 1. Add stock";
		cout<<"\n 2. Remove stock";
		cout<<"\n 3. Display stock available";
		cout<<"\n 4. Exit";
		cout<<"\n Enter your choice:";
		cin>>ch;

		switch(ch)
		{
			case 1:
				show();
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				displayQueue();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\n Invalid Choice \n";
		}
		system("pause");
	}
}

int identification() //choose type of user
{
	int counter=0,choice;
	do
	{
	cout<<"\nWelcome to Sephora Collection\nLogin as\n"<<endl;
	cout<<"1. Guest\n2. Admin\n";
	cout<<"Your choice:";
	cin>>choice;
		if (choice==1)
		{
			login(1);
			break;
			
		}
		if (choice==2)
		{
			login(2);
			break;
		}
		
		try
		{
			if ((choice<1)||(choice>3))
				throw 0; 
		}
		catch (int y)
		{
			counter++;
			cout<<"Invalid choice\n";
			if (counter==3) 
			{
				cout<<"Wrong choice too many times\nThe program will exited!";
				exit(0);
			}
		}
	}while (counter<3);
	
	return choice;
}

int main()
{
	bool w= true;
	
	int choice =identification();
	
	do
	{
		if (choice ==1)
			menu1();
		else if (choice==2)
			menu2();
	}while (w);
	

}
