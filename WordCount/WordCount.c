#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int charNumber=0;//�ַ���
	int wordNumber=0;//������
	int isBlankOrComma=0;//��һ���ַ��Ƿ�Ϊ�ո�򶺺š�
	char tempChar=' ';//������ʱ��Ŵ��ļ���������һ���ַ�
	FILE *fp;//�ļ�ָ��

	//�����������Ƿ���ȷ
	if(argc!=3)
	{
		printf("���󣺲�����������ȷ��\n");
		exit(0);
	}

	//���ļ�
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("�����޷����ļ���\n");
		exit(0);
	}
	
	//��ת���ļ���ͷ��
	fseek(fp,0L,0);

	//���ַ���ȡ�ļ�
	while(!feof(fp))
	{
		//��ȡһ���ַ�
		tempChar=fgetc(fp);
		//�ַ�����1
		charNumber++;

		//����������ַ����ǿո����ҳ�һ������
		if(tempChar==' ' || tempChar==',')
		{
			//�����һ���ַ����ǿո�
			if(isBlankOrComma==0)
			{
				//��������1
				wordNumber++;
			}
			isBlankOrComma=1;
		}
		else
		{
			isBlankOrComma=0;
		}
	}
	//������������һ���ַ����ǿո�򶺺ţ�˵������һ������δ������
	if(isBlankOrComma==0)
	{
		wordNumber++;
	}

	//������
	if(strcmp(argv[1],"-c")==0)
	{
		printf("�ַ�����%d\n",charNumber);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		printf("��������%d\n",wordNumber);
	}
	else
	{
		printf("��������ĵڶ�����������\n");
	}
	fclose(fp);
	return 0;
}