#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// initializing functions
float get_num();
char get_op();
float m_exp(float sub_exp, char op);
float s_exp(float sub_exp, char op);

int main() {

	char choice;
	printf("Please enter a simple arithmetic expression: ");
	float ans = s_exp(0, '+');
	printf("%.2f\n", ans);
	
	printf("Do you want to Continue? Y/N: ");
	scanf("%c", &choice);
	if (choice == 'Y')
		main();
	else exit;

}

float s_exp(float sub_exp, char op) {
	
	// when op is \n it's the end of the expression so return it.
	if (op == '\n')
		return sub_exp;

	// otherwise call m_exp because it's not the end of the expression
	else {

		float f1 = m_exp(1, '*');
		// regets the op used in m_exp
		char op1 = get_op();
		if (op == '+')
			f1 = sub_exp + f1;
		else if (op == '-')
			f1 = sub_exp - f1;
		return s_exp(f1, op1);
	}

}

float m_exp(float sub_exp, char op) {

	// if it's any of these three, return what you have so far, and unget the op, 
	// this is important because s_exp needs to use that op.
	if (op  == '\n' || op == '+' || op == '-') {
		ungetc(op, stdin);
		return sub_exp;
	}
	// if it's a * or / do the appropriate calculation on the next num and next op
	else  {
		float f1 = get_num();
		char op1 = get_op();
		if (op == '*')
			f1 = f1 * sub_exp;
		else if (op  == '/')
			f1 = sub_exp / f1;
		return m_exp(f1,op1);
	}

}

float get_num() {

	float var;
	scanf(" %f",  &var);

	return var;

}

char get_op() {

	char var;
        do scanf("%c", &var);
	while (var == ' ');

	return var;
}

