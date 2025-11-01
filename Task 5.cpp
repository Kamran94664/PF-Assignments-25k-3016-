#include <stdio.h>

void reverseString(char msg[]) {
    int i, j, temp, len = 0;
    while (msg[len] != '\0') len++;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = msg[i];
        msg[i] = msg[j];
        msg[j] = temp;
    }
}

void toggleBits(char msg[]) {
    int i = 0;
    while (msg[i] != '\0') {
        msg[i] ^= (1 << 1);  
        msg[i] ^= (1 << 4);  
        i++;
    }
}

void encodeMessage(char msg[]) {
    reverseString(msg);
    toggleBits(msg);
}

void decodeMessage(char msg[]) {
    toggleBits(msg);
    reverseString(msg);
}

int main() {
    char msg[200];
    int choice;

    while (1) {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 3)
            break;

        printf("Enter message: ");
        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n')
            msg[i++] = ch;
        msg[i] = '\0';

        if (choice == 1) {
            encodeMessage(msg);
            printf("Encoded Message: %s\n", msg);
        } else if (choice == 2) {
            decodeMessage(msg);
            printf("Decoded Message: %s\n", msg);
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

