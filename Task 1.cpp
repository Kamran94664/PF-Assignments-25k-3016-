#include<stdio.h>
int AddBook(long long int isbn[],char titles[][50],float prices[],int quantities[],int count){
	long long int newISBN;
	int newQty;
    float newPrice;
    char newTitle[50];
    int i;
	if(count>=100){
		printf("\n'Inventory is Full'.");
		return count;
	}
	printf("Enter New Isbn:");
	scanf("%lld",&newISBN);
	
	for(i=0;i<count;i++){
	 if(isbn[i]==newISBN){
	 	printf("'Book Alredy Exist...'\n");
	 	return count;
	   }	
	}
	isbn[count]=newISBN;
	
	printf("Add your Book Tittle:  ");
	scanf(" %[^\n]", titles[count]);

	
	printf("Enter Price:    ");
	scanf("%f",&prices[count]);
	
	printf("Enter Quantity");
	scanf("%d",&quantities[count]);
	
	printf("'Book Added Successfully!'\n");
	
	return count+1;
	
}
int processSale(long long isbn[],int quantities[],float prices[],int count ){
  long long  int n;
  int i,q;	
	printf("What is the ISBN for the Requred book: ");
	scanf("%lld",&n);
	
	printf("What is the Quantity:-  ");
	scanf("%d",&q);
	
	for(i=0;i<count;i++){
		if(n==isbn[i]){
			if(q<=quantities[i]){
				quantities[i]-=q;
				return 1;
			}
			return -1;
		}
	}
	return 0;
}
void LowStockReport(long long isbn[],char titles[][50],float prices[],int quantities[],int count){
	int i, found=0;
	for(i=0;i<count;i++){
		if(quantities[i]<5){
			printf("\nThe ISBN is :(  %lld  )",isbn[i]);
			printf("\nThe Title is: ");
			printf(" \n%s",titles[i]);
			printf("\nThe price is : ( %.2f )",prices[i]);
			printf("\n'The Quantities Left are':(  %d  )",quantities[i]);
	        
	        found=1;
		}
	}
	if(!found){
		printf("'The Quantities are sufficient!..'");	
	}
}
  

int main(){

long long int isbn[100];
	char titles[100][50];
	float prices[100];
	int quantities[100];
	
	int choice,count=0,b;
	
	do{
	
	printf("\nWhat is your Choice:- 1-Adding the book. 2-Processing a Sale, 3-Generating a low-Stock Report. 4-Want to Exit: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			count=AddBook(isbn,titles,prices,quantities,count);
			break;
		
		
        case 2:
           b= processSale(isbn,quantities,prices,count);
            if(b==1){
            	printf("'Book Sold!!'");
			}
			else if(b==-1){
				printf("'Insufficient inventory...'");
			}
			else{
				printf("'Invalid Input'");
			}
			
			break;

        case 3:
            LowStockReport(isbn,titles,prices, quantities,count);
            break;

        case 4:
            printf("'Exiting...'\n");
            break;

        default:
            printf("'Invalid choice!'\n");	
			
	}
}while(choice!=4);
}




































