#include <iostream>
using namespace std;

class TreeNode{
    int data;
    bool lbit, rbit;
    TreeNode *rch, *lch;
    TreeNode(int val){
        data = val;
        rch = lch = NULL;
    }
    friend class TBST;
};

class TBST{
    TreeNode *root;

    public:
        TBST(){
            root = NULL;
        }

        void insert(int val){

            TreeNode *curr = root;
            TreeNode *prev = NULL;

            while(curr!=NULL){

                if(curr->data == val){
                    cout << "Duplicate Value";
                    return;
                }

                prev = curr;

                if(val>curr->data){
                    if(!curr->rbit){
                        curr = curr->rch;
                    }
                    else{
                        break;
                    }
                }

                else{ 
                    if(val<curr->data){
                        if(!curr->lbit){
                            curr = curr->lch;
                        }
                        else{
                            break;
                        }  
                    }
                }
            }

            TreeNode *temp = new TreeNode(val);

            temp->lbit=temp->rbit=true;

            if(!prev){
                temp->lch = NULL;
                temp->rch = NULL;
                root = temp;
            }

            else if(val<prev->data){
                temp->lch = prev->lch;
                temp->rch = prev;
                prev->lbit = false;
                prev->lch = temp;
                
            }

            else{
                temp->rch = prev->rch;
                temp->lch = prev;
                prev->rbit = false;
                prev->rch = temp;
            }
            
        }

        TreeNode *inordersuccessor(TreeNode * temp){
            if(temp->rbit){
                return temp->rch;
            }
            temp = temp->rch;
            while(!temp->lbit){
                temp = temp->lch;
            }
            return temp;
        }

        TreeNode *inorderpredecessor(TreeNode * temp){
            if(temp->lbit){
                return temp->lch;
            }
            temp = temp->lch;
            while(!temp->rbit){
                temp = temp->rch;
            }
            return temp;

        }

    void inorder(){
        if(root == NULL){
            cout << "EMPTY!!";
            return;
        }
        TreeNode *ptr = root;
        while(!ptr->lbit){
            ptr = ptr->lch;
        }
        while(ptr != NULL){
            cout << ptr->data << " ";
            cout << "lbit is: " << ptr->lbit << "  ";
            cout << "rbit is: " << ptr->rbit << "  ";
            cout << endl; 
            ptr = inordersuccessor(ptr);
        }
        cout << endl;
    }

    void preorder(){
        if(root == NULL){
            cout << "EMPTY!!";
            return;
        }
        TreeNode *ptr = root;
        while(ptr != NULL){
            cout << ptr->data << " ";
            cout << "lbit is: " << ptr->lbit << "  ";
            cout << "rbit is: " << ptr->rbit << "  ";
            cout << endl; 
            if(ptr->lbit == false){
                ptr = ptr->lch;
            }                
            else if(ptr->rbit == false){
                ptr = ptr->rch;
            }
            else{
                while((ptr != NULL)&&(ptr->rbit==true)){
                    ptr = ptr->rch;
                }
                if(ptr != NULL){
                    ptr = ptr->rch;
                }
            }
        }
        cout << endl;        
    }

// Deletion Try from Ass1

};

int main(){

    TBST T;

    T.insert(10);
    T.insert(90);
    T.insert(43);
    T.insert(102);
    T.insert(901);
    T.insert(35);
    T.insert(150);
    T.insert(19);
    T.insert(433);    


    cout << "INORDER: " << endl;
    T.inorder();
    cout << endl;

    cout << "PREORDER: " << endl;
    T.preorder();
    cout << endl;
}
