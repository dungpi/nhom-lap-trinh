#include <stdio.h>
#define MAX 50
void nhapMang(int a[], int &n);
void xuatmang(int a[],int n);
int kiemtraToanChan(int a[], int n);
void xuatMangChan (int a[],int n);
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
    printf ("Cac phan tu:");
    xuatmang (a,n);
    	if (kiemtraToanChan(a,n) == -1){
	    	printf("\nMang khong toan so chan!");
		}
		else{
			printf("\nMang toan so chan!");
		}
	xuatMangChan (a,n);
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
void xuatMangChan (int a[],int n){
	int temp;
	printf ("\nCac so chan :");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n;j++){
			if (a[i]%2 == 0){
			a[i] = a[j]; 
					printf ("\t%d",a[j]);
			}
		}
	}
}
