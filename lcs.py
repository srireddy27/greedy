def longest_common_sub(string1,string2):
    m=len(string1)
    n=len(string2)
    lcs=[[None]*(n+1) for i in range(m+1)]
    for i in range(m+1):
        lcs[i][0]=0
    for i in range(n+1):
        lcs[0][i]=0
    for i in range(1,m+1):
        for j in range(1,n+1):
            if(string1[i-1]==string2[j-1]):
                lcs[i][j]=lcs[i-1][j-1]+1
            else:
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])
    return lcs[m][n]
string1=input("Enter the string1: ")
string2=input("Enter the string2: ")
print("Length of LCS is",longest_common_sub(string1,string2))
