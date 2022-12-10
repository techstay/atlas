def greet [name?: string] {
    if ($name == null) {
        "Hello nobody"
    } else {
        $"Hello ($name)"
    }
}

greet
greet zhang3
