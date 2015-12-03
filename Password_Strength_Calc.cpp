#include<iostream.h>
#include<conio.h>

void main()
{
   char a[30];
   cout<<"################################\n";
   cout<<" Password - Strength Calculator\n";
   cout<<"               ~TheAbhi97\n";
   cout<<"################################\n\n";
	cout<<"Input a Password : "; cin>>a;
  	int characters=0 , uppercase=0, lowercase=0 , digit=0 , middigit=0 ,len=0 ;
   for(int k=0;a[k] ;k++)
   	len++;
   characters= len*4;
   for(int k=0;k<len ;k++)
   {
		if(a[k]>='A' && a[k]<='Z')
      	uppercase++;
      if(a[k]>='a' && a[k]<='z')
      	lowercase++;
      if(a[k]>='0' && a[k] <='9')
      	digit++;
   }
   for(int k=1;k<len-1;k++)
   	if(a[k]>='0' && a[k]<='9')
      	middigit++;
   uppercase*=2;
   lowercase*=2;
   digit*=4;
   middigit*=2;
   int gained = characters+uppercase+lowercase+digit+middigit,p=1,q=1;
   for(int k=0;k<len && p==1;k++)
   {
   	if((a[k]>='a' && a[k]<='z') || (a[k]>='A' && a[k]<='Z'))
      	p=1;
      else
      	p=0;
   }
   for(int k=0;k<len && q==1;k++)
   {
   	if(a[k]>='0' && a[k]<='9')
      	q=1;
      else
      	q=0;
   }
   int onlydigchar=0;
   if(q==1 || p==1)
   	onlydigchar=len;
   int conschar=0,up=0,low=0;
   for(int k=0;k<len;k++)
   {
      if(a[k]>='A' && a[k]<='Z')
      {
      	up++;
         if(low==1)
         	low=0;
         else
         {
         	conschar+=low;
            low=0;
         }
      }
      else
      if(a[k]>='a' && a[k]<='z')
      {
      	low++;
         if(up==1)
         	up=0;
         else
         {
         	conschar+=up;
            up=0;
         }
      }
   }
   if(low==1 || up==1)
   	low=up=0;
   conschar+=up+low;
   int repeatchar[30]={0},d=0,repeattimes=0;
   for(int k=0;k<len;k++)
   {
   	d=0;
   	for(int n=0;n<len;n++)
      {
      	if(a[k]==a[n])
         	d++;
      }
      if(d==1 || d==0)
      	repeatchar[k]=0;
      else
      if(d>1)
      	repeatchar[k]=1;
   }
   for(int k=0;k<len;k++)
   	repeattimes+=repeatchar[k];
   int sequ=0,s=1;
   for(int k=1;k<len;k++)
   {
   	if(a[k-1]+1==a[k])
      	s++;
      else
      {
      	if(s>1){
         	sequ+=s;
         }
         s=1;
      }
   }
   if(s>1)
   	sequ+=s;
   int penalty = onlydigchar + (repeattimes+conschar+sequ)*2;
   int result = gained - penalty;
   if(result<0)
   	result = 0;
   cout<<"\n\n\nPassword Strength is "<<result<<endl;
   if(result <= 29)
   	cout<<"Password is WEAK.\n";
   else
   if(result <= 59)
   	cout<<"Password is MODERATE.\n";
   else
   if(result <= 79)
   	cout<<"Password is STRONG.\n";
   else
   	cout<<"Password is VERY STRONG.\n";
   getch();

}
