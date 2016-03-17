import urllib2
import StringIO
import string

root = urllib2.urlopen("https://leetcode.com/problemset/algorithms/").read()
prefix = 'https://leetcode.com'

with open("leetcode.html", "w") as f:
	f.write(root) 

buf = StringIO.StringIO(root)
line_1 = ''
line_2 = ''
golang_count = 0
	
with open("leetcode.csv", "w") as f:
	for line_0 in buf.readlines():
		isSubstring = "<a href=\"/problems/" in line_0
		if isSubstring:
			number = line_2.strip()
			number = string.replace(number, '<td>', '');
			number = string.replace(number, '</td>', '');
			print number

			line = line_0.strip()
			line = string.replace(line, '<a href=\"', prefix)
			line = string.replace(line, '\">', ',')
			line = string.replace(line, '</a>', '')
			split_fields = line.split(',')
			print split_fields

			problem = urllib2.urlopen(split_fields[0]).read()
			buf2 = StringIO.StringIO(problem)
			for line2 in buf2.readlines():
				isSubstring2 = "golang" in line2
				if isSubstring2:
					line = line+",golang"
					golang_count++
					print "golang"
					break

			f.write(number+","+line+"\n")
		
		line_2 = line_1
		line_1 = line_0			

print "Total golang count is: "+golang_count