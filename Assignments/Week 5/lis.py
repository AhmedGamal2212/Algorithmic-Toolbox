arr = list(map(int, input().split()))
dp = [1] * len(arr)


def lis():

    for i in range(1, len(arr)):
        for j in range(i):
            if arr[j] < arr[i] and dp[i] < dp[j] + 1:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)


ans = lis()

last = 0
output = []
for i in range(len(dp)):
    if dp[i] > last:
        last = dp[i]

for _ in range(len(dp) - 1, 0, -1):
    if dp[_] == last:
        output.append(arr[_])
        last -= 1

print()
output.reverse()
print(output)
