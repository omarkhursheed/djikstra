import matplotlib.pyplot as plt
import numpy as np
"""circle = plt.Circle((0.2,0.2), 0.05, color = 'r')

ax = plt.gca()
ax.cla()

ax.add_artist(circle)"""


x = np.arange(-10,10)
y = x**2

number = input("how many nodes do you wish to enter?")
fig = plt.figure()
ax = plt.gca()
ax.set_xlim([0, 10])
ax.set_ylim([0, 10])
coords = []

def onclick(event):
    global number
    global ix, iy

    ix, iy = event.xdata, event.ydata
    print ('x = %f, y = %f')%(ix, iy)

    global coords
    coords.append((ix, iy))

    circle = plt.Circle((ix, iy), 0.2, color = 'r')
    ax.text(ix, iy, len(coords))
    ax.add_artist(circle)

    print(number)
    print (len(coords))
    print (int(len(coords)) == int(number))
    if (int(len(coords)) == int(number)):
        fig.canvas.mpl_disconnect(cid)
    plt.show()
    return coords

cid = fig.canvas.mpl_connect('button_press_event', onclick)

coordsforedges = []
def onclick2(event):
    global coordsforedges
    if event.dblclick:
        ix1, iy1 = event.xdata, event.ydata
        coordsforedges.append((ix1, iy1))
        print(len(coordsforedges))
        if (len(coordsforedges) == 2):
            return
def callforedges():
    global coordsforedges
    edges = input("How many edges do you wish to have in your graph?")
    for edge in range(edges):
        edgemaker()
def edgemaker():
        print("Change")
        coordsforedges[:] = []
        print("success")
callforedges()            
cid = fig.canvas.mpl_connect('button_press_event',onclick2)

plt.show()

