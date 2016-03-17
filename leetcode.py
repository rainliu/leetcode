import urllib2
import StringIO
import string

root = urllib2.urlopen("https://leetcode.com/problemset/algorithms/").read()
prefix = 'https://leetcode.com'

#with open("leetcode.html", "w") as f:
#	f.write(root) 

buf = StringIO.StringIO(root)

golang_count = 0

with open("leetcode_golang_support.csv", "w") as f:
	f.write("#,URL,Title,Acceptance,Difficulty,Golang Support\n");

	lines = buf.readlines()
	for idx, line_0 in enumerate(lines):
		isSubstring = "<a href=\"/problems/" in line_0
		if isSubstring:
			number = lines[idx-2].strip()
			number = string.replace(number, '<td>', '');
			number = string.replace(number, '</td>', '');
			#print number

			extra_line_number = 0
			isExtraLines = "fa fa-lock" in lines[idx+2]
			if isExtraLines:
				extra_line_number = 2

			acceptance = lines[idx+3+extra_line_number].strip()
			acceptance = string.replace(acceptance, '<td>', '');
			acceptance = string.replace(acceptance, '</td>', '');
			#print acceptance

			difficulty = lines[idx+5+extra_line_number].strip()
			difficulty = string.replace(difficulty, '</td>', '');
			i = difficulty.index('>')
			difficulty = string.replace(difficulty, difficulty[0:i+1], '');
			#print difficulty

			line = line_0.strip()
			line = string.replace(line, ',', '') #remove ',' between pow(x,n)
			line = string.replace(line, '<a href=\"', prefix)
			line = string.replace(line, '\">', ',')
			line = string.replace(line, '</a>', '')
			split_fields = line.split(',')
			#print split_fields

			golang_exist = ''
			problem = urllib2.urlopen(split_fields[0]).read()
			buf2 = StringIO.StringIO(problem)
			for line2 in buf2.readlines():
				isSubstring2 = "golang" in line2
				if isSubstring2:
					golang_exist = 'golang'
					golang_count += 1
					#print "golang"
					break

			print number+","+line+","+acceptance+","+difficulty+","+golang_exist+"\n"
			f.write(number+","+line+","+acceptance+","+difficulty+","+golang_exist+"\n")	

print "Total golang count is: "+str(golang_count)