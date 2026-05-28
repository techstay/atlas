# frozen_string_literal: true
# typed: true

# emulating dice with ten sides
rank = {
  techstay: 100,
  jack: 46,
  jason: 78,
  josh: 90,
  jake: 50,
  jerry: 60,
  kevin: 30,
  git: 0
}

p rank

# deleting elements
rank.delete(:git)

p rank

# removing first pair of hashes
rank.shift

p rank

# rejecting elements and returning the modified hashes
p(rank.reject { |_k, v| v <= 60 })

# rejecting elements directly in the original hashes
rank.delete_if do |_k, v|
  v <= 60
end
p rank
