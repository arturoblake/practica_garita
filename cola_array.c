#include <stdio.h>   

//Prototipos  
int push(int[100], int, int);  
int pop(int[100], int);  
int colaVacia(int);
int colaLlena(int, int);
void mostrarCola(int[100], int);
void top(int[100], int);

void main()  
{  
    int posicionA = -1;
    int cola[100];
    int opcion = 0;
    int n;
      
    printf("\nIngresa el numero de elementos disponibles en la cola ");   
    scanf("%d",&n);    
  
    while(opcion != 6)  
    {  
        printf("\n--------MENU--------\n");  
        printf("1.Push\n2.Pop\n3.Mostrar la cola\n4.Top\n5.Size\n6.Salir");  
        printf("\nIngresa la opcion deseada: ");         
        scanf("%d",&opcion);  
        switch(opcion)  
        {  
            case 1:  
                posicionA = push(cola, n, posicionA);  
                break;   
            case 2:   
                posicionA = pop(cola, posicionA);  
                break;  
            case 3:  
                mostrarCola(cola, posicionA);  
                break;
            case 4:
                top(cola, posicionA);
                break;
            case 5:
                printf("\nEl tamaño de la cola es: %d",n);//Cuenta el tamano de la cola
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
//Permite agregar un valor al principio de la cola  
int push (int cola[100], int n, int posicionA)  
{  
    int dato = 0;      
    if (colaLlena(n, posicionA))
    {   
        printf("\nLa cola esta llena.\n"); 
    }
    else   
    {  
        printf("\nIngresa un valor: ");  
        scanf("%d",&dato);         
        posicionA = posicionA +1;   
        cola[posicionA] = dato;   
    }
    return posicionA;     
}   
//Permite eliminar el elemento al tope de la cola  
int pop (int cola[100], int posicionA)   
{   
    if(colaVacia(posicionA))
    {   
        printf("\nLa cola esta vacia.\n");  
    }
    else
    {  
        posicionA = posicionA -1;
    }
    return posicionA;     
}   
//Valida si hay elementos en la cola
int colaVacia(int posicionA)
{
    if(posicionA == -1)
    { 
        return 1;
    }
    else
    { 
        return 0;
    }
}
//Verifica si la cola esta llena
int colaLlena(int n, int posicionA)
{
    if(posicionA == n-1)
    { 
        return 1;
    }
    else
    { 
        return 0;
    }
}
//Imprime los elementos de la cola
void mostrarCola(int cola[100], int posicionA)  
{
    if(colaVacia(posicionA))   
    {  
        printf("\nLa cola esta vacia.\n");  
    }    
    else
    {
        for (int i = posicionA; i >= 0; i--)  
        {  
            printf("[%d] ",cola[i]);  
        }  
    }
}
//Muestra el elemento del tope de la cola sin eliminarlo
void top(int cola[100], int posicionA)
{
    if(colaVacia(posicionA))
    { 
        printf("\ncola Vacia");
    }
    else
    { 
        printf("\n[%d] esta en el top de la cola",cola[posicionA]);
    }
}  