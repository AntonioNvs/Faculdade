from PIL import Image

with open('file.txt', 'r') as src:
  bits = src.read()
  qtd = 0

  img = Image.new('RGB', (500, 400), "black")
  for i in range(img.size[0]):
    for j in range(img.size[1]):
      a = int(bits[(i*img.size[0] + j) % len(bits)])
      qtd += a

      color = 255*a
      img.putpixel((i, j), (color, color, color))

  print(img.size[0]*img.size[1])
  print(qtd)
  img.show()