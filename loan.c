#include<stdio.h>
#include <math.h>

float monthlypaymentcalc(float r, int n, float p){
    r = r/1200;
    float num = pow((1 + r), n);
    float answer = p*((r * num)/(num - 1));
    return answer;
}

struct payment{
    float interest; 
    float principal;
    float balance;
};

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
    struct payment payments[100];
    
    payments[0].balance = loan_amount;
    for (int i = 0; i<n; i++){
        payments[i].interest = payments[i].balance * r;
        payments[i].principal = monthlypayment - payments[i].interest;
        payments[i+1].balance = payments[i].balance - payments[i].principal;
        if (payments[i+1].balance > 1){
            if(payments[i].interest > 10){
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i+1, monthlypayment, payments[i].principal, payments[i].interest, payments[i+1].balance);
            }
            else{
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$%.2f\n", i+1, monthlypayment, payments[i].principal, payments[i].interest, payments[i+1].balance);
            }
        }
        else{
            printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$0\n", i+1, monthlypayment, payments[i].principal, payments[i].interest);
        }
    }
    
    return 0;
}