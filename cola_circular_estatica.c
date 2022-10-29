#include <stdio.h>
#define MAX 5

//Prototipos  
void push(int[MAX]);  
int pop(int[MAX]);  
void size();
void mostrarCola(int[MAX]);
void size(int final);
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
                pop(cola);
                break;  
            case 3:
				mostrarCola(cola);  
                break;
            case 4:
                break;
            case 5:
                size(final);
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
    {
        printf("\nLa cola esta llena\n");
    }
    else
    {
        int n = 0;
        printf("\nValor n: ");
        scanf("%d", &n);
        if (inicio == -1)
        { 
            inicio = 0;
        }
        final = (final + 1) % MAX;
        cola[final] = n;
        printf("\n%d Entro a la cola.", n);
  }
}

int pop(int cola[MAX])
{
    int variable;
    if (inicio == -1) {
        printf("\nLa cola esta vacia.\n");
        return -1;
    } 
    else
    {
        variable = cola[inicio];
        if (inicio == final) 
        {
            inicio = final = -1;
        } 
    else 
    {
      inicio = (inicio + 1) % MAX;
    }
    printf("\n%d Salio de la cola.", variable);
    return 1;
  }
}

void mostrarCola(int cola[MAX])
{
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        for(int i = final ; i >= inicio; i--)
        {
            printf("[%d] ", cola[i]);
        }
    }
}

void size(int final) 
{
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        printf("\nLa cantidad de elementos de la cola es: %d ", final +1);
    }
}

