#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    float ratio;
};


bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

float fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);  

    int currWeight = 0;  
    float totalValue = 0.0;

  
    cout << "Item   Weight   Value   Ratio      Taken\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < items.size(); i++) {
        if (currWeight + items[i].weight <= W) {
           
            currWeight += items[i].weight;
            totalValue += items[i].value;

           
            cout << i + 1 << "      " << items[i].weight << "        " 
                 << items[i].value << "       " 
                 << items[i].ratio << "      Fully\n";

        } else {
            
            int remainingWeight = W - currWeight;
            float fraction = (float)remainingWeight / items[i].weight;
            totalValue += items[i].value * fraction;

           
            cout << i + 1 << "      " << items[i].weight << "        " 
                 << items[i].value << "       " 
                 << items[i].ratio << "      Partially (" << (fraction * 100) << "%)\n";
            break;  
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);

    
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;

        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    cout << "\nTable of Items (sorted by value-to-weight ratio):\n";
    float maxValue = fractionalKnapsack(W, items);
    cout << "\nMaximum value we can obtain = " << maxValue << endl;

    return 0;
}
