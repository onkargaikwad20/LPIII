#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        cout << root->ch << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void buildHuffmanTree(unordered_map<char, int> &freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    
    while (minHeap.size() != 1) {
       
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

       
        int sum = left->freq + right->freq;
        Node *newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    printCodes(root, "");
}

int main() {
    int n;
    unordered_map<char, int> freqMap;

    cout << "Enter the number of characters: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cout << "Enter character:" << endl;
        cin >> ch;
        cout<<"enter the frequency:"<<endl;
        cin>>freq;
        freqMap[ch] = freq;
    }

    buildHuffmanTree(freqMap);

    return 0;
}