#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;      // X
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyDL
{
    public:
        PNODE First;
        int i;

        DoublyDL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyDL::DoublyDL()
{
    First = NULL;
    i = 0;
}

void DoublyDL::InsertFirst(int no)
{
    // PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X
        First = newn;
    }

}

void DoublyDL::InsertLast(int no)
{
  //  PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

void DoublyDL::Display()
{
    cout<<"Elements of Linked list are : "<<"\n";

    PNODE temp = First;

    cout<<"NULL<=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int DoublyDL::Count()
{
    int iCnt = 0;
    PNODE temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyDL::DeleteFirst()
{
    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 node
    {
        delete(First);
        First = NULL;
    }
    else    // LL contains more than 1 node
    {
        First = (First) -> next;
        delete((First)->prev);               // X
        (First)->prev = NULL;              // X
    }
}

void DoublyDL::DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 node
    {
        delete(First);
        First = NULL;
    }
    else    // LL contains more than 1 node
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
    }
}


void DoublyDL::InsertAtPos(int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        // newn = (PNODE)malloc(sizeof(NODE));

        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

void DoublyDL::DeleteAtPos(int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      // X
        delete(temp2);
    }
}

int main()
{
    DoublyDL obj;
    int iRet = 0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    obj.DeleteFirst();
    obj.Display();
    iRet =obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    obj.DeleteLast();
    obj.Display();
    iRet =obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    obj.DeleteAtPos(5);
    obj.Display();
    cout<<"Number of elements are : "<<obj.Count()<<"\n";

    return 0;

}