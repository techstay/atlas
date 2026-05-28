"aaa, bbb, ccc; ddd" | parse '{a}, {b}, {c}; {d}'

"Username: techstay_523, email: techstay_523@gmail.com" | parse --regex 'Username: (?P<username>[A-Za-z][A-Za-z0-9_]+), email: (?P<email>[A-Za-z0-9_\.\-]+@[a-zA-Z0-9_\-\.]+\.[a-zA-Z]{2,5})'
