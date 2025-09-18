#include<iostream>
using namespace std;

void sparseTriplet(int ptr[100][100],int r,int c){
    int srr[100][3];
    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ptr[j][i]!='\0'){
                srr[k][0]=i;
                srr[k][1]=j;
                srr[k][2]=ptr[j][i];
                k++;
            }
        }
    }
    srr[0][0]=r;
    srr[0][1]=c;
    srr[0][2]=k-1;
    cout<<"Here's the Sparse Matrix:"<<endl;
    for(int i=0;i<k;i++){
        cout<<"srr["<<i<<"]:";
        for(int j=0;j<3;j++){
            cout<<srr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int arr[100][100],r,c;
    cout<<"Enter the value of row and column of an matrix:";
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"arr["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
        }
    }

    sparseTriplet(arr,r,c);
}