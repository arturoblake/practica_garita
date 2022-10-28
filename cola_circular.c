#include <stdio.h>   

//Prototipos  
int push();  
int pop();  
void size();
void mostrarCola();
void top();

void main()  
{  
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
                break;   
            case 2:   
                break;  
            case 3:  
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
