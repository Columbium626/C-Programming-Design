#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
int add(void);
int del(void);
int modify(void);
int search(void);
void outputsea(int);
void outputtablehead(void);
void outputcour(void);
int input(int,int);
int import(void);
int importsave(void);
int export(void);
int exportsave(void);
int sortstu(void);
int modcour(void);
int advanced(void);
#define CHSIZE sizeof(char)
int st_num=0;//ȫ�ֱ�������ǰ�����ѧ������
const char ChineseCharacterSample[]="��";
#define CCByte (sizeof(ChineseCharacterSample)-1)//��ȡһ���������û�����ϵͳ����ģʽ����ռ���ֽ���

struct infcourse{
	char name[15];
	double credit;
};//����γ���Ϣ
struct infcourse course[10+1]={ {"������1",2.0},{"רҵ��1",3.0},{"רҵ��2",4.0} };//����Ĭ�Ͽγ���Ϣ
int num_course=3;
double credit_sum=9.0;
struct infgrade{
	double gpa;
    double score[10];
};

struct information{
	char number[21];
	char name[21];
	char schclass[21];
	struct infgrade grade;
}st[10005];
//ѧ����Ϣ������ѧ���ɼ���Ƕ�׵Ľṹ�����
struct information* psearch (char* s);

int sortstu_optcour;
int cmp1(const void* a,const void* b);
int cmp2(const void* a,const void* b);
int cmp3(const void* a,const void* b);
int cmp4(const void* a,const void* b);
int cmp5(const void* a,const void* b);
int cmp6(const void* a,const void* b);
int cmp7(const void* a,const void* b);


int main()
{
	printf("��������������������������������������������������������������������������������\n");
	printf("��      ��ӭʹ��ѧ����Ϣ����ϵͳv1.0    ��\n");
	printf("��������������������������������������������������������������������������������\n");
	short option;
	int isyes;
	printf("������ѡ����ţ��Իس���������\n");
	printf("[1]����ѧ����Ϣ\n");
	printf("[2]ɾ��ѧ����Ϣ\n");
	printf("[3]�޸�ѧ����Ϣ\n");
	printf("[4]����ѧ����Ϣ\n");
	printf("[5]����ѧ����Ϣ\n");
	printf("[6]����ѧ����Ϣ\n");
	printf("[7]����ѧ����Ϣ\n");
	printf("[8]�༭�γ���Ϣ\n");
	printf("[9]��������\n");
	printf("[0]��������\n");
	printf("����ʹ��ϵͳ����������8���ÿγ���Ϣ\n");
	//�򿪳�����ʾ�����˵�
	while(1)
	{
		scanf("%hd",&option);
		fflush(stdin);
		switch (option){
		case 1:add();break;
		case 2:del();break;
		case 3:modify();break;
		case 4:search();break;
		case 5:import();break;
		case 6:export();break;
		case 7:sortstu();break;
		case 8:modcour();break;
		case 9:advanced();break;
		case 0:break;
		default:printf("��Ч��ָ����������룺\n");fflush(stdin);break;
		}
		
		if(option==0)
		{
			printf("��ȷʵҪ�˳���������������δ���������ݶ����ᱻ���档\n");
			printf("����ǣ�������100��������ǣ�����������������\n");
			scanf("%d",&isyes);
			fflush(stdin);
			if(isyes==100)
				break;
		}
		option=-1;
		printf("���ѻص����˵��������������ţ�\n");
		printf("[1]����ѧ����Ϣ\n");
		printf("[2]ɾ��ѧ����Ϣ\n");
		printf("[3]�޸�ѧ����Ϣ\n");
		printf("[4]����ѧ����Ϣ\n");
		printf("[5]����ѧ����Ϣ\n");
		printf("[6]����ѧ����Ϣ\n");
		printf("[7]����ѧ����Ϣ\n");
		printf("[8]�༭�γ���Ϣ\n");
		printf("[9]��������\n");
		printf("[0]��������\n");
	}
	printf("�������˳���\n��л����ʹ�ã���ӭ�´�������\n");
	
	system("PAUSE");
	return 0;}

int add(void)
{
	if(st_num>=10000) {printf("����ռ�����!\n");return 1;}
	printf("����������ÿλѧ����ѧ�š��������༶�ͷֿ�Ŀ�ɼ���\n");
	printf("ÿһ��ֻ������һλѧ����һ����Ϣ���Իس�������\n");
	printf("***����#�������˵�***\n");
	while(1)
	{
		if(input(st_num,1)==1)  break;//����input��������ѧ����Ϣ
		st_num++;
	}
	return 0;
}

int del(void)
{
	printf("[1]ɾ��һ����¼\n");
	printf("[2]ɾ�����м�¼\n");
	printf("[0]�������˵�\n");
	int option,isyes;
	char cache[1005];
	struct information* p;
	int idx;
	while(1)
	{
		scanf("%d",&option);
		fflush(stdin);
		if(option==0) return 0;
		if(option!=1&&option!=2)
		{printf("��Ч�����룡������\n");continue;}
		break;
	}
	if(option==2)
	{
		printf("��Ҫɾ������ѧ����Ϣ��\n");
		printf("����ǣ������999��������ǣ����������������ַ������˵�\n");
		scanf("%d",&isyes);
		fflush(stdin);
		if(isyes!=999)  return 0;
		printf("�ٴ�ȷ�ϣ���ȷʵҪɾ�� ȫ�� ѧ����Ϣ��\n");
		printf("����ǣ������1��������ǣ����������������ַ������˵�\n");
		printf("���ڳ�����ͣ5����...\n");
		fflush(stdin);
		Sleep(5000);
		fflush(stdin);
		printf("�������һ��ȷ�ϣ��Ƿ�Ҫɾ������ѧ����Ϣ��\n");
		scanf("%d",&isyes);
		fflush(stdin);
		if(isyes!=1)  return 0;
		printf("���������ѧ����Ϣ��\n");
		printf("������볷��ɾ����������1�����������������������֣����򽫷������˵�\n");
		scanf("%d",&isyes);
		fflush(stdin);
		if(isyes==1)  {printf("���ѳɹ�����ɾ����\n");return 0;}
		st_num=0;
		return 0;
	}
	
	if(option==1)
	{
		while(1)
		{
			printf("������Ҫɾ����ѧ����ѧ�ţ��Իس�����\n");
			scanf("%s",cache);
			fflush(stdin);
			if(cache[0]=='#') return 0;
			if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
			break;
		}
		p=psearch(cache);//��ȡѧ����Ϣ�ĵ�ַ
		if(p==NULL){printf("δ�ҵ���Ӧ����Ϣ��\n");return 1;}
		printf("��ȷʵҪɾ��ѧ����%s������Ϣ��\n",p->name);
		printf("����ǣ������1����������������������ֻص����˵�\n",p->name);
		scanf("%d",&isyes);
		fflush(stdin);
		if(isyes!=1)  return 0;
		for(idx=p-st;idx<=st_num-2;idx++)//ɾ��ѧ����Ϣ������ѭ��ǰ��
			st[idx]=st[idx+1];
		st_num--;
		printf("���ѳɹ�ɾ����\n");
		
	}
	return 0;
}

int input(int index,int typ)
{
	//�ڶ����β�typ��ʾ���ú��������ͣ�TypeΪ1ʱ�����ѧ����Ϣ��Ϊ2ʱ���޸�ѧ����Ϣ
	char cache[1000];
	char number_cache[21];
	char name_cache[21];
	char schclass_cache[21];
	double dou_cache[11];
	double scoresum;
	int i;
	int rep=0;
	while(1)
	{
		while(1)//number
		{
			if(typ==2) break;
			printf("ѧ�ţ�");
			scanf("%100s",cache);
			fflush(stdin);
			if(cache[0]=='#') return 1;
			if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
			for(i=0;i<=st_num-1;i++)
				if(!strcmp(cache,st[i].number))
				{printf("ѧ�Ŵ����ظ�������������\n");rep=1;break;}
				if(rep==1){rep=0;continue;}
				strcpy(number_cache,cache);
				break;
		}
		while(1)//name
		{
			printf("������");
			gets(cache);
			fflush(stdin);
			if(cache[0]=='#') return 1;
			if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
			strcpy(name_cache,cache);
			break;
		}
		while(1)//schclass
		{
			printf("�༶��");
			scanf("%100s",cache);
			fflush(stdin);
			if(cache[0]=='#') return 1;
			if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
			strcpy(schclass_cache,cache);
			break;
		}
		while(1)//grade
		{
			for(i=0;i<=num_course-1;i++)
			{
				printf("%s������",course[i].name);
				scanf("%lf",&dou_cache[i]);
				fflush(stdin);
				if(dou_cache[i]==-1) return 1;
				if(dou_cache[i]>=1001||dou_cache[i]<=-1001)
				{
					printf("������ĳɼ���Ч���ɼ�������Ϊ�㣡\n");
					dou_cache[i]=0;
				}
				
			}
			break;
		}
		
		if(typ!=2)
		    strcpy(st[index].number,  number_cache);
		strcpy(st[index].name,  name_cache);
		strcpy(st[index].schclass,  schclass_cache);
		scoresum=0;
		for(i=0;i<=num_course-1;i++)
		{
			st[index].grade.score[i]=dou_cache[i];
			scoresum=scoresum+st[index].grade.score[i]*course[i].credit;
		}
		st[index].grade.gpa=scoresum/credit_sum;
		printf("������Ϣ¼����ϣ�\n");
		return 0;
	}
}

struct information* psearch (char* s)
{//����Ĳ���Ϊ����ѧ����Ϣ���ַ�����ַ
	int i,idx=-1;
	for(i=0;i<=st_num-1;i++)
		if(!strcmp(s,st[i].number))
		{
			idx=i;
			return &st[idx];//���ҵ�ѧ����Ϣ�����ض�Ӧָ��
			break;
		}
		if(idx==-1)
		{
			return NULL;
		}
		return NULL;//�Ҳ���ѧ����Ϣ�����ؿ�ָ��
}

int modify(void)
{
	char cache[1005];
	struct information* p;
	int idx;
	
	while(1)
	{
		printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ��Իس�����������#�ɷ������˵�\n");
		scanf("%s",cache);
		fflush(stdin);
		if(cache[0]=='#') return 0;
		if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
		break;
	}
	p=psearch(cache);
	if(p==NULL)  {printf("δ�ҵ�������Ϣ��\n");return 1;}
	idx=p-st;
	printf("��ѯ������ԭ����Ϣ���£�\n");
	outputtablehead();
	outputsea(idx);
	printf("������޸ĺ�ĸ�����Ϣ��ע�⣬ѧ�Ų����޸ģ�������������ѧ�ţ���ɾ�����������\n");
				
				if( input(idx,2)==0 )//����input���������޸ĺ��ѧ����Ϣ
				printf("��Ϣ���޸ģ�\n");
				return 0;
}

void outputsea(int index)
{
	int icour;
	printf("%9s\t%7s\t%20s\t%9.2f",st[index].number,st[index].name,st[index].schclass,st[index].grade.gpa);
	for(icour=0;icour<=num_course-1;icour++)
		{  printf("\t%12.1f",st[index].grade.score[icour]);  }
	printf("\n");

}

void outputtablehead(void)
{
	int i;
	printf("%9s\t%7s\t%20s\t%9s","ѧ��","����","�༶","��Ȩƽ���ɼ�");
	for(i=0;i<=num_course-1;i++)
			printf("\t%12s",course[i].name);
	printf("\n");

}

int search(void)
{
	printf("[1]�������ѧ���ɼ�\n");
	printf("[2]��ѧ�ž�ȷ����\n");
	printf("[3]����������ģ������\n");
	int option;
	int i,j,k,sealen;
	int dif,size;
	int outcome;
	long idx=-1;
	char cache[1005];
	char name_search[17];
	char name_cmp[17];
	scanf("%d",&option);
	fflush(stdin);
	if(option!=1&&option!=2&&option!=3&&option!=0)
	{
		printf("��Ч�����룡\n");
	}
	if(option==0) return 0;
	if(option==3)
	{
		printf("������ѧ��������������4�����֣�\n");
		while(1)//name
		{
			gets(cache);
			fflush(stdin);
			if(cache[0]=='#') return 1;
			if(strlen(cache)>=17)  {printf("�����޶����ȣ�����������\n");continue;}
			strcpy(name_search,cache);
			break;
		}
		outcome=0;
		size=CCByte;
		sealen=strlen(name_search);
		outputtablehead();
		for(i=0;i<=st_num-1;i++)
		{
			dif=strlen(st[i].name)-sealen;
			for(j=0;j<=dif;j=j+size)//ÿ��λ��size���ֽڣ�sizeΪһ��������ռ���ֽ���
			{
				for(k=0;k<=sealen-1;k++)//����ַ��ȶ�
					name_cmp[k]=st[i].name[j+k];
				if( strncmp(name_search,name_cmp,sealen)==0 )//����ҵ������Ӧ���
				{
					outputsea(i);
					outcome++;
					break;
				}
			}
		}
		printf("��������в��ң����ҵ�%d�������\n\n",outcome);

	}
	if(option==1)
	{
		outputtablehead();
		for(i=0;i<=st_num-1;i++)
			outputsea(i);
		return 0;
	}
	if(option==2)
	{
		while(1)
		{
			printf("������ѧ�ţ��Իس�������\n");
			scanf("%100s",cache);
			fflush(stdin);
			idx=-1;
			if(cache[0]=='#') return 1;
			if(strlen(cache)>=20)  {printf("�����޶����ȣ�����������\n");continue;}
			for(i=0;i<=st_num-1;i++)
				if(!strcmp(cache,st[i].number))
				{
					idx=i;
					break;
				}
				if(idx==-1)
				{
					printf("û���ҵ���\n");
					return 2;
				}
				printf("�ҵ�����1�������\n\n");
				outputtablehead();
				outputsea(idx);
				printf("\n");
				return 0;
				
		}
	}
	return 0;
}


int import(void)
{
	printf("[1]���ϴδ浵�㵼��\n");
	printf("[2]���ⲿtxt�ļ�����\n");
	printf("[0]�������˵�\n");
	int option;
	int old_num;
	while(1)
	{
		scanf("%d",&option);
		fflush(stdin);
		if(option==0) return 0;
		if(option!=1&&option!=2)
		{printf("��Ч�����룡������\n");continue;}
		break;
	}
	if(option==1)
		return importsave();
	
	printf("ע�����\n");
	printf("*********************************\n");
	printf("�뽫��������ļ�������Ϊ\"import.txt\"�����ı�����ʽ���뱾���򴢴���ͬһĿ¼��\n");
	printf("�ļ���ÿһ�д���һ��ѧ������Ϣ\n");
	printf("ÿһ���ڣ�һ��ѧ���Ĳ�ͬ��Ϣ���Ʊ��Tab�ָ�\n");
	printf("�ļ���Ҫ������ͷ��ÿһ���ڣ��������Ϣ������\n");
	printf("ѧ����ѧ�š��������༶�����ſγ̵ĳɼ�\n");
	printf("���Ƴɼ���˳�������ǣ�\n");
	int k;
	for(k=0;k<=num_course-1;k++)
		printf("[%6s]\t",course[k].name);
	printf("\n");
	printf("������Ҳ���ܴ���ѧ�����ܳɼ����������������õ�ѧ�֣��Զ�����ѧ���ļ�Ȩƽ���ɼ�\n");
	printf("�����Խ�Excel�е���Ϣ���Ƶ�txt�ļ�����\n");
	printf("��ѧ�������⣬������Ϣ���ܰ����ո�\n");
	printf("�ļ�����ǰ�����������Ƿ񳬳���Χ\n");
	printf("ѧ����ѧ�š��������༶����Ӧ����20���ַ���10�����֣�\n");
	printf("ѧ����ѧ�Ų������ظ�\n");
	printf("���ѧ���ظ�������ֻ������һ������\n");
	printf("������ഢ��10000��ѧ����Ϣ�������Ĳ��ֲ��ᱻ����\n");
	printf("�����Ḳ��ԭ�е�ѧ����Ϣ\n");
	printf("����������ϸ��������ļ��Ƿ񶼷�������Ҫ��\n");
	printf("���ر�ע�⡿��ǰϵͳ�й���%d�ſγ̣���ȷ�������ļ��еĿγ�����һ�£�\n",num_course);
	printf("*********************************\n");
	printf("����1����ʼ�����ļ������򽫷������˵�\n");
	scanf("%d",&k);
	fflush(stdin);
	if(k!=1) return 0;
	printf("������ʼ����");
	for(k=0;k<=2;k++)
	{
		Sleep(200);
		printf(". ");//ÿ0.2s��ӡ��һ����
		fflush(stdout);
	}
	old_num=st_num;
	printf("\n");
	FILE *fp;
	char number_cache[21];
	char name_cache[21];
	char schclass_cache[21];
	double grade_cache;
	int i,rep,skip;
	int icour;
	double scoresum;
	
	if  (( fp=fopen("import.txt","r") )==NULL)
	{
		printf("�ļ������ڻ��ʧ�ܣ�\n");
		return 1;
	}
	skip=0;
	while( (!feof(fp)) &&(st_num<=10000) )
	{
		fscanf(fp,"%20s\t",number_cache);

		for(i=0;i<=st_num-1;i++)
		    if(!strcmp(number_cache,st[i].number))
			{skip++;rep=1;break;}
		if(rep==1)//���ѧ���ظ�����װ������ȡ��һ�е��������ݣ�����д��ѧ����Ϣ
		{
			fscanf(fp,"%20[^\t]",name_cache);
		    fscanf(fp,"%20s\t",schclass_cache);
			for(icour=0;icour<=num_course-1;icour++)
			{ 
			fscanf(fp,"%lf",&grade_cache); 
			}
			fscanf(fp,"\n");
			rep=0;continue;
		}
		strcpy(st[st_num].number,number_cache);
		fscanf(fp,"%20[^\t]",st[st_num].name);
		fscanf(fp,"%20s\t",st[st_num].schclass);
		scoresum=0;
		for(icour=0;icour<=num_course-1;icour++)
		{ 
			fscanf(fp,"%lf",&st[st_num].grade.score[icour]); 
			scoresum=scoresum+st[st_num].grade.score[icour]*course[icour].credit ;
		}
		fscanf(fp,"\n");
		st[st_num].grade.gpa=scoresum/credit_sum;
		st_num++;
		
	}
	if(fclose(fp))
	{
		printf("�ļ��ر�ʧ�ܣ�\n");
		return 1;
	}
	printf("�ɹ�����%d�����ݣ�%d��������ѧ���ظ�δ�����롣\n",st_num-old_num,skip);
	return 0;
}


int importsave(void)
{
	int isyes,icour;
	int InputNumCour;
	FILE* fp;
	printf("����ѧ�����Ḳ������ѧ����Ϣ\n");
	printf("���ѧ����������������ƣ���ô�����Ĳ��ֽ����ᱻ����\n");
	printf("�Ƿ���������ǣ�������1\n");
	scanf("%d",&isyes);
	fflush(stdin);
	if(isyes!=1)
	{printf("����ȡ�����룡\n");return 2;}
	if  (( fp=fopen("SAVE.txt","r") )==NULL)
	{
		printf("�ļ������ڻ��ʧ�ܣ�\n");
		return 1;
	}
	fscanf(fp,"%d\n",&InputNumCour);
	if(InputNumCour!=num_course)
	{
		printf("�γ���������һ�α���ʱ��һ�£����Ȼ����˵�����8���ÿγ���Ϣ��\n");
		return 4;
	}
	st_num=0;
	while( (!feof(fp)) &&(st_num<=10000) )
	{
		fscanf(fp,"%20s\t",st[st_num].number);
		fscanf(fp,"%20[^\t]",st[st_num].name);
		fscanf(fp,"%20s\t",st[st_num].schclass);
		for(icour=0;icour<=num_course-1;icour++)
		{ 
			fscanf(fp,"%lf",&st[st_num].grade.score[icour]); 
		}
		fscanf(fp,"%lf",&st[st_num].grade.gpa); 
		fscanf(fp,"\n");
		st_num++;
	}
	if(fclose(fp))
		printf("�ļ��ر�ʧ�ܣ�\n");
	if(st_num>=10001)
		printf("�������ܳ���������ƣ��������ݿ���δ�����룡\n");
	printf("��������%d�����ݡ�\n",st_num);
	printf("������ɣ�\n");
	return 0;
}


int export(void)
{
	printf("[1]�浵��ǰ��Ϣ\n");
	printf("[2]����Ϊtxt�ļ�\n");
	printf("[0]�������˵�\n");
	int option;
	while(1)
	{
		scanf("%d",&option);
		fflush(stdin);
		if(option==0) return 0;
		if(option!=1&&option!=2)
		{printf("��Ч�����룡������\n");continue;}
		break;
	}
	if(option==1)
		return exportsave();
	
	FILE *fp;
	int i;
	int icour;
	if  (( fp=fopen("export.txt","w") )==NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
		return 1;
	}
	fprintf(fp,"%20s\t%10s\t%30s","ѧ��","����","�༶");
	for(i=0;i<=num_course-1;i++)
		fprintf(fp,"\t%20s",course[i].name );
	fprintf(fp,"\t�ܷ�");
	for(i=0;i<=st_num-1;i++)
	{
		fprintf(fp,"\n%20s\t",st[i].number);
		fprintf(fp,"%10s\t",st[i].name);
		fprintf(fp,"%30s",st[i].schclass);
		for(icour=0;icour<=num_course-1;icour++)
		{  fprintf(fp,"\t%20.1f",st[i].grade.score[icour]);  }
		fprintf(fp,"\t");
		fprintf(fp,"%.2lf",st[i].grade.gpa);
	}
	if(fclose(fp))
	{
		printf("�ļ��ر�ʧ�ܣ�\n");
		return 1;
	}
	printf("�����ɹ���\n");
	printf("�ļ�������txt�ļ�����ʽ���洢�ڱ�����Ŀ¼�µ�\"export.txt\"�ļ���\n");
	Sleep(1000);
	return 0;
}

int exportsave(void)
{
	int isyes;
	int i,icour;
	FILE* fp;
	printf("����ѧ����Ϣ�Ḳ��ԭ�е�ѧ����Ϣ�Ϳγ���Ϣ���Ƿ���������ǣ�������1\n");
	scanf("%d",&isyes);
	fflush(stdin);
	if(isyes!=1)
	{printf("����ȡ��������\n");return 2;}
	if(st_num==0)
	{printf("��ǰ��û������κ�ѧ����\n");return 3;}
	if( (fp=fopen("SAVE.txt","w"))==NULL )
		{printf("�ļ�����ʧ�ܣ�\n");return 1;}
	fprintf(fp,"%d\n",num_course);
	for(i=0;i<=st_num-1;i++)
	{
		fprintf(fp,"%s\t",st[i].number);
		fprintf(fp,"%s\t",st[i].name);
		fprintf(fp,"%s",st[i].schclass);
		for(icour=0;icour<=num_course-1;icour++)
		{  fprintf(fp,"\t%f",st[i].grade.score[icour]);  }
		fprintf(fp,"\t");
		fprintf(fp,"%lf\n",st[i].grade.gpa);
	}
	if(fclose(fp))
		printf("�ļ��ر�ʧ�ܣ�\n");
	printf("������ɣ�\n");
	return 0;
}

void outputcour(void)
{
	int i;
	printf("�γ�");
	for(i=1;i<=num_course;i++)
		printf("\t%8s",course[i-1].name);
	printf("\n");
	printf("ѧ��");
	for(i=1;i<=num_course;i++)
		printf("\t%8.1f",course[i-1].credit);
	printf("\n");
}


int sortstu(void)
{
	printf("[1]��ѧ������\n");
	printf("[2]����������\n");
	printf("[3]���༶����\n");
	printf("[4]���ܷ�����\n");
	printf("[5]���༶-�ܷ�����\n");
	printf("[6]�����Ƴɼ�����\n");
	printf("[7]���༶-���Ƴɼ�����\n");
	printf("[0]�������˵�\n");
	int option;
	int i;
	while(1)
	{
		scanf("%d",&option);
		fflush(stdin);
		if(option==0) return 0;
		if(option<=0||option>=8)
		{printf("��Ч�����룡������\n");continue;}
		break;
	}

	if(option==6||option==7)
	{
		printf("��Ҫ���ݵڼ��ſγ̵ĳɼ�������������ţ�\n");
		outputcour();
		while(1)
		{
		scanf("%d",&sortstu_optcour);
		fflush(stdin);
		if(sortstu_optcour==0) return 0;
		if(sortstu_optcour<=0||sortstu_optcour>=num_course+1)
		{printf("��Ч�����룡������\n");continue;}
		sortstu_optcour--;//-1,yuxiabiaopipei
		break;
		}
	}

	switch (option)//ѡ��ͬ������ģʽ
	{
        case 1: qsort( st, st_num, sizeof(st[0]), cmp1 ); break;
        case 2: qsort( st, st_num, sizeof(st[0]), cmp2 ); break;
		case 3: qsort( st, st_num, sizeof(st[0]), cmp3 ); break;
		case 4: qsort( st, st_num, sizeof(st[0]), cmp4 ); break;
		case 5: qsort( st, st_num, sizeof(st[0]), cmp5 ); break;
		case 6: qsort( st, st_num, sizeof(st[0]), cmp6 ); break;
		case 7: qsort( st, st_num, sizeof(st[0]), cmp7 ); break;
	}
	printf("������ɣ�\n");
	if(st_num<=80)
	{
		outputtablehead();
		for(i=0;i<=st_num-1;i++)
			outputsea(i);
	}
	if(st_num>=81)
		printf("����ѧ�����࣬�����ﲻ��ʾ��������������Ҫ���뷵�����˵����в鿴��\n");
	return 0;
}

int cmp1(const void* a,const void* b)
{return strcmp( ((struct information*)a)->number, ((struct information*)b)->number );}
int cmp2(const void* a,const void* b)
{return strcmp( ((struct information*)a)->name, ((struct information*)b)->name );}
int cmp3(const void* a,const void* b)
{return strcmp( ((struct information*)a)->schclass, ((struct information*)b)->schclass );}
int cmp4(const void* a,const void* b)
{return  ((struct information*)a)->grade.gpa>((struct information*)b)->grade.gpa?-1:1 ;}
int cmp5(const void* a,const void* b)
{   int res;
	res=strcmp( ((struct information*)a)->schclass, ((struct information*)b)->schclass );
	if(  res!=0 )
	return  res ;
	else return ((struct information*)a)->grade.gpa>((struct information*)b)->grade.gpa?-1:1;}
int cmp6(const void* a,const void* b)
{return  ((struct information*)a)->grade.score[sortstu_optcour]>((struct information*)b)->grade.score[sortstu_optcour]?-1:1 ;}
int cmp7(const void* a,const void* b)
{   int res;
	res=strcmp( ((struct information*)a)->schclass, ((struct information*)b)->schclass );
	if(  res!=0 )
	return  res ;
	else return ((struct information*)a)->grade.score[sortstu_optcour]>((struct information*)b)->grade.score[sortstu_optcour]?-1:1 ;}

int modcour()
{
	int option;
	int i,j;
	int order;
	int isyes;
	FILE* fp;
	char name_cache[1000];
	double credit_cache;
	printf("[1]��ѯ�γ���Ϣ\n");
	printf("[2]���ӿγ���Ϣ\n");
	printf("[3]�޸Ŀγ���Ϣ\n");
	printf("[4]ɾ���γ���Ϣ\n");
	printf("[5]�����γ���Ϣ\n");
	printf("[6]����γ���Ϣ\n");
	printf("[0]�������˵�\n");
	while(1)
	{
		printf("��ѡ��[1]��ѯ[2]����[3]�޸�[4]ɾ��[5]����[6]����[0]���أ�\n");
		scanf("%d",&option);
		fflush(stdin);
		if(!option) {printf("�ѻص����˵�\n");break;}
		fflush(stdin);

		if(option==5)
		{
			printf("�����γ���Ϣ�Ḳ��ԭ�е��ļ����Ƿ���������ǣ�������1\n");
			scanf("%d",&isyes);
			fflush(stdin);
			if(isyes!=1)
			{printf("����ȡ��������\n");continue;}
			if( (fp=fopen("Course.txt","w"))==NULL )
			{printf("�ļ�����ʧ�ܣ�\n");continue;}
			fprintf(fp,"%d",num_course);
			for(i=0;i<=num_course-1;i++)
				fprintf(fp,"\n%s",course[i].name);
			for(i=0;i<=num_course-1;i++)
				fprintf(fp,"\n%f",course[i].credit);
			if(fclose(fp))
				printf("�ļ��ر�ʧ�ܣ�\n");
			printf("�����ɹ���\n");
		}

		if(option==6)
		{
			if(st_num!=0)
			{printf("����γ���Ϣǰ�������ѧ���б�����ѧ����û������ӿγ̵ĳɼ���\n");return 0;}
			printf("����γ���Ϣ�Ḳ�����е���Ϣ���Ƿ���������ǣ�������1\n");
			scanf("%d",&isyes);
			fflush(stdin);
			if(isyes!=1)
			{printf("����ȡ�����룡\n");continue;}
			if( (fp=fopen("Course.txt","r"))==NULL )
			{printf("�ļ���ʧ�ܣ�\n");continue;}
			fscanf(fp,"%d",&num_course);
			for(i=0;i<=num_course-1;i++)
				fscanf(fp,"%s",course[i].name);
			credit_sum=0;
			for(i=0;i<=num_course-1;i++)
			{
				fscanf(fp,"%lf",&course[i].credit);
				credit_sum=credit_sum+course[i].credit;
			}
			if(fclose(fp))
				printf("�ļ��ر�ʧ�ܣ�\n");
			printf("����ɹ���\n");

		}

		if(option==2)
		{
			if(st_num!=0)  {printf("�����ӿγ���Ϣ�����Ƚ�ѧ���б��ÿգ�����ѧ����û������ӿγ̵ĳɼ���\n");continue;}
			if(num_course>=10)  {printf("��ӵĿγ������Ѵ����ޣ�\n");continue;}
		}
		
		if(option==4)
		{
			if(st_num!=0)  
			{
			printf("��ɾ���γ���Ϣ�����Ƚ�ѧ���б��ÿգ�\n\
				���������ĳһ�ſγ̲������ܳɼ��������Խ���ѧ�����㡣\n");
			continue;
			}
		}
		
		if(option>=1&&option<=4)
		{
			if(num_course==0) 
				printf("����û������κογ���Ϣ��\n");
			if(num_course!=0)
			{
				printf("��ǰ����ӵĿγ���Ϣ���£�\n");
				printf("�γ�");
				for(i=1;i<=num_course;i++)
					printf("\t%12s",course[i-1].name);
				printf("\n");
				printf("ѧ��");
				for(i=1;i<=num_course;i++)
					printf("\t%12.1f",course[i-1].credit);
				printf("\n");
			}
		}
		if(option==1)  printf("�����ɹ����������\n");
		
		if(option==2)
		{
			
			while (1)
			{
				printf("��Ҫʹ����ӵĿγ����ڿγ��б�ĵڼ�λ������룺\n");
				scanf("%d",&order);
				fflush(stdin);
				if(order>num_course+1||order<=0)
				{
					printf("��Ч�����룬�����ԣ�\n");fflush(stdin);order=-1;continue;
				}
				fflush(stdin);
				printf("������Ҫ��ӵĿγ̵����ƣ�\n");
				scanf("%s",name_cache);
				fflush(stdin);
				name_cache[14]=0;
				printf("������Ҫ��ӵĿγ̵�ѧ�֣�\n");
				scanf("%lf",&credit_cache);
				if(credit_cache>=128||credit_cache<=-1)
				{
					printf("��Ч�����ݣ�ѧ�ֽ�����ֵΪ�㣡���Ժ���\n");credit_cache=0;
				}
				fflush(stdin);
				for(i=num_course; i>=order ;i--)
					course[i]=course[i-1];
				
				course[i].credit=credit_cache;
				for(j=0;name_cache[j]!=0;j++)
					course[i].name[j]=name_cache[j];
				course[i].name[j]=0;
				num_course++;
				credit_sum=credit_sum+credit_cache;
				printf("��ӳɹ����������\n");
				break;
			}
		}
		if(option==3)
		{
			while (1)
			{
				printf("��Ҫ�޸ĵڼ��ſγ̵���Ϣ�������һ�����������֣�\n");
				scanf("%d",&order);
				fflush(stdin);
				if(order>num_course||order<=0)
				{
					printf("��Ч�����룬�����ԣ�\n");fflush(stdin);order=-1;continue;
				}
				fflush(stdin);
				printf("���������øÿγ̵����ƣ�\n");
				scanf("%s",name_cache);
				fflush(stdin);
				name_cache[14]=0;
				printf("���������øÿγ̵�ѧ�֣�\n");
				scanf("%lf",&credit_cache);
				if(credit_cache>=128||credit_cache<=-1)
				{
					printf("��Ч�����ݣ�ѧ�ֽ�����ֵΪ�㣡���Ժ���\n");credit_cache=0;
				}
				fflush(stdin);
				course[order-1].credit=credit_cache;
				for(j=0;name_cache[j]!=0;j++)
					course[order-1].name[j]=name_cache[j];
				course[order-1].name[j]=0;
				for(credit_sum=0,j=0;j<=num_course-1;j++)
					credit_sum=credit_sum+course[j].credit;
				printf("�޸ĳɹ����������\n");
				break;
			}
		}
		
		if(option==4)
		{
			if(num_course<=1)
			{
				printf("�γ������Ѵ���Сֵ�����������ɾ����\n");
				return 1;
			}
			while (1)
			{
				printf("��Ҫɾ���ڼ��ſγ̵���Ϣ�������һ�����������֣�\n");
				scanf("%d",&order);
				fflush(stdin);
				if(order>num_course||order<=0)
				{
					printf("��Ч�����룬�����ԣ�\n");fflush(stdin);order=-1;continue;
				}
				fflush(stdin);
				printf("��ȷʵҪɾ���γ̡�%s��������ǣ������1��������ǣ�����������������\n",course[order-1].name);
				scanf("%d",&i);
				fflush(stdin);
				if(i!=1)
				{printf("��ȡ��ɾ��\n");break;}
				credit_sum=credit_sum-course[order-1].credit;
				for(j=order-1;j<=num_course-2;j++)
					course[j]=course[j+1];
				num_course--;
				
				printf("ɾ���ɹ���\n");
				break;				
			}
		}
	option=-10;
	}
	return 0;
}
int advanced(void)
{
	char* author="������Ϣ��github@Columbium626\nлл����ʹ�ã�\n*****************\n";
	int option,optcour;
	int i,num,res=0;
	float fres;
	double sum,ave,std,devsum;
	FILE *fp;
	printf("[1]����ƽ���ֺͱ�׼��\n");
	printf("[2]������ɹ������õĽ��Ʒ�����̬�ֲ���ѧ���ɼ�\n");
	printf("[8]��ʾ������Ϣ\n");
	printf("[9]����\n");
	printf("[0]�������˵�\n");
	scanf("%d",&option);
	fflush(stdin);
	if(option==9)
		system("CLS");//����
	if(option==1)
	{
		printf("��Ҫ����ڼ��ſγ̵�ƽ���ֺͱ�׼������룺\n");
		printf("�����Ҫ�����ֵܷ�ƽ���ֺͱ�׼�������0\n");
		outputcour();
		while(1)
		{
		scanf("%d",&optcour);
		fflush(stdin);
		if(optcour<=-1||optcour>=num_course+1)
		{
			printf("��Ч�����룬�����ԣ�\n");
			continue;
		}
		optcour--;
		break;
		}
		
		if(optcour==-1)
		{
			sum=ave=std=devsum=0;
			for(i=0;i<=st_num-1;i++)
				sum=sum+st[i].grade.gpa;
			ave=sum/st_num;
			printf("�ֵܷ�ƽ������%.2f\n",ave);
			for(i=0;i<=st_num-1;i++)
				devsum=devsum+(st[i].grade.gpa-ave)*(st[i].grade.gpa-ave);
			std=sqrt((devsum/st_num));
			printf("�ֵܷı�׼����%.2f\n",std);
			printf("������ɣ�\n");
		}
		if(optcour>=0)
		{
			sum=ave=std=devsum=0;
			for(i=0;i<=st_num-1;i++)
				sum=sum+st[i].grade.score[optcour];
			ave=sum/st_num;
			printf("�γ̡�%s����ƽ������%.2f\n",course[optcour].name,ave);
			for(i=0;i<=st_num-1;i++)
				devsum=devsum+(st[i].grade.gpa-ave)*(st[i].grade.gpa-ave);
			std=sqrt((devsum/st_num));
			printf("�γ̡�%s���ı�׼����%.2f\n",course[optcour].name,std);
			printf("������ɣ�\n");
		}
	}

	if(option==2)
	{
		printf("������Ҫ���ɵ��������������\n");
		while(1)
		{
		scanf("%d",&num);
		fflush(stdin);
		if(num<=0||num>=20000)
		{
			printf("�������ݷ�Χ�������ԣ�\n");
			continue;
		}
		break;
		}
		if  (( fp=fopen("RandomNumbers.txt","w") )==NULL)
		{
		printf("�ļ�����ʧ�ܣ�\n");
		return 1;
		}

		for(i=1;i<=num;i++)
		{
		srand((unsigned int)time(0)+res);
		res=rand()%300+rand()%300+rand()%300;
		res=res/3+18;
		fres=res*1.0/2;
		if(fres>100){i--;continue;}
		fprintf(fp,"%g\n",fres);
		}
        if(fclose(fp))
		{
	     	printf("�ļ��ر�ʧ�ܣ�\n");
	     	return 1;
		}
		printf("�������������ϣ������ڱ�����Ŀ¼�µ�RandomNumbers.txt�ļ��С�\n");
	}
	if(option==8)
		printf(author);//���������Ϣ
	return 0;
}
