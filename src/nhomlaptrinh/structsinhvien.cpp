//1. Bien luan ngay thang nam
//2. Sap xep danh sach sinh vien tang dan theo diem tb
//3. Sap xep theo ten (goi y ham: strcmp thuoc thu vien string.h)
//4. Kiem tra hoc bong co sv
//5. Dem so luong sinh vien co hoc luc gioi
//6. Tim kiem sinh vien theo ten
#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct DataTime { // ngay thang nam 
    int day, month, year;
};
typedef struct Student { // 1 hoc sinh gom ten diem va sinh nhat
    char name [25];
    float mark;
    DataTime birth_of_date;
};
typedef struct Students { //1 list hoc sinh (tong so hoc sinh)
    Student list [MAX];
    int amount;
};
void enter (DataTime &input);//nhap sinh nhat
void enter (Student &input);//nhap thong tin hoc sinh do 
void enter (Students &input);// cac hoc sinh
// đây là dong them vao
bool isLeapYear(int year);
bool isValid (DataTime checker);
void ascSortByMark (Students &source);//sap xep diem
void ascSortByName (Students &source);//sap xep ten
int countStudentsHaveScholarship (Students source);
void printAmountStudentsHaveScholarship (Students source);//hoc bong
void digitsListStudentsHaveScholarship (Students source);
int countStudentsHaveGoodAcademicPower (Students source);//hoc sinh gioi
void printNumberOfStudentsHaveGoodAcademicPower (Students source);
Students findStudentByName (Students source,char name []);
void digitsStudentByName (Students source,char name[]);
void printValue (DataTime output);// in ra ngay sinh nhat
void printValue (Student output);//in ra thong tin hoc sinh do
void printValue (Students output);//in ra cac hoc sinh
int main (){
    Students list;//viec trong muc nhiu hoc sinh
    enter (list);// nhap 
    printValue (list);//xuat
    // sap xep tang dan
    ascSortByMark (list);
    printf ("\n\nAsc Sort By Mark : ");
    printValue (list);
    //sap xep theo ten
    printf ("\n\nAsc Sort By Name : ");
    ascSortByName (list);
    printValue (list);
    //hoc bong
    printAmountStudentsHaveScholarship(list);
    digitsListStudentsHaveScholarship (list);
    //hoc sinh gioi
    printNumberOfStudentsHaveGoodAcademicPower(list);
    //tim ten
    printf ("\nName to search: ");
    fflush (stdin);
    gets (search.name);
    digitsStudentByName (list,search.name);
    return 0;
}
void enter (DataTime &input){
    do{
    printf ("\nenter day: ");
    scanf ("%d",&input.day);
    printf ("\nenter month: ");
    scanf ("%d",&input.month);
    printf ("\nenter year: ");
    scanf ("%d",&input.year);
        if(!isValid(input)){
            printf ("\nenter again!");
        }
    }while (!isValid(input));
}// cong viec nhap sinh nhat
void enter (Student &input){
    printf ("name: ");
    fflush (stdin);//xoa bo nho dem 
    gets (input.name);//nhap chuoi
    printf ("enter birth of date");
    enter (input.birth_of_date);// goi ham nhap sinh nhat 
    printf ("enter mark: ");
    scanf ("%f",&input.mark);//nhap diem bth
}
void enter (Students &input){
    printf ("enter number of students: ");
    scanf ("%d",&input.amount);// nhap bao nhiu hoc sinh
    for (int position = 0; position < input.amount; position ++){
        printf ("enter student at %d ",position);
        enter (input.list[position]);
    }
}
bool isLeapYear(int year){
    return year%4 == 0;
}
bool isValid(DataTime date){
    bool is_valid = true;
    if((date.month<1 || date.month >12)||(date.day<1)){
        is_valid = false;
    }else{
        switch(date.month){
            case 1:case 3: case 5: case 7: case 8: case 10: case 12:
                if(date.day>31){
                    is_valid = false;
                }
                break;
            case 4: case 6: case 9: case 11:
                if(date.day>30){
                    is_valid = false;
                }
                break;
            case 2: 
                if(isLeapYear(date.year) && date.day>29){
                    is_valid = false;
                }
                else if(!isLeapYear(date.year) &&date.day>28){
                    is_valid = false;
                }
            break;
        }
    }
    return is_valid;
}
void printValue (DataTime output){
    printf ("Birthday: %.2d/%.2d/%.4d\t",output.day,output.month,output.year);
}
void printValue (Student output){
    printf ("\nName: %s  \t",output.name);
    printValue (output.birth_of_date);
    printf ("Mark:%.2f\t",output.mark);
}
void printValue (Students output){
    printf ("\n\nlist of student");
    for (int position = 0;position < output.amount; position ++ ){
        printf ("\n\nStudent %d is   ",position);
        printValue (output.list[position]);
    }
}
void ascSortByMark (Students &source){
    Student temp ;
    for (int pre = 0; pre < source.amount - 1;pre ++){
        for (int next = pre + 1; next < source.amount ;next ++ ){
            if (source.list[pre].mark > source.list[next].mark){
                temp = source.list[pre];
                source.list[pre] = source.list[next];
                source.list[next] = temp;
            }
        }
    }
}
void ascSortByName (Students &source){
    Student temp ;
    for (int pre = 0; pre < source.amount - 1;pre ++){
        for (int next = pre + 1; next < source.amount ;next ++ ){
            if (strcmp(source.list[pre].name,source.list[next].name) == 1){
                temp = source.list[pre];
                source.list[pre] = source.list[next];
                source.list[next] = temp;
            }
        }
    }
}
int countStudentsHaveScholarship (Students source){
    int counter = 0;
    for (int position = 0;position < source.amount; position ++ ){
        if (source.list[position].mark >= 7){
            counter ++;
        }
    }
    return counter;
}
void printAmountStudentsHaveScholarship (Students source){
    int counter =  countStudentsHaveScholarship (source);
    printf ("\n\nNumber Of Students Have Scholarship: %d",counter);  
}
void digitsListStudentsHaveScholarship (Students source){
    int counter = 0;
    printf ("\n\nList Of Students Have Scholarship:\n ");
        for (int position = 0;position < source.amount; position ++ ){
            if (source.list[position].mark >= 7){
                printValue(source.list[position]);  
            }
        }
}
int countStudentsHaveGoodAcademicPower (Students source){
    int counter = 0;
    for (int position = 0;position < source.amount; position ++ ){
            if (source.list[position].mark >= 8){
                counter ++;
            }
    }
    return counter;
}
void printNumberOfStudentsHaveGoodAcademicPower (Students source){
    int counter = countStudentsHaveGoodAcademicPower (source);
    printf ("\n\nNumber Of Students Have Good Academic Power:%d",counter);
}
Students findStudentByName (Students source,char name []){
    Students dest;
    dest.amount = 0;
    for (int position = 0;position < source.amount; position ++ ){
        if (strcmp (source,Students[position].name,name) == 0){
            dest.amount ++;
            dest.Students[dest.amount-1] == source.Students[position];
        }
    }
    return dest;
}
void digitsStudentByName (Students source,char name[]){
    Students dest = findStudentByName (source,name);
    for (int position = 0;position < source.amount; position ++ ){
        printValue (dest.Students[position]);
    }
}