#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>
/*一个数组中只有两个数字是出现一次， 
其他所有数字都出现了两次。 
找出这两个只出现一次的数字，*/
void search_two(int arr[],int len){
	int ret = 0;
	for (int i = 0; i < len; i++){
		ret ^= arr[i];
	}
	int pos = 0;
	for (int i = 0; i < 32; i++){
		if ((ret >> i) & 1){
			pos = i;
			break;
		}
	}
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < len; i++){
		if ((arr[i] >> pos) & 1){
			num1 ^= arr[i];
		}
		else{
			num2 ^= arr[i];
		}
	}
	printf("first num is:%d second num is:%d\n", num1, num2);
}

/*
2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
给20元，可以喝多少汽水。
编程实现*/
int bottle(int money){
	int suda = money;//能喝到的汽水=钱
	int bottle = suda;//空瓶=喝到的汽水
	int ret = 0;//总数
	while (suda){//当还能喝到汽水的时候

		ret = ret + suda;
		suda = bottle / 2 ;//两个空瓶=1瓶汽水
		if (bottle % 2 == 0){//如果空瓶是双数
			bottle = suda;//空瓶=已喝汽水
		}
		else{
			bottle = suda + 1;//单数则空瓶多出一个
		}
		
	}
	return ret;
}

/*3.模拟实现strcpy*/
void my_strcpy(char *str1,const char *str2){
	assert(str1 || str2);
	while (*str1&&*str2){
		*str1 = *str2;
		str1++;
		str2++;
	}
}
/*4.模拟实现strcat*/
void my_strcat(char *str1, const char *str2){//把字符串2的内容追加连接到字符串2的后面
	assert(str1 || str2);
	str1 += strlen(str1);
	while (*str2){
		*str1 = *str2;
		str1++;
		str2++;
	}
}
int main(){
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	search_two(arr, size);
	printf("%d\n", bottle(20));
	
	char string1[40] = "hello ";
	char string2[] = "world!";

	
	/*my_strcpy(string1, string2);
	printf(string1);*/

	printf(string1);
	my_strcat(string1, string2);
	printf("\n");
	printf(string1);

	printf("\n");
	system("pause");
	return 0;
}