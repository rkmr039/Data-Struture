/*
 * File:   main.cpp
 * Author: Rishab Kumar
 *
 * Created on 6 October, 2018, 11:28 PM
 * 
 * Implementation of Queue usng Stack
 * Rear equal to size of stack1
 */
#include<iostream>
#include<stack>

using namespace std;
stack<int>  s1;
stack<int>  s2;
int front = 0;
int rear = 0;
unsigned int size;

void CopyStacks(int num)
{
    int stackSize;
    int i;
    switch(num)
    {
        case 1:
            stackSize = s1.size();
            for(i=0;i<stackSize;i++)
            {
                s2.push(s1.top());
                s1.pop();
            }
            break;
        case 2:
            stackSize = s2.size();
            for(i=0;i<stackSize;i++)
            {
                s1.push(s2.top());
                s2.pop();
            }
            break;
    }
}
bool IsOverflow()
{
    if(s1.size() >= size)
        {
            cout<<"\n=======Overflow========\n";
            return true;
        }
    else return false;
}
bool isUnderflow()
{
    if(s1.size() <= 0)
        {
            cout<<"\n=======Underflow========\n";
            return true;
        }
    else return false;
}
int getFrontItem()
{
    int temp;
    CopyStacks(1);
    temp = s2.top();
    CopyStacks(2);
    return temp;
}
int getRearItem()
{
    int temp;
    temp = s1.top();
    return temp;
}
void enQueue(int item)
{
    if(front == 0) rear++;
    front ++;
    s1.push(item);
}
int deQueue()
{
    int temp;
    CopyStacks(1);
    temp = s2.top();
    s2.pop();front--;
    CopyStacks(2);
    return temp;
}
bool isEmpty()
{
    cout<<"\n\nChecking Stack's emptiness...\n";
    bool flag = false;
    if(s1.empty())
    {
        flag = true;
        //cout<<"\nStack is Empty\n";
    }
    return flag;
}
int main(int argc, char** argv) {

    int option,flag,item;
    cout<<"\nEnter size of the queue : ";
    cin>>size;

    do{
        cout<<"\nSelect any one operation\n1.EnQueue\n2.DeQueue\n3.Get Current Queue Size\n4.Get Front Item and Rear Item\n";
        cin>>option;
        switch(option)
        {
            case 1:
                if(IsOverflow())
                    cout<<"\nOverflow occurs..... Unable to EnQueue\n";
                else
                    {
                    cout<<"\nEnter item to be insert : ";
                    cin>>item;
                    enQueue(item);
                    }
                break;

            case 2:
                if(isUnderflow())
                    cout<<"\nUnderflow occurs..... Unable to DeQueue\n";
                else
                    {
                     cout<<"\nDeQueued Item : "<<deQueue()<<endl;
                    }
                break;

            case 3:
                    cout<<"\nSize of Current Queue : "<<s1.size()<<endl;
                    break;

            case 4:
                    cout<<"\nFront "<< front <<" Item : "<<getFrontItem()<<endl;
                    cout<<"\nRear "<< rear <<" Item : "<<getRearItem()<<endl;
                    break;
            default : cout<<"\nPlease select correct option\n";
        }

        cout<<"\nWant to perform more operations...?[1/0]";
        cin>>flag;

     }while(flag == 1);
    return 0;
}
