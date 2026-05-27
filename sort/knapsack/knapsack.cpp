#include <iostream>
// #include <iomanip>
using namespace std;

struct Item{
    int id;
    int weight;
    int profit;
    int ratio;
};

void customSwap(Item* a, Item* b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(Item items[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(items[j].ratio < items[j+1].ratio){
                customSwap(&items[j], &items[j+1]);
            }
        }
    }
}

int main(){
    Item items[100];
    cout << "enter size: ";
    int n;
    if (!(cin >> n)) return 0;

    for(int i=0; i<n; i++){
        items[i].id = i;
        cout << "enter profit: ";
        cin >> items[i].profit;  
        cout << "enter weight for " << items[i].profit << ": ";
        cin >> items[i].weight;
        items[i].ratio = items[i].profit / items[i].weight;
        cout << "profit: " << items[i].profit << endl << "weight: " << items[i].weight << endl << "ratio: " << items[i].ratio << endl << endl;
    }

    double capacity;
    cout << "enter capacity: ";
    cin >> capacity;

    sortItems(items, n);

    double totalProfit = 0.0;
    double fractions[100];

    for(int i=0; i<n; i++) fractions[i] = 0.0;

    for(int i=0; i<n; i++){

        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            fractions[items[i].id] = 1.0;
        } else {
            double fraction = capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            fractions[items[i].id] = fraction;
            capacity = 0; 
            break;
        }
    }

   cout << "Objects worth Rs." /*<< fixed << setprecision(2) */<< totalProfit << endl;

    return 0;
}
