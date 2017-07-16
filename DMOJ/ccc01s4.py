import itertools
import math

def inCircle(point, centre, radius):
    return math.sqrt((centre[0]-point[0])**2 + (centre[1] - point[1])**2) <= radius

def findCentre(edges):
    if len(edges) == 2:
        return [(edges[0][0] + edges[1][0])/2, (edges[0][1] + edges[1][1])/2]
    else: 
        a,b,c = edges
        try:
            t = c[0]**2 + c[1]**2 - b[0]**2 - b[1]**2
            s = b[0]**2 + b[1]**2 - a[0]**2 - a[1]**2
            f = (b[0] - c[0])/(b[0] - a[0])
            y = (t + f*s) / (2*((c[1]-b[1]) - f*(a[1]-b[1])))
            x = ( s + 2 * y * (a[1] - b[1]) ) / (2 * (b[0] - a[0]))
            return (x,y)
        except:
            return None

def roundProperly(x): #2 decimal places
    x *= 100
    if x - int(x) >= .5:
        return (int(x)+1)/100
    else:
        return int(x)/100


n = int(input())
coords = [[int(i) for i in input().split()] for x in range(n)]
minRadius = 999999
for comb in itertools.combinations(coords, 3):
    centre = findCentre(comb)
    if not centre:
        continue
    radius = math.sqrt((centre[0]-comb[0][0])**2 + (centre[1] - comb[0][1])**2)
    if all(inCircle(x, centre, radius) for x in coords) and radius < minRadius:
        minRadius = radius

for comb in itertools.combinations(coords, 2):
    centre = findCentre(comb)
    if not centre:
        continue
    radius = math.sqrt((centre[0]-comb[0][0])**2 + (centre[1] - comb[0][1])**2)
    if all(inCircle(x, centre, radius) for x in coords) and radius < minRadius:
        minRadius = radius


print("{0:.2f}".format(roundProperly(2*minRadius)))