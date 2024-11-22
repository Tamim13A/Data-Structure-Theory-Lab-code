#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//Create new node
Node* newNode(int data){
    Node* node=new Node();
    node->data=data;
    node->left=node->right=nullptr;
    return node;
}

//insert new value
Node* insert(Node* root, int data){
    if(root==nullptr){
        return newNode(data);
    }
    if(data < root->data){
        root->left=insert(root->left,data);
    }else if(data > root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

//Tabular format print
void printTree(Node* root){
    if(root==nullptr){
        return;
    }

    cout<< "\n\tNode`s value: " << root->data<<endl;
    
    //left child
    if(root->left){
        cout<< "   Left: " << root->left->data;
    }else{
        cout<< "   Left: NULL";
    }
    //right child
    if(root->right){
        cout<< "   Right: " << root->right->data;
    }else{
        cout<< "   Right: NULL";
    }
    cout<<endl;
    //recursive process
    printTree(root->left);
    printTree(root->right);
}
int main(){
    Node* root=nullptr;
   
    root=insert(root, 50);
    root=insert(root, 40);
    root=insert(root, 22);
    root=insert(root, 13);
    root=insert(root, 91);
    root=insert(root, 70);
    root=insert(root, 34);
    root=insert(root, 80);
    root=insert(root, 93);
    root=insert(root, 98);
    root=insert(root, 100);
    root=insert(root, 113);
    root=insert(root, 124);
    root=insert(root, 122);
    root=insert(root, 135);

    printTree(root);

  return 0;
}
