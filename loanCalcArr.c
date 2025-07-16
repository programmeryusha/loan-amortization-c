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
    balancearr[0] = loan_amount;
    for (int i = 0; i<n; i++){
        interestarr[i] = balancearr[i] * r;
        principalarr[i] = monthlypayment - interestarr[i];
        balancearr[i+1] = balancearr[i] - principalarr[i];
        if (balancearr[i+1] > 1){
            if(interestarr[i] > 10){
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i+1, monthlypayment, principalarr[i], interestarr[i], balancearr[i+1]);
            }
            else{
                printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$%.2f\n", i+1, monthlypayment, principalarr[i], interestarr[i], balancearr[i+1]);
            }
        }
        else{
            printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t\t$0\n", i+1, monthlypayment, principalarr[i], interestarr[i]);
        }
        
    }
    
    return 0;
}