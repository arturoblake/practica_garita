#include <stdio.h>   

//Prototipos  
int push(int[100], int, int);  
int pop(int[100], int);  
int pilaVacia(int);
int pilaLLena(int, int);
void mostrarPila(int[100], int);
void top(int[100], int);

void main()  
{  
    int posicionA = -1;
    int pila[100];
    int opcion = 0;
    int n;
      
    printf("\nIngresa el numero de elementos de la pila: ");   
    scanf("%d",&n);    
  
    while(opcion != 6)  
    {  
        printf("\n--------MENU--------\n");  
        printf("1.Push\n2.Pop\n3.Mostrar la pila\n4.Top\n5.Size\n6.Salir");  
        printf("\nIngresa la opcion deseada: ");         
        scanf("%d",&opcion);  
        switch(opcion)  
        {  
            case 1:  
                posicionA = push(pila, n, posicionA);  
                break;   
            case 2:   
                posicionA = pop(pila, posicionA);  
                break;  
            case 3:  
                mostrarPila(pila, posicionA);  
                break;
            case 4:
                top(pila, posicionA);
                break;
            case 5:
                printf("\nEl tamaño de la pila es: %d",n);//Cuenta el tamano de la pila
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
//Permite agregar un valor al principio de la pila  
int push (int pila[100], int n, int posicionA)  
{  
    int dato = 0;      
    if (pilaLLena(n, posicionA))
    {   
        printf("\nLa pila esta llena.\n"); 
    }
    else   
    {  
        printf("\nIngresa un valor: ");  
        scanf("%d",&dato);         
        posicionA = posicionA +1;   
        pila[posicionA] = dato;   
    }
    return posicionA;     
}   
//Permite eliminar el elemento al tope de la pila  
int pop (int pila[100], int posicionA)   
{   
    if(pilaVacia(posicionA))
    {   
        printf("\nLa pila esta vacia.\n");  
    }
    else
    {  
        posicionA = posicionA -1;
    }
    return posicionA;     
}   
//Valida si hay elementos en la Pila
int pilaVacia(int posicionA)
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
//Verifica si la pila esta llena
int pilaLLena(int n, int posicionA)
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
//Imprime los elementos de la pila
void mostrarPila(int pila[100], int posicionA)  
{
    if(pilaVacia(posicionA))   
    {  
        printf("\nLa pila esta vacia.\n");  
    }    
    else
    {
        for (int i = posicionA; i >= 0; i--)  
        {  
            printf("[%d]\n",pila[i]);  
        }  
    }
}
//Muestra el elemento del tope de la pila sin eliminarlo
void top(int pila[100], int posicionA)
{
    if(pilaVacia(posicionA))
    { 
        printf("\nPila Vacia");
    }
    else
    { 
        printf("\n[%d] esta en el top de la pila",pila[posicionA]);
    }
}  