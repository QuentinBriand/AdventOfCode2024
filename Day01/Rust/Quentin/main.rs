use std::fs::File;
use std::io::BufReader;
use std::io::prelude::*;

fn my_atoi(s: &str, start: usize) -> i32 {
    let mut i = start;
    let mut result = 0;
    let mut sign = 1;
    if s.as_bytes()[i] == 45 {
        sign = -1;
        i += 1;
    }
    while i < s.len() && s.as_bytes()[i] >= 48 && s.as_bytes()[i] <= 57 {
        result = result * 10 + (s.as_bytes()[i] - 48) as i32;
        i += 1;
    }
    return result * sign;
}

fn main() -> std::io::Result<()> {
    let file = File::open("./resources/Day01/Quentin.txt")?;
    let mut buf_reader = BufReader::new(file);
    let mut contents = String::new();
    buf_reader.read_to_string(&mut contents)?;

    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();

    let mut counts: std::collections::HashMap<i32, i32> = std::collections::HashMap::new();

    for line in contents.lines() {
        let first_number = my_atoi(line, 0);
        let mut next_index = 3;
        if first_number != 1 {
            next_index += (first_number as f64).log10().ceil() as usize;
        } else {
            next_index += 1;
        }
        let second_number = my_atoi(line, next_index);
        
        left.push(first_number);
        right.push(second_number);

        let count = counts.entry(second_number).or_insert(0);
        *count += 1;
    }

    left.sort();
    right.sort();

    let mut sum = 0;
    for i in 0..left.len() {
        sum += (left[i] - right[i]).abs();
    }
    println!("Sum: {}", sum);

    let mut similarity = 0;
    for i in 0..left.len() {
        if let Some(count) = counts.get(&left[i]) {
            similarity += left[i] * count;
        }
    }
    println!("Similarity: {}", similarity);

    Ok(())
}