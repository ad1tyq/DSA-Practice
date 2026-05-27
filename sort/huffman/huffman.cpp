#include <iostream>
using namespace std;

struct Node{
    char data;
    unsigned int freq;
    Node *left, *right; // pointers

    Node(char data, unsigned int freq){
        (*this).right = (*this).left = nullptr;
        (*this).data = data;
        (*this).freq = freq;
    }
};

class MinHeap{
    Node** arr; // pointer to the pointer
    int capacity;
    int size;

    public:
    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->arr = new Node*[capacity]; // Allocates an array of pointers to store Huffman Tree nodes for the heap.
    }

    void swapNodes(Node** a, Node** b){
        Node* t = *a;
        *a = *b;
        *b = t;
    }

    void minHeapify(int idx){
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && (*arr[left]).freq < arr[smallest]->freq){
            smallest = left;
        }
        if (right < size && (*arr[right]).freq < arr[smallest]-> freq){
            smallest = right;
        }

        if(smallest != idx){
            // this array contains pointers & using call by value so sending a pointer of pointer
            swapNodes(&arr[smallest], &arr[idx]); 
            minHeapify(smallest); // after swap we are heapifying from new smallest top
        }
    }

    Node* extractMin() {
        if (size <= 0) return nullptr;
        Node* temp = arr[0]; // temp is a pointer and arr[0] has a pointer
        arr[0] = arr[size-1];
        --size;
        minHeapify(0); // after the removal of top min and putting last val of array at top we min heapify the tree
        return temp; // returning the extracted pointer
    }

    void insert(Node* node){
        int i = (++size)-1;
        while(i && node->freq < arr[(i-1)/2]->freq){
            arr[i] = arr[(i-1)/2];
            i = (i-1)/2;
        }
        arr[i] = node;
    }

    int getSize() {return size;}
};

// Recursive function to print codes using a simple character array as a buffer
void printCodes(Node* root, char code[], int top){
    if(root->left){
        code[top] = '0';
        printCodes(root->left, code, top + 1); // root->left is the new top node
    }
    if(root->right){
        code[top] = '1';
        printCodes(root->right, code, top + 1); // root->right is the new top node
    }
    if(!root->left && !root->right){
        cout << root->data << ": ";
        for (int i = 0; i < top; ++i)
            cout << code[i];
        cout << endl;
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    MinHeap minHeap(size);

    for(int i=0; i<size; i++)
        minHeap.insert(new Node( data[i], freq[i]) );
    
    while (minHeap.getSize() != 1){
        Node* left = minHeap.extractMin();
        Node* right = minHeap.extractMin();

            // making a new node named $ and its freq is total of left and right
        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.insert(top); // inserting it to the minheap
    }

    char code[100]; // buffer array for code of the letter
    printCodes(minHeap.extractMin(), code, 0);
}

int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}

