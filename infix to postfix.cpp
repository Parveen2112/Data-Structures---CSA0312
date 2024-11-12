#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char c) {
    return (c == '^') ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : -1;
}
void infixToPostfix(char* expr) {
    char postfix[MAX]; int k = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (stack[top] != '(') postfix[k++] = pop();
            top--; // discard '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1) postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}
int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expr);
    infixToPostfix(expr);
    return 0;
}
