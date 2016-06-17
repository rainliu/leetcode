package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
)

type langSupport struct {
	number     string
	line       string
	lang       string
	difficulty string
	locked     string
}

func findLang(out chan<- langSupport, lines []string, idx int, lang string) error {
	prefix := "https://leetcode.com"

	var ls langSupport

	ls.number = strings.TrimSpace(lines[idx-2])
	ls.number = strings.Replace(ls.number, "<td>", "", -1)
	ls.number = strings.Replace(ls.number, "</td>", "", -1)
	//print number

	extraLineNumber := 0
	ls.locked = ""
	isExtraLines := strings.Contains(lines[idx+2], "fa fa-lock")
	if isExtraLines {
		extraLineNumber = 2
		ls.locked = "Locked"
	}

	isEditorial := strings.Contains(lines[idx+6+extraLineNumber], "true")
	if isEditorial {
		extraLineNumber += 9
	}

	ls.difficulty = strings.TrimSpace(lines[idx+10+extraLineNumber])
	ls.difficulty = strings.Replace(ls.difficulty, "</td>", "", -1)
	i := strings.Index(ls.difficulty, ">")
	ls.difficulty = strings.Replace(ls.difficulty, ls.difficulty[0:i+1], "", -1)

	ls.line = strings.TrimSpace(lines[idx])
	ls.line = strings.Replace(ls.line, ",", "", -1) //remove ',' between pow(x,n)
	ls.line = strings.Replace(ls.line, "<a href=\"", prefix, -1)
	ls.line = strings.Replace(ls.line, "\">", ",", 1)
	ls.line = strings.Replace(ls.line, "</a>", "", -1)
	splitFields := strings.Split(ls.line, ",")

	//////////////////////////////////////////
	resp2, err := http.Get(splitFields[0])
	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch %s: %v\n", splitFields[0], err)
		return err
	}
	problem, err := ioutil.ReadAll(resp2.Body)
	resp2.Body.Close()
	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", splitFields[0], err)
		return err
	}

	ls.lang = ""
	buf2 := strings.Split(string(problem), "\n")
	for _, line2 := range buf2 {
		isSubstring2 := strings.Contains(line2, lang)
		if isSubstring2 {
			ls.lang = lang
			break
		}
	}

	out <- ls

	return nil
}

func main() {
	if len(os.Args) != 2 {
		println("Usage: leetcode language")
		println("\t language: C/C++/golang/swift...")
		return
	}

	lang := os.Args[1]
	url := "https://leetcode.com/problemset/algorithms/"

	resp, err := http.Get(url)
	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
		return
	}
	root, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close()
	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", url, err)
		return
	}

	/*fp_html, err := os.Create("leetcode.html")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Create file leetcode.html failed\n")
		return
	}
	defer fp_html.Close()
	fp_html.Write(root)*/

	fp_lang, err := os.Create("leetcode_" + lang + "_support.csv")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Create file leetcode_lang_support.csv failed\n")
		return
	}
	defer fp_lang.Close()

	fp_lang.WriteString("#,URL,Title,Support,Difficulty,Locked\n")

	langSupportChan := make(chan langSupport)
	count := 0
	lines := strings.Split(string(root), "\n")
	for idx, line_0 := range lines {
		isSubstring := strings.Contains(line_0, "<a href=\"/problems/")
		if isSubstring {
			count++
			go findLang(langSupportChan, lines, idx, lang)

		}
	}

	for i := 0; i < count; i++ {
		ls := <-langSupportChan
		print(ls.number + "," + ls.line + "," + ls.lang + "," + ls.difficulty + "," + ls.locked + "\n")
		fp_lang.WriteString(ls.number + "," + ls.line + "," + ls.lang + "," + ls.difficulty + "," + ls.locked + "\n")
	}
}
