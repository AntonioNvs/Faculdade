from PIL import Image

with open('file.txt', 'r') as src:
  bits = src.read()

  img = Image.open("submarino.png")
  newimg = Image.new('RGB', img.size, "black")

  for i in range(img.size[0]):
    for j in range(img.size[1]):
      # 255 is white, less than is black
      data = img.getpixel((i, j))
      bit = data == 255
      
      a = int(bits[(i*img.size[0] + j) % len(bits)])
      color = 255*((bit ^ bool(a)) ^ bool(a))
      newimg.putpixel((i, j), (color, color, color))

  newimg.show()