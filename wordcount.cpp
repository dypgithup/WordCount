#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])//argc����������argv��ÿһ������
{
	FILE *fp;
	char t[1024];
	int cntchar=0,cntword=0,len,i;
	char c;
	if(argc<3)	//�����ʽΪ��ִ���ļ��� ������ ��ȡ�ĵ�����
	{
		printf("�����������\n");
		exit(1);
	}
	fp = fopen(argv[2], "r");
	if (strcmp(argv[1], "-c") == 0) //ͳ���ַ���
    {
        while ((c = fgetc(fp)) != EOF)
                cntchar++;
        fclose(fp);
        printf("�ַ�����%d\n", cntchar);
        return 0;
    }

	else if(strcmp(argv[1],"-w")==0)//����Ϊ-w��ͳ���ַ���
	{
		while(fgets(t,1024,fp)!=NULL)
		{
			len=strlen(t);//��ȡ�����ַ�����
			for(i=0;i<len;i++)//�Ѷ���ȫ��ת��Ϊ�ո�
			{
				if(t[i]==',')
					t[i]=' ';
			}
			for(i=0;i<len;i++)//ͳ�Ƶ��ʸ���
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
		printf("���ʸ�����%d\n",cntword);
		return 0;
	}
}