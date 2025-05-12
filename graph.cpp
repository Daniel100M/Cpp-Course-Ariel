#include "graph.hpp"

using namespace graph;

//---------------------------------------------------------------------------
// Node class - function definitions:

Node::Node(int n, int w){
    data[0] = n;
    data[1] = w;
    // color = 'w'; 
    next = nullptr;
}

graph::Node::Node() {} 

void Node::setNext(Node* nxt){
    next = nxt;
}

Node* Node::getNext(){
    return next;
}

int Node::getNum(){
    return data[0];
}

Node::~Node(){
    std::cout << "Node destructor called.\n";
    //delete this;
    // The line above causes a stack overflow.
}

//---------------------------------------------------------------------------
// Queue class - function definitions:

graph::Queue::Queue(int size){
    std::cout << "Queue constructor called.\n";
    arr = new int[size];
    front = rear = -1;
    this->size = size;
}

graph::Queue::~Queue(){
    std::cout << "Queue destructor called.\n";
    delete[] arr;
}

bool graph::Queue::isEmpty()
{
    if (front > rear || front == -1){
        front = rear = -1;
        return true;
    }
    return false;
}

bool graph::Queue::isFull()
{
    return rear - front == size - 1;
}

int graph::Queue::getFront()
{
    if (isEmpty()){
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return arr[front];
}

int graph::Queue::getRear()
{
    if (isEmpty()){
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return arr[rear];
}

void graph::Queue::enqueue(int val)
{
    // Assuming: rear < n - 1
    if (isFull()){
        std::cout << "Queue is full.\n";
        return;
    }
    if (isEmpty()) {front++;} // front = rear = -1
    // if (rear == n - 1){}
    rear++;
    arr[rear] = val;
}

int graph::Queue::dequeue()
{
    int val = getFront();
    front++;
    return val; // Will return -1 if queue was already empty.
}

void graph::Queue::display(){
    if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
    std::cout << "front -| ";
    for (int i = front; i <= rear; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "|- rear\n";
    
}

//---------------------------------------------------------------------------
// LinkedList class - function definitions:

LinkedList::LinkedList(){
    // A newly constructed LinkedList will be empty.
    head = nullptr;
    n = 0;
}

graph::LinkedList::~LinkedList()
{
    std::cout << "LinkedList destructor called.\n";
    // Delete every node object in the list (one by one).
    while (n > 0){
        std::cout << "Deleting node #" << head->getNum() << std::endl;
        remove(head->getNum());
    }
    std::cout << "Finished destroying LinkedList.\n";    
}

void LinkedList::insert(int num, int w){
    // int* p = nullptr;
    // *p = 19;
    // The code above causes a segmentation fault.

    Node* node = new Node(num, w); // Memory allocted on the heap.
    if (head){
        node->setNext(head); // Dereference node pointer to access the object.
    } else {
        // std::cout << "Adding first item to the list!" << std::endl;
    }
    head = node;
    if (head){
        // std::cout << "Success.\nCurrent head adress: " << head << std::endl;
    }
    n++;// Number of neighbours increases.
    // std::cout << "Finished insertion.\n";
}

void LinkedList::remove(int num){
    Node* temp = head;
    if (temp) { // Verifying non-empty list.

        if (temp->getNum() == num){ // Delete head.
            head = temp->getNext();
            delete temp; // Calls destructor: ~Node()
            n--;
            return;
        }
        
        for (int i = 0; i < n && temp->getNext(); i++)
        {
            if (temp->getNext()->getNum() == num){
                // Save the node to be deleted
                Node* nodeToDelete = temp->getNext(); 
                // Update the next pointer
                temp->setNext(temp->getNext()->getNext());
                // Delete the node
                delete nodeToDelete;
                n--;
                return;
            }
            temp = temp->getNext();   
        }
    
    } 

    // At this stage there are two possibilities:
    // 1. Empty List.
    // 2. Invalid node number.
    // Throw exception:
    throw std::out_of_range("Invalid edge.");
}

void LinkedList::display(){
    if (!head) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < n && temp; i++)
    {
        std::cout << temp->getNum() << " -> "; 
        temp = temp->getNext();
    }
    
    std::cout << "NULL" << std::endl;
}

//---------------------------------------------------------------------------
// Graph class - function definitions:

Graph::Graph(int n){
    this->n = n;
    neighbours = new LinkedList[n]; // Allocated on the heap.
}

Graph::~Graph(){
    std::cout << "Graph destructor called.\n";
    delete[] neighbours;
}

void Graph::addEdge(int src, int dest, int w){
    /*
    Assuming that there is no edge between source & destination nodes.
    */
    std::cout << "Adding edge between nodes: " << src << ", " << dest << std::endl;
    neighbours[src].insert(dest, w);
    std::cout << "Adding edge between nodes: " << dest << ", " << src << std::endl;
    neighbours[dest].insert(src, w);
}

void Graph::removeEdge(int src, int dest){
    neighbours[src].remove(dest);
    neighbours[dest].remove(src);
}

void Graph::print_graph(){
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n[" << i << "] : ";
        neighbours[i].display();
    }
    
}















