package main

import (
	"testing"
)

func TestZigZagConversion(t *testing.T) {
	var tests = []struct {
		input   string
		numRows int
		output  string
	}{
		{"A", 1, "A"},
		{"ABCD", 3, "ABDC"},
	}

	for _, test := range tests {
		if result := convert(test.input, test.numRows); result != test.output {
			t.Errorf("convert(%s, %d) =  %s", test.input, test.numRows, result)
		}
	}
}
