#include<bits/stdc++.h>
using namespace std;

#define p 999999
#define h 26


int hash1(string pat)
{
    int s=pat.size();
    int val=0;
    for(int i=0;i<pat.size();i++)
    {
        val=val+(pow(h,s-i-1)*(pat[i]-'A'));
    }

    return val%p;
}


void string_match(string text,string pat)
{
    int phval=hash1(pat);
    int txts=text.size();
    int pats=pat.size();
    if(txts<pats)
    cout<<"No match found"<<endl;
    else
    {
        int hval=0,all=0;
        for(int i=0;i<pats;i++)
        {
            hval=hval+(pow(h,pats-i-1)*(text[i]-'A'));
        }
        hval=hval%p;

        if(hval==phval)
        {
            int s=0;
            for(int i=0;i<pats;i++)
            {
                if(text[i]!=pat[i])
                {
                    s=1;
                    break;
                }
            }
            if(s==0)
            {
                cout<<"Pattern found at index:0"<<endl;
                all=1;
            }
            
        }

        int k=0;
        for(int i=pats;i<txts;i++)
        {
            hval=hval-(pow(h,pats-1)*(text[k]-'A'));
            hval=hval*h;
            hval=hval+(text[i]-'A');
            hval=hval%p;
            k++;
            if(hval==phval)
            {
                int l=k,t=0;
                for(int j=0;j<pats;j++)
                {
                    if(text[l]!=pat[j])
                    {
                        t=1;
                        break;
                    }
                    l++;
                }

                if(t==0){
                cout<<"Pattern found at index:"<<k<<endl;
                all=1;}

            }

        }
      if(all==0)
      cout<<"Pattern Not found"<<endl;
    }
    
}