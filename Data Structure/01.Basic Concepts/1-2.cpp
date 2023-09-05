// Q. 1-1 문제에서 입력 데이터는 파일로 처리한다.

#include <iostream>
using namespace std;

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
    fscanf(fp,"%d",&n);

    int min = 999, num;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&num);
        if(num < min)
        {
            min = num;
        }
    }

    fclose(fp);

    cout << min ;
    return 0;
}

// Ex) Input : (File name), File Data : 5 -1 0 3 100 , Output : -1
