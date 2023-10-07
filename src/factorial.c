/*
 * @Author: zz
 * @Date: 2023-10-07 14:27:54
 * @LastEditors: zz 861692232@qq.com
 * @LastEditTime: 2023-10-07 15:06:46
 * @FilePath: \vscode\Personal-library\src\factorial.c
 * @Description: 计算1!,2!,3!...到50!,并分别打印出来
 *
 * Copyright (c) 2023 by zz/861692232@qq.com, All Rights Reserved.
 */
#include <stdio.h>
int main()
{
	int jw, w = 1, t, a[5000];
	int i, j, z;
	// Jw为进位 W为位数 a为大数储存 T储存临时数据
	a[0] = 1;
	for (i = 1; i <= 50; i++)
	{
		for (j = 1, jw = 0; j <= w; j++)
		{
			t = a[j - 1] * i + jw; // 使被拆分为数组的大数的每一项与 i 相乘并且加上进位
			a[j - 1] = t % 10;	   // 将余数存到当前项中
			jw = t / 10;		   // 取进位
		}

		while (jw)
		{
			a[++w - 1] = jw % 10;
			jw /= 10;
		}
		// 当有进位的时候将进位给到下一项
		for (z = w; z >= 1; z--)
		{
			printf("%d", a[z - 1]);
		}
		printf("\n");
	}
	return 0;
}
