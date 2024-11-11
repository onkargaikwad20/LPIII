#include<iostream>
using namespace std;

void knapsack(int n, int w, int wt[], int pr[]) {
    int mat[n+1][w+1];  
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                mat[i][j] = 0;  
            } else if (wt[i-1] <= j) {
                mat[i][j] = max(pr[i-1] + mat[i-1][j-wt[i-1]], mat[i-1][j]);
            } else {
                mat[i][j] = mat[i-1][j];  
            }
        }
    }

    
    cout << "Maximum profit: " << mat[n][w] << endl;

   
    int remainingCapacity = w;
    int taken[n] = {0};  
   
    for (int i = n; i > 0; i--) {
        if (mat[i][remainingCapacity] != mat[i-1][remainingCapacity]) {
            taken[i-1] = 1; 
            remainingCapacity -= wt[i-1];  
        }
    }

   
    cout << "Objects taken (1 = taken, 0 = not taken): ";
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << taken[i];
        if (i < n-1) cout << ", ";  
    }
    cout << "]" << endl;

   
    cout << "DP table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, w;
    
    cout << "Enter the total number of objects: ";
    cin >> n;

    int wt[n], pr[n];  

    
    for (int i = 0; i < n; i++) {
        cout << "Enter weight for object " << i+1 << ": ";
        cin >> wt[i];
        cout << "Enter profit for object " << i+1 << ": ";
        cin >> pr[i];
    }

    cout << "Enter the capacity: ";
    cin >> w;

    
    knapsack(n, w, wt, pr);

    return 0;
}
