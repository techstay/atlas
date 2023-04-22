use std::{
    fs::{self, File},
    io::{self, ErrorKind, Read},
};

fn main() {
    println!("{}", read_hosts1());
    println!("{}", read_host2().unwrap());
    println!("{}", read_host3().unwrap());
    println!("{}", read_host4().unwrap());
}

// panic if failed
fn read_hosts1() -> String {
    let result = File::open("C:\\Windows\\system32\\drivers\\etc\\hosts");
    let mut file_content = String::new();
    let _result = match result {
        Ok(mut file) => file.read_to_string(&mut file_content),
        Err(error) => match error.kind() {
            ErrorKind::NotFound => panic!("not found the file: {:?}", error),
            other_error => panic!("Problem opening the file: {:?}", other_error),
        },
    };
    file_content
}

// propagating error if failed
fn read_host2() -> Result<String, io::Error> {
    let result = File::open("C:\\Windows\\system32\\drivers\\etc\\hosts");
    let mut file = match result {
        Ok(file) => file,
        Err(error) => return Err(error),
    };
    let mut file_content = String::new();
    match file.read_to_string(&mut file_content) {
        Ok(_) => Ok(file_content),
        Err(error) => Err(error),
    }
}

// simpler approach
fn read_host3() -> Result<String, io::Error> {
    let result = File::open("C:\\Windows\\system32\\drivers\\etc\\hosts");
    let mut file_content = String::new();
    result?.read_to_string(&mut file_content)?;
    Ok(file_content)
}

fn read_host4() -> Result<String, io::Error> {
    fs::read_to_string("C:\\Windows\\system32\\drivers\\etc\\hosts")
}
