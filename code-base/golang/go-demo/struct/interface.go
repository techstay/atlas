package main

import "fmt"

type Person interface {
	IsLive() bool
	Speak() string
	Run()
}

type LiveMan struct{}

func (this *LiveMan) IsLive() bool {
	return true
}

func (this *LiveMan) Speak() string {
	return "I can speak!"
}

func (this *LiveMan) Run() {
	fmt.Println("I can run!")
}

func main() {
	var person Person = &LiveMan{}
	fmt.Printf("I'm live: %v! %s\n", person.IsLive(), person.Speak())
	person.Run()
}
