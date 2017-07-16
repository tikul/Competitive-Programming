cur_city = ""
cities = []
temps = []
while(cur_city != "Waterloo"):
    data = input().split()
    cities.append(data[0])
    temps.append(int(data[1]))
    cur_city = data[0]

print(cities[temps.index(min(temps))])