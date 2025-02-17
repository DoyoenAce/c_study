n = int(input()) #입력할 변수를 선언
a = []
for i in range(n): #첫번째 입력한 수만큼 반복하기
    a.append(int(input())) #줄 하나씩 늘리기(첫번쨰 입력한 수만큼)
for i in range(n): #첫번째 입력한 수만큼 반복하기
    for j in range(n-i-1): #n-i-1만큼 반복하기기
        if(a[j]>a[j+1]): #만약 a의 j번쨰 수가 j+1번쨰 숫자보다 크다면
            temp = a[j+1] #a의 j번째 수와 a의 j+1번쨰 수의 자리를 바꾸기기
            a[j+1] = a[j]
            a[j] = temp
for k in range(1,n+1):
    print(a[k-1])


    


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