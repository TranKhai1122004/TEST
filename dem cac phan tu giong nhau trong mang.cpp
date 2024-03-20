#include<bits/stdc++.h>
using namespace std;
int dem[100000000];
	int main()
{ 	int i,j,n;
do
{cout<<"Nhap so phan tu cua mang :";cin>>n;}
while(n<0);
	int a[n];
	for(i=0;i<n;i++)
{ cout<<"a["<<i<<"]=";cin>>a[i];}



for(i=0;i< n ;i++) // xet phan tu co chi so i
{ 
	dem[a[i]]++; //  a[i] chi so cho mang dem 
}
	for(i=0;i<n;i++)
{ 	if(dem[a[i]] != 0)
   	  {	cout<<a[i]<< " xuat hien "<<dem[a[i]]<< " lan "<< endl;
    	dem[a[i]] = 0 ; // lan sau  gap a[i] ko in ra nua , no van dang trong vong for va van lap ,in theo thu tu xuat hien
    	}
   	  
}
	
	return 0;
	}
