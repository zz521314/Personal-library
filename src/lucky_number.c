/*
 * @Author: zz
 * @Date: 2023-10-07 14:27:54
 * @LastEditors: zz 861692232@qq.com
 * @LastEditTime: 2023-10-07 15:07:38
 * @FilePath: \vscode\Personal-library\src\lucky_number.c
 * @Description:计算幸运数的个数
 * 幸运数是波兰数学家乌拉姆命名的。它采用与生成素数类似的“筛法”生成。
 * 首先从1开始写出自然数1,2,3,4,5,6,…
 * 1 就是第一个幸运数。
 * 我们从2这个数开始。把所有序号能被2整除的项删除，变为：
 * 1 _ 3 _ 5 _ 7 _ 9 …
 * 把它们缩紧，重新记序，为：
 * 1 3 5 7 9 … 。这时，3为第2个幸运数，然后把所有能被3整除的序号位置的数删去。注意，是序号位置，不是那个数本身能否被3整除!! 删除的应该是5，11, 17, …
 * 此时7为第3个幸运数，然后再删去序号位置能被7整除的(19,39,…)
 * 最后剩下的序列类似：
 * 1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, …
 *
 * 输入
 * 输入两个正整数m n, 用空格分开 (m < n < 1000*1000)
 *
 * 输出
 * 程序输出 位于m和n之间的幸运数的个数（不包含m和n）。
 *
 * 样例输入
 * 30 69
 *
 * 样例输出
 * 8
 *
 * Copyright (c) 2023 by zz/861692232@qq.com, All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n, s, d, i, j, r;
	scanf("%d%d", &m, &n);
	if (m >= n || n >= 1000000)
	{
		printf("请重新输入,第一个小于第二个数，并且第二个数小于1000000\n");
		return 0;
	}

	int a[n / 2 + 2];
	int len = n / 2 + 2;
	int p = 0;
	for (i = 1; i < len; i++)
		a[i] = 1 + 2 * (i - 1);
	for (j = 3; j < len; j++)
	{
		r = j;
		for (i = j; i < len; i++)
		{
			if (i % a[j - 1] != 0)
				a[r++] = a[i];
		}
		len = r;
	}
	for (i = 1; i < len; i++)
	{
		if (a[i] > m && p == 0)
		{
			s = i;
			p = 1;
		}
		if (a[i] < n)
			d = i;
		if (a[i] >= n)
			break;
	}
	printf("%d", d - s + 1);
	printf("\n");
	return 0;
}
