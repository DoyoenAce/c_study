n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
def quick_sort(n, start, end):
    if start >= end:
        return 
    pivot = start
    left = start
    right = end

while left <= right:
    while left <= end and array[left] <= n(pivot):
        