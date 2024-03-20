#include<bits/stdc++.h> 
using namespace std;
bool SNT(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int sumsnt(int n)
{  int s = 0;

	while(n != 0) // n=0 vong lap se dung
	{ s += n % 10; // lay so cuoi
		n /= 10; // lay so dau
	}
	return s;
}
int cp(int n)
{ int c = sqrt(n);// khai int vi so chinh phuong la so nguyen 
	return c * c == n;
}
	int main()
{ int i,n;
int demsnt = 0 , demsumsnt = 0 , demcp = 0;

cout<<"Nhap so phan tu cua mang";cin>>n;
int a[n];

for(i = 0;i < n;i++)
{ cout<<"a["<<i<<"]=";cin>>a[i];}

for(i = 0;i < n;i++)
{ 
	if(SNT(a[i])) ++demsnt;
	if(cp(a[i])) ++demcp;
	if(SNT(sumsnt(a[i]))) ++demsumsnt;
}
cout<<"So luong snt co trong mang la: "<<demsnt<<endl;
cout<<"So luong so co tong chu so la snt trong mang la: "<<demsumsnt;
return 0;
}
