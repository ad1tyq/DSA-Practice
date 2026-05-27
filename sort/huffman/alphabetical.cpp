#include <iostream>
using namespace std;

struct Result{
    char character;
    string code;
};

struct Node{
    char data;
    unsigned int freq;
    Node *left, *right;

    Node(int data, unsigned int freq){
        this->data = data;
        this->freq = freq;
        this->right = this->left = nullptr;
    }
};

class MinHeap{
    int size;
    int capacity;
    Node** arr;

    public:
    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->arr = new Node*[capacity];
    };
    
    void swapNodes(Node** a, Node** b){
        Node * t = *a;
        *a = *b;
        *b = t;
    }

    void minHeapify(int idx){
        int smallest = idx;
        int left = (idx*2)+1;
        int right = (idx*2)+2;

        if(left< size && arr[left]->freq < arr[smallest]->freq){
            smallest = left;
        }
        if(right < size && arr[right]->freq < arr[smallest]->freq){
            smallest = right;
        }
        if(smallest != idx){
            swapNodes(&arr[smallest], &arr[idx]);
            minHeapify(smallest);
        }
    }

    Node* extractMin(){
        if (size<=0) return nullptr;
        Node* temp = arr[0];
        arr[0] = arr[(size--)-1];
        minHeapify(0);
        return temp;
    }

    void insert(Node* node){
        int i = (++size)-1;
        while(i && node->freq < arr[(i-1)/2]->freq){
            arr[i] = arr[(i-1)/2];
            i = (i-1)/2;
        }
        arr[i] = node;
    }

    int getSize() { return size; }
};

void storeCodes(Node* root, string str, Result store[], int &index){
    if (!root)
        return;

    if (!root->left && !root->right) {
        store[index].character = root->data;
        store[index].code = str;
        index++; // Move to next slot in array
    }

    storeCodes(root->left, str + "0", store, index);
    storeCodes(root->right, str + "1", store, index);
}

void bubbleSort(Result arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].character > arr[j + 1].character) {
                // Swap manually
                Result temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void HuffmanCodes(char arr[],unsigned int freq[], int size){
    MinHeap minheap(size);

    for(int i=0; i<size; i++) minheap.insert(new Node( arr[i], freq[i] )); // creating a minheap

    while(minheap.getSize() != 1){
        Node* left = minheap.extractMin();
        Node* right = minheap.extractMin();

       Node* top = new Node('$', left->freq + right->freq);
       top->left = left;
       top->right = right;
       minheap.insert(top);
    }

    // creating an array of Result structures
    Result* results = new Result[size];
    int index = 0;

    storeCodes(minheap.extractMin(), "", results, index);
    bubbleSort(results, size);

    for (int i = 0; i < size; i++) {
        cout << results[i].character << ": " << results[i].code << endl;
    }
}


int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}
