#include <iostream>
#define MAX 50
#include <stack>
using namespace std;

class TreeNode{
    TreeNode *lch;
    TreeNode *rch;
    int data;
    friend class Tree;
    friend class Stack;
    public:
    TreeNode(){
        lch = NULL;
        rch = NULL;
        data = 0;
    }
};

class Tree{
    TreeNode *root;
    TreeNode *maketree();
    TreeNode *maketreeite();
    int cnt = 0;
    public:

        Tree(){
            root = NULL;
        }

        void create(){
            root = maketree();
        }

        void createite(){
            root = maketreeite();
        }

        void inorder(TreeNode *temp);
        void preorder(TreeNode *temp);
        void postorder(TreeNode *temp);

        void inorderite(TreeNode *temp);
        void preorderite(TreeNode *temp);
        void postorderite(TreeNode *temp);

        void leafcountcall();
        int getleafcount(TreeNode *temp);

        void nodecountcall();
        int getnodecount(TreeNode *temp);

        void heightcall();
        int getheight(TreeNode *temp);

        void mirrorcall();
        void mirror(TreeNode *temp);
        void mirrorite(TreeNode *temp);

        void deletetreecall();
        void deletetree(TreeNode *temp);

        Tree operator=(Tree T);
        TreeNode *copy(TreeNode *temp);

        TreeNode *getroot(){
            return root;
        }
};

class Stack{
    TreeNode* arr[MAX];
    int top;
    public:
    void push(TreeNode *temp);
    void pop();
    bool isFull();
    bool isEmpty();
    TreeNode *gettop(){
        return arr[top];
    }

    Stack(){
        top = 0;
        arr[top] = NULL;
    }
};

void Stack :: push(TreeNode *temp){
    if(isFull()){
        cout << "Stack Overflow";
    }
    else{
        top++;
        arr[top] = temp;
        if(isFull()){
            cout << "Stack is now Full";
        }
    }
}

void Stack :: pop(){
    if(isEmpty()){
        cout << "Stack Underflow";
    }
    else{
        top--;
        /*if(isEmpty()){
            cout << "Stack is now Empty";
        }*/
    }
}

bool Stack :: isFull(){
    if(top == MAX){
        return true;
    }
    else{
        return false;
    }
}

bool Stack :: isEmpty(){
    if(top == 0){
        return true;
    }
    else{
        return false;
    }
}

TreeNode *Tree :: maketree(){

    TreeNode *temp;
    temp = new TreeNode;

    char ch;

    cout << "Enter Data:";
    cin >> temp->data;

    cout << "\nDo you want to add a right child of " << temp->data << "(y/n)\n";
    cin >> ch;
    if(ch == 'y'){
        temp->rch = maketree();
        }

    cout << "\nDo you want to add a left child of " << temp->data << "(y/n)\n";
    cin >> ch;
    if(ch == 'y'){
        temp->lch = maketree();
    }

    return temp;
}

void Tree :: inorder(TreeNode *temp){

    if(temp!=NULL){
        inorder(temp->lch);
        cout << temp->data << " ";
        inorder(temp->rch);
        }
}

void Tree :: preorder(TreeNode *temp){

    if(temp!=NULL){
        cout << temp->data << " ";
        preorder(temp->lch);
        preorder(temp->rch);
    }
}

void Tree :: postorder(TreeNode *temp){

    if(temp!=NULL){
        postorder(temp->lch);
        postorder(temp->rch);
        cout << temp->data << " ";
        }
}

void Tree :: inorderite(TreeNode *temp){

    Stack s;

    while(temp!=NULL || !s.isEmpty()){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->lch;
        }
        temp = s.gettop();
        s.pop();
        cout << temp->data << " ";
        temp = temp->rch;
    }
}

void Tree :: preorderite(TreeNode *temp){

    Stack s;

    while(temp!=NULL || !s.isEmpty()){
        while(temp!=NULL){
            s.push(temp);
            cout << temp->data << " ";
            temp = temp->lch;
        }
        temp = s.gettop();
        s.pop();
        temp = temp->rch;
    }
}

void Tree :: postorderite(TreeNode *temp){
    Stack s1, s2;

    s1.push(temp);
    while(!s1.isEmpty()){
        temp = s1.gettop();
        s1.pop();
        s2.push(temp);
        if(temp->lch){
            s1.push(temp->lch);
        }
        if(temp->rch){
            s1.push(temp->rch);
        }
    }
    while(!s2.isEmpty()){
        temp = s2.gettop();
        cout << temp->data << " ";
        s2.pop();
    }
}


void Tree :: leafcountcall(){
    cout << "The Number of Leaves is: " << getleafcount(root);
}

int Tree :: getleafcount(TreeNode *temp){
    if(temp->lch == NULL && temp->rch == NULL){
        cnt++;
    }
    else if(temp->lch == NULL){
        getleafcount(temp->rch);
    }
    else if(temp->rch == NULL){
        getleafcount(temp->lch);
    }
    else{
        getleafcount(temp->lch);
        getleafcount(temp->rch);
    }
    return cnt;
}


void Tree :: nodecountcall(){
    cout << "The Number of Nodes is: " << getnodecount(root);
}

int Tree :: getnodecount(TreeNode *temp){
    if(temp == NULL){
        return 0;
    }
    else{
        int l = getnodecount(temp->lch);
        int r = getnodecount(temp->rch);
        return l+r+1;
    } 
}


void Tree :: heightcall(){
    cout << "Height is: " << getheight(root);
}

int Tree :: getheight(TreeNode *temp){
    int x, y;
    if(temp == NULL){
        return -1;
    }
    else{
        x = getheight(temp->lch);
        y = getheight(temp->rch);
        if(x>y){
            return ++x;
        }
        else{
            return ++y;
        }
    }
}


void Tree :: mirrorcall(){
    mirror(root);
}
void Tree :: mirror(TreeNode *temp){
    TreeNode *extra;
    if(temp!=NULL){
        mirror(temp->lch);
        mirror(temp->rch);
        extra = temp->lch;
        temp->lch = temp->rch;
        temp->rch = extra;
    }
}


void Tree :: deletetreecall(){
    deletetree(root);
    cout << "Tree Deleted";
}

void Tree :: deletetree(TreeNode *temp){
    if(temp!=NULL){
        deletetree(temp->lch);
        deletetree(temp->rch);
        delete temp;
    }
}

Tree Tree :: operator=(Tree T){
    Tree tree;
    tree.root = copy(T.root);
    return tree;
} 

TreeNode *Tree :: copy(TreeNode *temp){
    if (temp!=NULL){

        TreeNode *t = new TreeNode;
        t->data = temp->data;

        if(temp->lch == NULL){
            t->lch = NULL;
        }
        else{
            t->lch = copy(temp->lch);
        }

        if(temp->rch == NULL){
            t->rch = NULL;
        }
        else{
            t->rch = copy(temp->rch);
        }
        return t;
    }
}

int main(){

    Tree T;
    int choice;


    while(1<2){
        cout<<"\n***************** MENU *****************";
            cout<<"\n1.Create Binary Tree";
            cout<<"\n2.Traverse With Recursion";
            cout<<"\n3.Traverse Without recursion";
            cout<<"\n4.Display Count of Leaves";
            cout<<"\n5.Display Count of Nodes";
            cout<<"\n6.Display Height";
            cout<<"\n7.Copy Tree";
            cout<<"\n8.Mirror Tree";
            cout<<"\n9.Delete Tree";
            cout<<"\n10.Exit";
            cout<<"\n\nEnter your choice : ";
            cout<<"\n>>";

            cin>>choice;

        if(choice == 1){
            T.create();
        }
        else if(choice == 2){
            cout << endl << "Inorder Recursive: ";
            T.inorder(T.getroot());
            cout << endl << "Preorder Recursive: ";
            T.preorder(T.getroot());
            cout << endl  << "Postorder Recursive: ";
            T.postorder(T.getroot());

            cout << endl;

        }
        else if(choice == 3){
            cout << endl << "Inorder Iterative: ";
            T.inorderite(T.getroot());
            cout << endl << "Preorder Iterative: ";
            T.preorderite(T.getroot());
            cout << endl  << "Postorder Iterative: ";
            T.postorderite(T.getroot());

            cout << endl;
        }
        else if(choice == 4){
            T.leafcountcall();
        }
        else if(choice == 5){
            T.nodecountcall();
        }
        else if(choice == 6){
            T.heightcall();
        }
        else if(choice == 7){
            T.mirrorcall();

            cout << endl << "Inorder Recursive: ";
            T.inorder(T.getroot());
            cout << endl << "Preorder Recursive: ";
            T.preorder(T.getroot());
            cout << endl  << "Postorder Recursive: ";
            T.postorder(T.getroot());

            cout << endl;
        }
        else if(choice == 8){
            T.deletetreecall();
        }
        else if(choice == 9){
            Tree tree;
            tree = T;

            cout << "Copied Tree is:";

            cout << endl << "Inorder Recursive: ";
            T.inorder(T.getroot());
            cout << endl << "Preorder Recursive: ";
            T.preorder(T.getroot());
            cout << endl  << "Postorder Recursive: ";
            T.postorder(T.getroot());

            cout << endl;
        }
        else if(choice == 10){
            cout << "EXIING...";
            cout << endl << "EXITED";
            return 0;
        }
        else{
            cout << "INVALID RESPONSE";
        }
}

}
