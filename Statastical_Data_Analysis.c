#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
// driver code
    int z;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t==========================================\
\n\n\t\t\t\t\t Statistical Analysis using C-Language\n\n\t\t\t\t\t==========================================\n");
    printf("\n\n\n\n");
    printf("\n\n\t\t\t\t\tChoose the data for analysis\n\n");
    printf("\t\t\t\t\t***********************\n\n");
    printf("\t\t\t\t\t1.For Raw Data\n\n");
    printf("\t\t\t\t\t2.For continuos Data\n\n");
    printf("\t\t\t\t\t3.For discrete Data\n\n");
    printf("\t\t\t\t\t***********************\n\n\n");
    printf("\t\t\t\t\tEnter the Sr.No. to your choice : ");
    scanf("%d",&z);
    switch(z)
    {
    case 1:
        raw();
        break;
    case 2:
        continuos();
        break;
    case 3:
        discrete();
        break;
    }
}
// discreate data analysis
void discrete()
{

    int i,j,r,c=2,temp,f=0;
    float Q1,Q2,Q3,skb;
    float sum=0,std,cv,mat[50],freq[50],freq1[50],sumxifi[50],xsum,var,freq_sum=0,xifi[50],mean=0,xifi_sum=0,ne,ltcf[50],mef,d=0,mev,mode,skp;
     printf("\n\n\t\t\t\t\t======================\n\n");
    printf("\t\t\t\t\tanalysis for discrete data\n\n");
    printf("\n\n\t\t\t\t\t======================\n\n");
    printf("\nEnter total number of observations\n :");
    scanf("%d",&r);
    printf("\n observations are:\n");
    for(i=0; i< r; i++)
    {
        scanf("%f",&mat[i]);

        printf("\n");
    }
    printf("\nenter the freq of obs\n");
    for (i = 0; i < r; ++i)
    {
        scanf("%f",&freq[i]);
    }
    for(i=0; i<r; i++)
    {
        freq_sum=freq_sum+freq[i];
    }
    for(i=0; i<r; i++)
    {
        xifi[i]=mat[i]*freq[i];
    }
    for(i=0; i<r; i++)
    {

        xifi_sum=xifi_sum+xifi[i];
    }
    {
        mean=(xifi_sum/freq_sum);
        printf("\n\t\t\t\t\t1)The mean is%f",mean);
    }
    //for xi²fi multiplication

    for(i=0; i<r; i++)
    {
        sumxifi[i]=(mat[i]*mat[i])*freq[i];
    }

    for(i=0; i<r; i++)
    {

        xsum=xsum+sumxifi[i];
    }
    var=(xsum/freq_sum)-(mean*mean);
    printf("\n\t\t\t\t\t2)variance=%f",var);

    std=sqrt(var);

    printf("\n\t\t\t\t\t3)The standard deviations is : %f",std);
    cv=((std/mean)*100);
    printf("\n\t\t\t\t\t4)the cv is =%f",cv);
//median logic
    for(i=0; i<r; i++)
    {
        ltcf[i]=d+freq[i];
        d=ltcf[i];

    }
    if(freq_sum/(float)2==1)
    {
        f=f+1;
    }
    if(f==1)
    {
        mev=(((freq_sum/2)+((freq_sum/2)+1))/2);

    }
    else {
        mev=((freq_sum+1)/2);
    }
    for(i=0; i<r; i++)
    {
        if(ltcf[i]>mev)
        {
            mef=ltcf[i];
            break;
        }
    }
    for(i=0; i<r; i++)
    {
        if(ltcf[i]==mef)
        {
            printf("\n\t\t\t\t\t5)The median is %f",mat[i]);
        }
    }
//mode

    for(i=0; i<r; i++)
    {
        freq1[i]=freq[i];
    }
    for(i=0; i<r; i++)
    {
        if(freq[0]<freq[i])
            freq[0]=freq[i];
        ne=freq[0];
    }



    for(i=0; i<r; i++)
    {
        if(freq1[i]==ne)
        {
            printf("\n\t\t\t\t\t6)The mode is %f",mat[i]);
            mode=mat[i];
        }
    }
    skp=((mean-mode)/std);
    printf("\t\t\t\t\t7)The skp is %f\n",skp);
    if(skp<0)
        printf("\t\t\t\t\tdisstribution is negatively skewed\n");
    else
        printf("\t\t\t\t\tdisstribution is positively skewed\n");
    if(f=1) {
        Q1=(((freq_sum/4)+(freq_sum/4)+1)/2);
        Q2=((2*(freq_sum/4)+2*(freq_sum/4)+1)/2);
        Q3=((3*(freq_sum/4)+3*(freq_sum/4)+1)/2);

    }
    else
    {
        Q1=((freq_sum+1)/4);
        Q2=(2*(freq_sum+1)/4);
        Q3=(3*(freq_sum+1)/4);

    }
    printf("\n\t\t\t\t\t8)The Quartile first is %f",Q1);
    printf("\n\t\t\t\t\t9)The Quartile Second is %f",Q2);
    printf("\n\t\t\t\t\t10)The Quartile Third is %f",Q3);
    skb=((Q3+Q1-2*Q2)/Q3-Q1);
    printf("\n\t\t\t\t\t11)The skb is %f",skb);
    if(skb<0)
        printf("\n\t\t\t\t\tdisstribution is negatively skewed\n");
    else
        printf("\n\t\t\t\t\tdisstribution is positively skewed\n");
}



//continuos data analysis
void continuos()
{
    int i,j,up,sf,cf[100],l[100],u[100],temp,x[100],sort[100],tempsort;
    float xl,fm,f1,f2,Q1,Q2,Q3 ;
    int ll,cl,nc,freq[20],f[20];
    float std,mean=0,median=0,mode=0,skp,skb,cv;
    int mat[20][20],sumxifi[20],xsum,var;
    int r,c=2,freq_sum=0,xifi[20],xifi_sum=0;
    float sum=0,mid[20];
   
    printf("\n\t\t\t\t\t====================================\n");
    printf("\n\t\t\t\t\tThe analysis for continous data\n\n");
    printf("\n\t\t\t\t\t====================================\n");
    printf("\n\t\t\t\t\tEnter total number of observations : ");
    scanf("\t\t\t\t\t%d",&r);
    nc=r;
    printf("\n\t\t\t\t\tEnter observations : ");
    for(i=0; i< r; i++)
    {
        for(j=0; j< c; j++)
        {
            scanf("\t\t\t\t\t%d",&mat[i][j]);
        }
    }
    ll=mat[0][0];
    cl=mat[0][1]-mat[0][0];
    printf("\n\t\t\t\t\tenter the freq of obs : ");
    for (i = 0; i < r; ++i)
    {
        scanf("\t\t\t\t\t%d",&freq[i]);
    }
    for(i=0; i<r; i++)
    {
        f[i]=freq[i];
    }
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            sum = sum + mat[i][j] ;
        }
        mid[i]=(sum/2);
        sum = 0;
    }
    for(i=0; i<r; i++)
    {
        freq_sum=freq_sum+freq[i];
    }
    for(i=0; i<r; i++)
    {
        xifi[i]=mid[i]*freq[i];
    }
    for(i=0; i<r; i++)
    {
        xifi_sum=xifi_sum+xifi[i];
    }
    {
        mean=(xifi_sum/freq_sum);
    }
    for(i=0; i<r; i++)
    {
        sumxifi[i]=(mid[i]*mid[i])*freq[i];
    }
    for(i=0; i<r; i++)
    {
        xsum=xsum+sumxifi[i];
    }
    printf("\n\t\t\t\t\t1)The mean is : %f",mean);
    var=(xsum/freq_sum)-(mean*mean);
    printf("\n\t\t\t\t\t2)variance=%d",var);
    std=sqrt(var);
    printf("\n\t\t\t\t\t3)standard deviation is :%f",std);
    cv=((std/mean)*100);
    printf("\n\t\t\t\t\t4)the cv is:%f\n\n",cv);
    for(i=0; i<nc; i++)
    {
        up=ll+cl;
        l[i]=ll;
        u[i]=up;
        ll=up;
        x[i]=((float)l[i]+(float)u[i])/2;
    }
    for(i=0; i<nc; i++)
    {
        sort[i]=f[i];
    }
    cf[0]=f[0];
    for(i=0; i<nc; i++)
    {
        cf[i+1]=cf[i]+f[i+1];
    }
    for(i=0; i<nc; i++)
        sf+=f[i];
    for(i=0; i<nc; i++)
    {
        if((sf/2) >= cf[i]) temp=i+1;
    }
    printf(" \n\t\t\t\t\t5)The median is: %.4f",median=l[temp]+(((((float)sf/(float)2) - cf[temp-1] )/f[temp])*cl));
    printf(" \n\t\t\t\t\t6)The quartile 1 is: %.4f",Q1=l[temp]+(((((float)sf/(float)4) - cf[temp-1] )/f[temp])*cl));
    printf(" \n\t\t\t\t\t7)The quartile 2 is: %.4f",Q2=l[temp]+(((((float)2*sf/(float)4) - cf[temp-1] )/f[temp])*cl));
    printf(" \n\t\t\t\t\t8)The quartile 3 is: %.4f",Q3=l[temp]+(((((float)3*sf/(float)4) - cf[temp-1] )/f[temp])*cl));
    for(i = 0; i < nc-1; i++)
    {
        for(j = i + 1; j < nc ; j++)
        {
            if(sort[i] > sort[j])
            {
                tempsort = sort[i];
                sort[i] =sort[j];
                sort[j] = tempsort;
            }
        }
    }
    for(i=0; i<nc; i++)
        for(i=0; i<nc; i++)
        {
            if(sort[nc-1]==f[i])
            {
                temp=i;
            }
        }
    for(i=0; i<nc; i++)
        xl=(float)l[temp];
    fm=(float)f[temp];
    f1=(float)f[temp-1];
    f2=(float)f[temp+1];
    mode=xl+(((fm-f1)/((2*fm)-f1-f2))*cl);
    printf("\n\t\t\t\t\t9)The mode is : %.4f",mode);
    skb=((Q3+Q1-2*Q2)/Q3-Q1);
    printf("\n\n\n\t\t\t\t\t10)the skb is=>%f",skb);
    if(skb<0)
    {
        printf("\n\t\t\t\t\tDistribution is negatively skewed");
    }
    else {
        printf("\n\t\t\t\t\tDistribution is positively skewed");
    }
    skp=((mean-mode)/std);
    printf("\n\n\n\t\t\t\t\t11)the skp is=>%f",skp);
    if(skp<0)
    {
        printf("\n\t\t\t\t\tDistribution is negatively skewed");
    }
    else {
        printf("\n\t\t\t\t\tDistribution is positively skewed");
    }
}
// Raw data analysis
void raw()
{
    float SD,cv=0,var,median=0,Q1=0,Q2=0,Q3=0,skb=0,skp=0;
    int i,j,a[10],sub[10],sum=0,temp,n,t,s,b[10],k=0,o=1,max=0,mode;
    float x=0.0,y=0.0;
    system("cls");
    printf("\n\t\t\t\t\t=========================\n");
    printf("\n\t\t\t\t\tAnalysis for Raw data\n\n");
    printf("\t\t\t\t\t=========================\n");
    printf("\n\t\t\t\t\t Enter the total No.of Observations : ");
    scanf("\t\t\t\t\t%d",&n);
    printf("\n\t\t\t\t\tEnter the set of number : ");
    for(i=0; i<n; i++)
    {
        scanf("\t\t\t\t\t%d",&a[i]);
        sum=sum+a[i];
    }
    x=(float)sum/(float)n;
    printf("\n\t\t\t\t\t1)mean\t= %f\n",x);
    for(i=0; i<n; i++)
    {
        sub[i]=(a[i]-x)*(a[i]-x);
        sum+=sub[i];
    }
    var=(float)(sum/n);
    SD=(sqrt(var));
    printf("\t\t\t\t\t2)Variance =%f\n",var);
    printf("\t\t\t\t\t3)Sandard Deviation=%f\n",SD);
    cv=((SD/x)*100);
    printf("\t\t\t\t\t4)The cv is=%.2f\n",cv);
    for(i = 0; i < n-1; i++)
    {
        for(j = i + 1; j < n ; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] =a[j];
                a[j] = temp;
            }
        }
    }
    if((n%2)==0)
    {
        printf("\n\t\t\t\t\t5)The median is %.2f\n",median=((float)a[(n/2)-1] + (float)a[((n/2)+1)-1])/2);
        printf("\t\t\t\t\t6)The quartile 1 is %.2f\n",Q1=((float)a[(n/4)-1] + (float)a[((n/4)+1)-1])/2);
        printf("\t\t\t\t\t7)The quartile 2 is %.2f\n",Q2=((float)a[2*(n/4)-1] + (float)a[(2*(n/4)+1)-1])/2);
        printf("\t\t\t\t\t8)The quartile 3 is %.2f\n",Q3=((float)a[3*(n/4)-1] + (float)a[(3*(n/4)+1)-1])/2);
    }
    else
    {
        printf("\t\t\t\t\t5)The median is %.2f\n",median=a[((n+1)/2)-1]);
        printf("\t\t\t\t\t6)The quartile 1 is  %.2f\n",Q1=a[((n+1)/4)-1]);
        printf("\t\t\t\t\t7)The quartile 2 is  %.2f\n",Q2=a[(2*(n+1)/4)-1]);
        printf("\t\t\t\t\t8)The quartile 3 is  %.2f\n",Q3=a[((3*n+1)/4)-1]);
    }
    for(i=0; i<n-1; i++)
    {
        mode=0;
        for(j=i+1; j<n; j++)
        {
            if(a[i]==a[j])
            {
                mode++;
            }
        }
        if((mode>max)<<(mode!=0))
        {
            k=0;
            max=mode;
            b[k]=a[i];
            k++;
        }
    }
    for(i=0; i<n; i++)
    {
        if(a[i]==b[i])
            o++;
    }
    if(o==n)
        printf("\n\t\t\t\t\t9)Their is no mode");
    else
    {
        for(i=0; i<k; i++)
            printf("\t\t\t\t\t9)The mode is : %d",b[i]);
    }
    skb=((Q3+Q1-2*Q2)/(Q3-Q1));
    printf("\n\n\t\t\t\t\t10)The bowleys coefficient of skewness is %.2f",skb);
    if(skb<0)
    {
        printf("\n\t\t\t\t\tThe distribution is negatively skewed");
    } 
    else
    {
        printf("\n\t\t\t\t\tThe distribution is positively skewed");
    }
    skp=((x-mode)/SD);
    printf("\n\n\t\t\t\t\t11)The skp is = %.2f",skp);
    if(skp<0)
    {
        printf("\n\t\t\t\t\tThe distribution is negatively skewed");
    }
    else
    {
        printf("\n\t\t\t\t\tThe distribution is positively skewed");
    }
}
/****** Code By Prasad Pansare  ******/

