# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %% [markdown]
# # Morfologia Matemática Binária
# ## Exemplo de Reconstrução Geodésica
# 
# Por Luiz Eduardo da Silva

# Nome: Lucas Pessoa Oliveira Alves
# RA: 2022.1.08.044
# %%
import matplotlib.pyplot as plt
import numpy as np


# %%
def readpbm (name):
    f = open(name,"r")

    assert f.readline() == 'P1\n'
    line = f.readline()
    while (line[0] == '#'):
           line = f.readline()
    (width, height) = [int(i) for i in line.split()]
    print (width, height)
    img = []
    row = []
    j = 0
    for line in f:
       values = line.split()
       for val in values:
           row.append (int (val))
           j = j + 1
           if j >= width:
              img.append (row)
              j=0
              row = []

    f.close()
    return img

def readpbmNew (name):
    f = open(name,"r")

    assert f.readline() == 'P1\n'
    line = f.readline()
    while (line[0] == '#'):
           line = f.readline()
    (width, height) = [int(i) for i in line.split()]
    print (width, height)
    img = []
    row = []
    j = 0
    for line in f:
       for val in line:
           if val == "\n":
               continue
           row.append (int (val))
           j = j + 1
           if j >= width:
              img.append (row)
              j=0
              row = []
    f.close()
    return img


# %%
def imgalloc (nl, nc):
    img = []
    for i in range(nl):
        lin = []
        for j in range(nc):
            lin.append(0)
        img.append(lin)
    return img


# %%
img = readpbm ('texto.pbm')


# %%
print (np.asarray (img))


# %%
plt.figure(figsize=(16,8))
plt.imshow(img, cmap='gray')
plt.show()


# %%
nl = len(img)
nc = len(img[0])
imgE = readpbmNew("textoMask.pbm")


# %%
plt.figure(figsize=(16,8))
plt.imshow(imgE, cmap = 'gray', aspect='auto')
plt.show()


# %%
changed = True
imgR = imgalloc(nl, nc)
count = 1
while (changed):
    changed = False
    print('count = ', count)
    count = count + 1
    for i in range(nl):
        for j in range(nc):
            if (img[i][j]==1):
                max = -1
                for y in range(-1,2):
                    for x in range(-1,2):
                        pi = i + y
                        pj = j + x
                        if (pi >= 0) and (pi < nl) and (pj >= 0) and (pj < nc):
                            if (imgE[pi][pj] > max):
                                max = imgE[pi][pj]
                if (max == 1 and imgR[i][j] == 0):
                    changed = True
                    imgR[i][j] = 1
    if (changed):
        imgE = imgR


# %%
plt.figure(figsize=(16,8))
plt.imshow(imgR, cmap = 'gray')
plt.show()


# %%



