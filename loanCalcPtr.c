#include<stdio.h>
#include <math.h>

float monthlypaymentcalc(float r, int n, float p){
    r = r/1200;
    float num = pow((1 + r), n);
    float answer = p*((r * num)/(num - 1));
    return answer;
}

int main()
{
    
    float loan_amount, r, principal;
    int n;
    printf("Enter amount of loan : $");
    scanf("%f", &loan_amount);
    printf("Enter interest rate per year : %%");
    scanf("%f", &r);
    printf("Enter number of payments per year : ");
    scanf("%d", &n);
    float monthlypayment = monthlypaymentcalc(r, n, loan_amount);
    printf("Monthly payment should be %.2f\n", monthlypayment);
    printf("=================AMORTIZATION SCHEDULE=============\n");
    printf("#\t\tPayment\t\tPrincipal\tInterest\t\tBalance\n");
    r = r/1200;
    float principalarr[n];
    float interestarr[n];
    float balancearr[n];
    float* principal_pointer = principalarr;
    float* interest_pointer = interestarr;
    float* balance_pointer = balancearr;
    *balance_pointer = loan_amount;
    for (int i = 0; i < n; i++) {
        *interest_pointer = *balance_pointer * r;
        *principal_pointer = monthlypayment - *interest_pointer;
        *(balance_pointer + 1) = *balance_pointer - *principal_pointer;
        
        if (*(balance_pointer + 1) > 1) {
            if (*interest_pointer > 10) {
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i+1, monthlypayment, *principal_pointer, *interest_pointer, *(balance_pointer + 1));
            } else {
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$%.2f\n", i+1, monthlypayment, *principal_pointer, *interest_pointer, *(balance_pointer + 1));
            }
        } else {
            printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$0\n", i+1, monthlypayment, *principal_pointer, *interest_pointer);
        }
        
        interest_pointer++;
        principal_pointer++;
        balance_pointer++;
    }
    
    return 0;
}