#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/../", => "/"
path = "/home//foo/", => "/home/foo/"
click to show corner cases.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;

        int size = path.size();
        int b=0, e;

        while(b<size){
	        while(b<size&&path[b]=='/') b++;

	        e=b;

	        while(e<size&&path[e]!='/') e++;

	        string str = path.substr(b, e-b);
	        if(str=="" || str=="."){
	        	//do nothing
	        }else if(str==".."){
	        	if(!paths.empty())
	        		paths.pop();
	        }else{
	        	paths.push(str);
	        }

	        b=e;
	    }

	    stack<string> reverse_paths;
	    while(!paths.empty()){
	    	reverse_paths.push(paths.top());
	    	paths.pop();
	    }

	    if(reverse_paths.empty()){
	    	return "/";
	    }else{
		    ostringstream oss;
		    while(!reverse_paths.empty()){
		    	oss<<"/"<<reverse_paths.top();
		    	reverse_paths.pop();
		    }
		    return oss.str();
    	}
    }
};

int main(){
	Solution s;
	
	cout<<s.simplifyPath("/home/")<<endl;//, => "/home"
	cout<<s.simplifyPath("/a/./b/../../c/")<<endl;//, => "/c"
	cout<<s.simplifyPath("/../")<<endl;//, => "/"
	cout<<s.simplifyPath("//")<<endl;//, => "/"
	cout<<s.simplifyPath("/home//foo/")<<endl;//, => "/home/foo/"

	return 0;
}