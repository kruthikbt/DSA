#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct {     char name[20]; 
    int emp_id; 
    enum { FULL_TIME, CONTRACT } type;     
    union {         float salary;        
         struct {             
            float hourly_rate;             
            int hours_worked; 
        } contract_info; 
    } pay; 
} Employee; 
 
int main() { 
    int n, i; 
    float total_bill = 0, pay; 
    Employee *e; 
 
    printf("Enter number of employees: ");     
    scanf("%d", &n); 
 
    e = malloc(n * sizeof(Employee)); 
 
    if (e == NULL) { 
        printf("Memory allocation failed!\n"); 
        return 1; 
    } 
 
    for (i = 0; i < n; i++) {         
        printf("\nEnter employee name: ");         
        scanf("%19s", (e+i)->name); 
 
        printf("Enter employee ID: ");        
         scanf("%d", &(e+i)->emp_id); 
 
        printf("Enter type (0-Full-time, 1-Contract): ");         
        scanf("%d", (int *)&(e+i)->type); 
 
        if ((e+i)->type == FULL_TIME) {             
            printf("Enter monthly salary: ");            
             scanf("%f", &(e+i)->pay.salary); 
        } else { 
            printf("Enter hourly rate: "); 
            scanf("%f", &(e+i)->pay.contract_info.hourly_rate); 
 
            printf("Enter hours worked: "); 
            scanf("%d", &(e+i)->pay.contract_info.hours_worked); 
        } 
    } 
 
    printf("\n--- Employee Payslips ---\n"); 
 
    for (i = 0; i < n; i++) {         
        if ((e+i)->type == FULL_TIME) 
            pay = (e+i)->pay.salary; 
        else 
 
            pay = (e+i)->pay.contract_info.hourly_rate * 
                  (e+i)->pay.contract_info.hours_worked; 
 
        printf("\nName: %s\n", (e+i)->name);         
        printf("Employee ID: %d\n", (e+i)->emp_id);         
        printf("Total Pay: %.2f\n", pay); 
 
        total_bill += pay; 
    } 
 
    printf("\nTotal Salary Bill: %.2f\n", total_bill); 
 
    free(e);    
 return 0; 
} 
