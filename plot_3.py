import matplotlib.pyplot as plt
import csv
x = []
y = []
with open('e_data.csv','r') as csvfile:
        plots = csv.reader(csvfile, delimiter=',')
        for row in plots:
            x.append(int(row[0]))
            y.append(int(row[1]))
plt.rcParams["font.family"]='Malgun gothic'
plt.rcParams["figure.figsize"]=(6,4)
plt.figure()
plt.plot(x,y, label='전력사용량!')
plt.xlabel('월')
plt.ylabel('사용량')
plt.title('월별 전력사용량')
plt.legend()
plt.show()