#include<stdio.h>
#define MAX 50
void nhap(int a[],int &n);
//phan tu lon nhat
int timGTLN(int a[],int n);
void xuatGTLN(int a[],int n);
//liet ke phan tu le
void lietKeSoLe(int a[],int n);

//tim x trong mang
void timViTriX (int a[],int n,int x);
int main (){
	//kahi bao bien
	int a[MAX];
	int n;
	int x;
	// nhap mang
	printf("Nhap vao n so nguyen: ");
	do {
	scanf("%d",&n);
	 if (n <= 0){
            printf("\nNhap lai n: ");
        }
    } while (n <= 0);
	nhap (a,n);
	//xuat so lon nhat
	xuatGTLN(a,n);
	//cac so le
	lietKeSoLe (a,n);
	//x o vi tri
	timViTriX (a,n,x);
return 0;
}
void nhap(int a[],int &n){
	int temp;
	printf("Nhap cac phan tu cua mang:\n");
	for (int i=0;i<n;i++){
		printf("a[%d]:",i);
		scanf("%d",&temp);
		a[i]=temp;
	}
}
int timGTLN(int a[],int n){
	int gtln=a[0];
	for (int i=1;i<n;i++){
		if (a[i]>gtln){
			gtln=a[i];
		}	
	}
	return gtln;	
}
void xuatGTLN(int a[],int n){
	int gtln = timGTLN (a,n);
	printf("\n\nGia Tri Lon Nhat La: %d ",gtln);
}
void lietKeSoLe(int a[],int n){
	int soluong = 0;
	int temp;
	printf("\n\nCac so le: ");
	for (int i = 0; i < n; i++){
		if (a[i]%2 != 0){
			soluong++;
                printf("%d  ",a[i]);
		}
	}
	if(soluong==0){
		printf("Khong co");
	}
}
void timViTriX (int a[],int n,int x){
	printf("\n\nNhap gia tri X can tim: ");
	scanf("%d",&x);
	printf("X o vi tri: ");
	int soluong = 0;
		for (int i = 0; i < n; i++){
			if(a[i]==x){
			soluong++;
			printf("%d ",i);
			}
		}
			if(soluong == 0){
				printf("Khong co x trong mang");
			}
}