#include<stdio.h>
#include<stdlib.h>
int N1,N2,kk1,kk2,kk3;
struct couse * head1;
struct student * head2;
struct couse//�γ���Ϣ�ṹ��
{
    int num1;
    char name1[20];
    int score;
    int nelepeo;
    //�γ���ѡ����
    int Melepeo;
    //�γ���������
    struct couse * next;
}
;
struct student//ѧ����Ϣ�ṹ��
{
    int num2;
    char name2[20];
    int nelenum[50];
    //��ѡ�γ̱��
    int nelen;
    //��ѡ�γ�����
    struct student * next;
}
;
void Ms()
{
    for (kk1=0;kk1<1100;kk1++)
            for (kk2=0;kk2<1200;kk2++)
              for (kk3=0;kk3<1200;kk3++);
}
void keyboardc()//¼��γ��Ӻ���(�Ӽ���¼��)
{
    struct couse *p1,*p2;
    N1=0;
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    printf("�γ̱��\t�γ�����\tѧ��\t�γ���������\n");
    scanf("%d%s%d%d",&p1->num1,p1->name1,&p1->score,&p1->Melepeo);
    p1->nelepeo=0;
    head1=NULL;
    while(p1->num1!=0)
    {
        N1=N1+1;
        if(N1==1)head1=p1; else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        scanf("%d%s%d%d",&p1->num1,p1->name1,&p1->score,&p1->Melepeo);
        p1->nelepeo=0;
    }
    p2->next=NULL;
}
void filec()//¼������Ӻ���(���ļ�¼��)
{
    FILE * fp;
    char filepath[20];
    struct couse *p1,*p2;
    N1=0;
    printf("����Ҫ������ļ�·��:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"r"))==NULL)
    {
        printf("�Ҳ���%s�ļ�!\n",filepath);
        exit(0);
    }
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    head1=NULL;
    while(!feof(fp))
    {
        N1=N1+1;
        if(N1==1)head1=p1; else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    }
    p2->next=NULL;
}
void inputc()//¼��γ�������
{
    int i;
    printf("\t\t\t¼��γ���Ϣ\n");
    printf("\n1.�Ӽ���¼��\n");
    printf("2.���ļ�¼��\n");
    printf("3.�������˵�\n");
    printf("��ѡ��(1~3):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):keyboardc();
        break;
        case(2):filec();
        break;
        case(3):break;
    }
}
void insertc(struct couse *incouse)//�γ̹����Ӻ���(���ӿγ�)
{
    struct couse *p0,*p1,*p2;
    p1=head1;
    p0=incouse;
    if(head1==NULL)
    {
        head1=p0;
        p0->next=NULL;
    } else
    {
        while((p0->num1 > p1->num1) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num1 <= p1->num1)
        {
            if(head1==p1) head1=p0; else p2->next=p0;
            p0->next=p1;
        } else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N1=N1+1;
}
void delc(int num1)//�γ̹����Ӻ���(ɾ���γ�)
{
    struct couse *p1,*p2;
    if(head1==NULL)
    {
        printf("\nû�пγ�,�޷�ɾ��!\n");
        goto end;
    }
    p1=head1;
    while(num1!=p1->num1 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num1==p1->num1)
    {
        if(p1==head1) head1=p1->next; else p2->next=p1->next;
        printf("��ɾ���ñ�ſγ�!\n");
        N1=N1-1;
    } else printf("�޸ñ�ŵĿγ�!\n");
    end:;
}
void managementc()//�γ̹���������
{
    struct couse * incouse;
    int i,num1;
    printf("\t\t\t�γ̹���\n");
    printf("1.�����γ�\n");
    printf("2.ɾ���γ�\n");
    printf("3.�������˵�\n");
    printf("��ѡ��(1~3):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):
        {
            incouse=(struct couse *)malloc(sizeof(struct couse));
            printf("�γ̱��\t�γ�����\tѧ��\t�γ���������\n");
            scanf("%d%s%d%d",&incouse->num1,incouse->name1,&incouse->score,&incouse->Melepeo);
            incouse->nelepeo=0;
            insertc(incouse);
            break;
        }
        case(2):
        {
            printf("������Ҫɾ���γ̵ı��:\n");
            scanf("%d",&num1);
            delc(num1);
            break;
        }
        case(3):break;
    }
}
void keyboards()//¼��ѧ����Ϣ�Ӻ������Ӽ���¼�룩
{
    int i;
    struct student *p1,*p2;
    N2=0;
    p1=p2=(struct student *)malloc(sizeof(struct student));
    printf("ѧ��ѧ��\tѧ������\n");
    scanf("%d%s",&p1->num2,p1->name2);
    p1->nelen=0;
    for (i=0;i<20;i++) p1->nelenum[i]=0;
    head2=NULL;
    while(p1->num2!=0)
    {
        N2=N2+1;
        if(N2==1)head2=p1; else p2->next=p1;
        p2=p1;
        p1=(struct student * )malloc(sizeof(struct student));
        scanf("%d%s",&p1->num2,p1->name2);
        p1->nelen=0;
        for (i=0;i<20;i++) p1->nelenum[i]=0;
    }
    p2->next=NULL;
}
void files()//¼��ѧ����Ϣ�Ӻ��������ļ�¼�룩
{
    int i=0;
    FILE * fp;
    char filepath[20];
    struct student *p1,*p2;
    N2=0;
    printf("����Ҫ������ļ�·��:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"r"))==NULL)
    {
        printf("�Ҳ���%s�ļ�!\n",filepath);
        exit(0);
    }
    p1=p2=(struct student*)malloc(sizeof(struct student));
    fread(p1,sizeof(struct student),1,fp);
    head2=NULL;
    while(!feof(fp))
    {
        i=0;
        N2=N2+1;
        if(N2==1)head2=p1; else p2->next=p1;
        p2=p1;
        p1=(struct student * )malloc(sizeof(struct student));
        fread(p1,sizeof(struct student),1,fp);
    }
    p2->next=NULL;
}
void inputs()//¼��ѧ����Ϣ������
{
    int i;
    printf("\t\t\t¼��ѧ����Ϣ\n");
    printf("\n1.�Ӽ���¼��\n");
    printf("2.���ļ�¼��\n");
    printf("3.�������˵�\n");
    printf("��ѡ��(1~3):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):keyboards();
        break;
        case(2):files();
        break;
        case(3):break;
    }
}
void inserts(struct student * incouse)//ѧ����Ϣ�����Ӻ���(���ѧ����Ϣ)
{
    struct student *p0,*p1,*p2;
    p1=head2;
    p0=incouse;
    if(head2==NULL)
    {
        head2=p0;
        p0->next=NULL;
    } else
    {
        while((p0->num2 > p1->num2) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num2 <= p1->num2)
        {
            if(head2==p1) head2=p0; else p2->next=p0;
            p0->next=p1;
        } else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N2=N2+1;
}
void dels(int num2)//ѧ����Ϣ�����Ӻ�����ɾ��ѧ����Ϣ)
{
    struct student *p1,*p2;
    if(head2==NULL)
    {
        printf("\nû�и�ѧ����Ϣ,�޷�ɾ��!\n");
        goto end;
    }
    p1=head2;
    while(num2!=p1->num2 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num2==p1->num2)
    {
        if(p1==head2) head2=p1->next; else p2->next=p1->next;
        printf("��ɾ����ѧ����Ϣ!\n");
        N2=N2-1;
    } else printf("�޸�ѧ�ŵ�ѧ��!\n");
    end:;
}
void managements()//ѧ����Ϣ����������
{
    struct student * incouse;
    int i,num2;
    printf("\t\t\tѧ����Ϣ����\n");
    printf("1.����ѧ����Ϣ\n");
    printf("2.ɾ��ѧ����Ϣ\n");
    printf("3.�������˵�\n");
    printf("��ѡ��(1~3):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):
        {
            incouse=(struct student *)malloc(sizeof(struct student));
            incouse->nelen=0;
            incouse->nelenum[0]=0;
            printf("ѧ��ѧ��\tѧ������\n");
            scanf("%d%s",&incouse->num2,incouse->name2);
            inserts(incouse);
            break;
        }
        case(2):
        {
            printf("������Ҫɾ��ѧ����ѧ��:\n");
            scanf("%d",&num2);
            dels(num2);
            break;
        }
        case(3):break;
    }
}
void elect(struct student * s)//ѡ��
{
    struct couse * p;
    int num1,i;
    printf("������Ҫѡ�εı��:\n");
    scanf("%d",&num1);
    for (i=0;s->nelenum[i]!=0;i++);
    s->nelenum[i]=num1;
    (s->nelen)++;
    p=head1;
    while(p->num1!=num1) p=p->next;
    (p->nelepeo)++;
}
void cheak()//ѧ��ѡ���Ӻ���(��ѯ��ѡ�γ�)
{
    char e;
    struct couse * c;
    struct student * s;
    int num2,i,j=0,t=0;
    printf("���������ѧ��:");
    scanf("%d",&num2);
    s=head2;
    while(s->num2!=num2 && s->next!=NULL) s=s->next;
    if(s->num2!=num2)
    {
        printf("�����������Ϣ,��������˵�¼�������Ϣ!\n");
        goto end;
    }
    c=head1;
    printf("��Ŀ�ѡ�γ̱��:\n");
    while(c!=NULL)
    {
        for (t=0,i=0;s->nelenum[i]!=0;i++)
        {
            if(c->num1==s->nelenum[i]) t=1;
        }
        if(t==0 && (c->nelepeo!=c->Melepeo))
        {
            printf("%d\n",c->num1);
            j++;
        }
        c=c->next;
    }
    if(j==0)
    {
        printf("����ѡ�����пγ̣��޷��ٶ�ѡ!\n");
        goto end;
    }
    printf("ѡ��(y/n)?:\n");
    getchar();
    e=getchar();
    i=0;
    while(e=='y')
    {
        elect(s);
        printf("����ѡ��(y/n)?:\n");
        getchar();
        e=getchar();
    }
    end:;
}
void back(struct student * p)//�˿�
{
    struct couse * p1;
    int num1,i,j;
    printf("��������Ҫ�˵��Ŀγ̱��:\n");
    scanf("%d",&num1);
    p1=head1;
    while(p1->num1!=num1) p1=p1->next;
    for (i=0;p->nelenum[i]!=num1;i++);
    for (j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
    p->nelenum[--j]=0;
    (p1->nelepeo)--;
    printf("�˿γɹ�!\n");
}
void hcheak()//ѧ��ѡ���Ӻ�������ѯ��ѡ�γ�)
{
    char c;
    struct couse * p0;
    struct student * p;
    int num2,i,f=0;
    printf("������ѧ��:\n");
    scanf("%d",&num2);
    p=head2;
    while(p->num2!=num2 && p!=NULL) p=p->next;
    if(p==NULL)
    {
        printf("�����������Ϣ,������˵�¼����Ϣ:\n");
        goto end;
    }
    printf("��ѡ�γ̱��:\n");
    if(p->nelenum[0]==0)
    {
        printf("�㻹ûѡ��!\n");
        goto end;
    }
    for (i=0;p->nelenum[i]!=0;i++)
    {
        printf("%d\n",p->nelenum[i]);
        p0=head1;
        while(p0->num1!=p->nelenum[i]) p0=p0->next;
        f=f+p0->score;
    }
    printf("��ѧ��:%d\n",f);
    printf("�Ƿ�����˿�(y/n)?");
    getchar();
    c=getchar();
    while(c=='y')
    {
        back(p);
        printf("�����˿�(y/n)?");
        getchar();
        c=getchar();
        (p->nelen)--;
    }
    end:;
}
void elective()//ѧ��ѡ��������
{
    int i;
    printf("\t\t\tѧ��ѡ��\n");
    printf("1.��ѯ��ѡ�γ�\n");
    printf("2.��ѯ��ѡ�γ�\n");
    printf("3.�������˵�\n");
    printf("������(1~3):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):cheak();
        break;
        case(2):hcheak();
        break;
        case(3):break;
    }
}
void listc()//����γ���Ϣ
{
    struct couse * p;
    p=head1;
    printf("�γ̱�� �γ����� ѧ�� �γ���ѡ���� �γ���������\n");
    while(p!=NULL)
    {
        printf("%-8d%10s%6d%8d%12d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
}
void lists()//���ѧ����Ϣ
{
    struct student * p;
    p=head2;
    printf("ѧ��ѧ�� ѧ������ ��ѡ�γ�����\n");
    while(p!=NULL)
    {
        printf("%-4d %10s %6d\n",p->num2,p->name2,p->nelen);
        p=p->next;
    }
}
void intoc()//�洢�γ���Ϣ
{
    FILE * fp;
    struct couse * p;
    char filepath[30];
    printf("����γ���ϢҪ������ļ�·��:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"w"))==NULL)
    {
        printf("\n����ʧ��!");
        exit(0);
    }
    p=head1;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %d %d %d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    fclose(fp);
    printf("�γ���Ϣ�ѱ�����%s��!\n",filepath);
}
void intos()//�洢ѧ����Ϣ
{
    FILE * fp;
    struct student * p;
    char filepath[30];
    printf("����ѧ����ϢҪ������ļ�·��:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"w"))==NULL)
    {
        printf("\n����ʧ��!");
        exit(0);
    }
    p=head2;
    while(p!=NULL)
    {
        fwrite(p,sizeof(struct student),1,fp);
        p=p->next;
    }
    fclose(fp);
    printf("ѧ����Ϣ�ѱ�����%s��!\n",filepath);
}
void into()//�洢��Ϣ
{
    int i;
    printf("1.�洢�γ���Ϣ\n");
    printf("2.�洢ѧ����Ϣ\n");
    printf("3.�������˵�\n");
    printf("������(1~3)\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):intoc();
        break;
        case(2):intos();
        break;
        case(3):break;
    }
}
void store()//��Ϣ������
{
    int i;
    printf("\t\tϵͳ��Ϣ�鿴���洢\n");
    printf("1.�鿴�γ���Ϣ\n");
    printf("2.�鿴ѧ����Ϣ\n");
    printf("3.�洢��Ϣ\n");
    printf("4.�������˵�\n");
    printf("������(1~4):\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):listc();
        break;
        case(2):lists();
        break;
        case(3):into();
        break;
        case(4):break;
    }
}
int main()//������
{
    int i;
    start:
      printf("\n\t\t\t��ӭʹ��ѧ��ѡ��ϵͳ!\n");
    printf("�˵�:\n");
    printf("1.¼��γ���Ϣ\n");
    printf("2.�γ̹���\n");
    printf("3.¼��ѧ����Ϣ\n");
    printf("4.ѧ����Ϣ����\n");
    printf("5.ѧ��ѡ��\n");
    printf("6.ϵͳ��Ϣ�鿴���洢\n");
    printf("7.�˳�ϵͳ\n");
    printf("\n������˵�ѡ��(1~7):\n");
    scanf("%d",&i);
    if(i<1 || i>7)
    {
        printf("�������,������:\n");
        goto start;
    }
    switch(i)
    {
        case(1):
        {
            system("cls");
            inputc();
            goto start;
            break;
        }
        case(2):
        {
            system("cls");
            managementc();
            goto start;
            break;
        }
        case(3):
        {
            system("cls");
            inputs();
            goto start;
            break;
        }
        case(4):
        {
            system("cls");
            managements();
            goto start;
            break;
        }
        case(5):
        {
            system("cls");
            elective();
            goto start;
            break;
        }
        case(6):
        {
            system("cls");
            store();
            goto start;
            break;
        }
        case(7):
        {
            system("cls");
            printf("��лʹ�ñ�ϵͳ!\n\n�ټ�!\n");
        }
    }
    return(0);
}



