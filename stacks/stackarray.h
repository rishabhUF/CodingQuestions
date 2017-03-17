#ifndef STACKARRAY_H_INCLUDED
#define STACKARRAY_H_INCLUDED
template <typename T>
class stack
{
    T arr[100];
    int index;
public:
    stack():index(0){}
    void clear()
    {
        while(index!=-1)
        {
            arr[index]=NULL;
            --index;
        }
    }
    void push(const T&el)
    {
        if(index!=100)
        {
        arr[index]=el;
        index++;
        }
        else
        {
            cout<<"stack full";
        }
    }
    void pop()
    {
        if(index==0)
        {
            cout<<"not possible";
        }
        else
        {
            arr[index-1]=NULL;
            index--;
        }
    }
    const T& top()
    {
        return arr[index-1];
    }
};


#endif // STACKARRAY_H_INCLUDED
