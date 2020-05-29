n=int(input("Enter the no of items: "))
capacity=int(input("Enter the capactiy: "))
item=[]
profit=[]
weight=[]
for i in range(n):
    val=list(map(int,input().split()))
    item.append(val[0])
    profit.append(val[1])
    weight.append(val[2])
ratio=[]
for i in range(n):
    ratio.append(profit[i]/weight[i])
for i in range(n-1):
    for j in range(0, n-i-1):
        if ratio[j] < ratio[j+1]:
            ratio[j], ratio[j+1] = ratio[j+1],ratio[j] ;
            weight[j],weight[j+1]=weight[j+1],weight[j];
            profit[j],profit[j+1]=profit[j+1],profit[j];
maxprofit=0.0
for i in range(n):
    if(weight[i]<capacity):
        capacity-=weight[i];
        maxprofit+=profit[i];
    else:
        maxprofit+=profit[i]*(capacity/weight[i])
        break
print("MAX:",maxprofit)
  
    
