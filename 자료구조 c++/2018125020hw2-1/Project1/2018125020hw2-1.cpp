#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define R 1001
using namespace std;


char word[R]; // �ؽ�Ʈ���Ͽ��� ���ڸ� �޾ƿ��� �����Դϴ�.
char WordDataSet[R][R]; // ���� �����͸� ����ִ� 2���� �迭�Դϴ�.
char tword[R];
char tg[R];
int t = 0;
int r = 0;

int main() {

	FILE* f = fopen("input.txt", "r"); // ������ �б� �������� �޾��ݴϴ�. 

	if (f == NULL) printf("None file\n"); // ������ �������� ���� ��� ����ó���Դϴ�.
	int i = 0; //  ���� �����͵��� �ε����� ǥ���ϴ� �����Դϴ�.
	int k = 0;

	while (!feof(f)) {
		fscanf(f, "%s", WordDataSet[i]); // �ؽ�Ʈ���Ͽ��� ���ڿ��� �޽��ϴ�.
		int size = strlen(WordDataSet[i]); //  �ؽ�Ʈ���Ͽ� �ִ� ���ڿ��� ���̸� ���մϴ�.
		if (WordDataSet[i][0] == '!') //���� '!' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '\"')//���� '"' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '\'')//���� ''' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '.')//���� '.' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == ',')//���� ',' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '?')//���� '?' ��ȣ ����
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][size - 1] == '?') WordDataSet[i][size - 1] = NULL; //  ���� '?' ��ȣ ����
		if (WordDataSet[i][size - 1] == '.') WordDataSet[i][size - 1] = NULL;//  ���� '.' ��ȣ ����
		if (WordDataSet[i][size - 1] == ',') WordDataSet[i][size - 1] = NULL;//  ���� ',' ��ȣ ����
		if (WordDataSet[i][size - 1] == '!') WordDataSet[i][size - 1] = NULL;//  ���� '!' ��ȣ ����
		if (WordDataSet[i][size - 1] == '\'') WordDataSet[i][size - 1] = NULL;//  ���� ''' ��ȣ ����
		if (WordDataSet[i][size - 1] == '\"') WordDataSet[i][size - 1] = NULL;//  ���� '"' ��ȣ ����
		i++;
	}
	
	

	for (int i = 0; strlen(WordDataSet[i])>1; i++) // ���������� �̿��� �ܾ� �迭
	{
		for (int y = i+1; strlen(WordDataSet[y])>1; y++)
		{
			if (strcmp(WordDataSet[i], WordDataSet[y]) == 0)// �ܾ� ����Ʈ�� �ߺ��Ǵ� �ܾ� ����
			{
				strcpy(WordDataSet[i], WordDataSet[R]);
				for (int jj = i; WordDataSet[jj] != WordDataSet[R]; jj++)
				{
					strcpy(WordDataSet[jj], WordDataSet[jj+1]);

				}
				t = t + 1;
			}
			if (strcmp(WordDataSet[i], WordDataSet[y]) > 0) // ������ ���� �迭 ��ü
			{

				strcpy(tword, WordDataSet[i]);
				strcpy(WordDataSet[i], WordDataSet[y]);
				strcpy(WordDataSet[y], tword);
			}

			
		}


	}
	i = i-t;
	for (int j = 0; j<i; j++) { // ����� ���ڿ��� ����մϴ�.

		printf("%d. %s\n", j+1,WordDataSet[j]);
		r = j;
	}
	for (int u = 0; u < 3; u++)
	{
		cout << "ã�� �ܾ �Է��ϼ��� : ";
		cin >> tg; //  �˻��� �ܾ� ����
		int start = 0;
		int end = r;
		int mid;
		int va = 0;// while �� �ۿ� �ִ� printf("-1\n"); �� ���� ��Ű�� �ʱ� ���ؼ�

		while (end - start >= 0) // �̿�Ž���� �̿��� �ܾ� ���� �˻�
		{
			va = 0; 
			mid = (start + end) / 2;

			if (strcmp(WordDataSet[mid], tg) == 0) // �ܾ ã������ �迭 ���� ���
			{
				printf("%d\n", mid + 1);
				va = 1;
				break;

			}
			else if (strcmp(WordDataSet[mid], tg) > 0)
			{
				end = mid - 1;
			}
			else if (strcmp(WordDataSet[mid], tg) < 0)
			{
				start = mid + 1;
			}
			else
				return -1;
		}
		if (va == 0)
		{
			printf("-1\n");
		}



	}
}

