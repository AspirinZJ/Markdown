fn main() {
    let x = 5;
    println!("x: {}", x);
    // x = 6; Error: x is immutable by default!

    let x = x + 1; // showing previous x
    println!("x: {}", x);

    // shadow
    let spaces = "   ";
    let spaces = spaces.len();
    println!("number of spaces: {}", spaces);

    // const
    const MAX_POINTS: u32 = 100_000;

    // float
    let y = 2.0; // f64 by default
    let z: f32 = 1.0;   // f32
    println!("y: {}, z: {}", y, z);

    // boolean
    let t = true;
    let f: bool = false;
    println!("t: {}, f: {}", t, f);

    // char
    let heart_eyed_cat = '😻';
    println!("{}", heart_eyed_cat);

    // tuple
    let tup: (i32, f64, u8) = (500, 3.14, 1);
    let (x, y, z) = tup;
    println!("{}, {}, {}", x, y, z);
    println!("{}, {}, {}", tup.0, tup.1, tup.2);

    // array
    let arr = [1, 2, 3];
    let arr2: [i64; 5] = [1, 2, 3, 4, 5];
    let arr3 = [3, 5];  // [3, 3, 3, 3, 3]
}
