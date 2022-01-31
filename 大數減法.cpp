#include <stdio.h>
#define n 200

void reverse(int *, int);

int main()
{
    char a[200], b[200]; 
    while(printf("enter two number: "), scanf("%s %s", &a, &b))
    {
        int na[200]={0}, nb[200]={0}, sum[200]={0};
        int ca=0, cb=0, i, flag; 
        i=0;
        while(a[i]!='\0')
        {
            na[i]=(int)a[i]-48;
            ca++, i++;
        }
        reverse(na, ca);
        i=0; 
        while(b[i]!='\0')
        {
            nb[i]=(int)b[i]-48;
            cb++, i++;
        }
        reverse(nb, cb);
        int max=(ca>cb)?ca:cb;
        int min=(ca>cb)?cb:ca;
        flag=0;
        int check;
        if(ca>=cb)
        {
        	if(ca==cb)
        	{
        		for(int i=ca; i>=0; i--)
        		{
        			if(na[i]<nb[i])
        			{
        				check=-1;
        				break;
					}	
				}
				check=1;
			}
        	else
        		check=1;
		}
		else
			check=-1;
			
        if(check==1)
        {
	       	for(int i=0; i<max; i++)
	        {
	            
				if(i<=min)
	            {
	                if(na[i]-nb[i]<0)
	                {
	                    na[i+1]--;
	                    na[i]+=10;
	                    sum[i]=na[i]-nb[i];
	                }
	                else
	                {
	                    sum[i]=na[i]-nb[i];
	                }
	            }
	            else
	            {
	                if(na[i]<0)
	                {
	                	na[i+1]--;
	                    na[i]+=10;
	                    sum[i]=na[i];
					}
					else
						sum[i]=na[i];
	            }
	
	        }
	        printf("The answer of %s - %s is: ", a, b);
		}
		if(check==-1)
		{
			for(int i=0; i<max; i++)
	        {
	            
				if(i<=min)
	            {
	                if(nb[i]-na[i]<0)
	                {
	                    nb[i+1]--;
	                    nb[i]+=10;
	                    sum[i]=nb[i]-na[i];
	                }
	                else
	                {
	                    sum[i]=nb[i]-na[i];
	                }
	            }
	            else
	            {
	                if(nb[i]<0)
	                {
	                	nb[i+1]--;
	                    nb[i]+=10;
	                    sum[i]=nb[i];
					}
					else
						sum[i]=nb[i];
	            }
	
	        }
	        printf("The answer of %s - %s is: -", a, b);
		}
        for(int i=0; i<max; i++)
        {
            (sum[max-1-i]==0 && flag==0)?0:(printf("%d", sum[max-1-i]), flag++);
        }
        printf("\n\n");

    } 
    return 0;
}

void reverse(int *num, int count)
{
    int temp[200];
    for(int i=0; i<count; i++)
    {
        temp[i]=num[i];
    }
    for(int i=0; i<count; i++)
    {
        num[i]=temp[count-i-1];
    }

}
