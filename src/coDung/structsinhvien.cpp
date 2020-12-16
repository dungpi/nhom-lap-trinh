//1. Bien luan ngay thang nam
//2. Sap xep danh sach sinh vien tang dan theo diem tb
//3. Sap xep theo ten (goi y ham: strcmp thuoc thu vien string.h)
//4. Kiem tra hoc bong co sv
//5. Dem so luong sinh vien co hoc luc gioi
//6. Tim kiem sinh vien theo ten
#include<stdio.h>
struct Date{
	int ngay,thang,nam;
};
struct SinhVien{
	char Ten[30];
	char MSSV[20];
	float DiemTB;
	struct Date NgaySinh;	
};
void NhapNgaySinh(struct Date &ns){
	printf("\tNhap ngay: ");
	scanf("%d", &ns.ngay);
	printf("\tNhap thang: ");
	scanf("%d", &ns.thang);
	printf("\tNhap nam: ");
	scanf("%d", &ns.nam);
}
void XuatNgaySinh(struct Date ns){
	printf("Ngay sinh: %.2d/%.2d/%.2d\n",ns.ngay,ns.thang,ns.nam);
}
void Nhap(struct SinhVien &a){
	fflush(stdin);
	printf("Nhap ten: ");
	gets(a.Ten);
	printf("Nhap MSSV: ");
	gets(a.MSSV);
	printf("Nhap Diem TB: ");
	scanf("%f", &a.DiemTB);
	printf("Nhap Ngay sinh: \n");
	NhapNgaySinh(a.NgaySinh);
}
void Xuat(struct SinhVien a){
	printf("Ten: %s\n", a.Ten);
	printf("MSSV: %s\n",a.MSSV);
	printf("DiemTB: %.1f\n",a.DiemTB);
	XuatNgaySinh(a.NgaySinh);
}
void NhapDS(struct SinhVien a[], int n){
	for(int i=0;i<n;i++){
		printf("Nhap sv %d: \n",i+1);
		Nhap(a[i]);
	}
}
void XuatDS(struct SinhVien a[], int n){
	for(int i=0;i<n;i++){
		printf("Xuat sv %d: \n",i+1);
		Xuat(a[i]);
	}
}
int main(){
	struct SinhVien sv[10], a1,a2;
	Nhap(a1);
	a2=a1;
	Xuat(a1);
	Xuat(a2);
	//int n=3;
	//NhapDS(sv,n);
	//XuatDS(sv,n);
	/*printf("Nhap sv1: \n");
	Nhap(sv1);
	printf("Nhap sv2: \n");
	Nhap(sv2);
	printf("Xuat sv1: \n");
	Xuat(sv1);
	printf("Xuat sv2: \n");
	Xuat(sv2);
	*/
	/*nhap thong tin sv1
	printf("Nhap ten sv1: ");
	gets(sv1.Ten);
	printf("Nhap MSSV: ");
	gets(sv1.MSSV);
	printf("Nhap Diem TB: ");
	scanf("%f", &sv1.DiemTB);
	fflush(stdin);
	printf("Nhap ten sv2: ");
	gets(sv2.Ten);
	printf("Nhap MSSV: ");
	gets(sv2.MSSV);
	printf("Nhap Diem TB: ");
	scanf("%f", &sv2.DiemTB);
	printf("Thong tin sv 1: \n");
	printf("Ten: %s\n", sv1.Ten);
	printf("MSSV: %s\n",sv1.MSSV);
	printf("DiemTB: %.1f",sv1.DiemTB);
	
	printf("Thong tin sv 2: \n");
	printf("Ten: %s\n", sv2.Ten);
	printf("MSSV: %s\n",sv2.MSSV);
	printf("DiemTB: %.1f",sv2.DiemTB);
	*/
}