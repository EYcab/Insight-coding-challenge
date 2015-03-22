#!/usr/bin/python
#import all the required packages re and os,shutil
import re
import os.path
import os,shutil
#glue all the input text files into one single file named out.txt
f=open("out.txt","w")
for r,d,fi in os.walk("wc_input"):
    for files in fi:
        if files.endswith(".txt"):                         
            g=open(os.path.join(r,files))
            #combine into a new file from child files one by one, g as the child text file, f is the target file
            shutil.copyfileobj(g,f)
            g.close()
f.close()
#regular expression pattern matching to get rid of symbolic expression
pattern = re.compile('([^\s\w]|_)+')
result = open("count_result.txt",'w')
fo = open("out.txt",'r')
#split the text file and make it a list
data = fo.read().split()
for i in range(0,len(data),1):
	data[i]=data[i].lower()
	data[i] = pattern.sub('', data[i])
#after all the conversions, sort all data to ease the counting process
data.sort()
oldKey = None
count = 0
#utilize the counting algorithm
for i in range(0,len(data),1):
	newKey = data[i]
	if oldKey and oldKey != newKey:
		result.write(oldKey+"\t"+str(count)+"\n")
		count = 0
	oldKey = newKey
	count +=1
result.write(oldKey+"\t"+str(count)+"\n")

fo.close()
result.close()


#copy the result to the wc_output file
readResult = open("count_result.txt",'r')
save_path = 'wc_output'

completeName = os.path.join(save_path,"count_result.txt")         

file1 = open(completeName, "w")
for line in readResult:
	file1.write(line)

file1.close()

readResult.close()
