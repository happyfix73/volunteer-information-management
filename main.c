#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"main.h"


Volunteer volunteers[MAX_VOLUNTEERS];
int numVolunteers = 0;

// ��ʾ־Ը����Ϣ
void displayVolunteers() 
{
    if (numVolunteers == 0) 
    {
        printf("û��־Ը����Ϣ��\n");
    }
    else {
        printf("---------------------־Ը����Ϣ���£�-------------------\n");
        printf("--------------------------------------------------------\n");
        printf("�����\t����\t����\t�Ա�\t��������\tְҵ\t�绰����\t��ַ\n");
        printf("--------------------------------------------------------\n");
        for (int i = 0; i < numVolunteers; i++) 
        {
            printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
                volunteers[i].serviceNumber, volunteers[i].name, volunteers[i].age, volunteers[i].gender, volunteers[i].birthDate, volunteers[i].occupation, volunteers[i].phoneNumber, volunteers[i].address);
        }
        printf("---------------------------------------------------------\n");
    }
}

// ��������
int _mycomp(const void *a, const void *b)
{
    Volunteer *ta = (Volunteer *)a;
    Volunteer *tb = (Volunteer *)b;
    return (ta->serviceNumber) - (tb->serviceNumber);
}
void paixu()
{
    qsort(DATA, MAX_VOLUNTEERS, sizeof(MAX_VOLUNTEERS), _mycomp);
    printf("�������\n");
    return 0;
}

// ־Ը��¼��
void addVolunteer() 
{
    if (numVolunteers == MAX_VOLUNTEERS) {
        printf("־Ը����Ϣ�Ѵﵽ������ơ�\n");
        return;
    }

    Volunteer volunteer;

    printf("������־Ը����Ϣ��\n");
    printf("����ţ�");
    scanf("%d", &volunteer.serviceNumber);
    printf("������");
    scanf("%s", volunteer.name);
    printf("���䣺");
    scanf("%d", &volunteer.age);
    printf("�Ա�");
    scanf("%s", volunteer.gender);
    printf("�������ڣ�");
    scanf("%s", volunteer.birthDate);
    printf("ְҵ��");
    scanf("%s", volunteer.occupation);
    printf("�绰���룺");
    scanf("%s", volunteer.phoneNumber);
    printf("��ַ��");
    scanf("%s", volunteer.address);

    volunteers[numVolunteers++] = volunteer;
    printf("־Ը����Ϣ¼��ɹ���\n");
}
int searchVolunteer() 
{
    int serviceNumber;
    char name[50];
    printf("������Ҫ���ҵ�־Ը�����������ţ�");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numVolunteers; i++) 
    {
        if (strcmp(volunteers[i].name, name) == 0) 
        {
            printf("�ҵ�����־Ը����Ϣ��\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("�����\t����\t����\t�Ա�\t��������\tְҵ\t�绰����\t��ַ\n");
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
        printf("δ�ҵ���־Ը����Ϣ��\n");
    }
}
void readfile()
{
    FILE *fp = fopen("־Ը����Ϣ����ϵͳ.bat", "r");
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
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
    FILE *file = fopen("־Ը����Ϣ����ϵͳ.txt", "wb");
    if (file == NULL) 
    {
        printf("�ļ���ʧ��\n");
        return;
    }

    /*for (int i = 0; i < MAX_VOLUNTEERS; i++)
    {
        
        fprintf(file, "����ţ�%d\n", volunteers[i].serviceNumber);
        fprintf(file, "������%s\n", volunteers[i].name);
        fprintf(file, "���䣺%d\n", volunteers[i].age);
        fprintf(file, "�Ա�%s\n", volunteers[i].gender);
        fprintf(file, "�������ڣ�%s\n", volunteers[i].birthDate);
        fprintf(file, "ְҵ��%s\n", volunteers[i].occupation);
        fprintf(file, "�绰��%s\n", volunteers[i].phoneNumber);
        fprintf(file, "��ַ��%s\n", volunteers[i].address);
    }*/
    fwrite(volunteers, sizeof(Volunteer), numVolunteers, file);
    fclose(file);
    
}
void ui()
{
    printf("\t\t\t------------------------------------------\t\t\t\t\t\n");
    printf("\t\t\t-----------��ӭʹ��־Ը�߹���ϵͳ---------\t\t\t\t\t\n");
    printf("\t\t\t-----------1. �� ʾ ־ Ը �� �� Ϣ--------\t\t\t\t\t\n");
    printf("\t\t\t-----------2. ־ Ը �� �� Ϣ ¼ ��--------\t\t\t\t\t\n");
    printf("\t\t\t-----------3. ־ Ը �� �� Ϣ �� ��--------\t\t\t\t\t\n");
    printf("\t\t\t-----------4. ־ Ը �� �� Ϣ �� ��--------\t\t\t\t\t\n");
    printf("\t\t\t-----------5. ־ Ը �� �� Ϣ �� ��--------\t\t\t\t\t\n");
    printf("\t\t\t-----------6. ־ Ը �� �� Ϣ �� ��--------\t\t\t\t\t\n");
    printf("\t\t\t-----------7. �� ȫ �� �� �� ϵ ͳ--------\t\t\t\t\t\n");
    printf("\t\t\t------------------------------------------\t\t\t\t\t\n");
    printf("\t\t\t\t����������ѡ��\t\t\t\t\t\t\t\t\t\t\t\t\n");

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
            printf("־Ը����Ϣ�Ѱ���������\n");
            break;
        case 4:
            searchVolunteer();
            break;
        case 5:
            baocunfile(volunteers,100);
            printf("־Ը����Ϣ�ѱ���\n");
            break;
        case 6:
            printf("־Ը�����˳�");
            break;
        case 7:
            printf("ллʹ�ã�\n");
            exit(0);
        default:
            printf("��Ч��ѡ��\n");
            break;
        }
    }

    return 0;
 }