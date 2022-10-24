#include <stdio.h>   

//Prototipos  
int push(int[20], int , int, int);  
int pop(int[20], int, int);  
void size(int, int);
void mostrarCola(int[20], int, int);
void top(int[20], int, int);

void main()  
{  
    int inicio = 0;
    int final = 0;
    int cola[20];
    int opcion = 0;
    int n = 0;
      
    while(opcion != 6)  
    {  
        printf("\n--------MENU--------\n");  
        printf("1.Push\n2.Pop\n3.Mostrar la cola\n4.Top\n5.Size\n6.Salir");  
        printf("\nIngresa la opcion deseada: ");         
        scanf("%d",&opcion);  
        
        switch(opcion)  
        {    
            case 1: 
                final = push(cola, inicio, final, n);
                break;   
            case 2:   
                inicio = pop(cola, inicio, final);
                break;  
            case 3:  
                mostrarCola(cola, inicio, final);  
                break;
            case 4:
                top(cola, inicio, final);
                break;
            case 5:
                size(inicio, final);
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

int push(int cola[20], int inicio, int final, int n) {
    if(final == 20){
        printf("\nEsta llena la cola ");
        }else{
        printf("\nValor n: ");
        scanf("%d", &n);
        cola[final] = n;
        final++;
    }
    return final; 
}

int pop(int cola[20], int inicio, int final){
    if(inicio != final){
        printf("\nSe borro: %d", cola[inicio]);
        cola[inicio] = 0;
        inicio++;
    }else{
        printf("\nNo hay nada");
    }
    return inicio;
}

void mostrarCola(int cola[20], int inicio, int final){
    for(int i = final-1 ; i >= inicio; i--){
        printf("[%d] ", cola[i]);
    }
}

void size(int inicio, int final){
    printf("\nLa cantidad de elementos de la cola es: %d ", final - inicio);
}

void top(int cola[20], int inicio, int final){
    if(inicio != final){
        printf("\nEl tope es: %d ", cola[inicio]);
    }
    else{
        printf("\nLa cola esta vacia");
    }
}