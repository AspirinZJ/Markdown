# Common Programming Concepts

This chapter covers concepts that appear in almost every programming language and how they work in Rust. Many programming languages have much in common at their core. None of the concepts presented in this chapter are unique to Rust, but we’ll discuss them in the context of Rust and explain the conventions around using these concepts.

Specifically, you’ll learn about variables, basic types, functions, comments, and control flow. These foundations will be in every Rust program, and learning them early will give you a strong core to start from.

> #### Keywords
>
> The Rust language has a set of *keywords* that are reserved for use by the language only, much as in other languages. Keep in mind that you cannot use these words as names of variables or functions. Most of the keywords have special meanings, and you’ll be using them to do various tasks in your Rust programs; a few have no current functionality associated with them but have been reserved for functionality that might be added to Rust in the future. You can find a list of the keywords in [Appendix A](https://doc.rust-lang.org/book/appendix-01-keywords.html).

## Variables and Mutability

As mentioned in Chapter 2, ==by default variables are immutable==. This is one of many nudges Rust gives you to write your code in a way that takes advantage of the safety and easy concurrency that Rust offers. However, you still have the option to make your variables mutable. Let’s explore how and why Rust encourages you to favor immutability and why sometimes you might want to opt out.

When a variable is immutable, once a value is bound to a name, you can’t change that value. To illustrate this, let’s generate a new project called *variables* in your *projects* directory by using `cargo new variables`.

Then, in your new *variables* directory, open *src/main.rs* and replace its code with the following code that won’t compile just yet:

Filename: src/main.rs

```rust
fn main() {
    let x = 5;
    println!("The value of x is: {}", x);
    x = 6; // Error!!!
    println!("The value of x is: {}", x);
}
```

Save and run the program using `cargo run`. You should receive an error message, as shown in this output:

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
error[E0384]: cannot assign twice to immutable variable `x`
 --> src/main.rs:4:5
  |
2 |     let x = 5;
  |         -
  |         |
  |         first assignment to `x`
  |         help: make this binding mutable: `mut x`
3 |     println!("The value of x is: {}", x);
4 |     x = 6;
  |     ^^^^^ cannot assign twice to immutable variable

error: aborting due to previous error

For more information about this error, try `rustc --explain E0384`.
error: could not compile `variables`

To learn more, run the command again with --verbose.
```

The error message indicates that the cause of the error is that you `cannot assign twice to immutable variable x`, because you tried to assign a second value to the immutable `x` variable.

It’s important that we get compile-time errors when we attempt to change a value that we previously designated as immutable because this very situation can lead to bugs. If one part of our code operates on the assumption that a value will never change and another part of our code changes that value, it’s possible that the first part of the code won’t do what it was designed to do. The cause of this kind of bug can be difficult to track down after the fact, especially when the second piece of code changes the value only *sometimes*.

In Rust, the compiler guarantees that when you state that a value won’t change, it really won’t change. That means that when you’re reading and writing code, you don’t have to keep track of how and where a value might change. Your code is thus easier to reason through.

But mutability can be very useful. Variables are immutable only by default; as you did in Chapter 2, y==ou can make them mutable by adding `mut` in front of the variable name==. In addition to allowing this value to change, `mut` conveys intent to future readers of the code by indicating that other parts of the code will be changing this variable’s value.

For example, let’s change *src/main.rs* to the following:

Filename: src/main.rs

```rust
fn main() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}
```

We’re allowed to change the value that `x` binds to from `5` to `6` when `mut` is used. In some cases, you’ll want to make a variable mutable because it makes the code more convenient to write than if it had only immutable variables.

There are multiple trade-offs to consider in addition to the prevention of bugs. For example, in cases where you’re using large data structures, mutating an instance in place may be faster than copying and returning newly allocated instances. With smaller data structures, creating new instances and writing in a more functional programming style may be easier to think through, so lower performance might be a worthwhile penalty for gaining that clarity.

### Differences Between Variables and Constants

Being unable to change the value of a variable might have reminded you of another programming concept that most other languages have: *constants*. Like immutable variables, ==constants== are values that are bound to a name and are not allowed to change, but there are a few differences between constants and variables.

==First, you aren’t allowed to use `mut` with constants. Constants aren’t just immutable by default—they’re always immutable.==

==You declare constants using the `const` keyword instead of the `let` keyword, and the type of the value *must* be annotated.== We’re about to cover types and type annotations in the next section, [“Data Types,”](https://doc.rust-lang.org/book/ch03-02-data-types.html#data-types) so don’t worry about the details right now. Just know that you must always annotate the type.

==Constants can be declared in any scope, including the global scope, which makes them useful for values that many parts of code need to know about.==

==The last difference is that constants may be set only to a constant expression, not the result of a function call or any other value that could only be computed at runtime.==

Here’s an example of a constant declaration where the constant’s name is `MAX_POINTS` and its value is set to 100,000. (==Rust’s naming convention for constants is to use all uppercase with underscores between words, and underscores can be inserted in numeric literals to improve readability)==:

```rust
const MAX_POINTS: u32 = 100_000;
```

Constants are valid for the entire time a program runs, within the scope they were declared in, ==making them a useful choice for values in your application domain that multiple parts of the program might need to know about,== such as the maximum number of points any player of a game is allowed to earn or the speed of light.

Naming hardcoded values used throughout your program as constants is useful in conveying the meaning of that value to future maintainers of the code. It also helps to have only one place in your code you would need to change if the hardcoded value needed to be updated in the future.

### Shadowing

As you saw in the guessing game tutorial in the [“Comparing the Guess to the Secret Number”](https://doc.rust-lang.org/book/ch02-00-guessing-game-tutorial.html#comparing-the-guess-to-the-secret-number) section in Chapter 2, ==you can declare a new variable with the same name as a previous variable, and the new variable shadows the previous variable==. Rustaceans say that the first variable is *shadowed* by the second, which means that the second variable’s value is what appears when the variable is used. ==We can shadow a variable by using the same variable’s name and repeating the use of the `let` keyword== as follows:

Filename: src/main.rs

```rust
fn main() {
    let x = 5;
    let x = x + 1;
    let x = x * 2;

    println!("The value of x is: {}", x);
}
```

This program first binds `x` to a value of `5`. Then it shadows `x` by repeating `let x =`, taking the original value and adding `1` so the value of `x` is then `6`. The third `let` statement also shadows `x`, multiplying the previous value by `2` to give `x` a final value of `12`. 

==Shadowing is different from marking a variable as `mut`,== because we’ll get a compile-time error if we accidentally try to reassign to this variable without using the `let` keyword. ==By using `let`, we can perform a few transformations on a value but have the variable be immutable after those transformations have been completed.==

==The other difference between `mut` and shadowing is that because we’re effectively creating a new variable when we use the `let` keyword again, we can change the type of the value but reuse the same name.== For example, say our program asks a user to show how many spaces they want between some text by inputting space characters, but we really want to store that input as a number:

```rust
    let spaces = "   ";
    let spaces = spaces.len();
```

This construct is allowed because the first `spaces` variable is a string type and the second `spaces` variable, which is a brand-new variable that happens to have the same name as the first one, is a number type. Shadowing thus spares us from having to come up with different names, such as `spaces_str` and `spaces_num`; instead, we can reuse the simpler `spaces` name. However, if we try to use `mut` for this, as shown here, we’ll get a compile-time error:

```rust
    let mut spaces = "   ";
    spaces = spaces.len();
```

The error says we’re not allowed to mutate a variable’s type:

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
error[E0308]: mismatched types
 --> src/main.rs:3:14
  |
3 |     spaces = spaces.len();
  |              ^^^^^^^^^^^^ expected `&str`, found `usize`

error: aborting due to previous error

For more information about this error, try `rustc --explain E0308`.
error: could not compile `variables`

To learn more, run the command again with --verbose.
```

Now that we’ve explored how variables work, let’s look at more data types they can have.

## Data Types

Every value in Rust is of a certain *data type*, which tells Rust what kind of data is being specified so it knows how to work with that data. We’ll look at two data type subsets: ==scalar and compound.==

Keep in mind that ==Rust is a *statically typed* language, which means that it must know the types of all variables at compile time==. The compiler can usually infer what type we want to use based on the value and how we use it. ==In cases when many types are possible, such as when we converted a `String` to a numeric type using `parse` in the [“Comparing the Guess to the Secret Number”](https://doc.rust-lang.org/book/ch02-00-guessing-game-tutorial.html#comparing-the-guess-to-the-secret-number) section in Chapter 2, we must add a type annotation,== like this:

```rust
let guess: u32 = "42".parse().expect("Not a number!");
```

If we don’t add the type annotation here, Rust will display the following error, which means the compiler needs more information from us to know which type we want to use:

```console
$ cargo build
   Compiling no_type_annotations v0.1.0 (file:///projects/no_type_annotations)
error[E0282]: type annotations needed
 --> src/main.rs:2:9
  |
2 |     let guess = "42".parse().expect("Not a number!");
  |         ^^^^^ consider giving `guess` a type

error: aborting due to previous error

For more information about this error, try `rustc --explain E0282`.
error: could not compile `no_type_annotations`

To learn more, run the command again with --verbose.
```

You’ll see different type annotations for other data types.

### ==Scalar Types==

A *scalar* type represents a single value. ==Rust has four primary scalar types: integers, floating-point numbers, Booleans, and characters.== You may recognize these from other programming languages. Let’s jump into how they work in Rust.

#### Integer Types

An *integer* is a number without a fractional component. We used one integer type in Chapter 2, the `u32` type. This type declaration indicates that the value it’s associated with should be an unsigned integer (signed integer types start with `i`, instead of `u`) that takes up 32 bits of space. Table 3-1 shows the built-in integer types in Rust. Each variant in the Signed and Unsigned columns (for example, `i16`) can be used to declare the type of an integer value.

==Table 3-1: Integer Types in Rust==

| ==Length==  | ==Signed==  | ==Unsigned== |
| ----------- | ----------- | ------------ |
| ==8-bit==   | ==`i8`==    | ==`u8`==     |
| ==16-bit==  | ==`i16`==   | ==`u16`==    |
| ==32-bit==  | ==`i32`==   | ==`u32`==    |
| ==64-bit==  | ==`i64`==   | ==`u64`==    |
| ==128-bit== | ==`i128`==  | ==`u128`==   |
| ==arch==    | ==`isize`== | ==`usize`==  |

Each variant can be either signed or unsigned and has an explicit size. Signed numbers are stored using [two’s complement](https://en.wikipedia.org/wiki/Two's_complement) representation.

Each signed variant can store numbers from $-2^{n-1}$ to $2^{n-1} -1$inclusive, where *n* is the number of bits that variant uses. So an `i8` can store numbers from$-2^7$ to $2^7-1$, which equals -128 to 127. Unsigned variants can store numbers from 0 to $2^n-1$, so a `u8` can store numbers from 0 to$2^8 - 1$, which equals 0 to 255.

Additionally, the `isize` and `usize` types depend on the kind of computer your program is running on: 64 bits if you’re on a 64-bit architecture and 32 bits if you’re on a 32-bit architecture.

You can write integer literals in any of the forms shown in Table 3-2. Note that all number literals except the byte literal allow a type suffix, such as `57u8`, and `_` as a visual separator, such as `1_000`.

==Table 3-2: Integer Literals in Rust==

| ==Number literals==  | ==Example==       |
| -------------------- | ----------------- |
| ==Decimal==          | ==`98_222`==      |
| ==Hex==              | ==`0xff`==        |
| ==Octal==            | ==`0o77`==        |
| ==Binary==           | ==`0b1111_0000`== |
| ==Byte (`u8` only)== | ==`b'A'`==        |

So how do you know which type of integer to use? If you’re unsure, Rust’s defaults are generally good choices, and i==nteger types default to `i32`: this type is generally the fastest, even on 64-bit systems.== The primary situation in which you’d use `isize` or `usize` is when indexing some sort of collection.

> ##### Integer Overflow
>
> Let’s say you have a variable of type `u8` that can hold values between 0 and 255. If you try to change the variable to a value outside of that range, such as 256, *integer overflow* will occur. Rust has some interesting rules involving this behavior. When you’re compiling in debug mode, Rust includes checks for integer overflow that cause your program to *panic* at runtime if this behavior occurs. ==Rust uses the term panicking when a program exits with an error==; we’ll discuss panics in more depth in the [“Unrecoverable Errors with `panic!`”](https://doc.rust-lang.org/book/ch09-01-unrecoverable-errors-with-panic.html) section in Chapter 9.
>
> When you’re compiling in release mode with the `--release` flag, Rust does *not* include checks for integer overflow that cause panics. Instead, if overflow occurs, Rust performs *two’s complement wrapping*. In short, values greater than the maximum value the type can hold “wrap around” to the minimum of the values the type can hold. In the case of a `u8`, 256 becomes 0, 257 becomes 1, and so on. The program won’t panic, but the variable will have a value that probably isn’t what you were expecting it to have. Relying on integer overflow’s wrapping behavior is considered an error.
>
> ==To explicitly handle the possibility of overflow, you can use these families of methods that the standard library provides on primitive numeric types:==
>
> - ==Wrap in all modes with the `wrapping_*` methods, such as `wrapping_add`==
> - ==Return the `None` value if there is overflow with the `checked_*` methods==
> - ==Return the value and a boolean indicating whether there was overflow with the `overflowing_*` methods==
> - ==Saturate at the value's minimum or maximum values with `saturating_*` methods==

#### Floating-Point Types

Rust also has two primitive types for *floating-point numbers*, which are numbers with decimal points. ==Rust’s floating-point types are `f32` and `f64`, which are 32 bits and 64 bits in size, respectively.== ==The default type is `f64`== because on modern CPUs it’s roughly the same speed as `f32` but is capable of more precision.

Here’s an example that shows floating-point numbers in action:

Filename: src/main.rs

```rust
fn main() {
    let x = 2.0; // f64
    let y: f32 = 3.0; // f32
}
```

Floating-point numbers are represented according to the IEEE-754 standard. The `f32` type is a single-precision float, and `f64` has double precision.

#### Numeric Operations

Rust supports the basic mathematical operations you’d expect for all of the number types: addition, subtraction, multiplication, division, and remainder. The following code shows how you’d use each one in a `let` statement:

Filename: src/main.rs

```rust
fn main() {
    // addition
    let sum = 5 + 10;
    // subtraction
    let difference = 95.5 - 4.3;
    // multiplication
    let product = 4 * 30;
    // division
    let quotient = 56.7 / 32.2;
    // remainder
    let remainder = 43 % 5;
}
```

Each expression in these statements uses a mathematical operator and evaluates to a single value, which is then bound to a variable. [Appendix B](https://doc.rust-lang.org/book/appendix-02-operators.html) contains a list of all operators that Rust provides.

#### The Boolean Type

As in most other programming languages, a Boolean type in Rust has two possible values: `true` and `false`. ==Booleans are one byte in size. The Boolean type in Rust is specified using `bool`.== For example:

Filename: src/main.rs

```rust
fn main() {
    let t = true;
    let f: bool = false; // with explicit type annotation
}
```

#### The Character Type

So far we’ve worked only with numbers, but Rust supports letters too. Rust’s `char` type is the language’s most primitive alphabetic type, and the following code shows one way to use it. (Note that `char` literals are specified with single quotes, as opposed to string literals, which use double quotes.)

Filename: src/main.rs

```rust
fn main() {
    let c = 'z';
    let z = 'ℤ';
    let heart_eyed_cat = '😻';
}
```

==Rust’s `char` type is four bytes in size and represents a Unicode Scalar Value,== which means it can represent a lot more than just ASCII. Accented letters; Chinese, Japanese, and Korean characters; emoji; and zero-width spaces are all valid `char` values in Rust. Unicode Scalar Values range from `U+0000` to `U+D7FF` and `U+E000` to `U+10FFFF` inclusive. However, a “character” isn’t really a concept in Unicode, so your human intuition for what a “character” is may not match up with what a `char` is in Rust. We’ll discuss this topic in detail in [“Storing UTF-8 Encoded Text with Strings”](https://doc.rust-lang.org/book/ch08-02-strings.html#storing-utf-8-encoded-text-with-strings) in Chapter 8.

### Compound Types

*Compound types* can group multiple values into one type. ==Rust has two primitive compound types: tuples and arrays.==

#### The Tuple Type

A tuple is a general way of grouping together a number of values with a variety of types into one compound type. ==Tuples have a fixed length: once declared, they cannot grow or shrink in size.==

We create a tuple by writing a comma-separated list of values inside parentheses. Each position in the tuple has a type, and the types of the different values in the tuple don’t have to be the same. We’ve added optional type annotations in this example:

Filename: src/main.rs

```rust
fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
}
```

The variable `tup` binds to the entire tuple, because a tuple is considered a single compound element. To get the individual values out of a tuple, we can use pattern matching to destructure a tuple value, like this:

Filename: src/main.rs

```rust
fn main() {
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);
}
```

This program first creates a tuple and binds it to the variable `tup`. It then uses a pattern with `let` to take `tup` and turn it into three separate variables, `x`, `y`, and `z`. This is called ==*destructuring*==, because it breaks the single tuple into three parts. Finally, the program prints the value of `y`, which is `6.4`.

==In addition to destructuring through pattern matching, we can access a tuple element directly by using a period (`.`) followed by the index of the value we want to access.== For example:

Filename: src/main.rs

```rust
fn main() {
    let x: (i32, f64, u8) = (500, 6.4, 1);
    let five_hundred = x.0;
    let six_point_four = x.1;
    let one = x.2;
}
```

This program creates a tuple, `x`, and then makes new variables for each element by using their respective indices. As with most programming languages, the first index in a tuple is 0.

#### The Array Type

Another way to have a collection of multiple values is with an *array*. Unlike a tuple, every element of an array must have the same type. Arrays in Rust are different from arrays in some other languages because ==arrays in Rust have a fixed length==, like tuples.

In Rust, the values going into an array are written as a comma-separated list inside square brackets:

Filename: src/main.rs

```rust
fn main() {
    let a = [1, 2, 3, 4, 5];
}
```

==Arrays are useful when you want your data allocated on the stack rather than the heap== (we will discuss the stack and the heap more in Chapter 4) or when you want to ensure you always have a fixed number of elements. An array isn’t as flexible as the vector type, though. A vector is a similar collection type provided by the standard library that *is* allowed to grow or shrink in size. If you’re unsure whether to use an array or a vector, you should probably use a vector. Chapter 8 discusses vectors in more detail.

An example of when you might want to use an array rather than a vector is in a program that needs to know the names of the months of the year. It’s very unlikely that such a program will need to add or remove months, so you can use an array because you know it will always contain 12 elements:

```rust
let months = ["January", "February", "March", "April", "May", "June", "July",
              "August", "September", "October", "November", "December"];
```

==You would write an array’s type by using square brackets, and within the brackets include the type of each element, a semicolon, and then the number of elements in the array,== like so:

```rust
let a: [i32; 5] = [1, 2, 3, 4, 5];
```

Here, `i32` is the type of each element. After the semicolon, the number `5` indicates the array contains five elements.

Writing an array’s type this way looks similar to an alternative syntax for initializing an array: ==if you want to create an array that contains the same value for each element, you can specify the initial value, followed by a semicolon, and then the length of the array in square brackets,== as shown here:

```rust
let a = [3; 5];
```

The array named `a` will contain `5` elements that will all be set to the value `3` initially. This is the same as writing `let a = [3, 3, 3, 3, 3];` but in a more concise way.

##### Accessing Array Elements

==An array is a single chunk of memory allocated on the stack. You can access elements of an array using indexing,== like this:

Filename: src/main.rs

```rust
fn main() {
    let a = [1, 2, 3, 4, 5];

    let first = a[0];
    let second = a[1];
}
```

##### Invalid Array Element Access

What happens if you try to access an element of an array that is past the end of the array? Say you change the example to the following code, which will compile but exit with an error when it runs:

Filename: src/main.rs

```rust
fn main() {
    let a = [1, 2, 3, 4, 5];
    let index = 10;

    let element = a[index];

    println!("The value of element is: {}", element);
}
```

Running this code using `cargo run` produces the following result:

```console
$ cargo run
   Compiling arrays v0.1.0 (file:///projects/arrays)
error: this operation will panic at runtime
 --> src/main.rs:5:19
  |
5 |     let element = a[index];
  |                   ^^^^^^^^ index out of bounds: the length is 5 but the index is 10
  |
  = note: `#[deny(unconditional_panic)]` on by default

error: aborting due to previous error

error: could not compile `arrays`

To learn more, run the command again with --verbose.
```

The compilation didn’t produce any errors, but the program resulted in a *runtime* error and didn’t exit successfully. When you attempt to access an element using indexing, Rust will check that the index you’ve specified is less than the array length. If the index is greater than or equal to the array length, Rust will panic.

This is the first example of Rust’s safety principles in action. In many low-level languages, this kind of check is not done, and when you provide an incorrect index, invalid memory can be accessed. Rust protects you against this kind of error by immediately exiting instead of allowing the memory access and continuing. Chapter 9 discusses more of Rust’s error handling.