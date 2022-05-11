#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<string>

using namespace std;
char a;
//char을 스택 element의 자료형으로 정의 
typedef char element;

typedef struct stackNode {
    element data;
    struct stackNode* link;
}stackNode;

stackNode* top;

//연결 리스트 스택의 삽입 연산 
void push(element item)
{
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

//연결 리스트 스택의 삭제 후 반환 연산 
element pop()
{
    element item;
    stackNode* temp = top;

    if (top == NULL) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

//연결 리스트 스택의 top 원소 검색 연산 
element peek()
{
    element item;

    if (top == NULL) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {
        item = top->data;
        return item;
    }
}

//연결 리스트 스택의 삭제 연산 
void del()
{
    stackNode* temp;

    if (top == NULL) {
        printf("\n\n Stack is empty !\n");
    }
    else {
        temp = top;
        top = top->link;
        free(temp);
    }
}

//연결 리스트 스택의 내용 출력 연산 
void printStack()
{
    stackNode* p = top;

    printf("\n STACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}

//수식의 괄호를 검사하는 연산 
int testPair(const char* exp)
{
    char symbol, open_pair;
    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++)
    {
        symbol = exp[i];
        switch (symbol) {
        case '(':
        case '[':
        case '{':
            push(symbol); break;
        case ')':
        case ']':
        case '}':
            if (top == NULL) return 0;
            else {
                open_pair = pop();
                a = open_pair;
                if ((open_pair == '(' && symbol != ')') ||
                    (open_pair == '[' && symbol != ']') ||
                    (open_pair == '{' && symbol != '}'))
                    return 0;
                else break;
            }
        }
    }
    if (top == NULL) return 1;
    else return 0;
}

int main(void)
{
    for (int i = 0; i < 2; i++)
    {
        string express;
        getline(cin, express, '#');
        char xpress[80];
        strcpy(xpress, express.c_str());

        if (testPair(xpress) == 1)
        {
            printf("\n\n 수식의 괄호가 맞게 사용되었습니다!");
        }
        else
        {
            printf("\n\n 수식의 괄호가 틀렸습니다!\n");
            cout << "error : " << xpress << '\n';
            cout << "오류시점 : " << a;
        }
        getchar();
    }
}