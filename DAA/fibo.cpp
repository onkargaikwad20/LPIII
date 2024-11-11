#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if (n <= 1) return n;
    
    int prev1 = 0, prev2 = 1, result;
    for (int i = 2; i <= n; i++) {
        result = prev1 + prev2;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci number: ";
    cin >> n;

    
    auto start_recursive = high_resolution_clock::now();
    int result_recursive = fibonacciRecursive(n);
    auto end_recursive = high_resolution_clock::now();
    auto duration_recursive = duration_cast<nanoseconds>(end_recursive - start_recursive);
    
    cout << "Recursive Fibonacci of " << n << " is " << result_recursive << endl;
    cout << "Time taken by recursive approach: " << duration_recursive.count() << " nanoseconds" << endl;
    cout << "Space complexity of recursive approach: O(n) (due to recursion stack)" << endl;

    
    auto start_iterative = high_resolution_clock::now();
    int result_iterative = fibonacciIterative(n);
    auto end_iterative = high_resolution_clock::now();
    auto duration_iterative = duration_cast<nanoseconds>(end_iterative - start_iterative);
    
    cout << "Iterative Fibonacci of " << n << " is " << result_iterative << endl;
    cout << "Time taken by iterative approach: " << duration_iterative.count() << " nanoseconds" << endl;
    cout << "Space complexity of iterative approach: O(1) (constant space)" << endl;

    return 0;
}