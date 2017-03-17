#ifndef
#define
#include<vector>
#include<list>
using namespace std;
int hashvalue (string k)
{
    int h_v=0;
    for(int i=0;i<k.size();i++)
    {
        h_v=h_v*29+k[i];
    }
    return h_v;
}
int hashvalue(int k)
{
    return key;
}
template <typename key,typename value>
class myunomap
{
    vector<list<pair<key,value>>>table;
    int currentel;
    int myhash(const key&k) const
    {
        return hashvalue(k)%table.size();
    }
public:
    myunomap(int size=101)
    {
        table.resize(size);
    }
    void expandAndRehash()
    {
        vector<list<pair<key,value>>>table;

    }
    bool isempty()const
    {
        return currentel==0;
    }
    int size()const
    {
        return currentel;
    }
    void insertOrUpdate(const key&k,const value& v)
    {
        list<pair<key,value>>&L=table[myhash(key)];//L si another name for the linklist ref.to avoid copying
        typename list<pair<key,value>>::iterator it;//typename is important for iterator
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->first==k)
            {
                it->second=v;
                return;
            }
        }
        pair<key,value>P(k,v);
        L.push_back(P);
        currentel++;
        if(currentel==table.size())
        {
            expanAndRehash();
        }
    }

    bool contains(const key&k)const
    {
      const  list<pair<key,value>>&L=table[myhash(key)];//L si another name for the linklist ref.to avoid copying
        typename list<pair<key,value>>:const_iterator it;//typename is important for iterator
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->first==k)
            {
                return true;
            }
        }
        return false;
    }
    value &get(const key&k)
    {
        const list<pair<key,value>>&L=table[myhash(key)];//L si another name for the linklist ref.to avoid copying
        typename list<pair<key,value>>::const_iterator it;//typename is important for iterator
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->first==k)
            {
                return it->second;
            }
        }
        throw "key doesn't exist";
    }
   const  value &get(const key&k) const
   {
       const list<pair<key,value>>&L=table[myhash(key)];//L si another name for the linklist ref.to avoid copying
        typename list<pair<key,value>>::const_iterator it;//typename is important for iterator
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->first==k)
            {
                return it->second;
            }
        }
        throw "key doesn't exist";
   }
   void erase(const key&k)
   {
       const list<pair<key,value>>&L=table[myhash(key)];//L si another name for the linklist ref.to avoid copying
        typename list<pair<key,value>>::const_iterator it;//typename is important for iterator
        for(it=L.begin();it!=L.end();it++)
        {
            if(it->first==k)
            {
                break;
            }
        }
        if(it==L.end()){
        throw "key doesn't exist";
        }
        else
        {
            L.erase(it);
        }
   }
   const value&operator[](const key&k)const
   {
       return get(key);
   }
   value&operator[](const key&k)const
   {
       if(!contains(k))
       {

           pair<key,value>P;
           P.first=k;
           insertOrUpdate(P.first,P.second);
       }
        return get(k);
   }
};
