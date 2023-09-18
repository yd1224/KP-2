#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
    double a,b,c;
    char ans[] = "yes";
    char lesszero[] = "yes";
    char exist[] = "yes";
    int result_ans = 0;
    int result_less0 = 0;
    int result_exist = 0;
    char exist1[3];
    char lesszero1[3];
    char ans1[3];

    
    
    while(result_ans == 0){
        while (result_less0 == 0) {
            while (result_exist == 0){
                
                printf("Enter the first side a: ");
                scanf("%lf",&a);
                printf("Enter the second side b: ");
                scanf("%lf",&b);
                printf("Enter the third side c: ");
                scanf("%lf",&c);
                if(a > 0 && b > 0 && c > 0){
                    if((a+b)>c && (a+c)>b && (b+c)>a){
                        double p=(a+b+c)/2.0;
                        double area=sqrt(p*(p-a)*(p-b)*(p-c));
                        printf("\n");
                        printf("\t Area of the triangle is: %f \n", area);
                        printf("\n");
                        double P = a + b + c;
                        printf("\t Perimeter of the triangle is: %f \n", P);
                        printf("\n");
                        
                        double ha = (2 * sqrt(p*(p-a)*(p-b)*(p-c)))/a;
                        printf("\t The height to side a is: %f\n", ha);
                        double hb = (2 * sqrt(p*(p-a)*(p-b)*(p-c)))/b;
                        printf("\t The height to side b is: %f\n", hb);
                        double hc = (2 * sqrt(p*(p-a)*(p-b)*(p-c)))/c;
                        printf("\t The height to side c is: %f\n", hc);
                        printf("\n");
                        
                        double ma = 0.5 * sqrt(2*b*b + 2*c*c - a*a);
                        printf("\t The median to side a is: %f\n", ma);
                        double mb = 0.5 * sqrt(2*a*a + 2*c*c - b*b);
                        printf("\t The median to side b is: %f\n", mb);
                        double mc = 0.5 * sqrt(2*a*a + 2*b*b - c*c);
                        printf("\t The median to side c is: %f\n", mc);
                        printf("\n");
                        
                        double bisect_a = 2/( b + c) * sqrt(b*c*p*(p-a));
                        printf("\t The bissectrice to side a is: %f\n", bisect_a);
                        double bisect_b = 2/( a + c) * sqrt(a*c*p*(p-b));
                        printf("\t The bissectrice to side b is: %f\n", bisect_b);
                        double bisect_c = 2/( a + b) * sqrt(a*b*p*(p-c));
                        printf("\t The bissectrice to side c is: %f\n", bisect_c);
                        printf("\n");
                        break;
                        
                    }
                    else{
                        printf("Triangle does not exist. If you want to try entering sides again, please type \"yes\", if you do not - type \"no\": \n");
                        scanf("%s", exist1 );
                        int result_exist = strcmp(exist, exist1);
                        if(!(result_exist == 0))
                            goto exit;
                    }
                }
                
                
                
                if(!(a > 0 && b > 0 && c > 0)){
                    
                    printf("The entered number is not greater than zero. If you want to try entering sides again, please type \"yes\", if you do not - type \"no\":\n");
                    scanf("%s", lesszero1);
                    int result_less0 = strcmp(lesszero, lesszero1);
                    if(!(result_less0 == 0))
                        goto exit;
                }
            }
            
            
            
            printf("If you want to continue, please type \"yes\", if you do not - type \"no\":\n");
            scanf("%s", ans1);
            int result_ans = strcmp(ans, ans1);
            if(!(result_ans == 0))
                break;
        }
        
    exit:
        return 0;
    }
}
