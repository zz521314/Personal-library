/*
 * @Author: zz
 * @Date: 2023-10-07 14:27:54
 * @LastEditors: zz 861692232@qq.com
 * @LastEditTime: 2023-10-07 15:07:58
 * @FilePath: \vscode\Personal-library\src\regular_expression_email.c
 * @Description: 使用正则表达式匹配邮件格式
 *
 * Copyright (c) 2023 by zz/861692232@qq.com, All Rights Reserved.
 */

#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

int main(int argc, char **argv)
{
	int status, i;
	int cflags = REG_EXTENDED;
	regmatch_t pmatch[1];
	const size_t nmatch = 1;
	regex_t reg;
	const char *pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*.\\w+([-.]\\w+)*$";
	char *buf = "chenjiayi@126.com";
	regcomp(&reg, pattern, cflags);			 // 编译正则模式
	status = regexec(&reg, buf, 0, NULL, 0); // 执行正则表达式和缓存的比较
	if (status == REG_NOMATCH)
		printf("No match\n");
	else if (0 == status)
	{
		printf("比较成功:");
		for (i = pmatch[0].rm_so; i < pmatch[0].rm_eo; ++i)
			putchar(buf[i]);
		printf("\n");
	}
	regfree(&reg);
	return 0;
}
