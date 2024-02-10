#include<iostream>
using namespace std;

int c=0;
char b[5][20];

int lru(char p[],int f,int n){
int i=0,j=0,k=0,m,l=0,flag1=0,flag2=0,pf=0,index=0;
    char fr[f],fs[f];

    for(i=0;i<f;i++){
        fr[i]='-';
    }

    c=0;

    for(i=0;i<f;i++){
        for(j=0;j<20;j++){
        b[i][j]='\0';
        }
    }

    for(j=0;j<n;j++){
        flag1=0;flag2=0;
        for(i=0;i<f;i++){
            if(fr[i]==p[j]){
                flag1=1;
                flag2=1;
            for(m=0;m<f;m++){
                b[m][c]=fr[m];
            }
            c++;
            break;
        }   
    }

    if(flag1==0){
        cout<<"F\n";
        for(i=0;i<f;i++){
            if(fr[i]=='-'){
                pf++;
                fr[i]=p[j];
                flag2=1;
                for(i=0;i<f;i++){
                    b[i][c]=fr[i];
                }
                c++;
                break;
            }
        }
    }

    if(flag2==0){
        for(i=0;i<f;i++)
            fs[i]=0;
            for(k=j-1,l=1;l<=f-1;l++,k--){
                for(i=0;i<f;i++){
                    if(fr[i]==p[k])
                        fs[i]=1;
                    }
                }

        for(i=0;i<f;i++){
            if(fs[i]==0)
            index=i;
        }
        fr[index]=p[j];
        pf++;
        for(i=0;i<f;i++){
            b[i][c]=fr[i];
        }
        c++;
    }
        }

    return pf;
}



int main(){
    int n,frame,fault2,i=0,j=0,k=0,count=0;

    cout<<"Introduce numero de paginas:";
    cin>>n;
    char p[n];
    cout<<"\nIntroduce las paginas:";   
        cout<<"\n";
        for(i=0;i<n;i++){
        cin>>p[i];
        }
    cout<<"\nIntroduce numero de marcos:"<<endl;
    cin>>frame;
    cout<<"\n";

    cout<<"\n";
    cout<<"Least Recently Used:";
    fault2=lru(p,frame,n);


    for(i=0;i<frame;i++){
    j=0;
    cout<<"\n";

    while(b[i][j]!='\0'){
    cout<<b[i][j];
    cout<<" ";
    j++;
    }
    cout<<"\n";
    }

    cout<<"\n\n\n";
    cout<<"The Page Fault in LRU is:"<<fault2<<endl;
    return 0;
}