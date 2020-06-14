n=int(input("Enter the n value: "))
w=int(input("Enter the capacity"))
wt=list(map(int,input("Enter the weight").split()))
val=list(map(int,input("Enter the profit").split()))
F=[[0 for i in range(w+1)] for x in range(n+1)]
for i in range(n + 1): 
        for j in range(w + 1): 
            if i == 0 or j == 0: 
                F[i][w] = 0
            elif wt[i-1] <= j: 
                F[i][j] = max(val[i-1]+ F[i-1][j-wt[i-1]],F[i-1][j]) 
            else: 
                F[i][j] = F[i-1][j] 
  
print(F[n][w]) 
