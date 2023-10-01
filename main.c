#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"main.h"


Volunteer volunteers[MAX_VOLUNTEERS];
int numVolunteers = 0;

// 显示志愿者信息
void displayVolunteers() 
{
    if (numVolunteers == 0) 
    {
        printf("没有志愿者信息。\n");
    }
    else {
        printf("---------------------志愿者信息如下：-------------------\n");
        printf("--------------------------------------------------------\n");
        printf("服务号\t姓名\t年龄\t性别\t出生日期\t职业\t电话号码\t地址\n");
        printf("--------------------------------------------------------\n");
        for (int i = 0; i < numVolunteers; i++) 
        {
            printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
                volunteers[i].serviceNumber, volunteers[i].name, volunteers[i].age, volunteers[i].gender, volunteers[i].birthDate, volunteers[i].occupation, volunteers[i].phoneNumber, volunteers[i].address);
        }
        printf("---------------------------------------------------------\n");
    }
}

// 快速排序
int _mycomp(const void *a, const void *b)
{
    Volunteer *ta = (Volunteer *)a;
    Volunteer *tb = (Volunteer *)b;
    return (ta->serviceNumber) - (tb->serviceNumber);
}
void paixu()
{
    qsort(DATA, MAX_VOLUNTEERS, sizeof(MAX_VOLUNTEERS), _mycomp);
    printf("排序完成\n");
    return 0;
}

// 志愿者录入
void addVolunteer() 
{
    if (numVolunteers == MAX_VOLUNTEERS) {
        printf("志愿者信息已达到最大限制。\n");
        return;
    }

    Volunteer volunteer;

    printf("请输入志愿者信息：\n");
    printf("服务号：");
    scanf("%d", &volunteer.serviceNumber);
    printf("姓名：");
    scanf("%s", volunteer.name);
    printf("年龄：");
    scanf("%d", &volunteer.age);
    printf("性别：");
    scanf("%s", volunteer.gender);
    printf("出生日期：");
    scanf("%s", volunteer.birthDate);
    printf("职业：");
    scanf("%s", volunteer.occupation);
    printf("电话号码：");
    scanf("%s", volunteer.phoneNumber);
    printf("地址：");
    scanf("%s", volunteer.address);

    volunteers[numVolunteers++] = volunteer;
    printf("志愿者信息录入成功。\n");
}
int searchVolunteer() 
{
    int serviceNumber;
    char name[50];
    printf("请输入要查找的志愿者姓名或服务号：");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numVolunteers; i++) 
    {
        if (strcmp(volunteers[i].name, name) == 0) 
        {
            printf("找到以下志愿者信息：\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("服务号\t姓名\t年龄\t性别\t出生日期\t职业\t电话号码\t地址\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n", 
                volunteers[i].serviceNumber, volunteers[i].name, volunteers[i].age, volunteers[i].gender, volunteers[i].birthDate, volunteers[i].occupation, volunteers[i].phoneNumber, volunteers[i].address);
            printf("---------------------------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) 
    {
        printf("未找到该志愿者信息。\n");
    }
}
void readfile()
{
    FILE *fp = fopen("志愿者信息管理系统.bat", "r");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    /*for (int i = 0;i < MAX_VOLUNTEERS;i++)
    {
        MD m;
        fread(&m.serviceNumber, sizeof(int), 1, fp);

        fread(&m.name, sizeof(char), 1, fp);

        fread(&m.age, sizeof(int), 1, fp);
   
        fread(&m.gender, sizeof(char), 1, fp);

        fread(&m.birthDate, sizeof(char), 1, fp);

        fread(&m.occupation, sizeof(char), 1, fp);

        fread(&m.phoneNumber, sizeof(char), 1, fp);
       
        fread(&m.address, sizeof(char), 1, fp);
      
        fread(m.name, sizeof(char), (m.serviceNumber - SIZE), fp);

    }*/
    fread(volunteers, sizeof(Volunteer), numVolunteers, fp);
    fclose(fp);
}
void baocunfile() 
{
    FILE *file = fopen("志愿者信息管理系统.txt", "wb");
    if (file == NULL) 
    {
        printf("文件打开失败\n");
        return;
    }

    /*for (int i = 0; i < MAX_VOLUNTEERS; i++)
    {
        
        fprintf(file, "服务号：%d\n", volunteers[i].serviceNumber);
        fprintf(file, "姓名：%s\n", volunteers[i].name);
        fprintf(file, "年龄：%d\n", volunteers[i].age);
        fprintf(file, "性别：%s\n", volunteers[i].gender);
        fprintf(file, "出生日期：%s\n", volunteers[i].birthDate);
        fprintf(file, "职业：%s\n", volunteers[i].occupation);
        fprintf(file, "电话：%s\n", volunteers[i].phoneNumber);
        fprintf(file, "地址：%s\n", volunteers[i].address);
    }*/
    fwrite(volunteers, sizeof(Volunteer), numVolunteers, file);
    fclose(file);
    
}
void ui()
{
    printf("\t\t\t------------------------------------------\t\t\t\t\t\n");
    printf("\t\t\t-----------欢迎使用志愿者管理系统---------\t\t\t\t\t\n");
    printf("\t\t\t-----------1. 显 示 志 愿 者 信 息--------\t\t\t\t\t\n");
    printf("\t\t\t-----------2. 志 愿 者 信 息 录 入--------\t\t\t\t\t\n");
    printf("\t\t\t-----------3. 志 愿 者 信 息 排 序--------\t\t\t\t\t\n");
    printf("\t\t\t-----------4. 志 愿 者 信 息 查 找--------\t\t\t\t\t\n");
    printf("\t\t\t-----------5. 志 愿 者 信 息 保 存--------\t\t\t\t\t\n");
    printf("\t\t\t-----------6. 志 愿 者 信 息 退 出--------\t\t\t\t\t\n");
    printf("\t\t\t-----------7. 安 全 退 出 本 系 统--------\t\t\t\t\t\n");
    printf("\t\t\t------------------------------------------\t\t\t\t\t\n");
    printf("\t\t\t\t请输入您的选择：\t\t\t\t\t\t\t\t\t\t\t\t\n");

}
int main()
{
    int put;
    while (1)
    {
        ui();
        scanf("%d", &put);
        switch (put)
        {
        case 1:
            displayVolunteers();
            break;
        case 2:
            addVolunteer();
            printf("\n");
            break;
        case 3:
            paixu();
            printf("志愿者信息已按姓名排序。\n");
            break;
        case 4:
            searchVolunteer();
            break;
        case 5:
            baocunfile(volunteers,100);
            printf("志愿者信息已保存\n");
            break;
        case 6:
            printf("志愿者已退出");
            break;
        case 7:
            printf("谢谢使用！\n");
            exit(0);
        default:
            printf("无效的选择。\n");
            break;
        }
    }

    return 0;
 }