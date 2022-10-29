#include <stdio.h>
#define MAX 5

//Prototipos  
void push(int[MAX]);  
int pop(int[MAX]);  
void size();
void mostrarCola(int[MAX]);
void top();

int inicio = -1;
int final = -1;

void main()  
{  
    int cola[MAX];
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
				push(cola); 
                break;   
            case 2:

                break;  
            case 3:
				mostrarCola(cola);  
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

void push(int cola[MAX])
{
    if ((inicio == final + 1) || (inicio == 0 && final == MAX - 1))
        printf("La cola esta llena\n");
    
    else
    {
        int n = 0;
        printf("\nValor n: ");
        scanf("%d", &n);
        if (inicio == -1) 
            inicio = 0;
        
        final = (final + 1) % MAX;
        cola[final] = n;
        printf("%d Entro a la cola.\n", n);
  }
}

int pop(int cola[MAX])
{

}

void mostrarCola(int cola[MAX])
{
    for(int i = final ; i >= inicio; i--)
    {
        printf("[%d] ", cola[i]);
    }
}