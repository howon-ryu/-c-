#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define R 1001
using namespace std;


char word[R]; // 텍스트파일에서 문자를 받아오는 변수입니다.
char WordDataSet[R][R]; // 받은 데이터를 담고있는 2차원 배열입니다.
char tword[R];
char tg[R];
int t = 0;
int r = 0;

int main() {

	FILE* f = fopen("input.txt", "r"); // 파일을 읽기 형식으로 받아줍니다. 

	if (f == NULL) printf("None file\n"); // 파일이 존재하지 않을 경우 예외처리입니다.
	int i = 0; //  받은 데이터들의 인덱스를 표시하는 변수입니다.
	int k = 0;

	while (!feof(f)) {
		fscanf(f, "%s", WordDataSet[i]); // 텍스트파일에서 문자열을 받습니다.
		int size = strlen(WordDataSet[i]); //  텍스트파일에 있는 문자열의 길이를 구합니다.
		if (WordDataSet[i][0] == '!') //앞의 '!' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '\"')//앞의 '"' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '\'')//앞의 ''' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '.')//앞의 '.' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == ',')//앞의 ',' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][0] == '?')//앞의 '?' 기호 제거
		{
			WordDataSet[i][0] = ' ';
			for (int p = 0; WordDataSet[i][p] != '\0'; p++)
			{
				WordDataSet[i][p] = WordDataSet[i][p + 1];
			}
		}
		if (WordDataSet[i][size - 1] == '?') WordDataSet[i][size - 1] = NULL; //  뒤의 '?' 기호 제거
		if (WordDataSet[i][size - 1] == '.') WordDataSet[i][size - 1] = NULL;//  뒤의 '.' 기호 제거
		if (WordDataSet[i][size - 1] == ',') WordDataSet[i][size - 1] = NULL;//  뒤의 ',' 기호 제거
		if (WordDataSet[i][size - 1] == '!') WordDataSet[i][size - 1] = NULL;//  뒤의 '!' 기호 제거
		if (WordDataSet[i][size - 1] == '\'') WordDataSet[i][size - 1] = NULL;//  뒤의 ''' 기호 제거
		if (WordDataSet[i][size - 1] == '\"') WordDataSet[i][size - 1] = NULL;//  뒤의 '"' 기호 제거
		i++;
	}
	
	

	for (int i = 0; strlen(WordDataSet[i])>1; i++) // 선택정렬을 이용한 단어 배열
	{
		for (int y = i+1; strlen(WordDataSet[y])>1; y++)
		{
			if (strcmp(WordDataSet[i], WordDataSet[y]) == 0)// 단어 리스트중 중복되는 단어 제거
			{
				strcpy(WordDataSet[i], WordDataSet[R]);
				for (int jj = i; WordDataSet[jj] != WordDataSet[R]; jj++)
				{
					strcpy(WordDataSet[jj], WordDataSet[jj+1]);

				}
				t = t + 1;
			}
			if (strcmp(WordDataSet[i], WordDataSet[y]) > 0) // 정렬을 위한 배열 교체
			{

				strcpy(tword, WordDataSet[i]);
				strcpy(WordDataSet[i], WordDataSet[y]);
				strcpy(WordDataSet[y], tword);
			}

			
		}


	}
	i = i-t;
	for (int j = 0; j<i; j++) { // 저장된 문자열을 출력합니다.

		printf("%d. %s\n", j+1,WordDataSet[j]);
		r = j;
	}
	for (int u = 0; u < 3; u++)
	{
		cout << "찾을 단어를 입력하세요 : ";
		cin >> tg; //  검색할 단어 저장
		int start = 0;
		int end = r;
		int mid;
		int va = 0;// while 문 밖에 있는 printf("-1\n"); 를 실행 시키지 않기 위해서

		while (end - start >= 0) // 이원탐색을 이용한 단어 순서 검색
		{
			va = 0; 
			mid = (start + end) / 2;

			if (strcmp(WordDataSet[mid], tg) == 0) // 단어를 찾았으면 배열 순번 출력
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

