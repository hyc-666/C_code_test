#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>//字符串比对函数
#pragma warning(disable:4996)
#define USER_NAME "timor"  //默认账户名
#define PASS_WORD "mima123"  //默认的初始化密码
int score = 0;//玩家得分
int N = 200;//难度
void showscore(){//显示得分
	printf("score:%d\n", score);
}
void menu(){  //主菜单函数
	printf("************************\n");
	printf("** 1.play      2.exit **\n");   //两个选项
	printf("************************\n");
}
void play(){  //玩游戏的函数
	srand((unsigned long)time(NULL));//生成随机数种子
	
	/*printf("please select easy or normal or hard or selfdefine:\n");
	printf("1.easy\t2.normal\t3.hard\t4.self define\nplease select:");
	int s = scanf_s("%d",&s);
	switch (s){
	case 1:
		break;
	case 2:
		N = 200;
		break;
	case 3:
		N = 500;
		break;
	case 4:{
		printf("enter max:");
		scanf_s("%d", &N);
		break;
	}
	defult:
		break;
	}*/

	int x = rand() % N + 1;  //生成一个一到一百的随机整数
	int guess = 0;//初始化开始猜的数字
	printf("please guess a magic number between 0 and %d ->:",N);//提示输入
	scanf("%d", &guess);//接受输入的数字
	do{
		//判断是否输对
		if (guess > x){//如果输入比随机数大
			printf("your guess is big,try again:");//提示猜大了，再输一次
			scanf("%d", &guess);
		}
		else if (guess < x){//如果输入比随机数小
			printf("your guess is small,try again:");//提示猜小了，再输一次
			scanf("%d", &guess);
		}
		else{
			printf("your right!\n");//否则证明猜对了
			score++;
			showscore();
			break;//然后不再执行循环，一次游戏结束
		}
	}while(1);
}
int main(){//程序入口
	int times = 3;//限制账户和密码的输入次数
	char user_name[32];//接受用户输入用户名
	char pass_word[16];//接受用户输入的密码
	
	while(times > 0){
		times--;//进入循环说明一次输入已经开始，次数自减1
		printf("please enter username->:");//提示输入
		scanf("%s", user_name);
		printf("please enter password->:");
		scanf("%s",pass_word);
		if (strcmp(user_name, USER_NAME) == 0 && strcmp(pass_word, PASS_WORD) == 0){//判断账户名和密码的正确性
			printf("login success!\n");//输入正确则提示登陆成功
			break;//不再继续输入
		}
		else{
			printf("username or password error!");//账号密码错误则提示错误
			printf("try again:\tyou have %d times!\n", times);//显示剩余输入次数
		}
	}
	if (times > 0){//此时大于0说明登陆成功
		
		for (int i = 5; i >= 0; i--){//加载画面
			printf("loading ...%d\r",i);
			Sleep(600);//频幕600ms刷新一次
		}
		int quit = 1;//不断显示主菜单
		while (quit){
			
			menu();//显示主菜单
			int select = 0;//选择退出或者继续
			printf("please select : ");
			scanf("%d", &select);
			switch (select){
			case 1:
				 play();
				break;
			case 2:
				printf("bye bye\n");
				quit = 0;
				break;
			defult:
				printf("select error\n");
				break; 
			
			}
		}
	}
	else{
		printf("login failed!\n");//登陆失败
	}

	system("pause");
	return 0;
}