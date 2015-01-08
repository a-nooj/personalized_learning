import sys
import json

def read_file(filename):
    new_dict = {}
    file_in = open(filename, 'r')
    return file_in

filename = sys.argv[1]
file_in = read_file(filename)
f = file_in.readlines()
new_d = f

action_locs = ['']*len(new_d)
#################################################
stats = 0
for i in range(len(new_d)):
    if new_d[i].find('END GAME', 0)!=-1:
        stats=i
        
stats_arr = new_d[stats:]
data_arr = new_d[:stats]
###################################################
arr=[]
for i in range(1,len(stats_arr)):
    temp = stats_arr[i]
    arr.append(temp.split(': '))
    arr[i-1][1]=int(arr[i-1][1].rstrip())
arr.append(stats_arr[0])
arr[len(arr)-1]=arr[len(arr)-1].split(' - ')
arr[len(arr)-1][1]=arr[len(arr)-1][1].rstrip()

stats_dict = {arr[i][0]: arr[i][1] for i in range(len(arr))}
###############################################
timestamp = [None]*len(data_arr)
locations = []
moves = [None]*len(data_arr)
turns = [None]*len(data_arr)
comments = ['']*len(data_arr)
helpscreen = [0]*len(data_arr)
timestamp[0] = 0
for i in range(len(data_arr)):
    temp = data_arr[i]
    if ('TIMESTAMP' in temp) and (i>0):
        timestamp[i] = int(temp.rstrip().split('TIMESTAMP: ')[1])
    elif 'MOVES' in temp:
        moves[i] = temp.rstrip()
    elif 'ACTION' in temp:
        None
    elif 'TURNS' in temp:
        turns[i] = temp.rstrip()
    else:
        if 'TIME IN HELP SCREEN' in temp:
            helpscreen[i] = int(temp.rstrip().split('TIME IN HELP SCREEN: ')[1])
        else:
            comments[i] = temp.rstrip() #multiple comments handle too!
#add helpscreen data; fix victor's file
action_ids = []
for i in range(len(data_arr)):
    if 'ACTION' in data_arr[i]:
        action_ids.append(i)
for i in range(1,len(action_ids)):
    locations.append(data_arr[action_ids[i]-1].rstrip())
    
for i in range(len(comments)):
    temp = comments[i]
    if (temp!='') and (('0' in temp) or ('1' in temp) or ('2' in temp) or ('3' in temp) or ('4' in temp) or ('5' in temp) or ('6' in temp) or ('7' in temp) or ('8' in temp) or ('9' in temp)):
        comments[i] = ''
        
cnt = []
for i in range(len(comments)):
    temp = comments[i]
    if temp!='':
        cnt.append(i)
        
for i in range(1,len(cnt)):
    if abs(cnt[i]-cnt[i-1])<=1:
        comments[cnt[i]]=comments[cnt[i-1]]+'; '+comments[cnt[i]]
        comments[cnt[i-1]] = ''
        
new_comments=['']*stats_dict['ACTIONS']
for i in range(1,stats_dict['ACTIONS']):
    new_comments[i-1] = comments[action_ids[i]-2]
    
ts = []
for i in range(len(timestamp)):
    if timestamp[i] != None:
        ts.append(timestamp[i])
        
new_moves = [None]*stats_dict['ACTIONS']
for i in range(0,stats_dict['ACTIONS']):
    new_moves[i] = moves[action_ids[i]+1]
    
new_turns = [None]*stats_dict['ACTIONS']
for i in range(0,stats_dict['ACTIONS']):
    new_turns[i] = turns[action_ids[i]+1]
    
new_helpscreen = [0]*stats_dict['ACTIONS']
for i in range(0,stats_dict['ACTIONS']):
    new_helpscreen[i] = helpscreen[action_ids[i+1]-2]
        
######################################
data_dict = {}
for i in range(stats_dict['ACTIONS']):
    temp = []
    data_dict[i] = {'TIMESTAMP': ts[i],'LOCATION': locations[i],'MOVES': new_moves[i],'TURNS': new_turns[i],'COMMENTS': new_comments[i],'TIME IN HELP SCREEN': new_helpscreen[i]}
###############################################
output_filename_suffix = filename.split("gameStream_")[1].split(".txt")[0]
data_filename = "dataDict_"+output_filename_suffix+".json"
stats_filename = "statsDict_"+output_filename_suffix+".json"
with open(data_filename, 'w') as outfile:
  json.dump(data_dict, outfile)
with open(stats_filename, 'w') as outfile:
  json.dump(stats_dict, outfile)
