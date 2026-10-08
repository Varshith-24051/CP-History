#include <stdio.h>
struct new_try{
    int Name ; 
    float Roll_Number ; 
    char Marks ; 
}

int main(){
    int Marks_avg  ; 
    struct new_try student1{1, 45.5, 'A'} ;
    struct new_try student2{2, 50.5, 'B'} ;
    struct new_try student3{3, 55.5, 'C'} ;
    printf("Student 1 : Name = %d , Roll Number = %.2f , Marks = %c \n", student1.Name, student1.Roll_Number, student1.Marks) ;
    printf("Student 2 : Name = %d , Roll Number = %.2f , Marks = %c \n", student2.Name, student2.Roll_Number, student2.Marks) ;
    printf("Student 3 : Name = %d , Roll Number = %.2f , Marks = %c \n", student3.Name, student3.Roll_Number, student3.Marks) ;
    Marks_avg = (student1.Marks + student2.Marks + student3.Marks) / 3 ;
    printf("Average Marks = %d \n", Marks_avg) ;

    return 0 ; 
}