// Q. Sequential Search 알고리즘, Iteartive Binary Search 알고리즘 , Recursive Binary Search 알고리즘을 차례로 작성한다.
// 각 알고리즘 마다 검색에 성공이면 'S' , 실패면 'F' 를 출력하는 코드를 작성하라.
// list.txt 에는 사전순으로 정렬된 영어 단어들이 있으며, 알파벳 소문자 3개로 구성되어 있다.
// 데이터의 개수는 주어지지 않음 (feof 함수 사용)
// 파일의 각 단어를 2차원 array 에 저장한 뒤, array의 내용에 대해 search algorithm 을 수행한다.
// 검색 단어 입력은 scanf 함수를 사용한다.

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char SeqSearch(char arr[][4],int n, char find[])
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(find,arr[i])==0) // strcmp(str1,str2) , 문자열이 일치하면 0 을, str1 이 str2 보다 크다면 0 보다 큰 값을, 그렇지 않다면 0 보다 작은 값을 리턴 
        {
            return 'S';
        }
    }
    return 'F';
}

char IterBinSearch(char arr[][4],char find[], int left,int right)
{
    int mid, cmp;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cmp = strcmp(arr[mid],find);
        if(cmp==0)
        {
            return 'S';
        }
        else if(cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 'F';
}

char RecurBinSearch(char arr[][4],char find[], int left,int right)
{
    int mid,cmp;

    if (left <= right)
    {
        mid = (left + right) / 2;
        cmp = strcmp(arr[mid],find);
        if(cmp==0)
        {
            return 'S';
        }
        else if(cmp < 0)
        {
            return RecurBinSearch(arr,find,mid+1,right);
        }
        else
        {
            return RecurBinSearch(arr,find,left,mid-1);
        }
    }
    return 'F';
}

int main()
{
    FILE *fp;
    char fname[50];
    cin >> fname;

    fp = fopen(fname,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"file open fail\n");
        exit(1);
    }

    int n;
    char arr[100][4];

    while(!feof(fp)) // feof(FILE* stream) , 파일 끝 지시자가 설정되어 있다면 0을, 그렇지 않다면 1을 리턴
    {
        n++;
        fscanf(fp,"%s",arr[n++]);    
    }
    fclose(fp);
    char find[4];
    scanf("%s",find);

    printf("Sequential search result : %c\n",SeqSearch(arr,n,find));
    printf("Iterative binary search result : %c\n",IterBinSearch(arr,find,0,n-1));
    printf("Recursive binary search result : %c\n",RecurBinSearch(arr,find,0,n-1));

    return 0;
}

// Ex) Input :dab , File Data : abc abd baa bcd caa dab , Output : S S S
// Ex) Input :dab , File Data : abc abd baa bcd caa bbz , Output : F F F
