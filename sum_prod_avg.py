#!/usr/bin/python
import math

def main():
  arr = [2, 3, 5, 6, 8, 32]
  print "Iterative sum: " + str(mysum(arr))
  print "Recursive sum: " + str(recursivesum(arr, len(arr) -1))
  print "Iterative product: " + str(myprod(arr))
  print "Recursive product: " + str(recursiveprod(arr))
  print "Average of arr: " + str(myavg(arr))
  reverse_arr(arr)
  print arr
  mapsqrt(arr)
  print arr

def mapsqrt(arr):
  for i in range(len(arr)):
    arr[i] = math.sqrt(arr[i])

#array passed by reference
def reverse_arr(arr):
  for i in range(len(arr)/2):
    tmp = arr[i]
    arr[i] = arr[len(arr) - 1 - i]
    arr[len(arr) - 1 - i] = tmp


def myavg(arr):
  answer = 0.0
  for i in arr:
    answer += i
  return answer/len(arr)

def myprod(arr):
  answer = 1
  for i in arr:
    answer *= i
  return answer

def recursiveprod(arr):
  if(len(arr) == 0):
    return 1
  else:
    return arr[0] * recursiveprod(arr[1:])  #this is syntax to pass the array from 1 to rest


def recursivesum(arr, mysize):
  if(mysize < 0):
    return 0
  else:
    return arr[mysize] + recursivesum(arr, mysize-1) 


def mysum(arr):
  answer = 0
  #expected value is 56
  for i in arr:
    answer += i
  return answer





main()
