/*
    La cola sigue la lógica de salida FIFO y es similar a la cola de entradas
    fuera de una sala de cine.

    Operaciones
    enQueue: agrega un elemento al final de la cola
    deQueue: elimina un elemento del frente de la cola
    IsEmpty: compruebasi la cola está vacía
    IsFull: comprueba si al cola está llena
    Peek: obtiene el valor del frente de la cola sin eliminarlo

    Haz qye el ultimo elemento no se quite no puede ingresar más valores
    a la cola :/
*/

#include <iostream>
#define SIZE 5

using namespace std;

// La clase cola
class Queue {
    private:
        int items[SIZE], front, rear;

    public:
        // Contructor:
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isFull() { // Si esta lleno el frontal esta en 0 y el trasero en -1
            if (front == 0 && rear == SIZE - 1) {
                return true;
            }
            return false;
        }

        bool isEmpty() {    // Si el frontal esta en -1
            if (front == -1)
                return true;
            else
                return false;
        }

        void enQueue(int element) { // Para agregar a la cola
            if (isFull()) {
                cout << "Queue is full";
            } else {   
                if (front == -1) front = 0;
                rear++; // Se aumenta en trasero en 1
                items[rear] = element;  // Se coloca el elemento
                cout << endl << "Inserted " << element << endl;
            }
        }

        int deQueue() { // Para sacar un elemento
            int element;
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return (-1);
            } else {
                element = items[front];
                if (front >= rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front++;
                }

                cout << endl << "Deleted -> " << element << endl;
                return (element);
            }
        }

        void display() {
            int i;
            if (isEmpty()) {
                cout << endl << "Empty Queue" << endl;
            } else {
                cout << endl << "Front index-> " << front;
                cout << endl << "Items -> ";
                for (i = front; i <= rear; i++)
                    cout << items[i] << " ";
                cout << endl << "Rear index-> " << rear << endl;
            }
        }
};

int main() {
    Queue q;

    // deQueue is not possible on empty queue
    q.deQueue();

    // enQueue 5 elements
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // 6th element can't be added because the queue is full
    q.enQueue(6);

    q.display();

    // deQueue removes element entered first i.e. 1
    q.deQueue();

    // Now we have just 4 elements
    q.display();

    return 0;
}
