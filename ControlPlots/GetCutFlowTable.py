import sys

infn=sys.argv[1]

from rootpy.io import root_open
from rootpy.plotting import Canvas

myfile = root_open(infn)

print myfile

mytree = myfile.otree

canvas = Canvas(700, 500)

hist = mytree.Draw('v_pt',  
			linecolor='red',
			fillstyle='/')
canvas.Draw()
canvas.SaveAs("test.pdf")

