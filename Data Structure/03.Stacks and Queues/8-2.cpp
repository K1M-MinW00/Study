// Q. 8-1.cpp 에서 postfix 표기의 수식을 계산하는 코드를 추가하고, infix 표기의 수식을 입력받아 그 계산 결과를 화면에 출력하는 코드를 작성하라.
// 연산자 : +, -, *, /, %
// 피연산자 : 1 ~ 9 사이의 한 자리 정수
// divde by zero 에 대한 테스트 및 처리는 구현 X

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum
{
    lparen,
    rparen,
    PLUS,
    MINUS,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
char s[MAX_EXPR_SIZE];
int top = 0, i = 0;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};  // incoming precedence
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0}; // in-stack precedence
// lparen, rparen, plus, minus, times, divide, mod, eos

precedence getToken(char *symbol, int *n, char expr[])
{
    *symbol = expr[(*n)++];

    switch (*symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return PLUS;
    case '-':
        return MINUS;
    case '/':
        return divide;
    case '*':
        return times;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

void push(int token)
{
    stack[++top] = token;
}

precedence pop()
{
    return static_cast<precedence>(stack[top--]);
}

void printToken(precedence token)
{
    switch (token)
    {
    case lparen:
        break;
    case rparen:
        break;
    case PLUS:
        printf("+ ");
        s[i++] = '+';
        break;
    case MINUS:
        printf("- ");
        s[i++] = '-';
        break;
    case divide:
        printf("/ ");
        s[i++] = '/';
        break;
    case times:
        printf("* ");
        s[i++] = '*';
        break;
    case mod:
        printf("%% ");
        s[i++] = '%';
        break;
    case eos:
        break;
    }
}

int eval()
{

    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    int top = -1;
    token = getToken(&symbol, &n, s);
    while (token != eos)
    {
        if (token == operand)
            push(symbol - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (token)
            {
            case PLUS:
                push(op1 + op2);
                break;
            case MINUS:
                push(op1 - op2);
                break;
            case times:
                push(op1 * op2);
                break;
            case divide:
                push(op1 / op2);
                break;
            case mod:
                push(op1 % op2);
            }
        }
        token = getToken(&symbol, &n, s);
    }
    return pop();
}
void postfix()
{
    char symbol;
    precedence token;
    int n = 0;
    stack[0] = eos;

    for (token = getToken(&symbol, &n, expr); token != eos; token = getToken(&symbol, &n, expr))
    {
        if (token == operand)
        {
            printf("%c ", symbol);
            s[i++] = symbol;
        }
        else if (token == rparen)
        {
            while (stack[top] != lparen)
                printToken(pop());
            pop(); // lparen 을 pop
        }
        else
        {
            // isp 가 현재 토큰의 icp 보다 크거나 같은 기호를 제거하고 출력
            while (isp[stack[top]] >= icp[token])
                printToken(pop());
            push(token);
        }
    }
    while ((token = pop()) != eos)
        printToken(token);
}

int main()
{
    scanf("%s", &expr);
    postfix();
    printf("\nResult : %d", eval());
    return 0;
}
// EX) Input : 6/2-3+4*2 , Output : 6 2 / 3 - 4 2 * + , Result : 8
// Ex) Input : ((1*2)+1-2)*(3%2) , Output : 1 2 * 1 + 2 - 3 2 % * , Result : 1
