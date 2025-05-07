#include <iostream>
using namespace std;
class Set
{
public:
    int cnt;
    int a[10];

    Set()
    {
        cnt=0;
    }
    void Insert(int);
    void Display();
    int Contain(int); //To search for a key
    void Size();
    void Remove();
    void Union(Set s1,Set s2);
    void Intersection(Set s1,Set s2);
    void Difference(Set s1,Set s2);
    void Subset(Set s1,Set s2);
};

void Set::Insert(int n)
{
    cout<<"Enter the elements of the Set:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt++;
    }
}

void Set::Display()
{
    cout<<"  ";
    for(int i=0;i<cnt;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int Set::Contain(int key)
{
    for(int i=0;i<cnt;i++)
    {
        if(a[i]==key)
            return i;
    }
    return -1;
}

void Set::Size()
{
    cout<<"\n  Size of Set is:"<<cnt<<endl;
}

void Set::Remove()
{
    int ele,temp;
    cout<<"\nEnter the element to be deleted:";
    cin>>ele;
    temp=Contain(ele);
    if(temp!=-1)
    {
        for(int i=temp;i<cnt-1;i++)
        {
            a[i]=a[i+1];
        }
        cnt--;
        cout<<"  Element "<<ele<<" is removed."<<endl;
    }
    else
        cout<<"  This element is not present in the set!"<<endl;
}

void Set::Union(Set s1,Set s2)
{
    cnt=0;
    for(int i=0;i<s1.cnt;i++)
    {
        a[cnt++]=s1.a[i];
    }
    for(int i=0;i<s2.cnt;i++)
    {
        if(s1.Contain(s2.a[i])== -1)
            {
                a[cnt++]=s2.a[i];
            }
    }
}

void Set::Intersection(Set s1,Set s2)
{
    cnt=0;
    for(int i=0;i<s2.cnt;i++)
    {
        if(s1.Contain(s2.a[i])!= -1)
            {
                a[cnt++]=s2.a[i];
            }
    }
}

void Set::Difference(Set s1,Set s2)
{
    cnt=0;
    for(int i=0;i<s1.cnt;i++)
    {
        if(s2.Contain(s1.a[i])==-1)
        {
            a[cnt++]=s1.a[i];
        }
    }
}

void Set::Subset(Set s1,Set s2)
{
    cnt=0;
    int subcnt=0;
    for(int i=0;i<s1.cnt;i++)
    {
        if(s2.Contain(s1.a[i])!=-1)
        {
            subcnt++;
        }
    }
    if(subcnt==s1.cnt)
    {
        cout<<"  Set-1 is subset of Set-2."<<endl;
    }
    else if(subcnt!=s1.cnt)
    {
        cout<<"  Set-1 is not a subset of Set-2."<<endl;
    }
}

int main()
{
    Set obj,s1,s2,s3;
    int n,ch;
    do
    {
        cout<<"\n**MENU**";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Size";
        cout<<"\n5.Remove";
        cout<<"\n6.Union";
        cout<<"\n7.Intersection";
        cout<<"\n8.Difference";
        cout<<"\n9.Subset";
        cout<<"\n10.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\nEnter the no. of elements to be inserted:";
                cin>>n;
                obj.Insert(n);
                break;
            }
        case 2:
            {
                cout<<"\n  Set elements are:"<<endl;
                obj.Display();
                break;
            }
        case 3:
            {
                int key;
                cout<<"\nEnter the key to be searched:";
                cin>>key;
                int result=obj.Contain(key);
                if (result!=-1)
                    cout<<"  Element found at index "<<result<<endl;
                else
                    cout<<"  Element not found."<<endl;
                break;
            }
        case 4:
            {
                obj.Size();
                break;
            }
        case 5:
            {
                obj.Remove();
                break;
            }
        case 6:
            {
                s1.cnt=0;
                s2.cnt=0;
                s3.cnt=0;
                int c1,c2;
                cout<<"\nEnter no. of elements in Set-1 :";
                cin>>c1;
                s1.Insert(c1);
                cout<<"\nEnter no. of elements in Set-2 :";
                cin>>c2;
                s2.Insert(c2);
                cout<<"\nElements of Set-1 are:";
                s1.Display();
                cout<<"Elements of Set-2 are:";
                s2.Display();
                s3.Union(s1,s2);
                cout<<"  Union=";
                s3.Display();
                break;
            }
        case 7:
            {
                s1.cnt=0;
                s2.cnt=0;
                s3.cnt=0;
                int c1,c2;
                cout<<"\nEnter no. of elements in Set-1 :";
                cin>>c1;
                s1.Insert(c1);
                cout<<"\nEnter no. of elements in Set-2 :";
                cin>>c2;
                s2.Insert(c2);
                cout<<"\nElements of Set-1 are:";
                s1.Display();
                cout<<"Elements of Set-2 are:";
                s2.Display();
                s3.Intersection(s1,s2);
                cout<<"  Intersection=";
                s3.Display();
                break;
            }
        case 8:
            {
                s1.cnt=0;
                s2.cnt=0;
                s3.cnt=0;
                int c1,c2;
                cout<<"\nEnter no. of elements in Set-1 :";
                cin>>c1;
                s1.Insert(c1);
                cout<<"\nEnter no. of elements in Set-2 :";
                cin>>c2;
                s2.Insert(c2);
                cout<<"\nElements of Set-1 are:";
                s1.Display();
                cout<<"Elements of Set-2 are:";
                s2.Display();
                s3.Difference(s1,s2);
                cout<<"  s1-s2=";
                s3.Display();
                s3.Difference(s2,s1);
                cout<<"  s2-s1=";
                s3.Display();
                break;
            }
        case 9:
            {
                s1.cnt=0;
                s2.cnt=0;
                s3.cnt=0;
                int c1,c2;
                cout<<"\nEnter no. of elements in Set-1 :";
                cin>>c1;
                s1.Insert(c1);
                cout<<"\nEnter no. of elements in Set-2 :";
                cin>>c2;
                s2.Insert(c2);
                cout<<"\nElements of Set-1 are:";
                s1.Display();
                cout<<"Elements of Set-2 are:";
                s2.Display();
                s3.Subset(s1,s2);
                break;
            }
        case 10:
            {
                cout<<"End of Program..."<<endl;
                break;
            }
        default:
            {
                cout<<"Invalid Choice!!Enter valid choice."<<endl;
            }
        }
    }while(ch!=10);
    return 0;
}

