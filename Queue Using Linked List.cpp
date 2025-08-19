#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include<assert.h>
#include <cstring>
using namespace std;
#define ll long long
const int max_length=100;
template<class t>
class LinkedQueue {
private:
    struct node {
        t data;
        node* next;
    };
    node* front;
    node* rear;
    int length;
    public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
        length = 0;
    }
    bool isEmpty() {
        return length == 0;
    }
    void Push_Back(t element) {
        node* temp = new node;
        temp->data = element;
        temp->next = NULL;
        if(isEmpty()) {
            front = temp;
            rear = temp;
            length++;
        }else {
            rear->next = temp;
            rear = temp;
            length++;
        }
    }
    void POP_Front() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else{
            node* temp = front;
            if(front == rear) {// if there exist one element
                front = NULL;
                rear = NULL;
                length--;
            }
            else{
                front = front->next;
            temp->next=NULL;
            delete temp;
            //free(temp);
                length--;
            }
        }
    }
    int GetFront() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            return front->data;
        }
    }
    int GetRear(){
       assert(!isEmpty());
        return rear->data;
    }
    void Clear() {
        node *cur;
        while(front != NULL) {
            cur = front;
            front = front->next;
            delete cur;
        }
        rear = NULL;
    }
    void Print() {
        node *cur=front;
        while(cur!=NULL) {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
};
int main() {

    return 0;
}
// the time complixty
// add(back) remove(front) o(1)
// access (front,back)   o(1)
// search()   o(1)
