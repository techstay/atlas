# frozen_string_literal: true
# typed: true

# emulating dice with ten sides
rank = {
  techstay: 100,
  zhang3: 90,
  li4: 80,
  wang5: 70,
  zhao6: 60,
  jack: 46,
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
