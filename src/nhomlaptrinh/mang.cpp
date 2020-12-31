#include <stdio.h>
#include <math.h>
#define MAX 50
void nhapMang(int a[], int &n);
void xuatmang(int a[],int n);
int kiemtraToanChan(int a[], int n);
int kiemtraCoTonTaiSoChan(int a[], int n);
void xuatTontaiSoChan(int a[], int n);
int sosanhChanle(int a[], int n);
void xuatsosanhChanLe(int a[], int n);
int tinhTileChanle(int a[], int n);
void xuatTileChanLe(int a[], int n);
int main(){
    int a[MAX],n;
        printf ("Nhap so phan tu n: ");
    do {
        scanf ("%d",&n);
        if (n <= 0){
            printf ("Nhap lai n: ");
            scanf ("%d",&n);
        }
    }while (n <= 0);
    nhapMang (a,n);
    printf ("\nCac phan tu:   ");
    xuatmang (a,n);
    	if (kiemtraToanChan(a,n) == -1){
	    	printf("\nMang khong toan so chan!");
		}
		else{
			printf("\nMang toan so chan!");
		}
	   printf("\nSo sanh so luong phan tu chan va le: %d ",sosanhChanLe(a,n));	
    return 0; 
}
void nhapMang(int a[], int &n){
    int temp;
    printf ("Nhap cac phan tu n: ");
  	for (int i=0;i<n;i++){
		printf("\na[%d]:",i);
		scanf("%d",&temp);
		a[i]=temp;
	}
}
void xuatmang(int a[],int n){
	 for(int i=0; i<n; i++){
	 	printf("\t%d", a[i]);
	 }
}
int kiemtraToanChan(int a[], int n){
	for (int i=0; i<n; i++)
	    if(a[i]%2!=0){
	     	return -1;
			 break;
		}
			return 1;	 
}
int kiemtraCoTonTaiSoChan(int a[], int n){
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			printf("\nMang co ton tai so chan!");
			return 1;
			break;
		}
		return 1;
    }
}
void xuatTontaiSoChan(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d",a[i]);
	}
}
int sosanhChanLe(int a[], int n){
	int demChan = 0;
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			demChan++;
		}
	}
	    if(demChan > n - demChan){
	    	return -1;
		}
		else (demChan < n - demchan){
			 return 1;
		}
		     return 0;
}
void xuatsosanhChanLe(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d",a[i]);
	}
}
int tinhTileChanle(int a[], int n){
	
}