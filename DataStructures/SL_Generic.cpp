#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    public:
        struct node<T> * First;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        /*void InsertAtPos(T no,int ipos);
        void DeleteAtPos(T no);*/
        void Display();
        int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new node<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    } 
    else
    {
        struct node<T> * temp =  First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next = NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        struct node<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next = NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        struct node<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct node<T> *  temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;

    SinglyLL <char>cobj;  
    cobj.InsertFirst('a');
    cobj.InsertFirst('e');
    cobj.InsertLast('q');
    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <int>iobj;  
    iobj.InsertFirst(101);
    iobj.InsertFirst(187);
    iobj.InsertLast(51);    
    iobj.DeleteFirst();
    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <float>fobj;  
    fobj.InsertFirst(13.21f);
    fobj.InsertFirst(45.77f); 
    fobj.InsertLast(44.44f);
    fobj.DeleteFirst();
    fobj.DeleteLast();
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL <double>dobj;  
    dobj.InsertFirst(101.323);
    dobj.InsertFirst(43.44);
    dobj.InsertLast(434.34343);
    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}