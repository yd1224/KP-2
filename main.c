#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
double getInput(const char *prompt);
bool isScientificNotation(const char *input);
int main(void) {
    double a,b,c;
    while(1){
        a = getInput("Enter the first side a: ");
        b = getInput("Enter the second side b: ");
        c = getInput("Enter the third side c: ");
        if(a < 0 || b < 0 || c < 0){
            printf("\n");
            printf("Enter only positive numbers. Please try again.\n");
            printf("\n");
        }
        else if ((a+b) <= c || (a+c) <= b || (c+b) <= a){
            printf("\n");
            printf("Triangle does not exist. Please try again.\n");
            printf("\n");
        }
            else{
                break;
            }
        }

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
        return 0;
      
    }

double getInput(const char *prompt) {
    char input[15];
    double number;

    do {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input) {
    int len = strlen(input);
    int eCount = 0;
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'e' || c == 'E') {
            eCount++;
        } else if (isdigit(c) && eCount == 0) {
            digitsBeforeE++;
        } else if (isdigit(c) && eCount == 1) {
            digitsAfterE++;
        }
    }


    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}
