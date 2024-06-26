use savvy::{ffi::DllInfo, savvy_init};
use std::sync::OnceLock;

pub(crate) static RUNTIME: OnceLock<tokio::runtime::Runtime> = OnceLock::new();

#[savvy_init]
fn init_runtime(_dll_info: *mut DllInfo) -> savvy::Result<()> {
    RUNTIME.get_or_init(|| tokio::runtime::Runtime::new().expect("cannot create runtime"));
    Ok(())
}
