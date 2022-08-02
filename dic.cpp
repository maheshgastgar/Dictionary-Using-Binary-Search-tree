


 #include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
    string word;
    string meaning;
    node *left, *right;
};
struct node *root = NULL;

struct node *createNode(string word, string meaning){
    struct node *newNode = new node;
    newNode->word = word;
    newNode->meaning = meaning;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(string word, string meaning){
    struct node *current=NULL, *parent=NULL, *newnode=NULL;
    if(root==NULL){
        root = createNode(word, meaning);
        return;
    }

    int flag=0;

    for(current=root;current!=NULL;current=(flag>0)?current->right:current->left){
        flag = word.compare(current->word);
        if(flag==0){
            cout<<"Duplicate Found"<<endl;
            return;
        }
        parent=current;
    }
    newnode = createNode(word, meaning);
    if(flag>0){
        parent->right = newnode;
    }
    else{
        parent->left = newnode;
    }
}

void search(string word){
    struct node *temp=NULL;
    int flag=0;
    int ans=0;
    if(root==NULL){
        cout<<"Binary Tree is empty"<<endl;
    }
    else{
        temp=root;

        while(temp){
            ans=word.compare(temp->word);
            if(ans==0){
                cout<<"Word Found"<<endl;
                cout<<"Word: "<<temp->word<<endl;
                cout<<"Meaning: "<<temp->meaning<<endl;
                flag=1;
                break;
            }
        temp=(ans<0)?temp->left:temp->right;
        }
        if(!flag){
            cout<<"Word not found"<<endl;
        }
        return;
    }
}

void _delete(string word){
    struct node *current=NULL, *parent=NULL, *temp=NULL;
    int flag=0, ans=0;

    if(root==NULL){
        cout<<"Binary Tree is empty"<<endl;
    }

    current=root;

    while(true){
        ans=current->word.compare(word);
        if(ans==0){
            break;
        }
        flag=ans;

        parent=current;
        current=(ans>0)?current->right:current->left;
        if(current==NULL){
            return;
        }
    }

    if (current->left == NULL && current->right == NULL)
    {

        if (current != root)
        {
            if (parent->left == current) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            root = NULL;
        }

        free(current);
    }



}



void read()
{

        ifstream file;
        file.open("project11.csv");
        int flag=0;
        while(file.good()){
            string word,meaning;
            getline(file, word, ',');
            getline(file, meaning);
            //cout<<word<<" "<<meaning<<endl;
            insert(word, meaning);
        }






}

void inOrderRecursive(struct node* root)
{
	if(root!=NULL)
	{
		inOrderRecursive(root->left);
		cout<<root->word<<"-->"<<root->meaning<<endl;
		inOrderRecursive(root->right);
	}
}
void createnewword()
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("project11.csv", ios::out | ios::app);

    cout << "Enter the word:"<< endl;

    string word;
    cin>>word;
    cout << "Enter the meaning:"<< endl;
    string meaning;
    cin>>meaning;


        // Insert the data to file
        fout << word << ", "
             << meaning << "\n ";

        insert(word,meaning);
        cout<<"Word Added successfully in a dictionary\n";
    }


int main(){




    read();
   while(true){
    system("CLS");
     cout<<"-----------------------WELCOME TO OUR  DICTIONARY----------------\n\n";
    cout<<"\t\tEnter Your Choice\n PRESS 1 For Search word meaning in a dictionary\n Press 2 For Add new word and its meaning in a dictionary\n Press 3 For Exit"<<endl;

    int n;
    cin>>n;
    if(n==2) {system("CLS");createnewword();cout<<"Still wants to continue-- press 1"<<endl;
    int p;
    cin>>p;
    if(p==1) continue;
    else break;}
    else if(n==1)
   {
    system("CLS");
    cout<<"enter the string"<<endl;
    string str;
    cin>>str;

     cout<<"\n-----------------------\n";
    search(str);
    cout<<"Still wants to continue-- press 1"<<endl;
    int p;
    cin>>p;
    if(p==1) continue;
    else break;


    }
    else break;

    }

     system("CLS");
    cout<<"ThankYou for using our dictionary!!!";


}
