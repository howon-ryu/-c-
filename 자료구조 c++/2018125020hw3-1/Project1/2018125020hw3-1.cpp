#include<iostream>
#include<string>
using namespace std;

class Polynomial
{
public:
	Polynomial();
	Polynomial Add(Polynomial poly);
	Polynomial Mult(Polynomial poly);
	void NewTerm(const float theCoeff, const int theExp);
	float Eval(float f);
	Polynomial operator+(Polynomial a, Polynomial b);
private:
	Term* termArray;
	int capacity;
	int terms;
};

class Polynomial;

class Term 
{
	friend Polynomial;
public:
	float coef;
	int exp;
};


Polynomial Polynomial::Add(Polynomial b)
{
	Polynomial C;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms))
	{
		if ((termArray[aPos].exp) == b.termArray[bPos].exp)
		{
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) C.NewTerm(t, termArray[aPos].exp);
			aPos++, bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp)
		{
			C.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else 
		{
			C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	for (; aPos < terms; aPos++)
	{
		C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	}
	for (; bPos < b.terms; bPos++)
		C.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return C;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	if (terms == capacity)
	{
		capacity *= 2;
		Term* temp = new Term[capacity];
		copy(termArray, termArray + terms, temp);
		delete[]termArray;
		termArray = temp;

	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

istream& operator>>(istream& is, Polynomial& p)

{

	int a = 0;
	int coef;
	int exp;
	char input[100];
	char newinput[100];
	cin >> input;
	string fuc = input;
	reverse(fuc.begin(), fuc.end());
	fuc.erase(remove(fuc.begin(), fuc.end(), '('), fuc.end());
	fuc.erase(remove(fuc.begin(), fuc.end(), ','), fuc.end());
	fuc.erase(remove(fuc.begin(), fuc.end(), ')'), fuc.end());


	a = stoi(fuc);
	coef = a % 10;
	a = a / 10;
	exp = a % 10;
	p.NewTerm(coef, exp);
}

Polynomial operator +(Polynomial a, Polynomial b)
{
	
}

int main(void)
{
	Polynomial a, b, c, d, t;
	int x;
	cin >> a; //다항식으로 입력
	cin >> b;
	cin >> c;
	cout << "A(x) = " << a; //다항식으로 출력
	cout << "B(x) = " << b << endl << "C(x) = " << c;
	t = a * c; // *연산자 오버로딩
	d = t + c;
	cout << "T(x) = " << t;
	cout << "D(x) = " << d;
	cin >> x;
	cout << "X = " << x << "-->" << d.evalPoly(x);

}