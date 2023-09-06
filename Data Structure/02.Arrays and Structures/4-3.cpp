// Q. 아래의 함수를 다음과 같이 수정하고, 수정한 함수를 테스트하는 코드를 작성하라.
/* 기존 함수
int humansEqual (humanBeing person1, humanBeing person2)
{
    if(strcmp(person1.name,person2.name))
        return FALSE;
    if(person1.age != person2.age)
        retirn FALSE;
    if(person1.salary != person2.salary)
        return FALSE;
    return TRUE;
}*/
// 수정 함수 int humansEqual (humanBeing *person1, humanBeing *person2)

#include <iostream>
#include <cstring>
#include <cstdio>
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct
{
    char name[10];
    int age;
    float salary;
} humanBeing;

int humansEqual(humanBeing *person1, humanBeing *person2)
{
    if (strcmp(person1->name, person2->name))
        return FALSE;
    if (person1->age != person2->age)
        return FALSE;
    if (person1->salary != person2->salary)
        return FALSE;
    return TRUE;
}
int main()
{
    humanBeing person1, person2;

    printf("Input person1's name, age, salary : \n");
    gets(person1.name);
    scanf("%d", &person1.age);
    scanf("%f%*c", &person1.salary);
    
    printf("Input person2's name, age, salary : \n");
//  fflush(stdin); %*c 이외에도 fflush(stdin) 를 통해서 입력 버퍼에 남아 있는 \n 제거 가능
    gets(person2.name);
    scanf("%d", &person2.age);
    scanf("%f", &person2.salary);

    printf("The two human beings are %s", humansEqual(&person1,&person2) ? "the same" : "not the same");
    return 0;
}
