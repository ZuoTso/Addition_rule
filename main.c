#include <stdio.h>
#include <math.h>

int main() {
    // Define two variables and their absolute values
    int a, b, absa, absb;
    long long int ans=0;
    int a_array[32] = {0}, b_array[32] = {0}, ans_array[32] = {0};
    int a_binary[20] = {0}, b_binary[20] = {0};
    int temp = 0, num = 0;
    scanf("%d%d", &a, &b);

    // For the input a b variable to determine whether it is a positive value
    // Convert it to binary
    if (a > 0) {
        a_array[0] = 0;
        absa = a;
    } else {
        a_array[0] = 1;
        absa = abs(a);
    }
    if (b > 0) {
        b_array[0] = 0;
        absb = b;
    } else {
        b_array[0] = 1;
        absb = abs(b);
    }
    //a
    temp = absa;
    int j = 19;
    while (temp > 0) {
        num++;
        a_binary[j] = temp % 2;
        temp /= 2;
        j--;
    }
    num--;
    int exp_a = num;
    num += 127;
    int k = 8;
    while (num > 0) {
        a_array[k] = num % 2;
        num /= 2;
        k--;
    }

    //b
    temp = absb;
    num = 0;
    j = 19;
    while (temp > 0) {
        num++;
        b_binary[j] = temp % 2;
        temp /= 2;
        j--;
    }
    num--;
    int exp_b = num;
    num += 127;
    k = 8;
    while (num > 0) {
        b_array[k] = num % 2;
        num /= 2;
        k--;
    }

    for (int i = 19 - exp_a + 1; i < 20; ++i) {
        a_array[9 + i + exp_a - 20] = a_binary[i];
    }

    for (int i = 19 - exp_b + 1; i < 20; ++i) {
        b_array[9 + i + exp_b - 20] = b_binary[i];
    }

    // Implement adder
    int c=0;
    for (int i = 31; i >= 0; i--) {
        if(a_array[i]+b_array[i]+c==0){
            ans_array[i]=0;
            c=0;
        } else if(a_array[i]+b_array[i]+c==1){
            ans_array[i]=1;
            c=0;
        } else if(a_array[i]+b_array[i]+c==2){
            ans_array[i]=0;
            c=1;
        } else if(a_array[i]+b_array[i]+c==3){
            ans_array[i]=1;
            c=1;
        }
    }
    int ans_array2[32]={0};
    if(ans_array[0]==1){
        for (int i = 0; i < 32; ++i) {
            ans_array2[i]=ans_array[i];
        }
        for (int i = 0; i < 32; ++i) {
            if(ans_array2[32-1-i]-1==0) {
                ans_array2[32-1-i] -=1;
                break;
            }
            else {
                ans_array2[32-1-i]=1;
            }
        }
        for (int i = 0; i < 32; ++i) {
            if(ans_array2[i]==1)ans_array2[i]=0;
            else ans_array2[i]=1;
        }
    }
    if(ans_array[0]==0) {
        for (int i = 0; i < 31; ++i) {
            ans += ans_array[31 - i] * pow(2, i);
        }
    } else{
        for (int i = 0; i < 31; ++i) {
            ans += ans_array2[31 - i] * pow(2, i);
        }
    }
    // output
    printf("   ");
    for (int i = 0; i < 32; ++i) {
        printf("%d", a_array[i]);
        if((i+1)%8==0&&i!=31) printf(" ");
    }
    printf("\n+) ");
    for (int i = 0; i < 32; ++i) {
        printf("%d", b_array[i]);
        if((i+1)%8==0&&i!=31) printf(" ");
    }
    printf("\n");
    for (int i = 0; i < 39; ++i) {
        printf("-");
    }
    printf("\n   ");
    for (int i = 0; i < 32; ++i) {
        printf("%d", ans_array[i]);
        if((i+1)%8==0&&i!=31) printf(" ");
    }
    if(ans_array[0]==0){
        printf("\n%d + %d = %lld", a, b, ans);
    } else printf("\n%d + %d = -%lld", a, b, ans);

    return 0;
}
