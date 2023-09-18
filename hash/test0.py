prime = 1000000007

def hash(s : str):
    h = 0 
    for c in s :
        h += ord(c)
        h %= prime
    return h


# 导入datetime模块
import datetime
# 获取当前时间
now = datetime.datetime.now()
# 格式化成年-月-日的形式
date = now.strftime('%Y-%m-%d')
print(now)
# 分解日期为年、月、日
year, month, day = date.split('-')
# 打印结果
#print(year, month, day)

