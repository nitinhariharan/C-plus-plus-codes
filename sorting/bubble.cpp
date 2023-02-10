#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void print_array(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
void bubble(int a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j+1]<a[j])
            {
                swap(&a[j],&a[j+1]);
                print_array(a,n);
            }
        }
    }
}
int main()
{
    /*
    // dynamic entry
    int n;
    cout<<"enter the number of elements";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    */
    int a[] = {64, 25, 12, 22, 11};
    int n=sizeof(a)/sizeof(a[0]);
    bubble(a,n);
    print_array(a,n);
    return 0;
}