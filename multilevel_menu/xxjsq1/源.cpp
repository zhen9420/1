#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>



using namespace std;



void tentoeight(int num)      //ʮ������ת�˽�����         
{
	int  m = 0, a[100], i = 0, k = 0;

	while (num / 8 != 0) {
		m = num % 8;
		num /= 8;
		a[i] = m;
		++i;
		++k;
	}
	a[k] = num;
	for (int i = k; i >= 0; --i) {
		cout << a[i];
	}


}

void tentosixteen(int n)         //ʮ������תʮ��������
{
	int i = 0;
	char s[200];
	while (n)
	{
		if (n % 16 >= 10)
			s[i] = n % 16 + 55;
		else
			s[i] = n % 16 + 48;
		i++;
		n = n / 16;
	}
	for (i = i - 1; i >= 0; i--)
		printf("%c", s[i]);


}

void digit(int n)     //�ж�λ�����Լ������λ��������
{
	int i = 1;
	int a[3] = { 0 };
	while (n)
	{
		if (n / 10 != 0)
		{

			a[i - 1] = n % 10;

			++i;
		}
		else
			a[i - 1] = n;
		n = n / 10;

	}

	cout << "����Ϊ" << i << "λ��" << "��";
	cout << '\n';

	while (i)
	{
		switch (i)
		{
		case 1:cout << "��λ��:" << a[i - 1] << ","; cout << '\n'; break;
		case 2:cout << "ʮλ��:" << a[i - 1] << ","; cout << '\n'; break;
		case 3:cout << "��λ��:" << a[i - 1] << ","; cout << '\n'; break;
		}
		--i;
	}

}

void leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d��������\n", year);
	else
		printf("%d�겻������\n", year);


}

void gradechange(int grade)     //�ɼ��ȼ�ת��
{
	if (grade > 100 || grade < 0)
	{
		cout << "�ɼ��������";
	}
	else
		switch (grade / 10)
		{
		case 10:
		case 9:printf("����"); break;
		case 8:printf("��"); break;
		case 7:printf("��"); break;
		case 6:printf("����"); break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:printf("������"); break;

		}

	cout << '\n';

}

void odd(int n)        //forѭ��
{
	int t = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		if (i % 2 != 0)
		{
			t = t + i;
		}

	}

	cout << "1������������������Ϊ��" << t;

	cout << '\n';

}

void even(int n)     //while�ж�
{

	int t = 0, j = 1, i = 1;
	while (j)
	{
		if (i % 2 == 0 || i == 1)
		{
			t = t + i;
		}

		if (i == n)
		{
			j = 0;
		}

		++i;

	}

	cout << "1������������ż����Ϊ��" << t;

	cout << '\n';

}

void three(int n)    //3�ı���
{
	int k = 1, i = 1;

	do
	{
		if (i == 1 || i % 3 == 0)
		{
			cout << i << ' ';

		}

		if (i == n)
		{
			k = 0;
		}

		++i;

	} while (k);

	cout << '\n';

}

void divisible(int n, int m)    //�жϱ���������������
{
	if (n % 3 == 0 && n % 5 == 0)
	{
		cout << n << "�ɱ�3��5����";
	}

	else if (m % 3 == 0 && m % 5 == 0)
	{
		cout << n << "���ɱ�3��5������" << m << "�ɱ�3��5����";
	}

	else
	{
		cout << n << "��" << m << "�����ɱ�3��5����";
	}

	cout << '\n';

}

void daffidil()    //�ж�1000���ڵ�ˮ�ɻ���
{

	int a, b, c, num1, num2;
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				num1 = a * a * a + b * b * b + c * c * c;
				num2 = a * 100 + b * 10 + c;
				if (num1 == num2)
				{
					cout << num2 << ' ';
				}
			}
		}

	}

	cout << '\n';

}

void max1(int x, int y)    //�����������ֵ
{

	cout << "�������нϴ���ǣ�";
	if (x > y)
	{
		cout << x;
	}
	else if (x < y)
	{
		cout << y;
	}
	else
	{
		cout << "������һ����";
	}

	cout << '\n';

}

void max2(int* x, int* y)    //��ָ�룩�����������ֵ����Сֵ
{

	if (*x > *y)
	{
		cout << "�������нϴ���ǣ�" << *x << ' ' << "�������н�С���ǣ�" << *y;
	}
	else if (*x < *y)
	{
		cout << "�������нϴ���ǣ�" << *y << ' ' << "�������н�С���ǣ�" << *x;
	}
	else
	{
		cout << "������һ����";
	}

	cout << '\n';
}

void maopao(int q[])   //ð��ѭ��
{
	int t;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9 - i; ++j)
		{
			if (q[j] > q[j + 1])
			{
				t = q[j];
				q[j] = q[j + 1];
				q[j + 1] = t;
			}



		}



	}

	cout << "��������Ϊ��";

	for (int i = 0; i < 10; ++i)
	{
		cout << q[i] << ' ';
	}

	cout << '\n';

}

void zhuanzhi()     //����ת��
{
	int arr1[3][4], arr2[4][3];
	for (int i = 0; i < 3; ++i)
	{
		cout << "������3x4�ľ����" << i + 1 << "�е�Ԫ�أ�";
		for (int j = 0; j < 4; ++j)
		{
			cin >> arr1[i][j];
		}
	}

	cout << "ת�ú�ľ���Ϊ��" << '\n';

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr2[i][j] = arr1[j][i];
		}

	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr2[i][j] << ' ';
		}
		cout << '\n';
	}

}

void duijiaoxian()   //���Խ���Ԫ�غ�
{
	int arr[3][3] = { 0 };

	for (int i = 0; i < 3; ++i)
	{
		cout << "����3x3�����" << i + 1 << "�е�Ԫ�أ�";

		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}

	}

	int t = arr[0][0] + arr[1][1] + arr[2][2];
	cout << "���Խ��ߵ�Ԫ�غ��ǣ�" << t;
	cout << '\n';

}

void dancishu()   //ͳ�Ƶ��ʸ���
{
	char a[101];
	int i, num = 0, word = 0;
	char c;

	printf("������һ��Ӣ�ģ�100�����£���");
	getchar();
	gets_s(a);


	for (i = 0; ((c = a[i]) != '\0'); i++)
		if (c == ' ') word = 0;
		else if (word == 0)
		{
			word = 1;
			num++;
		}
	printf("�ܹ���%d������\n", num);

}

void static1()         //������̬����
{
	struct student
	{
		char name[10];
		int age;
		student* next; //�ڵ��������͵�ָ��	
	};

	student d = { "ѧ��1",23,NULL }; //βָ��null 
	student c = { "ѧ��2",22,&d };
	student b = { "ѧ��3",21,&c };
	student a = { "ѧ��4",20,&b };
	student* head = &a; //ͷָ�� 

	student* point = head;

	while (point)
	{
		cout << point->name << " " << point->age << endl;
		point = point->next;
	}

	cout << '\n';

}

void trends1()    //������̬����
{
	typedef struct node
	{
		int data;
		struct node* next;
	} *nodes;

	int count;

	nodes head, p;

	p = (nodes)malloc(sizeof(node));
	p->next = NULL;
	head = p;
	p = head;

	cout << "�������������ݣ����븺��Ϊ��ֹ��ʶ��";

	while (cin >> count && count > 0)
	{
		nodes q = (nodes)malloc(sizeof(node));
		q->data = count;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	cout << "����������ݣ�";

	p = head->next;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << '\n';

}

void paixv()      //�ṹ��ѧ���ɼ�����
{
	typedef struct students                                      //������ֽṹ��Ϊ������st 
	{
		int num;
		char name[10];
		float grade;
	} st;

	struct students students[10];

	int i, j, t;

	st z;
	float sumgrade = 0;

	for (i = 0; i < 10; ++i)
	{
		cout << "�������" << i + 1 << "λѧ������Ϣ��";
		cout << "������ѧ�ţ�";
		cin >> students[i].num;
		cout << "������������";
		cin >> students[i].name;
		cout << "������ɼ���";
		cin >> students[i].grade;

		sumgrade = sumgrade + students[i].grade;
	}

	for (j = 0; j < 10; j++)
	{

		for (i = 0; i < -j - 1; i++)
		{
			if (students[i].grade > students[i + 1].grade)
			{
				z = students[i];
				students[i] = students[i + 1];
				students[i + 1] = z;
			}
		}
	}

	for (i = 0; i < 2; i++)
	{
		printf("ѧ����%d,������%s,�ɼ���%.1f\n", students[i].num, students[i].name, students[i].grade);
	}
	printf("\n");
	printf("�ܳɼ���%.1f,ƽ���ɼ���%.1f", sumgrade, sumgrade / 10);

}

void fileopen()
{
	int i, a[10];

	FILE* fp;
	fp = fopen("d:\\my.txt", "r+"); //��д��ʽ�� 

	for (i = 0; i < 10; ++i)
	{
		fscanf(fp, "%d", &a[i]);	  //�ļ���ȡ 
	}

	rewind(fp);   //�ػؿ�ͷ 

	for (i = 0; i < 10; ++i)
		fprintf(fp, "%d\n", a[i] + 10);  //��10�ֲ�����д�� 

	fclose(fp); //�ر��ļ� 

	printf("����ɲ���\n");
}





int main()
{



	//�����ǽ�������

	//��ʼ�Ŀո�
	for (int i = 0; i < 40; ++i)
	{
		cout << ' ';
	}


	//��ʼ��*��
	for (int i = 0; i < 40; ++i)
	{
		cout << '*';
	}
	cout << '\n';

	//���ֽ���
	for (int j = 0; j < 25;++j)
	{
		for (int i = 0; i < 40; ++i)
		{
			cout << ' ';
		}

		cout << '*';

		for (int i = 0; i < 13; ++i)
		{
			cout << ' ';
		}

		switch (j + 1)
		{
		case 1:
			cout << "СС������";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 2:
			cout << '1' << ' ' << "�ӷ�";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 3:
			cout << '2' << ' ' << "����";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 4:
			cout << '3' << ' ' << "�˷�";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 5:
			cout << '4' << ' ' << "����";
			for (int i = 0; i < 19; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 6:
			cout << '5' << ' ' << "ȡģ����";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 7:
			cout << '6' << ' ' << "����Բ���";
			for (int i = 0; i < 13; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 8:
			cout << '7' << ' ' << "�ж����ֵ�λ��";
			for (int i = 0; i < 9; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 9:
			cout << '8' << ' ' << "�ж�����";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 10:
			cout << '9' << ' ' << "�ɼ�ת��";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 11:
			cout << "10" << ' ' << "������";
			for (int i = 0; i < 16; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 12:
			cout << "11" << ' ' << "ż����";
			for (int i = 0; i < 16; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 13:
			cout << "12" << ' ' << "3�ı���";
			for (int i = 0; i < 15; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 14:
			cout << "13" << ' ' << "��3��5����";
			for (int i = 0; i < 12; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		case 15:
			cout << "14" << ' ' << "ˮ�ɻ���";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 16:
			cout << "15" << ' ' << "�����ֵ";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 17:
			cout << "16" << ' ' << "�������Сֵ";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 18:
			cout << "17" << ' ' << "ð��ѭ��";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 19:
			cout << "18" << ' ' << "����ת��";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 20:
			cout << "19" << ' ' << "�Խ��ߺ�";
			for (int i = 0; i < 14; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 21:
			cout << "20" << ' ' << "ͳ�Ƶ��ʸ���";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 22:
			cout << "21" << ' ' << "������̬����";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 23:
			cout << "22" << ' ' << "������̬����";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 24:
			cout << "23" << ' ' << "ѧ���ɼ�����";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;


		case 25:
			cout << "24" << ' ' << "�ɼ�����10��";
			for (int i = 0; i < 10; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;




		case 26:
			cout << "25" << ' ' << "�˳�";
			for (int i = 0; i < 18; ++i)
			{
				cout << ' ';
			}
			cout << '*' << '\n';
			break;

		}

	}

	//��β�ո�
	for (int i = 0; i < 40; ++i)
	{
		cout << ' ';
	}


	//��β*��
	for (int i = 0; i < 40; ++i)
	{
		cout << '*';
	}
	cout << '\n';
	cout << '\n';

	//�������ƽ���

	//�������������
	int t;
	int a, b;
	float c, d;
	int* m, * n;
	int arr[10] = { 0 };
	double e; double pai = 3.14;


	for (int l = 0; l < 1000; ++l)  //ͨ��forѭ��ʵ��ֻ��ѡ���˳��Ż�������򣬷���������һ�μ���
	{
		cout << ' ' << ' ' << ' ' << ' ' << "����������ʹ�õļ��㷽ʽ:";
		cin >> t;


		switch (t)
		{
		case 1:
			cout << "�����뱻�����ͼ�����";
			cin >> a >> b;
			cout << "ʮ������ʽ��" << a + b << '\n';
			cout << "�˽�����ʽ��" << ' '; tentoeight(a + b); cout << '\n';
			cout << "ʮ��������ʽ��" << ' ';   tentosixteen(a + b); cout << '\n';
			cout << '\n';
			break;


		case 2:
			cout << "�����뱻�����ͼ�����";
			cin >> a >> b;
			cout << "ʮ������ʽ��" << a - b << '\n';
			cout << "�˽�����ʽ��" << ' '; tentoeight(a - b); cout << '\n';
			cout << "ʮ��������ʽ��" << ' ';   tentosixteen(a - b); cout << '\n';
			cout << '\n';
			break;

		case 3:
			cout << "�����뱻�����ͳ�����";
			cin >> c >> d;
			cout << "С����ʽ��";  printf("%.6f\n", c * d);
			cout << "ָ����ʽ��"; printf("%.6e\n", c * d);
			cout << '\n';
			break;


		case 4:
			cout << "�����뱻�����ͳ�����";
			cin >> c >> d;
			cout << "С����ʽ��";  printf("%.6f\n", c / d);
			cout << "ָ����ʽ��"; printf("%.6e\n", c / d);
			cout << '\n';
			break;


		case 5:
			cout << "�����뱻ȡģ����ȡģ����";
			cin >> a >> b;
			if (b == 0)
			{
				cout << "��������Ϊ0";
				cout << '\n'; cout << '\n';
			}
			else
				cout << "ʮ������ʽ��" << a % b << '\n';
			cout << "�˽�����ʽ��" << ' '; tentoeight(a % b); cout << '\n';
			cout << "ʮ��������ʽ��" << ' ';   tentosixteen(a % b); cout << '\n';
			cout << '\n';
			break;


		case 6:
			cout << "������Բ�İ뾶��";
			cin >> e;
			cout << "��Բ������ǣ�"; printf("%.6f\n", pai * e * e);
			cout << "������λС���Ľ���ǣ�"; printf("%.2f\n", pai * e * e);
			cout << '\n';

		case 7:
			cout << "������Ҫ�жϵ����֣�";
			cin >> a;
			if (a / 1000 != 0)
			{
				cout << "Ҫ���������Ϊ3λ���ڵ�������";
				cout << '\n';
			}
			digit(a);
			cout << '\n';
			break;


		case 8:
			cout << "������Ҫ�жϵ���ݣ�";
			cin >> a;
			leapyear(a);
			cout << '\n';
			break;


		case 9:
			cout << "������ɼ���";
			cin >> a;
			cout << "�ɼ���Ӧ�ĵȼ��ǣ�"; gradechange(a);
			cout << '\n';
			break;


		case 10:
			cout << "������һ�����֣�";
			cin >> a;
			odd(a);
			cout << '\n';
			break;


		case 11:
			cout << "������һ�����֣�";
			cin >> a;
			even(a);
			cout << '\n';
			break;


		case 12:
			cout << "������һ�����֣�";
			cin >> a;
			three(a);
			cout << '\n';
			break;


		case 13:
			cout << "�������������֣�";
			cin >> a >> b;
			divisible(a, b);
			cout << '\n';
			break;


		case 14:

			cout << "1000���ڵ�ˮ�ɻ���Ϊ��";
			daffidil();
			cout << '\n';
			break;


		case 15:
		{
			cout << "�������������֣�";
			cin >> a >> b;

			max1(a, b);
			cout << '\n';
			break;

		}


		case 16:
		{
			cout << "�������������֣�";
			cin >> a >> b;

			m = &a, n = &b;

			max2(m, n);
			cout << '\n';
			break;
		}


		case 17:
		{
			cout << "������10������";
			for (int i = 0; i < 10; ++i)
			{
				cin >> arr[i];
			}
			maopao(arr);
			cout << '\n';
			break;
		}


		case 18:
			zhuanzhi();
			cout << '\n';
			break;


		case 19:
			duijiaoxian();
			cout << '\n';
			break;


		case 20:
			dancishu();
			cout << '\n';
			break;


		case 21:
			static1();
			cout << '\n';
			break;


		case 22:
			trends1();
			cout << '\n';
			break;


		case 23:
			paixv();
			cout << '\n';
			break;


		case 24:
			fileopen();
			cout << '\n';
			break;


		case 25:
			l = 1000;
			cout << "СС�������ѳɹ��˳�";
			break;

		}



	}





	return 0;
}