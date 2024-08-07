#include <iostream>
#include <string>
using namespace std;

class element{
    long phone;
    string name;
    int check;
    friend class Hash;
    element(){
        name = "empty";
        phone = 0;
    }
};

class Hash{
    element *withreplacement;
    element *withoutreplacement;
    int size = 0;
    public:
    Hash(int n){
        withreplacement = new element[n];
        withoutreplacement = new element[n];
        size = n;
    }

    void display();
    void insert_withoutreplacement(string name, long int number);
    void search_withoutreplacement(string name);
    void insert_withreplacement(string name, long int number);
    void search_withreplacement(string name);
};

void Hash :: display(){
    cout << "Linear Probing Without Replacement: " << endl;
    for (int i = 0; i<size; i++){
        cout << i << ") Name: " << withoutreplacement[i].name << "  Phone Number: " << withoutreplacement[i].phone << endl;
    }
    cout << endl << "Linear Probing With Replacement: " << endl;
    for (int i = 0; i<size; i++){
        cout << i << ") Name: " << withreplacement[i].name << "  Phone Number: " << withreplacement[i].phone << endl;
    }
}

void Hash :: insert_withoutreplacement(string name, long int number){
    int x = name.length()%(size);
    int ix = x; 

    while(1){
        if(withoutreplacement[x].phone == 0){
            withoutreplacement[x].phone = number;
            withoutreplacement[x].name = name;
            break;
        }
        if(x < (size-1)){
            x++;
        }
        else{
            x = 0;
        }
        if(ix == x){
            cout << "Array Full" << endl;
            break;
        }
    }
}

void Hash :: insert_withreplacement(string name, long int number){
    int x = name.length()%(size);
        int ix = x;

        if(withreplacement[x].phone == 0){
                withreplacement[x].phone = number;
                withreplacement[x].name = name;
                return;
        }
        else if (x!=(withreplacement[x].name.length()%size)){
            string temp = withreplacement[x].name;
            withreplacement[x].name = name;
            name = temp;
            long int numtemp = withreplacement[x].phone;
            withreplacement[x].phone = number;
            number = numtemp;
        }
        while(1){
            if(withreplacement[x].phone == 0){
                withreplacement[x].phone = number;
                withreplacement[x].name = name;
                break;
            }
            if (x<(size-1)){
                x=x+1;
            }else{
                x=0;
            }
            if(ix==x){
                cout<<"Array is full"<<endl;
                break;
            }
        }

}

void Hash :: search_withoutreplacement(string name){
    int comps = 0;
    int x = name.length()%size;
    int ix = x;
    while(1){
        comps++;

        if(withoutreplacement[x].name == name){
            cout<<"Phone Number of client "<<withoutreplacement[x].name<<" is: "<<withoutreplacement[x].phone<<endl;
            cout<<"Number of comparisons in Linear Probing without replacement is: "<<comps<<endl;
            break;
        }
        else{
        }
        if(x<(size-1)){
            x++;
        }
        else{
            x = 0;
        }
        if(ix == x){
            cout << "Array Not Found";
            break;
        }
    }
}

void Hash :: search_withreplacement(string name){
    int comps = 1;
    int x = name.length()%size;
    int ix = x;
    while(1){
        comps++;

        if(withreplacement[x].name == name){
            cout<<"Phone Number of client "<<withreplacement[x].name<<" is: "<<withreplacement[x].phone<<endl;
            cout<<"Number of comparisons in Linear Probing without replacement is: "<<comps<<endl;
            break;
        }
        else{
        }
        if(x<(size-1)){
            x++;
        }
        else{
            x = 0;
        }
        if(ix == x){
            cout << "Array Not Found";
            break;
        }
    }
}

int main(){

    int n,val;
    string client;
    long int telephoneno;
    cout<<"Enter number of clients: ";
    cin>>n;
    Hash h(n);
    while (1){
		cout<<"\n\nEnter 1 to insert a client in directory\nEnter 2 for searching number of client\nEnter 3 to display hash table\nEnter 0 to exit ";
		cin>>val;
		if (val==0){
			cout<<"\n\nThankyou"<<endl;
			break;
		}
		else if(val==1){
			cout<<"Enter client name: ";
			cin>>client;
            cout<<"Enter client Telephone number: ";
			cin>>telephoneno;
            h.insert_withoutreplacement(client,telephoneno);
            h.insert_withreplacement(client,telephoneno);
		}
		else if(val==2){
			cout<<"Enter client name to be searched: ";
			cin>>client;
            h.search_withoutreplacement(client);
            h.search_withreplacement(client);
		}
        else if(val==3){
            h.display();
		}
    }

    return 0;
}
