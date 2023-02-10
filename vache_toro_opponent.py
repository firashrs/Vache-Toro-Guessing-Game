# -*- coding: utf-8 -*-
"""Vache Toro.ipynb
This is the code for the Opponent player.

By Firas Hares. 2023
"""

import random

def get_new_secret_code():
  x = []
  x0 = int(random.randint(1, 9))
  x.append(x0)
  for i in range(3):
    r = int(random.randint(0, 9))
    while(r in x):
      r = int(random.randint(0, 9))
    x.append(r)
  return x

def check_answer(secret_code, answer):
  v = 0
  t = 0
  for i in range(4):
    nbr = int(answer[i])
    if nbr in secret_code:
      if nbr == secret_code[i]:
        t += 1
      else:
        v += 1
  if t == 4:
    print("CONGRATSS !!! YOU WON")
  else:
    print('T=',t, ' V=', v)

"""#PLAY"""

secret_code = get_new_secret_code()

tryy = input('enter answer: ')
check_answer(secret_code, tryy)