from tqdm.rich import trange
x = 10000
for i in trange(x):
    for j in range(x):
        k = i * j 
print('\n完成')
