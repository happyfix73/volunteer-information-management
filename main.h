
#define MAX_NAME_LENGTH 50
#define MAX_VOLUNTEERS 1000000
#define SIZE 12

// 定义志愿者结构体
typedef struct 
{
    int serviceNumber;
    char name[50];
    int age;
    char gender[10];
    char birthDate[20];
    char occupation[50];
    char phoneNumber[20];
    char address[100];
} Volunteer;
Volunteer DATA[MAX_VOLUNTEERS];
typedef struct 
{
    int serviceNumber;
    char name[50];
    int age;
    char gender[10];
    char birthDate[20];
    char occupation[50];
    char phoneNumber[20];
    char address[100];
}MD, *PMD;
