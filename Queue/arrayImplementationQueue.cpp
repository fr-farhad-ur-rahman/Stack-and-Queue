#include <iostream>
using namespace std;

// Creating Queue data structure.
class Queue{
private:
    // declaring variables.
    int* arr;
    int capacity;
    int rear;
    int sz;

public:
    // constructor.
    Queue(int size){
        arr = new int[size];
        this -> capacity = size;
        rear = -1;
        sz = 0;
    }

    // destructor
    ~Queue(){
        delete[] arr;
    }

    // function definition.
    bool empty();
    void enqueue(int data);
    int dequeue();
    int size();
    int peek();
};

// function implementaion
bool Queue :: empty(){
    return rear == -1;
}

void Queue :: enqueue(int data){
    if(rear == capacity - 1){
        cout << "Queue is full" << endl;
        return;
    }
    rear++;
    sz++;
    arr[rear] = data;
}

int Queue :: dequeue(){
    if(empty()){
        cout << "Queue is Empty" << endl;
    }

    int front = arr[0];
    for(int i = 0; i < rear; i++){
        arr[i] = arr[i + 1];
    }
    rear--;
    sz--;
    return front;
}

int Queue :: size(){
    return sz;
}

int Queue :: peek(){
    if(empty()){
        cout << "Queue is Empty" << endl;
        return -1;
    }

    return arr[0];
}

int main(){
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);

    queue.dequeue();

    while(not (queue.empty())){
        cout << queue.peek() << endl;
        queue.dequeue();
    }

    return 0;
}
