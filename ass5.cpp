#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
int comparisonDet,comparisonRand,swapDet,swapRand;

int partitionDet(vector<int>&arr,int low,int high)
{
   int pivot=arr[high];
   int i=low-1;
   for(int j=low;j<high;j++)
   {
        comparisonDet++;
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
            swapDet++;
        }

    
   }
   swap(arr[i+1],arr[high]);
   swapDet++;
   return i+1;
}

void quicksortDet(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int pi=partitionDet(arr,low,high);
        quicksortDet(arr,low,pi-1);
        quicksortDet(arr,pi+1,high);
    }
}


int partitionRand(vector<int>&arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        comparisonRand++;
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
            swapRand++;
        }
    }
    swap(arr[i+1],arr[high]);
    swapRand++;
    return i+1;

}

int randomPartition(vector<int>&arr,int low,int high)
{
    int ind=low + rand()%(high-low+1);
    swap(arr[ind],arr[high]);
    return partitionRand(arr,low,high);
}

void quicksortRand(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int pi=randomPartition(arr,low,high);
        quicksortRand(arr,low,pi-1);
        quicksortRand(arr,pi+1,high);
    }
}
int main()
{
    
    cout<<"Enter size of the array:";
    int n;
    cin>>n;
    vector<int>vct(n,0);
    cout<<"enter elements of array:";
    for(int i=0;i<n;i++)
    {
        cin>>vct[i];
    }
    quicksortDet(vct,0,n-1);
    cout<<endl;
    for(int n:vct)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<comparisonDet<<" - "<<swapDet<<endl;


    cout<<endl;
    cout<<"Enter size of the array:";
    int m;
    cin>>m;
    vector<int>arr2(m,0);
    cout<<"enter elements of array:";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    quicksortRand(arr2,0,m-1);
    cout<<endl;
    for(int m:arr2)
    {
        cout<<m<<" ";
    }
    cout<<endl;
    cout<<comparisonRand<<" - "<<swapRand<<endl;
}