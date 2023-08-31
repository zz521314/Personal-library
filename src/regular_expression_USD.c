/*
 *
 * 日期：20230830
 * 功能：用正则表达式匹配美元格式
 *
 * 给定字符串 str，检查其是否符合美元书写格式
 * 1、以 $ 开始
 * 2、整数部分，从个位起，满 3 个数字用 , 分隔
 * 3、如果为小数，则小数部分长度为 2
 * 4、正确的格式如：$1,023,032.03 或者 $2.03，错误的格式如：$3,432,12.12 或者 $34,344.3
 *
 *
 * 说明：匹配不成功，后续解决
 *
 *
 */

#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

// 首先是^$意思就是按照我们所设定的规则进行匹配
//  \是转义的意思，因为$在正则里面是以什么什么结尾的意思，所以要先用\把它转成普通含义
// *就是可有可无的意思
/*
bool matchRegex(const char* pattern,const char * userString)
{
	bool ret = false;
	
	regex_t regex;
	int regexInit = regcomp(&regex,pattern,REG_EXTENDED);
	if(regexInit)
	{

	}
	else
	{
		int reti = regexec(&regex,userString,0,NULL,0);
		if(REG_NOERROR != reti)
		{

		}
		else
		{
			ret = true;
		}
	}

	regfree(&regex);

	return ret;
}
*/

int main(void)
{

//	const char* pattern = "^\\$\\d{1,3}(,\\d{3})*(\\.\\d{2})*$";
//	const char* pattern = "^\\$[1-9]\\d{0,2}(,\\d{3})*(\\.\\d{2})?$";
	const char* pattern = "^\\$[1-9]\\d{0,2}(,\\d{3})*(\\.\\d{2})?$";
	char *string = "$32.03";
	regex_t regex;
	//const size_t nmatch = 1;
	//scanf("%s\n",string);
	//int ret = matchRegex(pattern,string);
	int i = regcomp(&regex,pattern,REG_EXTENDED);
	if(i)
	{
		printf("regcomp error\n");
		return 0;
	}
	//int ret = regexec(&regex,string,0,NULL,0);
	int ret = regexec(&regex,string,0,NULL,0);
	if(ret != REG_NOERROR)
	{
		printf("%s:	false\n",string);
	}
	else
	{
		printf("%s:     ture\n",string);
	}
	regfree(&regex);

	return 0;
}
