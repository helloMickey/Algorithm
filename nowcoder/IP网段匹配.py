import sys


def ip_match(net, s):
    # 24/10.1.2.0 10.1.2.3
    s_l = net.split('/')
    seg_ip = s_l[1]
    seg_net = int(s_l[0])+1

    ip_s = seg_ip.split('.')
    s_s = s.split('.')

    count = 0
    for p, i_s in zip(ip_s, s_s):
        if p != i_s:
            temp = count * 8
            if seg_net < temp:
                return False

            p_2 = bin(int(p))[2:]
            i_2 = bin(int(i_s))[2:]
            if len(p_2) < 8:
                p_2 = '0' * (8 - len(p_2)) + p_2
            if len(i_2) < 8:
                i_2 = '0' * (8 - len(i_2)) + i_2
            # 对二进制进行比较
            for index in range(seg_net - temp):
                if p_2[index] != i_2[index]:
                    return False
            return True
        else:
            count += 1

    return True


if __name__ == "__main__":
    input_num = sys.stdin.readline().strip().split(' ')
    n = int(input_num[0])
    m = int(input_num[1])

    info = {}
    for i in range(n):
        line = sys.stdin.readline().strip().split(' ')
        num = line[0]
        net = line[1]
        s_l = net.split('/')
        seg_ip = s_l[0]
        seg_net = s_l[1]
        net = seg_net + '/' + seg_ip  # 目的是为了按照大的排在前面
        info[net] = int(num)

    query = []
    for i in range(m):
        line = sys.stdin.readline().strip()
        query.append(line)

    # query.sort()
    sort_info = sorted(info, reverse=True)  # 把大的网段放前面

    result = []
    for q in query:
        find = False
        for key in sort_info:
            value = info[key]
            if ip_match(key, q):
                result.append(value)
                find = True
                break
        if not find:
            result.append(-1)

    assert len(result) == len(query)
    for r in result:
        print(r)