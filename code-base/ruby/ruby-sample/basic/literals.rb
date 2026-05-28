# frozen_string_literal: true
# typed: true

require_relative '../utils/utils'

print_header('Integer Literals')
ap 500
ap 500_500
ap(-700)

print_header('Integer Literals with Base')
ap 0o77
ap 0xcafe
ap 0b00100100

print_header('Big Integer Literals')
ap 1_287_480_932_704_975

print_header('Float Literals')
ap 3.14
ap 3.1415926
ap 3.14e10
ap 3.14e-10

print_header('Array Literals')
ap [1, 2, 3, 4, '5']

print_header('Hash Literals')
ap({ '1' => 1, '2' => 3, '3' => 5 })
