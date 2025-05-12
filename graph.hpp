#include <iostream>

namespace graph {

    class Node {    
        int data[2]; // Num, Weight.
        // char color; // Used for search algorithms.    
        Node* next;

        public:

            void setNext(Node*);

            Node* getNext();

            int getNum();

            Node(int, int);

            Node();

            ~Node();
    };

    class Queue {
        int front;
        int rear;
        int size;
        int* arr;

        public:
            Queue(int);
            ~Queue();
            bool isEmpty();
            bool isFull();
            int getFront();
            int getRear();
            void enqueue(int);
            int dequeue();
            void display();
    };

    class LinkedList {

        Node* head; 
        int n; // Total num of items in list.

        public:

            void insert(int, int); // At the start of the list.

            void remove(int); // Based on node number.

            void display();

            // void makeWhite(); // Colors all nodes white.

            Node* getHead() {return head;}

            int getLength() {return n;}

            LinkedList(); // Will create an empty list.

            ~LinkedList();
    };

    class Graph {

        int n; // Number of vertices.
        LinkedList* neighbours; 
        Node* nodes;

        public:
        
            void addEdge(int, int, int=1);

            void removeEdge(int, int);

            void print_graph();

            int getSize() {return n;}

            LinkedList* getNeighbours() {return neighbours;}

            Graph(int=10); // Constructor.

            ~Graph(); // Destructor.
    };
}