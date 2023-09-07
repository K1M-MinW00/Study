// Q. 동적 Array 를 사용해서 Stack 을 구현하라.
// push, pop, stackEmpty, stackFull 함수를 구현한다.
// 데이터 입력 형식은 'I x' 또는 'D' 로 구성된다. ('F' 인 경우 입력 종료)
// 'I x' 일 때는 stack 에 x를 푸쉬하고 , 'D' 이면 stack 에서 원소를 pop 한다.
// push/pop 을 모두 수행 후 최종 stack의 상태를 bottom 부터 top 까지 차례대로 출력한다.
// stack 이 empty 인 상태에서 pop 을 수행하면 'stack empty' message 를 출력하고 수행을 계속한다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct
{
    int key;
} element;

element *stack;
int cap = 1;
int top = -1;

element stackEmpty()
{
    printf("Stack Empty\n");
    
}

void stackFull()
{
    realloc(stack, 2 * cap * sizeof(*stack));
    cap *= 2;
}

element pop()
{
    if (top == -1)
        return stackEmpty();
    return stack[top--];
}

void push(element item)
{
    if (top >= cap - 1)
        stackFull();
    stack[++top] = item;
}
int main()
{
    stack = (element*)malloc(sizeof(element));

    char op;
    element item;

    while (1)
    {
        scanf("%c", &op);
        if (op == 'F')
            break;
        else if (op == 'D')
            pop();
        else if (op == 'I')
        {
            scanf("%d", &item.key);
            push(item);
        }
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
// Ex) Input : I 0 I 2 I 9 D D I 5 F , Output : 0 5
// Ex) Input : D I 2 I 9 I 5 I 7 D D I 8 F , Output : Stack Empty 2 9 8
