#include "ExpParser.h"
#include <string>
char infix[1024];

// ��ʼ��ջ
Status InitStack(Stack * s) {
	s->top = -1;
	return OK;
}
// ��ջ
Status Push(Stack * s, double e) {
	if (s->top == MAXSIZE - 1) {
		return ERROR;
	}
	s->top++;
	s->data[s->top] = e;
	return OK;
}
// ��ջ
Status Pop(Stack * s, double *e) {
	if (s->top == -1) {
		return ERROR;
	}
	*e = s->data[s->top];
	s->top--;
	return OK;
}
// �ж��Ƿ�Ϊ��
Status IsEmpty(Stack * s) {
	if (s->top == -1) {
		return TRUE;
	}
	return FALSE;
}

// ������ʽ
int GetFix(char *infix) {
	handleMinus(infix);
	return strlen(infix);
}

// �жϷ��ŵȼ�
int Rank(char sign) {
	if (sign == '+' || sign == '-') {
		return 1;
	}
	else if (sign == '*' || sign == '/') {
		return 2;
	}
	else if (sign == '%') {
		return 3;
	}
	else if (sign == '^') {
		return 4;
	}

	return 0;
}
// �ж��Ƿ�Ϊ����
int IsNum(char c) {
	if (c >= '0' && c <= '9') {
		return TRUE;
	}
	else if (c == '.') {
		return TRUE;
	}

	return FALSE;
}
// �ж��Ƿ�Ϊ����
int IsSign(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
		return TRUE;
	}

	return FALSE;
}
// �ж��Ƿ�Ϊ����
int IsKuo(char c) {
	if (c == '(' || c == ')') {
		return TRUE;
	}

	return FALSE;
}
// ���Ƿ��ַ�
Status isInvalid(char* infix) {
	int n = strlen(infix);
	for (int i = 0; i < n; i++) {
		if (!IsNum(infix[i]) && !IsSign(infix[i]) && !IsKuo(infix[i])) {
			return FALSE;
		}
	}
	return TRUE;
}

// ���ݷ��ż���
double cal(double a, double b, double sign) {
	if (sign == '+') {
		return a + b;
	}
	else if (sign == '-') {
		return a - b;
	}
	else if (sign == '*') {
		return a * b;
	}
	else if (sign == '/') {
		return a / b;
	}
	else {
		int aa = a, bb = b;
		if (sign == '%') {
			return aa % bb;
		}
		else if (sign == '^') {
			return pow(aa, bb);
		}
	}
	return ERROR;
}
//����һ���ַ���indexλ��
void insertChar(char *str, char ch, int index) {
	int len = strlen(str);
	if (len == 0 || index > len) {
		return;
	}
	for (int j = len; j >= index; j--) {
		str[j + 1] = str[j];
	}
	str[index] = ch;
}
//������
void handleMinus(char* str) {
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		//ǰ��������������Ǹ���
		if (str[i] == '-' && (IsSign(str[i - 1]) || i == 0)) {
			insertChar(str, '0', i);
			insertChar(str, '(', i);
			n += 2;
			int j = i + 2;
			while (IsNum(str[j + 1]) && j + 1 < n) {
				j++;
			}
			insertChar(str, ')', j + 1);
			n++;
		}
	}
}

// �����ʽ��ʽ
Status CheckFix(char *infix, int n) {
	int left = 0, right = 0;
	char a, b, c;
	//���Ƿ��ַ�
	if (!isInvalid(infix)) {
		return FALSE;
	}
	//�����β�ַ�
	if (IsSign(infix[0]) || infix[0] == ')') {
		return FALSE;
	}
	if (IsSign(infix[n - 1]) || infix[n - 1] == '(') {
		return FALSE;
	}
	for (int i = 0; i < n; i++) {
		c = infix[i];
		if (c == '(') {
			left++;
			if (i > 0 && !IsSign(infix[i - 1])) {
				return FALSE;
			}
		}
		else if (c == ')') {
			right++;
			if (i > 0 && infix[i - 1] == '(') {
				return FALSE;
			}
		}
		else if (IsSign(c) && i > 0) {
			a = infix[i - 1];
			b = infix[i + 1];
			if (IsSign(a) || IsSign(b) || a == '(' || b == ')') {
				return FALSE;
			}
		}
	}
	if (left > right) {
		return FALSE;
	}
	else if (right > left) {
		return FALSE;
	}
	else {
		return TRUE;
	}

}

// �����ʽת���沨�����ʽ
void ToPostfix(char *infix, int n, Stack * postfix) {
	char c, last;
	double e;                     // ��ȡ����ջ�ַ�
	Stack sign;                   // ����ջ
	InitStack(&sign);
	for (int i = 0; i < n; i++) {
		c = infix[i];               // ��ǰ�ַ�
		last = infix[i - 1];        // ��һ���ַ�
		//���ִ�ĩβ�ӿո�
		if (IsNum(last) && !IsNum(c)) {
			Push(postfix, ' ');
		}
		// �����ַ�ֱ�������postfix
		if (IsNum(c)) {
			Push(postfix, c);
		}
		else {
			// ����ջΪ�ջ����ַ���������ֱ��ѹ�����ջsign
			if (IsEmpty(&sign) || c == '(') {
				Push(&sign, c);
			}
			// �ַ���������,�������ջջ���ķ��ŵ�postfix,ֱ��ջ����������
			else if (c == ')') {
				Pop(&sign, &e);
				while (e != '(') {
					Push(postfix, e);
					Pop(&sign, &e);
				}
			}
			// �����ַ����������ջ�����ȼ����ߣ�����ȵķ��ŵ�postfix
			else {
				while (Rank(sign.data[sign.top]) >= Rank(c) && (!IsEmpty(&sign))) {
					Pop(&sign, &e);
					Push(postfix, e);
				}
				Push(&sign, c);
			}
		}
	}
	// ����ַ������֣���postfix�ӿո�
	if (IsNum(c)) {
		Push(postfix, ' ');
	}
	// �������ջ����ʣ����ţ���postfix
	while (!IsEmpty(&sign)) {
		Pop(&sign, &e);
		Push(postfix, e);
	}
}

// �����沨�����ʽ
double ToNum(Stack * postfix, Stack * num) {
	double a, b, temp = 0;
	char c;
	int p = 0;                    // С����λ��
	int len = 0;                  // ���ִ�����
	for (int i = 0; i <= postfix->top; i++) {
		c = postfix->data[i];
		// �ո�ѹ�����temp�е�����
		if (c == ' ') {
			if (p != 0) {
				temp = temp / pow(10, len - p); // ת����С��
			}
			Push(num, temp);
			temp = len = p = 0;
		}
		else if (c >= '0' && c <= '9') {
			len++;
			c = c - '0';
			temp = temp * 10 + c; // �������ַ�����temp
		}
		else if (c == '.') {
			len++;
			p = len;  // ��¼С����λ��
		}
		else {
			Pop(num, &b);
			Pop(num, &a);
			Push(num, cal(a, b, c));  // ����������������
		}
	}
	return num->data[num->top];
}