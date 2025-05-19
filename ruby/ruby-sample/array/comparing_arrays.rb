# frozen_string_literal: true
# typed: true

require('awesome_print')

# comparing arrays

a1 = [1, 2, 3]
a2 = [1, 2, 3]
a3 = [1, 2, 3.0]
a4 = [1, 3, 2]

ap("a1 ==a3 ? #{a1 == a3}")
ap("a1 eql? a3 ? #{a1.eql?(a3)}")
ap("a1 eql? a2 ? #{a1.eql?(a2)}")
ap("a1 <=> a4 ? #{a1 <=> a4}")
