#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int y;
    struct node *ptr;
};

struct node *start = NULL;

void addfirst(int a,int b){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->x = a;
    temp->y = b;
    temp->ptr = start;
    start = temp;
    
}

int delfirst(){
    struct node *temp;
    if(start == NULL){
        return -1;
    };
    temp = start;
    start = start->ptr;
    delete temp;
    temp = NULL;
    return 1;
}

void del(int a,int b){
    struct node *temp,*prev = NULL;
    temp = start;
    int flag=0;
    while(temp != NULL){
        if(temp->x==a  && temp->y==b){
            struct node *temp2;
            temp2= temp->ptr;
            if(prev==NULL){
                start= temp2;
                
                delete(temp);
                temp = NULL;
            }
            else{
                prev->ptr = temp2;
                delete(temp);
                temp = NULL;
            }   
            return;
        }
        else{
            prev = temp;
            temp = temp->ptr;
        }
    }
    cout<<"node does not exist\n";
}

void search(float d){
    struct node *temp;
    int flag=0;
    temp = start;
    float f;
    float a,b;
    while(temp!= NULL){
        a = temp->x;
        b= temp->y;
        f = (float)sqrt((a*a + b*b));
        //cout<<a;
        //f = f*f;
        //cout<<f;
        if(f<=d){
            cout<<"("<<temp->x<<","<<temp->y<<") ";
            flag++;
        };
        temp = temp->ptr;
    };
    if(flag==0){
        cout<<"no point found\n";
    }
    else{
        cout<<"\n";
    }
}

bool search2(int a,int b){
    struct node *temp;
    temp = start;
    while(temp!=  NULL){
        if(temp->x == a  && temp->y==b){
            return true;
        }
        temp= temp->ptr;
    };
    return false;
};

int length(){
    int count=0;
    struct node *temp;
    temp = start;
    while(temp!= NULL){
        count++;
        temp = temp->ptr;
    }
    return count;
}

int main(){
    int a,b,c;
    int t;
    float d;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            addfirst(b,c);
        }
        else if(a==2){
            delfirst();
        }
        else if(a==3){
            cin>>b>>c;
            del(b,c);
        }
        else if(a==4){
            cin>>d;
            search (d);
        }
        else if(a==5){
            cin>>b>>c;
            
            if(search2(b,c))cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else{
        
            b= length();
            cout<<b<<"\n";
        };
    };
    return 0;
}
























