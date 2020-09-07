alfa, beta, m, n=input().split()
text=list(input().split())

alfa.lower()
beta.lower()
m=int(m)
n=int(n)
cnt1=0
cnt2=0
cnt3=0

for word in text:
    if word[0].lower()==alfa and word[-1]==beta:
        if len(word)<=m:
            cnt1+=1
        elif m<len(word)<=n:
            cnt2+=1
        else:
            cnt3+=1

print(cnt1, cnt2, cnt3)