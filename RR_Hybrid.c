#include<stdio.h>
#include<conio.h>
struct process
{
char name;
int at,bt,wt,tt,rt;
int completed;
float ntt;
}p[10];
int n;
int q[10];
int front=-1,rear=-1;
void enqueue(int i)
{
if(rear==10)
printf("overflow");
rear++;
q[rear]=i;
if(front==-1)
front=0;
}
int dequeue()
{
if(front==-1)
printf("underflow");
int temp=q[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}
int isInQueue(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;
}void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
void simple()
{
int i,j,time=0,sum_bt=0,tq;
int c;
float avgwt=0,avgtt=0;
printf("Enter no of processes:");
scanf("%d",&n);
for(i=0,c='0';i<n;i++,c++)
{
p[i].name=c;
printf("\nEnter The Arrival Time Of Process %c :",p[i].name);
scanf("%d",&p[i].at);
printf("\nEnter The Arrival Brust Time Of Process %c :",p[i].name);
scanf("%d",&p[i].bt);
p[i].rt=p[i].bt;
p[i].completed=0;
sum_bt+=p[i].bt;
}
printf("\nEnter the time quantum:");
scanf("%d",&tq);
sortByArrival();
enqueue(0);
printf("\nProcess execution order: ");
for(time=p[0].at;time<sum_bt;)
{ i=dequeue();
if(p[i].rt<=tq)
{
time+=p[i].rt;
p[i].rt=0;
p[i].completed=1;
printf(" p%c ",p[i].name);
p[i].wt=time-p[i].at-p[i].bt;
p[i].tt=time-p[i].at;
p[i].ntt=((float)p[i].tt/p[i].bt);
for(j=0;j<n;j++)
{
if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
{
enqueue(j);
}
}
}
else
{
time+=tq;
p[i].rt-=tq;
printf(" p%c ",p[i].name);
for(j=0;j<n;j++)
{
if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
{
enqueue(j);
}
}
enqueue(i);
}
}
printf("\n\nProcess\t\t | Arrival Time\t | Burst Time\t | Waiting Time\t | TurnAround Time\t\n ");
for(i=0;i<n;i++)
{avgwt+=p[i].wt;
avgtt+=p[i].tt;
printf("\nProcess[%c]\t | \t%d\t | \t%d\t | \t%d\t | \t%d\t \n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
}
printf("\nAverage Waiting Time:%f\n",avgwt/n);
printf("\nAverage Turnaround Time:%f\n",avgtt/n);
}
void our()
{
int
n,i,j,bt[100],at[100],po,temp,min,smt,sum=0,num,b[100],time=0,max,k,p[100],l,wt[100],tt[100],g[100],st[100],f
=0,m;
printf("\nEnter Number of Process:");
scanf("%d",&n);
num=n;
for(i=0;i<n;i++)
{
printf("\nEnter The Arrival Time Of Process-%d:",i);
scanf("%d",&at[i]);
printf("\nEnter The Brust Time Of Process%d:",i);
scanf("%d",&bt[i]);
p[i]=i;
wt[i]=0;
}
int a=at[0];
for(i=0;i<n;i++)
{
if(at[i]<a)
a=at[i];
}
if(a!=0)
{
for(i=0;i<n;i++)
{
at[i]=at[i]-a;
}
}
for(i=0;i< n;i++) {
min=bt[i];
po=i;
for(j=i;j<n;j++) {
if(bt[j]<min && at[i]==at[j]) {
min=bt[j];
po=j; }}
temp=bt[po];
bt[po]=bt[i];
bt[i]=temp;
temp=at[po];
at[po]=at[i];
at[i]=temp;
temp= p[po];
p[po]= p[i];
p[i]=temp; }
for(i=0;i<n;i++) {
min=at[i];
po=i;
for(j=i;j<n;j++) {
if(at[j]<min) {
min=at[j];
po=j; }}
temp=bt[po];
bt[po]=bt[i];
bt[i]=temp;
temp=at[po];
at[po]=at[i];
at[i]=temp;
temp= p[po];
p[po]= p[i];
p[i]=temp; }
min=bt[0];
for(m=0;m<n;m++) {
if(min>bt[m]) {
min=bt[m]; }}
for(i=0;i<n;i++) {
sum=sum+bt[i];
}
sum=sum/n;
smt=(sum+min)/2;
for(i=0;i<n;i++) {
b[i]=bt[i]; }
for(i=0;i<n;i++) {
if(b[i]!=0) {
if(smt<b[i] ) {
wt[i]=(time
-at[i])
-(bt[i]
-b[i]);
b[i]=b[i]
-smt;
time=time+smt;
tt[i]=time
-at[i];
if(b[i]<=smt) {
time=time+b[i];
b[i]=0;
tt[i]=time
-at[i];
num--
;
}}
else {
wt[i]=(time
-at[i])
-(bt[i]
-b[i]);
time=time+b[i];
b[i]=0;
num--
;
tt[i]=time
-at[i];
}}
for(j=i+1;j<n &&j!=i;j++) {
min=b[j];
po=j;
for(k=j;k<n;k++) {
if(b[k]<min && at[k]<time) {
min=b[k];
po=k; }}
temp= b[po];
b[po]= b[j];
b[j]=temp;
temp=bt[po];
bt[po]=bt[j];
bt[j]=temp;
temp=at[po];
at[po]=at[j];
at[j]=temp;
temp= p[po];
p[po]= p[j];
p[j]=temp;
temp=wt[po];
wt[po]=wt[j];
wt[j]=temp;
temp=tt[po];
tt[po]=tt[j];
tt[j]=temp;
}
if(i== n-1)
{
i=-1;
if(num==0)
{
break;
}}}
printf("\n\n Process\t | Arrival Time | Brust Time | Turnaround Time| Waiting Time \n\n");
for(i=0;i<n;i++){ for(j=0;j<n;j++)
{
if(i==p[j])
{
printf("\n process-%d \t | \t %d \t | \t %d \t| \t %d \t | \t %d \n",p[j],at[i],bt[i],tt[j],wt[j]);
}}}
int s=0,s1=0;
for(i=0;i<n;i++)
{
s=s+wt[i];
s1=s1+tt[i];
}
printf("\nAverage Waiting Time: %f\n",(float)s/n);
printf("\nAverage turnaround Time: %f\n",(float)s1/n);
}
int main()
{
int ip;
printf("\n \t\t\t\t ROUND ROBIN CPU SCHEDULING \n ");
printf("\n \t\t\t\t\t TEAM MEMBERS \n");

while(ip!=3)
{
printf("\n ENTER THE OPERATION YOU WANT TO PERFORM: \n");
printf("\n 1. SIMPLE ROUND ROBIN\n");
printf("\n 2. HYBRID ROUND ROBIN\n");
printf("\n 3. EXIT\n");
scanf("%d",&ip);
if (ip==1)
{
 simple();
}
else if (ip==2){
 our();
}
else
{
ip=3;
}
}
return 0;
}

