use serde::{Deserialize, Serialize};
use std::result::Result;

#[derive(Serialize, Deserialize, Debug)]
struct MyConfig {
    name: String,
    description: String,
    version_number: i32,
}

impl Default for MyConfig {
    fn default() -> Self {
        Self {
            name: "MyApp".to_string(),
            description: "MyApp description".to_string(),
            version_number: 1,
        }
    }
}
// TODO: here I met some runtime error `Error: SerializeTomlError(UnsupportedType)`
// this is intended to be solved later on
fn main() -> Result<(), confy::ConfyError> {
    let app_name = "myapp";
    let cfg = confy::load(app_name, None)?;

    println!("{:?}", cfg);

    let new_config = MyConfig {
        name: "new app".to_string(),
        description: "new description".to_string(),
        version_number: 2,
    };

    confy::store(app_name, None, new_config)?;

    let cfg = confy::load(app_name, None)?;
    println!("{:?}", cfg);

    // config file path
    let path = confy::get_configuration_file_path(app_name, None);
    println!("config file path: {}", path.unwrap().to_str().unwrap());

    Ok(())
}
