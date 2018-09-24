#include<iostream>
#include<stdlib.h>
using namespace std;

template < class Temp >
class Initial
{
public:
    Temp info; //var in class temp
    Initial * next; //pointer to next
    Initial ()
    {
        info = 0;
        next = 0;
    }
    Initial (Temp a, Initial * b = 0)
    {
        info = a;
        next = b;
    }
    ~Initial ()
    {
       next = 0;
    }

};

template < class Temp >
class ArbitraryQueue
{
    public:

        Initial < Temp >*head, *tail; //ref both head and tail
        ArbitraryQueue ()
        {
            head = tail = 0;
        }
    ~ArbitraryQueue ()
    {
        for (Initial < Temp >*p; !isEmpty ();)
        {
            p = head->next; //using pointer to move the head.
            delete head; //delete and replace head.
            head = p;
        }
    }
    bool isEmpty ()
    {
        if (head == 0)
            return true;

        else
            return false;
    }

    void Push(Initial <Temp> *a)
    {
        if(tail==0)
        {
            head=tail=a;
        }
        else
        {
            Initial<Temp> *tmp = head;
            head = a;
            head->next=tmp;
        }

    }

    void Enqueue(Initial <Temp> *a)
    {
        if(tail==0)
        {
            head = tail =a;
        }
        else
        {
            tail->next=a;
            tail=tail->next;
        }
    }
    void Pop ()
    {
        if(head==0) //empty list
            cout << "Empty List Error"; // Sends error if the list is empty

        int a = head->info;
        Initial < Temp >*tmp = head;

        if (head == tail)
        {
            head = tail = 0;
        }

        else
        {
            head = head->next;
        }

        delete tmp; //deletes tmp and reallocates the memory
        cout << a << " deleted\n";
    }

    void Dequeue ()
    {
        if(head== 0) //empty list
            cout<< "Empty List Error";
        int a = tail->info;
        if (head == tail)
       {
            delete head;
            head = tail = 0;
        }
        else
        {
            Initial < Temp >*tmp;
            for (tmp = head; tmp->next != tail; tmp = tmp->next);
            delete tail;
            tail = tmp;
            tail->next = 0;
        }
        cout << a << " deleted\n";
    }

    Temp traverse(int position)
    {
        Initial < Temp >*tmp = head;
        for(int i=0;i<position-1;i++)
        {
            if(tmp==0)
                cout << "Index out of Bound";
            tmp=tmp->next;
        }
        return tmp->info;
    }
    void showQueue ()
    {
        Initial < Temp >*tmp;
        for (tmp = head; tmp != NULL; tmp = tmp->next)
            cout << tmp->info << " ";
        cout << endl;
    }
};
//the function menu
int main (){
    ArbitraryQueue < int >L;
    int element;
    char yes = 'y';
    while (yes == 'y' || yes == 'Y')
    {
        cout << "\n\t\t\tMAIN MENU\n\n\n";
        cout <<"1.ADD TO HEAD (Push)\n"
                "2.ADD TO TAIL (Enqueue)\n"
                "3.DELETE FROM HEAD (Pop)\n"
                "4.DELETE FROM TAIL (Dequeue)\n"
                "5.TRAVERSE\n"
                "6.SHOW ARBITRARY QUEUE\n"
                "\nENTER YOUR CHOICE : ";
        int choice;
        cin >> choice;
        cout << endl;

            switch (choice)
            {
                case 1:
                cout << "Enter element to be added : ";
                cin >> element;
                Initial <int> *n1;
                n1=new Initial<int>(element,0);
                L.Push(n1);//L.Push (element);
                cout << "\nElement added\n";
                break;

                case 2:
                cout << "Enter element to be added : ";
                cin >> element;
               Initial <int> *n2;
                n2=new Initial<int>(element,0);
                L.Enqueue(n2); //L.Enqueue (element);
                cout << "\nElement added\n";
                break;

                case 3:
                    // try can detect the deleted element and catch if there is an error
                try
                {
                    L.Pop ();
                    cout << "\nElement deleted\n";
                }
                catch(const char* msg)
                {
                    cout<<"Error: "<<msg<<endl;
                }
                break;
            case 4:
                try
                {
                    L.Dequeue ();
                    cout << "\nElement deleted\n";
                }
                catch(const char* msg)
                {
                    cout<<"Error: "<<msg<<endl;
                }
                break;
            case 5:
                int p;
                cout << "Enter position to traverse: ";
                cin >> p;
                try
                {
                    cout<<"Element at position "<<p<<" is "<<L.traverse(p)<<endl;
                }
                catch(const char* msg)
                {
                    cout<<"Error: "<<msg<<endl;
                }
                break;
            case 6:
                L.showQueue ();
                break;
            default:
                cout << "Something went wrong";
        }
        cout << "press y/Y to continue : ";
        cin >> yes;
    }
    return 0;
}