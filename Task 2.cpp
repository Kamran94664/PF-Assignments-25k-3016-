#include <stdio.h>

int MAX_PRODUCTS = 4;
int MAX_CART = 20;

char customerName[50], customerCNIC[25];
int customerEntered = 0;

int productCode[4]  = {1, 2, 3, 4};
int productQty[4]   = {50, 10, 20, 8};
int productPrice[4] = {100, 200, 300, 150};

int cartCode[20];
int cartQty[20];
int cartCount = 0;

void customerInformation();
void displayInventory();
int findProductIndex(int code);
void addItemToCart();
void displayBill();
void showInvoice();

int main() {
    int choice;
    while (1) {
        printf("\n========== SUPERMARKET MENU ==========\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: customerInformation(); break;
            case 2: displayInventory(); break;
            case 3: addItemToCart(); break;
            case 4: displayBill(); break;
            case 5: showInvoice(); break;
            case 6: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}

void customerInformation() {
    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]s", customerName);
    printf("Enter Customer CNIC: ");
    scanf(" %[^\n]s", customerCNIC);
    customerEntered = 1;
}

void displayInventory() {
    int i;
    printf("\nCode\tQty\tPrice\n");
    printf("-----------------------------\n");
    for (i = 0; i < MAX_PRODUCTS; i++) {
        printf("00%d\t%d\t%d\n", productCode[i], productQty[i], productPrice[i]);
    }
}

int findProductIndex(int code) {
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(productCode[i] == code)
            return i;
    }
    return -1;
}

void addItemToCart() {
    int code, qty, index;
    printf("\nEnter product code: ");
    scanf("%d", &code);
    index = findProductIndex(code);
    if(index == -1) {
        printf("Invalid product code!\n");
        return;
    }
    printf("Enter quantity: ");
    scanf("%d", &qty);
    if(qty > productQty[index]) {
        printf("Not enough stock!\n");
        return;
    }
    productQty[index] -= qty;
    cartCode[cartCount] = code;
    cartQty[cartCount] = qty;
    cartCount++;
}

void displayBill() {
    int i, index, promo;
    float total = 0, discount = 0, finalTotal;
    printf("\nITEMS IN CART\n");
    printf("Code\tQty\tPrice\tTotal\n");

    for(i = 0; i < cartCount; i++) {
        index = findProductIndex(cartCode[i]);
        float itemTotal = cartQty[i] * productPrice[index];
        total += itemTotal;
        printf("00%d\t%d\t%d\t%.2f\n", cartCode[i], cartQty[i], productPrice[index], itemTotal);
    }

    printf("\nDo you have promo code? (1=Yes / 0=No): ");
    scanf("%d", &promo);

    if(promo == 1){
        int code;
        printf("Enter promo code (2025 for 25%% OFF): ");
        scanf("%d", &code);
        if(code == 2025) {
            discount = total * 0.25;
        }
    }

    finalTotal = total - discount;
    printf("\nTotal Bill     : %.2f", total);
    printf("\nDiscount Given : %.2f", discount);
    printf("\nFinal Bill     : %.2f\n", finalTotal);
}

void showInvoice() {
    int i, index, code;
    float total = 0, discount = 0, finalTotal;

    if(!customerEntered) {
        printf("\nEnter customer info first!\n");
        return;
    }

    printf("\n=========== INVOICE ===========\n");
    printf("Customer: %s\n", customerName);
    printf("CNIC: %s\n", customerCNIC);
    printf("\nCode\tQty\tPrice\tTotal\n");

    for(i = 0; i < cartCount; i++) {
        index = findProductIndex(cartCode[i]);
        float itemTotal = cartQty[i] * productPrice[index];
        total += itemTotal;
        printf("00%d\t%d\t%d\t%.2f\n", cartCode[i], cartQty[i], productPrice[index], itemTotal);
    }

    printf("\nEnter promo code (or 0 for none): ");
    scanf("%d", &code);
    if(code == 2025){
        discount = total * 0.25;
    }

    finalTotal = total - discount;
    printf("\nBill without discount: %.2f", total);
    printf("\nDiscount            : %.2f", discount);
    printf("\nFinal Bill          : %.2f\n", finalTotal);
}

