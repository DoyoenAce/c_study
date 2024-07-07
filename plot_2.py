import matplotlib.pyplot as plt
x = [1,2,3,4,5,6,7,8,9,10,11,12]
y1 = [32,45,56,76,77,67,87,98,56,45,78]
y2 = [12,35,46,66,45,67,47,57,68,66,55,88]
plt.title('energy')
plt.xlabel('month')
plt.ylabel('kw')
plt.plot(x,y1,'gs-', x,y2,'rs--', lw=3, label = "kw")
plt.grid()
plt.legend