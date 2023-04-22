use log::{debug, error, info, trace, warn};

fn main() {
    simple_logger::SimpleLogger::new().env().init().unwrap();

    trace!("some trace");
    info!("some info");
    debug!("some debug");
    warn!("some warn");
    error!("some error");

    foo();
}

fn foo() {
    info!("some info in foo");
}
