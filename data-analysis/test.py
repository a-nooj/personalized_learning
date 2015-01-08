import sys

state = 0

while(True):
	var =raw_input()
	print var
	print state
	if var==9 and state==0:
		state = state+1
		print state
	elif var==7 and state==1:
		state = state+2
		print state
	elif var==7 and state==2:
		print 'cool'
		print state
	else:
		print 'nah'
		#print state
	
