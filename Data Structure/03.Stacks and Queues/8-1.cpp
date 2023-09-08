// Q. infix 표기로 표현된 수식을 파일로 입력받아 postfix 표기로 변환해서 화면에 출력하는 코드를 작성하라.

#include <iostream>
#include <cstdio>

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

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = 0;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};  // incoming precedence
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0}; // in-stack precedence
// lparen, rparen, plus, minus, times, divide, mod, eos

precedence getToken(char *symbol, int *n)
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

void push(precedence token)
{
    stack[++top] = token;
}

precedence pop()
{
    return stack[top--];
}

void printToken(precedence token)
{
    switch (token)
    {
    case lparen:
        printf("( ");
        break;
    case rparen:
        printf(") ");
        break;
    case PLUS:
        printf("+ ");
        break;
    case MINUS:
        printf("- ");
        break;
    case divide:
        printf("/ ");
        break;
    case times:
        printf("* ");
        break;
    case mod:
        printf("% ");
        break;
    case eos:
        printf("\0");
        break;
    }
}
void postfix()
{
    char symbol;
    precedence token;
    int n = 0;
    stack[0] = eos;

    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
    {
        if (token == operand)
            printf("%c ", symbol);
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

    return 0;
}

// EX) Input: e/(f+a*d)+c , Output : e f a d * + / c + 
