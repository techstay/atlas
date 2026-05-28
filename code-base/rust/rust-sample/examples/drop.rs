struct Resource {
    name: String,
}

impl Drop for Resource {
    fn drop(&mut self) {
        println!("Dropping {}", self.name);
    }
}

fn main() {
    let re1 = Resource {
        name: "resource 1".to_string(),
    };

    // manually destructing
    drop(re1);

    let _re2 = Resource {
        name: "resource 2".to_string(),
    };
    let _re3 = Resource {
        name: "resource 3".to_string(),
    };
}
