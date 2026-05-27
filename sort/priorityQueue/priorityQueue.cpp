#include <iostream>
#include <vector>
using namespace std;

struct Task{
    int id;
    int priority;
};

struct RawPQ{
    Task* heap;
    int capacity; int size;

    RawPQ(int initial_capacity){
        capacity = initial_capacity;
        size = 0;
        heap = new Task[capacity];
    }

    // Destructor: Clean up memory when done (No leaks!)
    ~RawPQ(){
        delete[] heap;
    }

    void swap_task(Task& a, Task& b){
        Task t = a;
        a = b;
        b = t;
    }

    void enqueue(int id, int priority){
        if(size == capacity){
            capacity *= 2;
            Task* newHeap = new Task[capacity];
            for(int i=0; i<size; i++) newHeap[i] = heap[i];
            delete[] heap;
            heap = newHeap;
        }

        heap[size].id = id;
        heap[size].priority = priority;

        int index = size; // cause array starts from 0 but size is 1 to whtv right
        while (index > 0){
            int parentIndex = (index-1)/2;
            if(heap[parentIndex].priority < heap[index].priority){
                swap_task(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
        size++;

    }

    void dequeue(){
        if (size == 0) return;
        cout << "Dequeued vehicle with Vehicle ID: " << heap[0].id << " (Priority: " << heap[0].priority << ")\n";
        heap[0] = heap[size-1];
        size--; // we arent actually deleting that space but when we enqueue again at that space we wont need to alot new memory
            
        int i=0;
        while(true){
            int largest = i;
            int left = (2*i)+1;
            int right = (2*i)+2;

            if(left<size && heap[largest].priority < heap[left].priority){
                largest = left;
            }
            if(right<size && heap[largest].priority < heap[right].priority){
                largest = left;
            }
            if (largest != i){
                swap_task(heap[largest], heap[i]);
                i = largest;
            } else {
                break;
            }
        }
    }
};

int main(){
    RawPQ pq(10);
    int id, priority;
    char choice;

    do {
        cout << "enter id:";
        cin >> id; 
        cout << "enter priority:";
        cin >> priority;
        pq.enqueue(id, priority);
     
        cout << "continue adding? (y/n)";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Output Loop (Empty the queue)
    while (pq.size > 0) {
        pq.dequeue();
    }

    return 0;
}
