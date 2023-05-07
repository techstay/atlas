package mymath

import (
	"testing"

	"github.com/ysmood/got"
)

func TestAdd(t *testing.T) {
	got.T(t).Eq(Add(3, 5), 3+5)
}

func TestSub(t *testing.T) {
	got.T(t).Eq(Sub(3, 5), 3-5)
}

func TestMul(t *testing.T) {
	got.T(t).Eq(Mul(3, 5), 3*5)
}

func TestDiv(t *testing.T) {
	got.T(t).Eq(Div(3, 5), 3/5)
}
