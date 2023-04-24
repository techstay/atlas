package tech.techstay.string

def texts = '''\
The Chinese premier described the world's second-largest economy as a butterfly struggling to emerge from a chrysalis.
He said this transformation was filled with promise but also great pain.
He repeatedly paid tribute to Communist Party leader Xi Jinping and said that under the sound leadership of the Party, the Chinese people had the courage and ingenuity to overcome all difficulties.
\
'''

def startsWithP = ~/\b[pP]\w+\b/
def matcher = texts =~ startsWithP
println(matcher[0..-1])

// exactly match
assert 'abc abc Acc' ==~/([aA]\w{2}\s?)+/
