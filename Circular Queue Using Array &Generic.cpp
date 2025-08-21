#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const int max_length=100;
template<class t>
class ArrayQueue {
    int rear;
    int front;
    int length;
    t *arr;
public:
    ArrayQueue(int len) {
front=0;rear=max_length-1;length=0;
        arr=new t[len];
    }
    bool IsEmpty() {return length==0;}
    bool IsFull() {return length==max_length-1;}
    void Enqueue(t value) {
       if(IsFull()) {
           cout<<"Queue is full"<<endl;
       }else {
           rear=(rear+1)%max_length;
           arr[rear]=value;
           length++;
       }
    }
    int Dequeue() {
        if(IsEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            front=(front+1)%max_length;
            length--;
        }
    }
    int Peek() {
        if(IsEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            return arr[front];
        }
    }
    int Rear() {
        if(IsEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            return arr[rear];
        }
    }
    void Print() {
        if(IsEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            for(int i=front;i!=rear;i=(i+1)%max_length) {
                cout<<arr[i]<<" ";
            }
            cout<<arr[rear]<<endl;
        }
    }
    int Size() {
        if(IsEmpty()) {
                cout<<"Queue is empty"<<endl;
        }else {
            return length;
        }
    }
    int QueueSearch(t value) {
        int pos=-1;
        if(IsEmpty()) {
            cout<<"Queue is empty"<<endl;
        }else {
            for(int i=front;i!=rear;i=(i+1)%max_length) {
                if(arr[i]==value) {
                    pos=i;
                    break;
                }
            }
            if(pos==-1) {
                if(arr[rear]==value) {
                    pos=rear;
                }
            }
        }
        return pos;
    }
};
int main() {
ArrayQueue<char> a(20);
    a.Enqueue(1);
    a.Enqueue(2);
    a.Enqueue(3);
    a.Enqueue(4);
    a.Print();

    return 0;
}
// the time complixty
// add(back) remove(front) o(1)
// access (front,back)   o(1)
// search()   o(1)

