n = int(input())
a = []
temp = 0
for i in range(n):
    a.append(int(input()))
for i in range(n):
    for j in range(n-i-1):
        if(a[j]>a[j+1]):
            temp = a[j+1]
            a[j+1] = a[j]
            a[j] = temp
print(a)    

    


'''
a = 0

a = input() # a: string
a = int(input())

for i in range(10):
    print(i)
    
while a < 10:
    print("a is smaller than 10")
    a += 1
    
if a < 10:
    print("a is smaller than 10")
elif a < 20:
    print("a is smaller than 20")
else:
    pass

b = [1, 2, 3, 4]

b.append(10)
'''