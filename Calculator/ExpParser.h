#ifndef EXP_PARSER_H
#define EXP_PARSER_H

#include<string.h>
#include<math.h>

#define MAXSIZE 1024
#define ERROR -1;
#define OK    1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct {
	double data[MAXSIZE];
	int top;
} Stack;

Status InitStack(Stack * s);
Status Push(Stack * s, double e);
Status Pop(Stack * s, double *e);
Status IsEmpty(Stack * s);
int GetFix(char *infix);
int Rank(char sign);
int IsNum(char c);
int IsSign(char c);
int IsKuo(char c);
Status isInvalid(char* infix);
double cal(double a, double b, double sign);
void insertChar(char *str, char ch, int index);
void handleMinus(char* str);
Status CheckFix(char *infix, int n);
void ToPostfix(char *infix, int n, Stack * postfix);
double ToNum(Stack * postfix, Stack * num);

#endif