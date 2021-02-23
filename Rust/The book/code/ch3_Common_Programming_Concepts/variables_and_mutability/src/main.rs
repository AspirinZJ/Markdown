fn main() {
    let x = 5;
    println!("x: {}", x);
    // x = 6; Error: x is immutable by default!

    let x = x + 1; // showing previous x
    println!("x: {}", x);

    // const
    const MAX_POINTS: u32 = 100_000;
}
