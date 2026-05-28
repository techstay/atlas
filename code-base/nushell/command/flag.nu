def greet [
    name: string
    --password (-p): string
] {
    if ($password == null) {
        $"Need authentication, ($name)!"
    } else {
        $"Try login, ($name) with pass ($password)!"
    }
}

greet techstay
greet techstay -p 1234
greet zhnag3 --password abcd
