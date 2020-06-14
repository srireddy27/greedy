A = list(map(int,input("Enter the list: ").split()))
k = int(input("Enter the k value"))
n=len(A)
dp = [[0 for i in range(n + 1)] for j in range(k + 1)]
for i in range(1,k+1):
    for j in range(1,n+1):
        dp[i][j]=dp[i][j-1]
        if(A[j-1]<=i and A[j-1]>0):
            dp[i][j] += dp[i //A[j - 1]][j - 1] + 1
print(dp[k][n])
