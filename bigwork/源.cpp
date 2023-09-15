#include<cstdio>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
using namespace std;
#define frame_width 50
#define frame_height 25

typedef struct {
    int x, y;
} Food;
typedef struct {
    int x[100], y[100], len, state;
} Snake;

void gotoxy(int x, int y);  //����Ҫ��һ�����������ƹ���λ��
void print_map();
void get_newfood();//������ʳ��
bool check_foodinsnake();//�����ʳ����û����������
void move_snake();
void check_foodeating();
bool check_snakealive();


//��Ҫ�õ���ȫ�ֱ���
int score;
Snake snake;
Food food;
bool check_eaten;

int main()
{
    system("color 0B");
    do
    {
        system("cls");
        print_map();
        score = 0, check_eaten = 0;
        //̰���ߵ�ÿ�غ����п���
        while (1)
        {
            check_foodeating();//system("pause");
            move_snake();
            Sleep(max(50, 300 - score));//�����ٶȣ��볤�ȳʷ��ȣ�
            if (!check_snakealive())
                break;
        }
        printf("Game Over!\n");
        printf("1:Restart\t2:exit\n");
        char com2;
        cin >> com2;
        if (com2 == '2')
            break;
    } while (1);
}

void gotoxy(int x, int y)
{
    COORD pos;//COORD��һ���Դ��ṹ�壬��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
    HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE); //�ӱ�׼����豸��ȡ��һ�����
    pos.X = y, pos.Y = x;
    SetConsoleCursorPosition(han, pos);//��λ���ĺ���
}

void print_map()
{
    //��ӡǽ��
    for (int i = 0; i < frame_height; i++)
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, frame_width - 1);//��Ϊ�������ǳ��ȣ����㿪ʼ�������Ҫ��1
        printf("#");
    }
    for (int i = 0; i < frame_width; i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(frame_height - 1, i);
        printf("#");
    }

    //�����ʼ��
    snake.len = 3;
    snake.state = 'w';
    snake.x[1] = frame_height / 2;
    snake.y[1] = frame_width / 2;
    gotoxy(snake.x[1], snake.y[1]);
    printf("@");
    for (int i = 2; i <= snake.len; i++)
    {
        snake.x[i] = snake.x[i - 1] + 1;
        snake.y[i] = snake.y[i - 1];
        gotoxy(snake.x[i], snake.y[i]);
        printf("@");
    }

    //��ӡ��ʼʳ��
    get_newfood();

    //��ӡ�ұ�״̬��
    gotoxy(2, frame_width + 3);
    printf("WELCOME TO THE GAME OF RETRO SNAKE");
    gotoxy(4, frame_width + 3);
    printf("UP:   w");
    gotoxy(6, frame_width + 3);
    printf("DOWN: s");
    gotoxy(8, frame_width + 3);
    printf("LEFT: a");
    gotoxy(10, frame_width + 3);
    printf("RIGHT:d");
    gotoxy(12, frame_width + 3);
    printf("Your score:%d", score);
    gotoxy(28, frame_width + 3);
    printf("Made by jokersio");
}

bool check_foodinsnake()
{
    for (int i = 1; i <= snake.len; i++)
        if (snake.x[i] == food.x && snake.y[i] == food.y)
            return 1;
    return 0;
}

void get_newfood()
{
    do {
        srand(time(0));
        food.x = rand() % (frame_height - 2) + 1;
        food.y = rand() % (frame_width - 2) + 1;
    } while (check_foodinsnake());
    gotoxy(food.x, food.y);
    cout << "$";
}

void move_snake()
{
    char com;
    while (kbhit())//����������
        com = getch();//�ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
    //û�гԵ�ȥ����β
    if (!check_eaten)
    {
        gotoxy(snake.x[snake.len], snake.y[snake.len]);
        printf(" ");
    }
    //������ͷ�������������ǰ�ƶ�
    for (int i = snake.len; i > 1; i--)
        snake.x[i] = snake.x[i - 1],
        snake.y[i] = snake.y[i - 1];
    //�ƶ���ͷ
    switch (com)
    {
    case 'w':
    {
        if (snake.state == 's') //��������뵱ǰ�����෴��������
            snake.x[1]++;
        else
            snake.x[1]--, snake.state = 'w';
        break;
    }
    case 's':
    {
        if (snake.state == 'w')
            snake.x[1]--;
        else
            snake.x[1]++, snake.state = 's';
        break;
    }
    case 'a':
    {
        if (snake.state == 'd')
            snake.y[1]++;
        else
            snake.y[1]--, snake.state = 'a';
        break;
    }
    case 'd':
    {
        if (snake.state == 'a')
            snake.y[1]--;
        else
            snake.y[1]++, snake.state = 'd';
        break;
    }
    default: //�����������״̬ǰ��
    {
        if (snake.state == 's')
            snake.x[1]++;
        else if (snake.state == 'w')
            snake.x[1]--;
        else if (snake.state == 'd')
            snake.y[1]++;
        else if (snake.state == 'a')
            snake.y[1]--;
        break;
    }
    }
    gotoxy(snake.x[1], snake.y[1]);
    printf("@");
    check_eaten = 0;
    gotoxy(frame_height, 0);
}

void check_foodeating()
{
    if (snake.x[1] == food.x && snake.y[1] == food.y)
    {
        score += 10;
        check_eaten = 1;
        gotoxy(12, frame_width + 3);
        printf("Your score:%d", score);
        snake.len++;
        get_newfood();
    }
}

bool check_snakealive()
{
    //�����û��ײ��ǽ
    if (snake.x[1] == 0 || snake.x[1] == frame_height - 1 || snake.y[1] == 0 || snake.y[1] == frame_width - 1)//ײǽ
        return 0;
    //�����û�гԵ��Լ�
    for (int i = 2; i <= snake.len; i++)
        if (snake.x[i] == snake.x[1] && snake.y[i] == snake.y[1])
            return 0;
    return 1;
}

