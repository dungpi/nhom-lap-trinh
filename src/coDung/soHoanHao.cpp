
//nhap vao day so nguyen
//a. Sap xep day giam dan
//b. Tim phan tu am nho nhat
//c. In ra cac so hoan hao trong day
#include <stdio.h>
void Nhapmang(int a[], int &n){
	printf("nhap n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("nhap a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void sapxep(int a[],int n){
	int t;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	//xuat(a,n);
}
//tim phan tu am lon nhat
void timPhanTuAmLonNhat(int a[], int n){
	int max,i;
	for(i=0;i<n;i++){
		if(a[i]<0){
				max =a[i];
				break;
		}	
	}
	if(i==n){
		printf("Khong co phan tu am trong day\n");
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]<0 && a[i]>max){
				max =a[i];
			}
		}
		printf("\nso am lon nhat: %d", max);
	}
	xuat(a,n);
}
void MaxAm(int a[], int n){
	if(a[n-1]>=0)
		printf("\nDay khong co so am.\n");
	else{
		int i=n-1;
		while(a[i]<0){
			i--;
		}
		printf("\nMax am la: %d\n",a[i+1]);	
	}
}
//so hoan hao
int SoHoanHao(int a){
	int S = 0;
	for (int i = 1; i < a; i++){
		if(a%i == 0){
			S += i;
		}
	}
	if (S == a)
		return 1; 
	else
		return 0;
}
void inraSoHoanHao(int a[],int n){
	printf("\nso hoan hao: ");
	for (int i = 0; i < n; i++){
		if (SoHoanHao(a[i])==1){
			printf("\t%d",a[i]);
			}
		}
	}
int main(){
	int a[100],n;
	Nhapmang(a,n);
	printf("Day so truoc khi sap xep: \n");
	xuat(a,n);
	printf("\nDay so sau khi sap xep giam dan: \n");
	sapxep(a,n);
	//timPhanTuAmLonNhat(a,n);
    xuat(a,n);
	MaxAm(a,n);
	inraSoHoanHao(a,n);
}