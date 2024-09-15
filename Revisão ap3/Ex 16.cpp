#include <iostream>
using namespace std;

struct Node{
        Node *left;
        int value;
        Node *right;
     };

void Destroy(Node *root){
    if(root == nullptr) return;
    Destroy(root->left);
    Destroy(root->right);
    delete root;
    root = nullptr;
}

Node* TransformToTree(int *vec, int size){
    if(size == 0) return nullptr;
    Node *root = nullptr;
    try{
    if(size == 1){
        root = new Node{nullptr, *vec, nullptr};
        return root;
    }
    else{
        int middle = size/2;
        root = new Node; root->value = *(vec+middle);
        try{
        root->left = TransformToTree(vec, middle); 
        }
        catch(bad_alloc &e){
            Destroy(root);
            throw;
        }
        try{
            root->right = TransformToTree((vec+middle+1), (size-middle-1));
        }
        catch(bad_alloc &e){
            Destroy(root);
            throw;
        }
    }
} 
catch(bad_alloc &e){
    throw;
}

}

void OrderPrint(Node *root){
    if(root == nullptr) return;
    OrderPrint(root->left);
    cout << root-> value << " ";
    OrderPrint(root->right);
}

int main(){
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; 
    try{
    Node *root = TransformToTree(vec, 30);
    OrderPrint(root);
    Destroy(root);
    }
    catch(bad_alloc &e){
        cout << e.what();
    }


    return 0;
}