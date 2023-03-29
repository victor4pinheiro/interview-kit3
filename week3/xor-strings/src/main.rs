fn strings_xor(first: String, second: String) -> i32 {
    let s: i32 = first.trim().parse().unwrap();
    let t: i32 = second.trim().parse().unwrap();

    s ^ t
}

fn main() {
    let mut first = String::new();
    std::io::stdin().read_line(&mut first).expect("failed to readline");

    let mut second = String::new();
    std::io::stdin().read_line(&mut second).expect("failed to readline");

    let result_xor = strings_xor(first, second);

    println!("{}", result_xor);
}
