n = int(input())
streams = [int(input()) for x in range(n)]
rounded_streams = []

while(True):
    c = int(input())
    if c == 77:
        break
    elif c == 99:
        ind = int(input())
        percent = int(input())/100
        stream_left = percent * streams[ind-1]
        stream_right = (1-percent) * streams[ind-1]
        streams.insert(ind-1, stream_left)
        streams[ind] = stream_right
    elif c == 88:
        ind = int(input())
        streams[ind-1] += streams.pop(ind)

for i, stream in enumerate(streams):
    rounded_streams.append(round(streams[i]))
    print(rounded_streams[i], end = " ")