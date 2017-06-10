package main

func largestNumber(nums []int) string {
    numstr := make([]string, len(nums))
    for i:=0; i<len(nums); i++{
        numstr[i] = strconv.Itoa(nums[i])
    }
    sort.Slice(numstr, func(i, j int) bool { 
        str1:=numstr[i]+numstr[j]
        str2:=numstr[j]+numstr[i]
        return str1<str2
    })
    var b bytes.Buffer
    for i:=len(numstr)-1; i>=0; i--{
        b.WriteString(numstr[i])
    }
    str:=b.String()
    i:=0;
    for i<len(str){
        if str[i]=='0' && i!=len(str)-1{
            i++
        }else{
            break
        }
    }
    return str[i:];
}

func main(){
}
