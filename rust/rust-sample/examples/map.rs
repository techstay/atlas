use std::collections::HashMap;

fn main() {
    let mut map: HashMap<String, i32> = HashMap::new();
    let str1 = "Hello".to_string();

    // updating
    map.insert(str1, 1);
    map.insert("foo".to_string(), 2);

    println!("{:?}", map);

    // getting values
    let value = map.get("Hello").copied().unwrap_or(0);
    println!("value: {value}");

    // iterating
    for (k, v) in map {
        println!("key: {k}, value: {v}");
    }
}
