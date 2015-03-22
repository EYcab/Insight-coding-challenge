#!/user/bin/env python
import os,shutil
#glue all the input text files into one single file named out.txt
f=open("out.txt","w")
for r,d,fi in os.walk("wc_input"):
    for files in fi:
        if files.endswith(".txt"):                         
            g=open(os.path.join(r,files))
            shutil.copyfileobj(g,f)
            g.close()
f.close()

l = []
count = 0
median = 0
#open the file to write
#split words in each line and count one by one
#get the median via the count since the count tells the element total
outfile = open("out.txt","r")
fo = open("median_result.txt",'w')
for line in outfile:
	data = line.strip().split()
	value = len(data)
	l.append(value)
	count +=1
	if count %2==0:
		median = (l[count/2-1] + l[count/2])/2.0
	else:
		median = float(l[count/2])
	fo.write(str(median))
	fo.write("\n")
fo.close()
outfile.close()

#copy the result to the wc_output file
readResult = open("median_result.txt",'r')
save_path = 'wc_output'
completeName = os.path.join(save_path,"median_result.txt")         

file1 = open(completeName, "w")
for line in readResult:
	file1.write(line)
file1.close()
readResult.close()
