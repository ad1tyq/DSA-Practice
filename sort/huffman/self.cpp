#include <iostream>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
};

class MinHeap{
    int size;
    int capacity;
    Node** arr; // because new returns a ptr idk man i will ask gemini gemini if u read this answer me why, also whys there no []

    public:
    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->arr = new Node*[capacity];
    };

    void swapNodes(Node **a, Node **b){
        Node *t = *a;
        *a = *b;
        *b = t;
    }

    void minHeapify(int idx){
        int smallest = idx;
        int right = (idx*2)+1;
        int left = (idx*2)+2;

        if(right<size && arr[right]->freq < arr[smallest]->freq){
             smallest = right;
        }
        if(left<size && arr[left]->freq < arr[smallest]->freq){
            smallest = left;
        }
        if(smallest != idx){
            swapNodes(&arr[idx], &arr[smallest]);
            minHeapify(smallest);
        } else {
            return;
        }
    }

    Node* extractMin(){
        if (size<=0) return nullptr;
        Node* t = arr[0]; 
        arr[0] = arr[(size--)-1];
        minHeapify(0);
        return t;
    }

    void insert(Node* node){
        int i = (++size)-1;
        arr[i] = node;
        while(i && arr[i]->freq < arr[(i-1)/2]->freq){
            swapNodes(&arr[i], &arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int getSize() { return size; }
};

void printCodes(Node* node, char codes[], int topIdx){
    if(node->left){
        codes[topIdx] = '0';
        printCodes(node->left, codes, topIdx+1);
    }
    if(node->right){
        codes[topIdx] = '1';
        printCodes(node->right, codes, topIdx+1);
    }
    if(!node->right && !node->left){
        cout << node->data << ": ";
        for(int i=0; i<topIdx; i++) cout << codes[i];
        cout << endl;
    }
}

void HuffmanCodes(char arr[], int freq[], int size){
    MinHeap minheap(size);
    
    for(int i=0; i<size; i++) minheap.insert(new Node ( arr[i], freq[i] ));
    
    // creating huffman tree:
    while(minheap.getSize() != 1){
        Node* left = minheap.extractMin();
        Node* right = minheap.extractMin();

        Node* top = new Node ('$', left->freq+right->freq);
        top->left = left;
        top->right = right;

        minheap.insert(top);
    }

    char codes[100];
    printCodes(minheap.extractMin(), codes, 0);
}

int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}
