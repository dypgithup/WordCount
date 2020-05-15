#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])//argc参数个数，argv存每一个参数
{
	FILE *fp;
	char t[1024];
	int cntchar=0,cntword=0,len,i;
	char c;
	if(argc<3)	//输入格式为（执行文件名 参数名 读取文档名）
	{
		printf("输入参数不足\n");
		exit(1);
	}
	fp = fopen(argv[2], "r");
	if (strcmp(argv[1], "-c") == 0) //统计字符数
    {
        while ((c = fgetc(fp)) != EOF)
                cntchar++;
        fclose(fp);
        printf("字符数：%d\n", cntchar);
        return 0;
    }

	else if(strcmp(argv[1],"-w")==0)//参数为-w即统计字符数
	{
		while(fgets(t,1024,fp)!=NULL)
		{
			len=strlen(t);//读取到的字符长度
			for(i=0;i<len;i++)//把逗号全都转换为空格
			{
				if(t[i]==',')
					t[i]=' ';
			}
			for(i=0;i<len;i++)//统计单词个数
			{
				if(cntword==0)
				{
					if(t[i]==' '&&t[i-1]!=' ')
						cntword++;
				}
				else
				{
					if(i!=len-1&&t[i]==' '&&t[i+1]!=' ')
						cntword++;
					else if(i==len-1)
						break;
				}
			}
		}
		printf("单词个数：%d\n",cntword);
		return 0;
	}
}