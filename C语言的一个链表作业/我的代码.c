#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student {
    char name[20];
    char studentID[50];
    char gender[10];
    char tellphone[50];
    char NativePlace[100];
    struct student* next;
};
//不立即初始化的指针，最好先赋值为NULL
struct student* head=NULL;
int Input()
{
    //pCurrent当前元素指针，pPrev“上一个元素”指针
    struct student* pCurrent=NULL, * pPrev = NULL;
    int i = 0;
    printf("在姓名处输入“ok”代表结束\n");
    while(1)
    {
        //因为这里输入的name并不一定是名字，因此弄一个单独的变量name，让代码更清晰
        //不至于和 pCurrent = (struct student*)malloc(sizeof(struct student))代码混在一起
        char name[20] = { 0 };
        printf("输入学生的信息\n");
        printf("enter name:");
        scanf("%s", name);
        if (strcmp(name, "ok") == 0)
        {
            printf("输入完毕\n");
            return i;
        }
        //在把pCurrent指向这个新节点之前，把pCurrent赋值给pPrev
        pPrev = pCurrent;
        pCurrent = (struct student*)malloc(sizeof(struct student));
        //把异常情况提前处理，提前退出，避免太深的{}嵌套
        if (pCurrent == NULL)
        {
            printf("内存不足！");
            exit(0);
            return i;
        }
        strcpy(pCurrent->name, name);
        printf("enter studentID:");
        scanf("%s", pCurrent->studentID);
        printf("enter gender:");
        scanf("%s", pCurrent->gender);
        printf("enter tellphone:");
        scanf("%s", pCurrent->tellphone);
        printf("enter NativePlace:");
        scanf("%s", pCurrent->NativePlace);
        //现在还不知道当前节点的下一个节点是什么呢，所以先提前next=NULL，
        //打好“预防针”，而且后面不用再惦记它了
        pCurrent->next = NULL;
        //如果是第一个节点
        if (i == 0)
        {
            //让head指向第一个节点
            head = pCurrent;
            pPrev=NULL;//不要搞“特殊化”，第一个节点就是没有hPrev，因此就赋值为NULL
        }
        else
        {
            //上“上一个节点的next”等于当前节点
            pPrev->next = pCurrent;
        }
        i++;
    }
}

void save(struct student* p)
{
    FILE* fp;
    char file[15];
    printf("保存数据\n");
    printf("输入文件名");
    scanf("%s", file);
    if ((fp = fopen(file, "w")) == NULL)
    {
        printf("cannot open this file");
        exit(0);
    }
    fprintf(fp, "姓名\t学号\t性别\t电话\t籍贯\n");
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->name);
        fprintf(fp, "%s\t", p->studentID);
        fprintf(fp, "%s\t", p->gender);
        fprintf(fp, "%s\t", p->tellphone);
        fprintf(fp, "%s\t", p->NativePlace);
        fprintf(fp, "%\n");//换行
        p = p->next;
    }
    printf("保存成功");
    fclose(fp);
}
int main()
{
    int i, n;
    char name[20];
    while (1)
    {
        printf("\t\t\t\t*********************************************\n");
        printf("\t\t\t\t1，输入学生的信息：\n");
        printf("\t\t\t\t2,保存文件\n");
        printf("\t\t\t\t输入你的选择：\n");
        printf("\t\t\t\t**********************************************\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            n = Input();
            break;
        case 2:
            save(head);
            break;
        }
    }
}
