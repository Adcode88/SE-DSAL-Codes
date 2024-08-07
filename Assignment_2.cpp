#include <iostream>
using namespace std;

class TreeNode{
    int data;
    TreeNode *lch, *rch;
    friend class Stack;
    friend class BST;
    TreeNode(int value){
        lch = NULL;
        rch = NULL;
        data = value;
    }
};

class BST{
    TreeNode *root;

    public:

        BST(){
            root = NULL;
        }

        void insert(int value){
            TreeNode *node = new TreeNode(value);

            if(!root){
                root = node;
            }
            else{
                TreeNode *temp = root;

                while(1){
                    if(value >= temp->data){
                        if(temp->rch){
                            temp = temp->rch;
                        }
                        else{
                            temp->rch = node;
                            break;
                        }
                    }
                    else{
                        if(temp->lch){
                            temp = temp->lch;
                        }
                        else{
                            temp->lch = node;
                            break;
                        }
                    }
                }
            }
        }

        void inorder(TreeNode *temp){
            if(temp){    
                inorder(temp->lch);
                cout << temp->data << " ";
                inorder(temp->rch);
            }
        }

        void reverse(TreeNode *temp){
            if(temp){    
                reverse(temp->rch);
                cout << temp->data << " ";
                reverse(temp->lch);
            }
        }

        TreeNode *MinValue(TreeNode *temp){
            TreeNode * curr = temp;
            while(curr->lch != NULL){
                curr = curr->lch;
            }
            return curr;
        }

        TreeNode *MaxValue(TreeNode *temp){
            TreeNode * curr = temp;
            while(curr->rch != NULL){
                curr = curr->rch;
            }
            return curr;
        }

        int minmaxvalue(TreeNode *temp){
            return temp->data;
        }


        TreeNode *deletenode(TreeNode *temp, int key){

            if(key>temp->data){
                temp->rch = deletenode(temp->rch, key);
            }
            else if(key<temp->data){
                temp->lch = deletenode(temp->lch, key);
            }
            else{
                if(temp->rch == NULL || temp->lch == NULL){
                    TreeNode *node1;
                    if(temp->lch != NULL){
                        node1 = temp->lch;
                    }
                    else{
                        node1 = temp->rch;
                    }

                    if(node1 == NULL){
                        node1 = temp;
                        temp = NULL;
                    }
                    else{
                        temp->data = node1->data;
                        temp->lch = NULL;
                        temp->rch = NULL;
                    }

                    delete node1;
                }
                else{
                    TreeNode *node1 = MinValue(temp->rch);
                    temp->data = node1->data;

                    temp->rch = deletenode(temp->rch, node1->data);
                }
            }
            return temp;
        }

        void search(TreeNode *temp, int val){
            TreeNode *curr = temp;
            int c = 0;
            while(curr){
                if(val != curr->data){
                    c++;
                    if(val>curr->data){
                        curr = curr->rch;
                        c++;
                    }
                    else{
                        curr = curr->lch;
                        c++;
                    }
                }
                else{
                    cout << "Element Found After " << c << " Comparisons";
                    return;
                }
            }
            cout << "Element Not Found";
        }

        int height(TreeNode *temp){
            if(temp == NULL){
                return -1;
            }
            else{
                int x = height(temp->lch);
                int y = height(temp->rch);

                if(x>y){
                    return ++x;
                }
                else{
                    return ++y;
                }
            }
        }

        void swapped(TreeNode *temp){
            TreeNode *node1;
            if(temp != NULL){
                swapped(temp->lch);
                swapped(temp->rch);
                node1 = temp->lch;
                temp->lch = temp->rch;
                temp->rch = node1;
            }
        }

        TreeNode *getroot(){
            return root;
        }
};

int main(){

    BST T;
    int val;

    while(1){
		cout<<"Enter value to be inserted in tree or 0 to exit: ";
		cin>>val;
		if (val==0){
			break;
		}
		T.insert(val);
        }

    cout << "Ascending Order:  ";
    T.inorder(T.getroot());
    cout << endl << "Descending Order: ";
    T.reverse(T.getroot());

    T.deletenode(T.getroot(), 255);

    cout << endl << endl  << "After Deleting 255:"<< endl;

    cout << "Ascending Order:  ";
    T.inorder(T.getroot());
    cout << endl << "Descending Order: ";
    T.reverse(T.getroot());


    cout << endl << endl << "Min Value is: " << T.minmaxvalue(T.MinValue(T.getroot()));
    cout << endl << "Max Value is: " << T.minmaxvalue(T.MaxValue(T.getroot()));

    cout << endl << endl << "Searching 84" << endl;
    T.search(T.getroot(), 84);

    cout << endl << endl << "Longest Path is:" << T.height(T.getroot());

    cout << endl << endl << "Mirroring" << endl;
    T.swapped(T.getroot());

    cout << "Ascending Order:  ";
    T.inorder(T.getroot());
    cout << endl << "Descending Order: ";
    T.reverse(T.getroot());   

}
