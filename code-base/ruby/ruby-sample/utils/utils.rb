# frozen_string_literal: true
# typed: true

require('awesome_print')

def print_header(header)
  max_width = 80 - 2
  padding_width = (max_width - header.length) / 2
  ap %(#{'-' * padding_width} #{header} #{'-' * (max_width - header.length - padding_width)})
end
