def greet [...name: string] {
    echo "Hello everyone, "
    for $n in $name {
        echo $"($n) "
    }
}

greet zhang3
greet zhang3 li4 techstay
