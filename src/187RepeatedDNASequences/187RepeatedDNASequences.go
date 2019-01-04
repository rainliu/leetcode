package main

func findRepeatedDnaSequences(s string) []string {
    dna2dig := map[byte]uint32{'A' : 0, 'C' : 1, 'G' : 2, 'T' : 3};
    m := make(map[uint32]int)
    r := make(map[uint32]int)
    for i:=0; i<=len(s)-10;i++{
        val := uint32(0)
        for j:=0; j<10;j++{
            val = val*10+dna2dig[s[i+j]]
        }
        if _, ok:=m[val]; ok{
            r[val] = i
        }else{
            m[val] = i
        }
    }
    var result []string
    for _, idx := range r{
        result = append(result, s[idx:idx+10])
    }
    return result
}

func main(){
}
