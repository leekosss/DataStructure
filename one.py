lis=['hello','world','python']
# print(id(lis))
lis2=list([1,2,3,4])
# print(lis2)
# lis2=lis[::-1]
lis.extend(lis2)
lis.insert(1,666)
lis[3::]=[]
print(lis)