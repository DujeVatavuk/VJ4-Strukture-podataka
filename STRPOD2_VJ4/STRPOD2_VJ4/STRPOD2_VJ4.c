//Binarno stablo pretrazivanja napunit sa 20 random brojeva od 50 do 90 i ispisati na sva 3 nacina, naravno podrazumjeva se da se brojevi ne smiju ponavljati
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//ovo rijesavamo tako sta punimo niz sa 20 rand brojeva i onda taj niz u stablo
typedef struct binStablo *node;
typedef struct binStablo
{
	int el;
	node left;
	node right;
}binStablo;

int random(int, int[]);
node unos(int, node);
void print1(node);
void print2(node);
void print3(node);

int main()
{
	srand(time(NULL));
	node stablo = NULL;
	int brojevi[20];

	for (int i = 0; i < 20; i++)
	{
		brojevi[i] = random(i, brojevi);
	}

	for (int i = 0; i < 20; i++)
	{
		stablo = unos(brojevi[i], stablo);
	}
	printf("\n");
	print1(stablo);
	printf("\n");
	print2(stablo);
	printf("\n");
	print3(stablo);
	printf("\n");
	getch();
	return 0;
}

int random(int brojac, int brojevi[])
{
	int R;
	int check = 0;
	do
	{
		check = 0;
		R = rand() % 40 + 50;
		for (int i = 0; i < brojac; i++)
		{
			if (brojevi[i] == R)
			{
				check = 1;
				break;
			}
		}
	} while (1 == check);
	return R;
}

node unos(int x, node S)
{
	if (NULL == S)
	{
		S = (node)malloc(sizeof(binStablo));
		S->left = NULL;
		S->right = NULL;
		S->el = x;
	}
	else if (x > S->el)
	{
		S->right = unos(x, S->right);
	}
	else if (x < S->el)
	{
		S->left = unos(x, S->left);
	}
	return S;
}

void print1(node S)
{
	if (NULL != S)
	{
		printf(" %d", S->el);
		print1(S->left);
		print1(S->right);
	}
}

void print2(node S)
{
	if (NULL != S)
	{
		print2(S->left);
		printf(" %d", S->el);
		print2(S->right);
	}
}

void print3(node S)
{
	if (NULL != S)
	{
		print3(S->left);
		print3(S->right);
		printf(" %d", S->el);
	}
}

