if __name__ == '__main__':
    filename = f'./resources/Day01/longInput'
    with open(filename, 'r') as f:
        lines = [i.replace('\n', '') for i in f.readlines()]
    
    lines = [[int(y) for y in i.split('   ')] for i in lines]
    lines = list(map(list, zip(*lines)))

    left_set = sorted(lines[0])
    right_set = sorted(lines[1])

    total_dst_sum = 0
    for i in range(len(left_set)):
        total_dst_sum += abs(left_set[i] - right_set[i])

    print("Total distance sum: ", total_dst_sum)