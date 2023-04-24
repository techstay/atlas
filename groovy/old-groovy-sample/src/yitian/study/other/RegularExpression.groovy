package yitian.study.other

//这次直接当做脚本用
def texts = '''
The Chinese premier described the world's second-largest economy as a butterfly struggling to emerge from a chrysalis.
He said this transformation was filled with promise but also great pain.
He repeatedly paid tribute to Communist Party leader Xi Jinping and said that under the sound leadership of the Party, the Chinese people had the courage and ingenuity to overcome all difficulties.'''

//p开头的单词
def startsWithP = /\b[pP]\w*\b/



def wordsStartsWithP = texts =~ startsWithP
println("p开头的单词")
while (wordsStartsWithP.find()) {
    print("${wordsStartsWithP.group()} ")
}
println()

//以y结尾的单词
def endsWithY = /^.*y$/
def words = ['happy', 'foolish', 'something', 'java','lucky']

def results = words.findAll { it ==~ endsWithY }.join(',')
println("y结尾的单词:$results")