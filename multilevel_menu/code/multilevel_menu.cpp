#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

 
void CheckFile();
int FirstMenu();
int SecondMenu(int i);

void Write();
void Search();
 
typedef struct Student
{
	char sNumber[9];
	char sName[20];
	char sSex[3];
	int iGrade[4];
} Stu;
 
int main()
{
	int flag=0;  
   
	while(flag!=3)
	{
		system("cls");
		flag=SecondMenu(FirstMenu());
	}
}
 
int FirstMenu()
{
	int i; 
	cout << "*****************************************************" << endl;
	cout << "*                                                   *" << endl;
	cout << "*            1    ¼��ѧ���ɼ�                      *" << endl;
	cout << "*            2    ��ѯѧ���ɼ�                      *" << endl;
	cout << "*            3    �˳�                              *" << endl;
	cout << "*****************************************************" << endl;
	cout << "����ѡ���������֣���";
	cin >> i;	
	return i;
}
 
int SecondMenu(int i)
{
	system("cls");
    switch(i)
	{
	   case 1:
		   {
			   Write();
			   break;
		   }
	   case 2:
		   {
			   Search();
			   break;
		   }
	   case 3:
		   {
			   cout << "�����Ѿ��˳���" << endl;
			   break;
		   }
	}
	return i;
 
}
 
void Write()
{
	FILE *fp;
	Stu s,*p;
	char s1;
	char s2='n';   
	p=&s;
	if((fp=fopen("ѧ����Ϣ.dat","ab"))==NULL)
	{
		if((fp=fopen("ѧ����Ϣ.dat","wb"))==NULL)
		{
			cout << "���ļ�ʱ����" << endl;
			exit(1);
		}
	}
	do
	{
		cout << "������ѧ������Ϣ��" << endl;
		cout << "ѧ�ţ�";
		cin >> s.sNumber;
		cout << "������";
		cin >> s.sName;
		cout << "�Ա�";
		cin >> s.sSex;
		cout << "������ɼ�,Ҫ������Ǹ�������" << endl;
		cout << "��ѧ��";
		cin >> s.iGrade[0];
		cout << "Ӣ�";
		cin >> s.iGrade[1];
		cout << "�������";
		cin >> s.iGrade[2];
		cout << "������";
		cin >> s.iGrade[3];
		cout << "�Ƿ�ȷ���������룺y/n��" << endl;
		cin >> s1;
		if(s1=='y')
		{
			fwrite(p,sizeof(Stu),1,fp);
			system("cls");
			cout << "¼��ɹ����Ƿ����¼�룿�����룺y/n��" << endl;
			cin >> s2;
			system("cls");
		}
	}while(s2=='y');
	fclose(fp);
}
  
void Search()
{
    FILE *fp;
	Stu s,*p;
    char sNumber1[9];
	int option;
	p=&s;
	cout << "������ѧ�ţ�";
    cin >> sNumber1;
	if((fp=fopen("ѧ����Ϣ.dat","rb"))==NULL)
	{
		cout << "���ļ�ʱ����";
		exit(1);
	}
	else
	{
		int k;
		do
		{
			fread(p,sizeof(Stu),1,fp);			
		}while(strcmp(p->sNumber,sNumber1)!=0&&feof(fp)==0);

		if(strcmp(p->sNumber,sNumber1)!=0)
		{
			cout << "�޴�ѧ����Ϣ��" << endl;
            cout << "�������ȷ����";
			getch();
			return;
		}
		cout << endl;
		cout << endl;

		cout << "++++++++++++++++++++++" << endl;
		cout << "+  1  �����ѧ�ɼ�   +" << endl;
		cout << "+  2  ���Ӣ��ɼ�   +" << endl;
		cout << "+  3  ���������ɼ� +" << endl;
		cout << "+  4  ��������ɼ�   +" << endl;
		cout << "+  5  ������гɼ�   +" << endl;
		cout << "++++++++++++++++++++++" << endl;
		cout << "��ѡ��";
		cin >> option;
		cout << endl;
        cout << "ѧ��" << '\t' << "����" << '\t' << "�Ա�" << endl;
		cout << p->sNumber << '\t' << p->sName << '\t' << p->sSex << endl;		
               
		switch(option)
		{
		  case 1:
			  {
				  cout << "��ѧ" << endl << p->iGrade[0] << endl;
				  break;
			  }
		  case 2:
			  {
				  cout << "Ӣ��" << endl << p->iGrade[1] << endl;
				  break;
			  }
		  case 3:
			  {
				  cout << "�����" << endl << p->iGrade[2] << endl;
				  break;
			  }
		  case 4:
			  {
				  cout << "����" << endl << p->iGrade[3] << endl;				  
				  break;
			  }
		  case 5:
			  {
				  cout << "��ѧ" << '\t' << "Ӣ��" << '\t' << "�����" << '\t' << "����" << '\t' << endl;
				  for(k=0;k<4;k++)
					  cout << p->iGrade[k] << '\t';
				  cout << endl;
			  }
		}
		cout << "�������ȷ����";
		getch();
	}
}
