list1=list(map(int,input("Enter the list1:").split()))
n=len(list1)
lns=[1]*n
for i in range(1,n):
    for j in range(0,i):
        if(list1[i]>list1[j] and lns[i]<lns[j]+1):
            lns[i]=lns[j]+1
maximum=0
for i in range(n):
    maximum=max(maximum,lns[i])
print(maximum)
