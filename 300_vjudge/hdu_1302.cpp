#include <cstdio>
int main()
{
    double H, U, D, F;
    while(~scanf("%lf%lf%lf%lf",&H,&U,&D,&F))
    {
        if(H==0 && U==0 && D==0 && F==0)
            break;
        double sum = 0;
        int k = 0;
        int flag = 0;
        double dd = (U*F)/100.0;
        while(sum <= H)
        {
            if(sum < 0)
            {
                flag = 1;
                break;
            }
            k++;
            sum+=U;
            if(sum > H)
                break;
            sum-=D;
            U-=dd;
        }
        if(flag)
            printf("failure on day %d\n",k);
        else
            printf("success on day %d\n",k);
    }
    return 0;
}