mylist=[2,5,8,8,11,1,0]
i=0
sum=0
a=len(mylist)
temp=mylist[0]
mylist[0]=mylist[a-1]
mylist[a-1]=temp
for i in range(0,len(mylist)):
    print(mylist[i])