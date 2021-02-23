// get input and output
use std::io;
// Rng trait defines methods that random number generators implement
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("Guess the number.");
    let secret_number = rand::thread_rng().gen_range(1, 101);
    // println!("The secret number is: {}", secret_number);

    loop {
        println!("Input your guess.");

        // use let to create a variable, which by default is immutable
        // mut means the variable mutable
        let mut guess = String::new();

        // stdin() create a new instance of std::io::Stdin
        // real_line() method get the input from the terminal
        // &mut guess is a reference and mutable, reference if immutable by default
        // An instance of io::Result has an expect method you can call.
        io::stdin().read_line(&mut guess).expect("Failed to read line.");

        // trim() methods on a String instance will eliminate any whitespace at the beginning and end
        // trim() methods to eliminate '\n' (Enter key)
        // parse() method will parse a string into some kind of number
        // use : to specify the variable's type
        // let guess: u32 = guess.trim().parse().expect("Please type a number!");
        let guess: u32 = match guess.trim().parse() {
            Ok(number) => number,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        // match expression
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small."),
            Ordering::Greater => println!("Too big."),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
