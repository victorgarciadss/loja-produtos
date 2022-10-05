#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Market{
	int code;
	char name[50];
	float salePrice;
	int currentStock;
	int soldAmount;
};

void variableBegin(struct Market mark[5]){
	int i;
	
	for(i = 0; i <= 4; i++){
		mark[i].code = 0;
	}
}

int findProduct(struct Market mark[5], char* name){
	
	int i;
	
	for(i = 0; i <= 4; i++){
		
		if(strcmp(name, mark[i].name) == 0){
			return i;
		}
			
	}
	
	return -1;
}

void listProducts(struct Market mark[5]){
	
	int i;
	
	for(i = 0; i <= 4; i++){
		if(mark[i].code != 0){
			printf("\nCodigo: %d", mark[i].code);
			printf("\nNome do produto: %s", mark[i].name);
			printf("\nPreco de venda: R$ %.2f", mark[i].salePrice);
			printf("\nQuantidade em estoque: %d", mark[i].currentStock);
			printf("\nQuantidade vendida: %d", mark[i].soldAmount);
			
			printf("\n");
		}
		
		
	}
}

void registerProducts(struct Market mark[5]){
	
	int i;
	int positionRegister;
	
	printf("\nEm qual posicao voce deseja armazenar o produto? ");
	fflush(stdin);
	scanf("%d", &positionRegister);
	
	
	printf("\nQual o codigo do produto? ");
	fflush(stdin);
	scanf("%d", &mark[positionRegister].code);

	printf("Qual o nome do produto? ");
	fflush(stdin);
	gets(mark[positionRegister].name);
	
	printf("Qual o preco de venda desse produto? ");
	fflush(stdin);
	scanf("%f", &mark[positionRegister].salePrice);
	
	printf("Qual o estoque atual desse produto? ");
	fflush(stdin);
	scanf("%d", &mark[positionRegister].currentStock);
	
	printf("Quantos foram vendidos? ");
	fflush(stdin);
	scanf("%d", &mark[positionRegister].soldAmount);
	
}

void deleteProducts(struct Market mark[5]){
	
	int i;
	char nameProduct[50];
	
	printf("\nDigite o nome do produto que voce deseja apagar: ");
	fflush(stdin);
	scanf("%[^\n]s", nameProduct);
	
	
	int index = findProduct(mark, nameProduct);
	
	for(i = 0; i <= 4; i++){
		
		if(index != -1){
			
			mark[index].code = 0;
			strcpy(mark[index].name, "");
			mark[index].salePrice = 0;
			mark[index].currentStock = 0;
			mark[index].soldAmount = 0;
			
		}
	}
}

void sellProduct(struct Market mark[5]){
	
	int i;
	int quantitySold;
	
	char productBuy[50];
	
	printf("\nQual produto voce deseja vender? ");
	fflush(stdin);
	scanf("%[^\n]s", productBuy);
	
	int index = findProduct(mark, productBuy);
	
	printf("\nQuantos produtos serao vendidos? ");
	scanf("%d", &quantitySold);

	if(index != -1){
		mark[index].currentStock -= quantitySold;
		mark[index].soldAmount += quantitySold;
	}
}

void calcTotalSale(struct Market mark[5]){
	
	int i;
	float totalSale = 0;
	
	for(i = 0; i <= 4; i++){
		totalSale += mark[i].salePrice * mark[i].soldAmount;
	}
	
	printf("\nO preco total das vendas eh: R$ %.2f", totalSale);
	
	printf("\n");
}



int main(int argc, char *argv[]) {
	
	struct Market mark[5];
	
	int i;
	int menu;
	
	printf(" ----- Mercado ----- \n");
	
	variableBegin(mark);
	
	
	do{
		printf("\n0 - Sair");
		printf("\n1 - Listar Produtos");
		printf("\n2 - Cadastrar Produto");
		printf("\n3 - Apagar Produto");
		printf("\n4 - Vender");
		printf("\n5 - Total vendido");
		
		printf("\n\nDigite o numero do que deseja: ");
		scanf("%d", &menu);
		
		switch(menu){
			
			case 1:
				listProducts(mark);		
			break;	

			case 2:
				registerProducts(mark);
			break;
			
			case 3:
				deleteProducts(mark);
			break;
			
			case 4:
				sellProduct(mark);
			break;
			
			case 5:
				calcTotalSale(mark);
			break;
			
			default:
				if(menu != 0){
					printf("\nDigite uma opcao valida!! \n");
				}
				
			break;
				
		}
		
		
	} while (menu != 0);
	
	
	
	
	
	
	return 0;
}
