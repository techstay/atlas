package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	infile := "/etc/hosts"
	outfile := "hosts.txt"
	// reading files
	file, err := ioutil.ReadFile(infile)
	if err != nil {
		fmt.Println("File reading Error", err)
	}
	fmt.Println(string(file))

	// writing files
	err = ioutil.WriteFile(outfile, file, 0644)
	if err != nil {
		fmt.Println("File writing error", err)
	}

	// deleting files
	os.Remove(outfile)
}
