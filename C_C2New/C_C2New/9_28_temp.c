#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)
int main()
{
	/*int a, b, temp;   //temp是中间变量
	printf("请输入a和b：");
	scanf("%d %d",&a,&b);
	printf("a = %d,b = %d   \n",a,b);
	temp = a;
	a = b;
	b = temp;

	printf("交换后：\n");
	printf("a = %d,b = %d  \n",a,b);*/

	//没有使用临时变量
	/*int a;
	int b;
	printf("请输入a，b：\n");
	scanf("%d %d",&a,&b);
	printf("a = %d,b = %d\n",a,b);
	printf("交换后：\n");
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d,b = %d\n",a,b);
*/
	
	//使用异或运算完成交换 
	/*
	int a;
	int b;
	printf("请输入a，b：\n");
	scanf("%d %d", &a, &b);
	printf("a = %d,b = %d\n", a, b);
	printf("交换后：\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d,b = %d\n", a, b);*/

	/*int arr[10];    //用数组存放10个数
	printf("请输入10个整数：\n");
	for (int i = 0; i < 10; i++)   //输入这10个数
	{
		scanf("%d",&arr[i]);

	}
	int max = arr[0];   //选定一个将要输出的最大的数
	for (int i = 0; i < 10; i++)
	{
		if (max <= arr[i])     如果max比后边的这个数字小则将它便后比它大的后一个数字
			max = arr[i];
	}
	printf("最大的数是%d：\n",max);     //输出最大的数字*/    



	//int arr[3];
	//printf("请输入三个数：\n");
	//for (int i = 0; i < 3;i++){    //输入三个数，任然用数组存放
	//	scanf("%d",&arr[i]);
	//}                    //采用冒泡排序算法
	//for (int i = 0; i < 3; i++){    //第一轮比较
	//	for (int j = 0; j < 2 - i; j++){      //第二轮比较
	//		if (arr[i] < arr[i + 1]){
	//			int temp = arr[i];       //交换算法
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//		}

	//	}
	//}
	//printf("从大到小的排序是：\n");  //输出排序后的顺序
	//for (int i = 0; i < 3; i++)
	//	printf("%d  ",arr[i]);


	   //使用辗转相除法计算两个数的最大公约数
	   /*    辗转相除法又称为欧几里得算法
	   先用大数除小数，记录余数，若余数为0，则除数为最大公约数
	   若余数不为0，用除数除余数，记录余数，若余数为0，
	   则上一个除数是最大公约数，若不为0，再重复上述操作
	   直到余数为0，则最后一个除数是最大公约数
	   */

	 //代码如下：

	//int a,b,m,n;
	//printf("输入两个数字：\n");
	//scanf("%d %d",&a,&b);
	//m = a;
	//n = b;
	//if (m < n){      //先确定哪个是除数哪个是被除数
	//	int temp = m;   //大数为被除数，小数为除数
	//	m = n;        
	//	n = temp;
	//}
	//int r;        //r用来记录余数
	//do{
	//	r = m%n;     //大数除小数得到余数
	//	m = n;      //除数作为被除数
	//	n = r;       //将余数作为除数
	//} while (r != 0);    //r余数不为0则执行循环，否则跳出
	//printf("%d和%d的最大公约数是：%d \n",a,b,m);


	//更相减损术计算最大公约数


	int a, b, m, n;
	printf("输入两个整数:\n");
	scanf("%d %d",&a,&b);
	m = a;
	n = b;
	       //还是大数减小数，m小于n则交换值
	/*if (m < n){
		int temp = m;
		m = n;
		n = temp;
	}*/
	////int r = 1; //先用2约分，记录一共除了几次2
	int s = 0; //更相减损术的差
	//if(m % 2 == 0 && n % 2 == 0){
	//	m = m / 2;   //用2 约分
	//	n = n / 2;
	//	//r = r * 2;    //用2约了几次
	//}
	//do
	//{
	//	s = m - n;        //m - n = s
	//	if(s > n)
	//		m = s;
	//	if(s < n){
	//		m = n;
	//		n = s;
	//	}
	//		/*else(s == n){
	//			r = r*s;
	//		}*/
	//}while (s != n);
	//printf("%d\n", s);


	
		while(m != n){
			if (m > n)
				m = m - n;
			else
				n = n - m;
		}
		s = m;


	
	printf("%d和%d的最小公倍数是：%d\n",a,b,s);
	system("pause");
	return 0;
}