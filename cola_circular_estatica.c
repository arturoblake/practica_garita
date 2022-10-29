#include <stdio.h>
#define MAX 5

//Prototipos  
void push(int[MAX]);  
int pop(int[MAX]);  
void mostrarCola(int[MAX]);
void size();
void top(int[MAX]);

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
                top(cola);
                break;
            case 5:
                size();
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
    int i;
    if (inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        printf("\nLa cola es: \n");
        for (i = inicio; i != final; i = (i + 1) % MAX)
        {
            printf("[%d] ", cola[i]);
        }
        printf("[%d] \n", cola[i]);
    }
}

void size() 
{
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        int size = 0;
        size = inicio > final ? (MAX - inicio + final + 1) : (final - inicio + 1);//La encontre en internet no  sabia como implementarlo
        printf("\nLa cantidad de elementos de la cola es: %d ", size);
    }
}

void top(int cola[MAX]){
    if(inicio == -1)
    {
        printf("\nLa cola esta vacia.\n");
    }
    else
    {
        printf("\nEl tope es: %d ", cola[inicio]);
    }
}