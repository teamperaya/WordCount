#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int charNumber=0;//字符数
	int wordNumber=0;//单词数
	int isBlankOrComma=0;//上一个字符是否为空格或逗号。
	char tempChar=' ';//用于暂时存放从文件读出来的一个字符
	FILE *fp;//文件指针

	//检查参数个数是否正确
	if(argc!=3)
	{
		printf("错误：参数个数不正确！\n");
		exit(0);
	}

	//打开文件
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("错误：无法打开文件！\n");
		exit(0);
	}
	
	//跳转到文件开头处
	fseek(fp,0L,0);

	//逐字符读取文件
	while(!feof(fp))
	{
		//读取一个字符
		tempChar=fgetc(fp);
		//字符数加1
		charNumber++;

		//如果读出的字符不是空格，则找出一个单词
		if(tempChar==' ' || tempChar==',')
		{
			//如果上一个字符不是空格
			if(isBlankOrComma==0)
			{
				//单词数加1
				wordNumber++;
			}
			isBlankOrComma=1;
		}
		else
		{
			isBlankOrComma=0;
		}
	}
	//如果读出的最后一个字符不是空格或逗号，说明还有一个单词未被发现
	if(isBlankOrComma==0)
	{
		wordNumber++;
	}

	//输出结果
	if(strcmp(argv[1],"-c")==0)
	{
		printf("字符数：%d\n",charNumber);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		printf("单词数：%d\n",wordNumber);
	}
	else
	{
		printf("错误：输入的第二个参数错误！\n");
	}
	fclose(fp);
	return 0;
}