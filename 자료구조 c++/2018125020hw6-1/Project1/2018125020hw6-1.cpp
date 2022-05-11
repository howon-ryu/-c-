
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <string>

using namespace std;

// ����� ����, node, pnode�� �����Ѵ�.   

typedef struct _node node;

typedef node* pnode;

// ����ü ��� ����, ���׽��� ����� ������ ������.

// ���׽��� ����� double������ �Ͽ���.

struct _node {

    double coef;   //���

    int expon;      //����

    pnode  next;

};



// �Ѱ��� ��带 �����Ͽ� �� ����� �ּҸ� ��ȯ�Ѵ�.

pnode createNode(double coef, int expon) {

    pnode p = (pnode)malloc(sizeof(node));

    p->coef = coef;

    p->expon = expon;

    p->next = NULL;

    return p;

}



// ��� ��ü �޸� ����.

void deleteNode(pnode* root) {

    pnode p = *root;

    pnode next;

    while (p) {

        next = p->next;

        free(p);

        p = next;

    }

    *root = NULL;

}



// ���׽Ŀ� x�� ���� �����Ͽ� �� ���� ��ȯ�Ѵ�.

double polyEval(pnode poly, double x) {

    double val = 0, v;

    pnode p = poly;

    int i;

    while (p) {

        // ����� ����

        v = p->coef;

        // x�� ���� �����Ͽ� �����ش���

        for (i = 0; i < p->expon; ++i) v = v * x;

        // ���׽��� ���� �����ش�.

        val = val + v;

        p = p->next;

    }

    return val;

}




// ���׽��� ����Ѵ�.

void polyPrint(pnode poly) {

    pnode p = poly;
    // ���׽��� ù�װ� ���������� �и��Ͽ� ó���Ѵ�.

    // ù���� + �� ������ ������ ������ ���� �ʱ� ���ؼ�

    // ���� ����� �ش�.

    // ����� 1�� ���� 1�� ������� �ʰ� x�κи� ����Ѵ�.

    if (p->expon > 1) {

        if (p->coef == 1)

            printf("x%d", p->expon);

        else if (p->coef != 0)

            printf("%gx%d", p->coef, p->expon);

    }

    else if (p->expon == 1) {

        if (p->coef == 1) printf("x");

        else printf("%gx", p->coef);

    }

    else printf("%g", p->coef);

    p = p->next;

    while (p) {

        while (p->coef == 0) {

            p = p->next;

        }

        if (p->coef > 0) printf("+");

        if (p->expon > 1) {

            if (p->coef == 1)

                printf("x%d", p->expon);

            else if (p->coef != 0)

                printf("%gx%d", p->coef, p->expon);

        }

        else if (p->expon == 1) {

            if (p->coef == 1) printf("x");

            else printf("%gx", p->coef);

        }

        else printf("%g", p->coef);

        p = p->next;

    }

    printf("\n");

}



void addNode(pnode* root, double coef, int expon) {

    pnode p = *root;
    pnode prev = NULL;

    // ��Ʈ��尡 ������ ��Ʈ��� ����.

    if (*root == NULL) {

        *root = createNode(coef, expon);

        return;

    }

    while (p) {
        if (p->expon == expon) {

            // ����� �������� ������ �����ش�.

            p->coef += coef;

            if (p->coef == 0) {

                // ������ �ƹ��͵� ���� �ʴ´�.

            }

            break;

        }

        else if (p->expon < expon) {

            // ����� ū���� �����ʿ� �����Ѵ�.

            pnode nnode = createNode(coef, expon);

            nnode->next = p;

            if (prev) prev->next = nnode;

            else *root = nnode;

            break;

        }

        if (p->next == NULL) {

            // �̰͵� ���͵� �ƴϸ� ������ ��忡 ���δ�.

            pnode nnode = createNode(coef, expon);

            p->next = nnode;
            break;

        }

        prev = p;

        p = p->next;

    }

}



// �ΰ��� ���׽��� ���Ͽ� �� ��� ���׽��� ��ȯ�Ѵ�.

pnode polyAdd(pnode poly1, pnode poly2) {

    pnode p = NULL;

    pnode p1 = poly1;

    pnode p2 = poly2;

    while (p1) {

        addNode(&p, p1->coef, p1->expon);

        p1 = p1->next;

    }

    while (p2) {

        addNode(&p, p2->coef, p2->expon);

        p2 = p2->next;

    }

    return p;

}



// �ΰ��� ���׽��� ���Ͽ� �� ��� ���׽��� ��ȯ�Ѵ�.

pnode polyMult(pnode poly1, pnode poly2) {

    pnode p = NULL;

    pnode p1 = poly1;

    pnode p2;

    while (p1) {

        p2 = poly2;

        while (p2) {

            // ���׽��� ���� : ����� �����ְ�, ������ �����ؾ� ��带 �߰��Ѵ�.

            addNode(&p, p1->coef * p2->coef, p1->expon + p2->expon);

            p2 = p2->next;

        }

        p1 = p1->next;

    }

    return p;

}



// Ű����� ���� �Է��� �޾Ƽ� ���׽��� ���� ��ȯ�Ѵ�.

pnode createPoly() {

    pnode p = NULL;

    double coef;

    int i, n, expon;

    n = 2;

    //printf("���׽��� ���� ����: ");

    //scanf("%d", &n);

    for (i = 0; i < n; ++i) {

        // ����� ������ ������ �Է��Ѵ�.

        // ������� �Է��� ���� ������ 0���� �־�� �Ѵ�.

        printf("����� ����: ");

        scanf("%lf%d", &coef, &expon);


        if (coef == '#' && expon == NULL || coef == NULL) // # �� �Է��ϸ� ����
        {
            printf("���α׷��� �����մϴ�.");
            exit(1);
        }


        addNode(&p, coef, expon);

    }

    return p;

}

/*istream& operator>>(istream& is, pnode p)

{
    //pnode p = NULL;

    int a = 0;
    double kcoef;
    int kexp;
    char input[100];
    char newinput[100];
    cin >> input;
    string fuc = input;
    reverse(fuc.begin(), fuc.end());
    fuc.erase(remove(fuc.begin(), fuc.end(), '('), fuc.end());
    fuc.erase(remove(fuc.begin(), fuc.end(), ','), fuc.end());
    fuc.erase(remove(fuc.begin(), fuc.end(), ')'), fuc.end());


    a = stoi(fuc);
    kcoef = a % 10;
    a = a / 10;
    kexp = a % 10;
    addNode(&p, kcoef, kexp);
    printf("0");
    return is;
}*/


int main() {

    pnode p1 = NULL;

    pnode p2 = NULL;

    pnode p3 = NULL;

    pnode p4 = NULL;

    pnode p5 = NULL;


    double x;

    char choice;

    // ���ѷ����� ���鼭, ���׽�1�� ���׽�2�� �Է¹޾Ƽ�

    // �Է¹��� ���׽��� ����ϰ�, x�� ���� �Է¹޾Ƽ� x�� ���� ���׽��� ���� ����Ѵ�.

    // 2���� ���׽��� ���Ѵ���, x�� ���� �Է¹޾Ƽ� x�� ���� ���׽��� ���� ����Ѵ�.

    // 2���� ���׽��� ���Ѵ���, x�� ���� �Է¹޾Ƽ� x�� ���� ���׽��� ���� ����Ѵ�.

    while (1) {

        printf("Input polynomials a\n");

        p1 = createPoly();
        //pnode p1;
        //cin >> p1;

        printf("A(x) = ");

        polyPrint(p1);

        /*printf("x=");

        scanf("%lf", &x);

        printf("P1(%g)=%g\n", x, polyEval(p1, x));*/



        printf("Input polynomials b\n");

        p2 = createPoly();

        printf("B(x) = ");

        polyPrint(p2);

        /*printf("x=");

        scanf("%lf", &x);

        printf("P2(%g)=%g\n", x, polyEval(p2, x));*/


        printf("Input polynomials c\n");

        p3 = createPoly();

        printf("C(x) = ");

        polyPrint(p3);

        /*printf("x=");

        scanf("%lf", &x);

        printf("P2(%g)=%g\n", x, polyEval(p3, x));*/








        p4 = polyMult(p1, p2);

        // ���׽� ���.

        printf("T(x) = ");

        polyPrint(p4);

        /*printf("x=");

        scanf("%lf", &x);

        printf("P7(%g)=%g\n", x, polyEval(p4, x));*/




        p5 = polyAdd(p4, p3);

        // ���׽� ���.

        printf("D(x) = ");

        polyPrint(p5);

        printf("Input x vlaue = ");

        scanf("%lf", &x);

        printf("A*B+C = %g\n", polyEval(p5, x));



        // �޸� ����.

        deleteNode(&p1);

        deleteNode(&p2);

        deleteNode(&p3);

        deleteNode(&p4);

        deleteNode(&p5);


        printf("����Ͻðڽ��ϱ�?(y/n or # ) ");

        scanf(" %c", &choice);

        if (choice != 'y') break;

    }

    return 0;

}