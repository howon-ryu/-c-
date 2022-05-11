#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<string>

using namespace std;
char a;
//char�� ���� element�� �ڷ������� ���� 
typedef char element;

typedef struct stackNode {
    element data;
    struct stackNode* link;
}stackNode;

stackNode* top;

//���� ����Ʈ ������ ���� ���� 
void push(element item)
{
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

//���� ����Ʈ ������ ���� �� ��ȯ ���� 
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

//���� ����Ʈ ������ top ���� �˻� ���� 
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

//���� ����Ʈ ������ ���� ���� 
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

//���� ����Ʈ ������ ���� ��� ���� 
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

//������ ��ȣ�� �˻��ϴ� ���� 
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
            printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�!");
        }
        else
        {
            printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
            cout << "error : " << xpress << '\n';
            cout << "�������� : " << a;
        }
        getchar();
    }
}