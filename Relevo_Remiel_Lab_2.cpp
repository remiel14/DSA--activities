#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("Sanctuary by Joji");
    
    head = insertAtEnd("BMF by SZA", head);
    head = insertAtEnd("Snooze by SZA", head);
    head = insertAtEnd("Lucid Dreams by Juice WRLD", head);
    head = insertAtEnd("Again by fettywap", head);
    
    head = insertAtBeginning("Gods plan by Drake", head);
    head = insertAtBeginning("City Girl by Shantidope", head);
    head = insertAtBeginning("All Girls Are The Same by Juice WRLD", head);
    head = insertAtBeginning("AMAZING by Rex Orange Country", head);
    traverse(head);
    
    insertAfter ("Uhaw by Dilaw", "Gods plan by Drake", head);
    insertAfter ("Marilag by Dionela", "City Girl by Shantidobe", head);
    insertAfter ("Palagi by KZ tandingan", "AMAZING by Rex Orange Country", head);
    traverse(head);
    
    

    return 0;
}