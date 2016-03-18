package main

import (
	"strings"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main(){
	if len(os.Args) != 2 {
		println("Usage: leetcode language")
		println("\t language: C/C++/golang/swift...")
		return
	}

	lang := os.Args[1]
	url := "https://leetcode.com/problemset/algorithms/"
	prefix := "https://leetcode.com"

	resp, err := http.Get(url)
	if err!=nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
		return
	}
	root, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close()
	if err!=nil {
		fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", url, err)
		return
	}

/*
	fp_html, err := os.Create("leetcode.html")
	if err!=nil{
		fmt.Fprintf(os.Stderr, "Create file leetcode.html failed\n")
		return
	}
	defer fp_html.Close()
	fp_html.Write(root)
*/
	
	fp_lang, err := os.Create("leetcode_"+lang+"_support.csv")
	if err!=nil{
		fmt.Fprintf(os.Stderr, "Create file leetcode_lang_support.csv failed\n")
		return
	}
	defer fp_lang.Close()

	fp_lang.WriteString("#,URL,Title,Support,Difficulty,Locked\n");

	lang_count := 0
	lines := strings.Split(string(root), "\n")
	for idx, line_0 := range lines {
		isSubstring := strings.Contains(line_0, "<a href=\"/problems/")
		if isSubstring {
			number := strings.TrimSpace(lines[idx-2])
			number = strings.Replace(number, "<td>", "", -1);
			number = strings.Replace(number, "</td>", "", -1);
			//print number

			extra_line_number := 0
			locked := ""
			isExtraLines := strings.Contains(lines[idx+2],"fa fa-lock")
			if isExtraLines{
				extra_line_number = 2
				locked = "Locked"
			}

			difficulty := strings.TrimSpace(lines[idx+5+extra_line_number])
			difficulty = strings.Replace(difficulty, "</td>", "", -1);
			i := strings.Index(difficulty,">")
			difficulty = strings.Replace(difficulty, difficulty[0:i+1], "", -1);
			//print difficulty

			line := strings.TrimSpace(line_0)
			line = strings.Replace(line, ",", "", -1) //remove ',' between pow(x,n)
			line = strings.Replace(line, "<a href=\"", prefix, -1)
			line = strings.Replace(line, "\">", ",", 1)
			line = strings.Replace(line, "</a>", "", -1)
			split_fields := strings.Split(line, ",")
			//print split_fields

			//////////////////////////////////////////
			resp2, err := http.Get(split_fields[0])
			if err!=nil {
				fmt.Fprintf(os.Stderr, "fetch %s: %v\n", split_fields[0], err)
				return
			}
			problem, err := ioutil.ReadAll(resp2.Body)
			resp2.Body.Close()
			if err!=nil {
				fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", split_fields[0], err)
				return
			}

			lang_exist := ""
			buf2 := strings.Split(string(problem), "\n")
			for _, line2 := range buf2{
				isSubstring2 := strings.Contains(line2, lang)
				if isSubstring2{
					lang_exist = lang
					lang_count += 1
					//print "golang"
					break
				}
			}

			print              (number+","+line+","+lang_exist+","+difficulty+","+locked+"\n")
			fp_lang.WriteString(number+","+line+","+lang_exist+","+difficulty+","+locked+"\n")	
		}
	}
	println("Total Count: ", lang_count)
}