#include <stdio.h>

void push(int stack[], int *top, int maxSize) {
    int val;
    if (*top == maxSize - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        *top = *top + 1;
        stack[*top] = val;
    }
}

void pop(int stack[], int *top) {
    if (*top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Popped element: %d\n", stack[*top]);
        *top = *top - 1;
    }
}

void peek(int stack[], int *top) {
    if (*top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[*top]);
}

void display(int stack[], int *top) {
    int i;
    if (*top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (i = *top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[10], top = -1, choice, maxSize = 10;

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice == 1)
            push(stack, &top, maxSize);
        else if (choice == 2)
            pop(stack, &top);
        else if (choice == 3)
            peek(stack, &top);
        else if (choice == 4)
            display(stack, &top);
        else
            printf("Invalid choice\n");
    }
    return 0;
}

