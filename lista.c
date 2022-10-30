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
void push(NODO **head);
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
        printf("1.Push\n2.Pop\n3.Mostra cola\n4.Top\n5.Size\n6.Salir");
	    printf("\nIngresa la opcion deseada: "); 
	    scanf("%d", &opcion);
		switch (opcion) 
        {
			case 1:
                push(&head);
				break;
			case 2: 
                pop(&head);
				break;
			case 3:
                mostrarCola(head);
				break;	
            case 4:
                top(head);
                break;
            case 5:
                printf("\nEl tamaño de la cola es de: %d", size(head));
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
void mostrarCola(NODO *head) 
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
//Permite agregar un valor al principio de la pila 
void push(NODO **head)
{
    int dato;
    NODO *nuevoNodo = malloc(sizeof(NODO));
	printf("%s", "Introduce un valor entero: ");
	scanf("\n%d", &dato);
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if(*head == NULL)
    {
        *head = nuevoNodo;
    }
    else
    {
        NODO *ultimo = *head;
        while(ultimo->sig != NULL)
        {
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevoNodo;
    }
}

//Permite eliminar el elemento al tope de la cola
void pop(NODO **head)
{
    if(head == NULL || *head == NULL)
    {
        printf("\nLa cola esta vacia. ");
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
        printf("\nLa cola esta vacia.");
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