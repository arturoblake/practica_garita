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
    NODO *sentri = NULL;
    NODO *readyline = NULL;
    int opcion;
    int sen;
    int red;

    while (opcion != 6)
    {
        printf("\n\nINGRESE EL TIPO DE VISA\n");
        printf("1.Sentri\n2.ReadyLine\n3.Mostra ambas colas\n4.Dejar pasar en Sentri\n5.Dejar pasar en ReadyLine\n6.Salir");
	    printf("\nIngresa la opcion deseada: "); 
	    scanf("%d", &opcion);
		switch (opcion) 
        {
			case 1:
                printf("\n\nVISA SENTRI\n");
                printf("1.Meter a la cola\n2.Mostrar la cola\n3.Ver el numero de personas\n4.Ver el tope de la cola\n5.Regresar al menu anterior");
                printf("\nIngresa la opcion deseada: "); 
                scanf("%d", &sen);
                switch (sen)
                {
                case 1:
                    push(&sentri);
                    break;
                case 2:
                    printf("\nLa cola de Sentri: \n");
                    mostrarCola(sentri);
                    break;
                case 3:
                    printf("\nEl tamaño de la cola es: %d", size(sentri));
                    break;
                case 4:
                    top(sentri);
                    break;
                case 5:
                    printf("\nRegresando...");
                    break;
                    
                default:
                    printf("\nIngresa una opcion correcta.");
                    break;
                };
				break;
			case 2: 
                printf("\n\nVISA READYLINE\n");
                printf("1.Meter a la cola\n2.Mostrar la cola\n3.Ver el numero de personas\n4.Ver el tope de la cola\n5.Regresar al menu anterior");
                printf("\nIngresa la opcion deseada: "); 
                scanf("%d", &sen);
                switch (sen)
                {
                case 1:
                    push(&readyline);
                    break;
                case 2:
                    printf("\nLa cola de ReadyLine: \n");
                    mostrarCola(readyline);
                    break;
                case 3:
                    printf("\nEl tamaño de la cola es: %d", size(readyline));
                    break;
                case 4:
                    top(readyline);
                    break;
                case 5:
                    printf("\nRegresando...");
                    break;
                    
                default:
                    printf("\nIngresa una opcion correcta.");
                    break;
                };
			    break;
            case 3:
                printf("\nLa cola de Sentri: \n");
                mostrarCola(sentri);
                printf("\n\nLa cola de ReadyLine: \n");
                mostrarCola(readyline);
                break;
            case 4:
                pop(&sentri);
                break;
            case 5:
                pop(&readyline);
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
	printf("%s", "Introduce tu numero de BCC de tu VISA: ");
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