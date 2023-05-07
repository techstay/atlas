package hello

import "testing"

func TestPI(t *testing.T) {
	got := PI
	want := 3.1415
	if got != want {
		t.Errorf("PI should be %f, but actually %f", want, got)
	}
}

func TestHello(t *testing.T) {
	if Hello("zhang3") != "Hello, zhang3" {
		t.Errorf("Hello should be %s, but actually %s", "Hello, zhang3", Hello("zhang3"))
	}
}

func TestHelloString(t *testing.T) {
	if hello_string != "Hello, World!" {
		t.Errorf("Hello should be %s, but actually %s", "Hello, World!", hello_string)
	}
}
