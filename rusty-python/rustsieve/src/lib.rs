use pyo3::Python;
use pyo3::prelude::*;
use pyo3::types::PyList;

fn sieve(n: usize) -> Vec<u32> {
    let mut sieve: Vec<u32> = (2..((n + 1) as u32)).collect();
    let limit: usize = ((n as f64).sqrt() + 1.0) as usize;

    for i in 2usize..limit {
        if sieve[i - 2] != 0 {
            let mut j = i * i;
            while j < n + 1 {
                sieve[j - 2] = 0;
                j += i;
            }
        }
    }

    sieve.into_iter().filter(|&x| x != 0).collect()
}

#[pymodule]
fn rustsieve(_py: Python, module: &PyModule) -> PyResult<()> {

    #[pyfn(module, "sieve")]
    fn sieve_py(py: Python, n: u32) -> &PyList {
        let list = PyList::new(py, &sieve(n as usize));
        list
    }

    Ok(())
}
