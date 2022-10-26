numbers = [int(i) for i in input().split(' ')]

class Node:
  def __init__(self, x):
    self.val = x
    self.right = None
    self.left = None

def insert(el: Node, val: int) -> Node:
  if(el == None):
    el = Node(val)
    return el

  if(val < el.val):
    if(el.left == None):
      el.left = Node(val)
    else:
      el.left = insert(el.left, val)
  elif(val > el.val):
    if(el.right == None):
      el.right = Node(val)
    else:
      el.right = insert(el.right, val)

  return el

def preorder(el: Node, arr: list):
  arr.append(el.val)
  if(el.left != None): preorder(el.left, arr)
  if(el.right != None): preorder(el.right, arr)

def postorder(el: Node, arr: list):
  if(el.left != None): postorder(el.left, arr)
  if(el.right != None): postorder(el.right, arr)
  arr.append(el.val)

root = None
for num in numbers:
  root = insert(root, num)

pre = []
preorder(root, pre)
for i in pre:
  print(i, end=" ")

print()

numbers.sort()
for n in numbers:
  print(n, end=" ")

print()

post = []
postorder(root, post)
for i in post:
  print(i, end=" ")
