string=input("Enter the string: ");
n=len(string)
lrs=[[0]*(n+1)]*(n+1)
for i in range(1,n+1):
    for j in range(1,n+1):
        if(string[i-1]==string[j-1] and i!=j):
            lrs[i][j]=1+lrs[i-1][j-1]
        else:
            lrs[i][j]=max(lrs[i][j-1],lrs[i-1][j])
print("the longest repeating subsequence",lrs[n][n])
