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
struct student* head;
int Input()
{
    struct student* p, * pr;
    int i = 0;
    printf("在姓名处输入“ok”代表结束\n");
    do {
        p = (struct student*)malloc(sizeof(struct student));
        if (p != NULL)
        {
            i++;
            printf("输入学生的信息\n");
            printf("enter name:");
            scanf("%s", p->name);
            if (strcmp(p->name, "ok") == 0)
            {
                printf("输入完毕\n");
                pr = p;
                pr->next = NULL;
                return i;
                exit(0);
            }
            printf("enter studentID:");
            scanf("%s", p->studentID);
            printf("enter gender:");
            scanf("%s", p->gender);
            printf("enter tellphone:");
            scanf("%s", p->tellphone);
            printf("enter NativePlace:");
            scanf("%s", p->NativePlace);
            if (i == 1)
            {
                head = p;
                pr = p;
            }
            pr->next = p;
            pr = p;
        }
    } while (i > 0);
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
            p = p->next;
        }
        printf("保存成功");
        printf("：：：：：：：：：：：：：：：：：：：：：：：：：");
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
