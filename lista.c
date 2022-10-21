#include <stdio.h>
#include <stdlib.h>

//Estructura
typedef struct Nodo
{
    int dato;
    struct Nodo *sig;
}NODO;

//prototipos
void mostrarCola(NODO *head);
void push(NODO **head, int dato);
void pop(NODO **head);
void top(NODO *head);
int size(NODO *head);

int main()
{
    NODO *head = NULL;
    int opcion, dato;

    while (opcion != 6)
    {
        printf("\n--------MENU--------\n");
        printf("1.Push\n2.Pop\n3.Mostra pila\n4.Top\n5.Size\n6.Salir");
	    printf("\nIngresa la opcion deseada: "); 
	    scanf("%d", &opcion);
		switch (opcion) 
        {
			case 1:
				printf("%s", "Introduce un valor entero: ");
				scanf("\n%d", &dato);
                push(&head, dato);
				break;
			case 2: 
                pop(&head);
				break;
			case 3:
                mostrarPila(head);
				break;	
            case 4:
                top(head);
                break;
            case 5:
                printf("\nEl tamaño de la pila es: %d", size(head));
                break;
            case 6:
                printf("\nTermino el programa.");
                break;
			default:
				printf("\nIngresa una opcion correcta.");
				break;
		}
	}

    return 0;
}
//Imprime los elementos de la cola
void mostrarPila(NODO *head) 
{
    if(head == NULL)
    {
        printf("\nLa cola esta vacia. ");
        return;
    }
    else
    {
        NODO *temp = head;

        while (temp != NULL)
        {
            printf("[%d] ", temp -> dato);
            temp = temp -> sig;
        }
    }
}
//Permite agregar un valor al principio de la cola 
void push(NODO **head, int dato)
{
    NODO *nuevoNodo = (NODO*)malloc(sizeof(NODO));
    NODO *actual = head;
    NODO *sig;
    while(actual != NULL){
        sig = actual;
        actual = actual->sig;
    };
    nuevoNodo -> dato = dato;
    nuevoNodo -> sig = *head;
    *head = nuevoNodo;
}
//Permite eliminar el elemento al tope de la cola
void pop(NODO **head)
{
    if(head == NULL || *head == NULL)
    {
        printf("\nLa pila esta vacia. ");
        return;
    }
    else
    {
        NODO *temp = (NODO*)malloc(sizeof(NODO));
        temp = *head;
        *head = (*head) -> sig;
        free(temp);
    }
}
//Muestra el elemento del tope de la cola sin eliminarlo
void top(NODO *head){
    if(head != NULL){
    printf("\nElemento de Top es: %d", head -> dato);
    }
    else
    {
        printf("\nLa pila esta vacia.");
    }
}
//Cuenta el tamano de la cola
int size(NODO *head)
{
    int cont = 0;
    NODO *actual = head;
    while (actual != NULL) {
        cont++;
        actual = actual->sig;
    }
    return cont;
}