#include <stdio.h>
#define MAX 5

//Prototipos  
int push(int[MAX], int, int);  
int pop(int[MAX], int, int);  
void size();
void mostrarCola(int[], int, int);
void top();

void main()  
{  
	int inicio = 0;
    int final = 0;
    int cola[20];
    int opcion = 0;

    while(opcion != 6)  
    {  
        printf("\n--------MENU--------\n");  
        printf("1.Push\n2.Pop\n3.Mostrar la cola\n4.Top\n5.Size\n6.Salir");  
        printf("\nIngresa la opcion deseada: ");         
        scanf("%d",&opcion);  
        
        switch(opcion)  
        {    
            case 1:
				final = push(cola, inicio, final); 
                break;   
            case 2:   
                break;  
            case 3:
				mostrarCola(cola, inicio, final);  
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("\nTermino el programa.");
                break;   
            default:    
                printf("\nIngresa una opcion correcta. ");   
        };
    } 
    return; 
}

int push(int cola[MAX], int inicio, int final)
{
	int n = 0;
	if(inicio == 0 && final == MAX|| inicio == final + 1)
	{
		printf("La cola esta llena.");
	}
	else
	{
		printf("\nValor n: ");
        scanf("%d", &n);
		cola[final%MAX] = n;
		final++;
	}
	return final;
}  


void mostrarCola(int cola[20], int inicio, int final){
    for(int i = final-1 ; i >= inicio; i--){
        printf("[%d] ", cola[i]);
    }
}