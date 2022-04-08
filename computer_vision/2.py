from PIL import Image
import numpy as np
import math
import matplotlib.pyplot as plt

# open the test image
# Note: If you didn't launch Python from the same directory where you saved
#       the file, chipmunk.png, you'll need to provide the full path name as
#       the argument to Image.open
#im = Image.open('0a_einstein.bmp')

# display relevant Image class attributes: dimensions (width, height),
# pixel format and file format
#print (im.size, im.mode, im.format)

def boxfilter(n):
    # only odd numbers could be accepted
    assert n % 2 == 1, "Dimension must be odd"
    # make n x n array
    arr = np.zeros((n, n))
    # decide each element
    ele = 1 / (n * n)
    # substititue zero to element
    arr = np.where(arr == 0, ele, arr)
    # print array
    np.set_printoptions(linewidth=np.inf)
    print_arr = "array({0})".format(arr)
    print(print_arr)
    print("\n")

# prob1 
boxfilter(3)
#boxfilter(4)
boxfilter(7)
print("\n\n")

def gauss1d(sigma):
    # decide size of array by definition
    size = math.ceil(sigma * 6)
    if (size % 2 == 0):
        size = size + 1
    # make gaussian kernel with density function
    x = np.linspace(-1 * int(size / 2), int(size / 2), size)
    y = np.exp(-1 * (x ** 2) / (2 * (sigma ** 2)))
    print(x)
    # normalize y 
    y = y / sum(y)
    return y
    print("array({})".format(y))
    print("\n")

# problem 2
gauss1d(0.3)
gauss1d(0.5)
gauss1d(1)
gauss1d(2)
print("\n\n")

def gauss2d(sigma):
    #make gauss2d with gauss1d outer 
    ans = np.outer(gauss1d(sigma), gauss1d(sigma))
    print("\n\n")
    print(ans)
    print("\n")
    return ans

#problem 3
gauss2d(0.5)

def convolve2d(array, g):
    # assign parameter array to x
    x = array
    # padding to x 
    x = np.pad(x, (1, 1), mode='constant', constant_values=0)
    #np = list(map(np.float32, array))
    for i in x:        # extract inner list from array 'x'
        for j in i:    # extract element from inner list 
            j = np.float32(j) # type change to float32
    print(x)
    print("\n")
    print(len(x))

    arr = np.zeros((4, 5))

    m, n = 3, 3

    for i in range(5): # slice 6 x 7 array to 3 x 3 array
        print("--------------------")
        for j in range(4):
            temp = np.dot(x[j:j+m, i:i+n] , g)
            print(x[j:j+m, i:i+n])
            arr[j][i] = np.sum(temp)
            print(temp)
    print("-------------------")
    print(arr)

def conv(X, filters, stride=1, pad=0): 
    n, c, h, w = X.shape
    n_f, _, filter_h, filter_w = filters.shape

    out_h = (h + 2 * pad - filter_h) // stride + 1 
    out_w = (w + 2 * pad - filter_w) // stride + 1 

    # add padding to height and width.
    in_X = np.pad(X, [(0, 0), (0, 0), (pad, pad), (pad, pad)], 'constant')
    out = np.zeros((n, n_f, out_h, out_w))

    for i in range(n): # for each image. 
        for c in range(n_f): # for each channel. 
            for h in range(out_h): # slide the filter vertically. 
                h_start = h * stride 
                h_end = h_start + filter_h 
                for w in range(out_w): # slide the filter horizontally. 
                    w_start = w * stride 
                    w_end = w_start + filter_w 
                    # Element-wise multiplication. 
                    out[i, c, h, w] = np.sum(in_X[i, :, h_start:h_end, w_start:w_end] * filters[c]) 
    return out

bb = np.array([[1,0,0,0,1], [2,3,0,8,0], [2,0,0,0,3], [0,0,0,1,0]])
print(bb)
conv(bb, gauss2d(0.5), 1, 0)
