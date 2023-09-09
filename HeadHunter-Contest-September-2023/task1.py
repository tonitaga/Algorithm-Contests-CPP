from math import ceil

def main():
    data = input()
    n, m = data.split(' ')
    n, m = int(n), int(m)

    cookies = []
    max_cookies = 0
    for _ in range(n):
        c = int(input())
        if c > max_cookies:
            max_cookies = c
        cookies.append(c)

    if sum(cookies) / max_cookies > m:
        print(0)
        return

    if sum(cookies) == 0:
        print(0)
        return

    left, right = 1, max_cookies
    while left < right:
        mid = (left + right) // 2
        current_hours = sum(ceil(count / mid) for count in cookies)
        if current_hours > m:
            left = mid + 1
        else:
            right = mid

    print(left)


if __name__ == '__main__':
    main()


# from math import ceil
#
#
# def main():
#     data = input()
#     n, m = data.split(' ')
#     n, m = int(n), int(m)
#
#     cookies = []
#     max_cookies = 0
#     for _ in range(n):
#         c = int(input())
#         if c > max_cookies:
#             max_cookies = c
#         cookies.append(c)
#
#     if sum(cookies) == 0:
#         print(0)
#         return
#
#     for i in range(1, max_cookies + 1):
#         current_hours = 0
#         for count in cookies:
#             current_hours += ceil(count / i)
#             if current_hours > m:
#                 break
#
#         if current_hours <= m:
#             print(i)
#             return
#
#     print(0)
#
#
# if __name__ == '__main__':
#     main()
