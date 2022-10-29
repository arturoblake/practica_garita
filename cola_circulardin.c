#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//Prototipos  
void push(int*, int);  
int pop(int*, int tam);  
void mostrarCola(int*, int);
void size(int);
void top(int *);

int inicio = -1;
int final = -1;

void main()  
{  
    int *cola = NULL;
    int opcion = 0;
    int tam = 0;

    printf("\nIngresa el tamaño de la cola: ");
    scanf("%d",&tam);
    cola = (int*)malloc((tam)*sizeof(int));

    while(opcion != 6)  
    {  
        printf("\n--------MENU--------\n");  
        printf("1.Push\n2.Pop\n3.Mostrar la cola\n4.Top\n5.Size\n6.Salir");  
        printf("\nIngresa la opcion deseada: ");         
        scanf("%d",&opcion);  
        
        switch(opcion)  
        {    
            case 1:
				push(cola, tam); 
                break;   
            case 2:
                pop(cola, tam);
                break;  
            case 3:
				mostrarCola(cola, tam);  
                break;
            case 4:
                top(cola);
                break;
            case 5:
                size(tam);
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

void push(int *cola, int tam)
{
    if ((inicio == final + 1) || (inicio == 0 && final == tam - 1))
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
        final = (final + 1) % tam;
        cola[final] = n;
        printf("\n%d Entro a la cola.", n);
  }
}

int pop(int *cola, int tam)
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
      inicio = (inicio + 1) % tam;
    }
    printf("\n%d Salio de la cola.", variable);
    return 1;
  }
}

void mostrarCola(int *cola, int tam)
{
    int i;
    if (inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        printf("\nLa cola es: \n");
        for (i = inicio; i != final; i = (i + 1) % tam)
        {
            printf("[%d] ", cola[i]);
        }
        printf("[%d] \n", cola[i]);
    }
}

void size(int tam) 
{
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        int size = 0;
        size = inicio > final ? (tam - inicio + final + 1) : (final - inicio + 1);//La encontre en internet no  sabia como implementarlo
        printf("\nLa cantidad de elementos de la cola es: %d ", size);
    }
}

void top(int *cola){
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        printf("\nEl tope es: %d ", cola[inicio]);
    }
}