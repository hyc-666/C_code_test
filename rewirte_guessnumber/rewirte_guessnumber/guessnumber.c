#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>//�ַ����ȶԺ���
#pragma warning(disable:4996)
#define USER_NAME "timor"  //Ĭ���˻���
#define PASS_WORD "mima123"  //Ĭ�ϵĳ�ʼ������
int score = 0;//��ҵ÷�
int N = 200;//�Ѷ�
void showscore(){//��ʾ�÷�
	printf("score:%d\n", score);
}
void menu(){  //���˵�����
	printf("************************\n");
	printf("** 1.play      2.exit **\n");   //����ѡ��
	printf("************************\n");
}
void play(){  //����Ϸ�ĺ���
	srand((unsigned long)time(NULL));//�������������
	
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

	int x = rand() % N + 1;  //����һ��һ��һ�ٵ��������
	int guess = 0;//��ʼ����ʼ�µ�����
	printf("please guess a magic number between 0 and %d ->:",N);//��ʾ����
	scanf("%d", &guess);//�������������
	do{
		//�ж��Ƿ����
		if (guess > x){//���������������
			printf("your guess is big,try again:");//��ʾ�´��ˣ�����һ��
			scanf("%d", &guess);
		}
		else if (guess < x){//�������������С
			printf("your guess is small,try again:");//��ʾ��С�ˣ�����һ��
			scanf("%d", &guess);
		}
		else{
			printf("your right!\n");//����֤���¶���
			score++;
			showscore();
			break;//Ȼ����ִ��ѭ����һ����Ϸ����
		}
	}while(1);
}
int main(){//�������
	int times = 3;//�����˻���������������
	char user_name[32];//�����û������û���
	char pass_word[16];//�����û����������
	
	while(times > 0){
		times--;//����ѭ��˵��һ�������Ѿ���ʼ�������Լ�1
		printf("please enter username->:");//��ʾ����
		scanf("%s", user_name);
		printf("please enter password->:");
		scanf("%s",pass_word);
		if (strcmp(user_name, USER_NAME) == 0 && strcmp(pass_word, PASS_WORD) == 0){//�ж��˻������������ȷ��
			printf("login success!\n");//������ȷ����ʾ��½�ɹ�
			break;//���ټ�������
		}
		else{
			printf("username or password error!");//�˺������������ʾ����
			printf("try again:\tyou have %d times!\n", times);//��ʾʣ���������
		}
	}
	if (times > 0){//��ʱ����0˵����½�ɹ�
		
		for (int i = 5; i >= 0; i--){//���ػ���
			printf("loading ...%d\r",i);
			Sleep(600);//ƵĻ600msˢ��һ��
		}
		int quit = 1;//������ʾ���˵�
		while (quit){
			
			menu();//��ʾ���˵�
			int select = 0;//ѡ���˳����߼���
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
		printf("login failed!\n");//��½ʧ��
	}

	system("pause");
	return 0;
}