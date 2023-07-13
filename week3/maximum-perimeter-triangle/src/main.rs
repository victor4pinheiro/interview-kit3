use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */

fn maximumPerimeterTriangle(sticks: &[i32]) -> Vec<i32> {
    let mut sticks_sorted = sticks.to_vec();
    sticks_sorted.sort_unstable();
    let mut result: Vec<i32> = vec![-1];
    let length = sticks_sorted.len();

    for i in 0..length - 2 {
        if sticks_sorted[i] + sticks_sorted[i + 1] <= sticks_sorted[i + 2] {
           continue; 
        } else if sticks_sorted[i + 1] + sticks_sorted[i + 2] <= sticks_sorted[i] {
            continue;
        } else if sticks_sorted[i] + sticks_sorted[i + 2] <= sticks_sorted[i + 1] {
            continue;
        } else {
            result = vec![sticks_sorted[i], sticks_sorted[i + 1], sticks_sorted[i + 2]];
        }
    }
    return result;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let sticks: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    let result = maximumPerimeterTriangle(&sticks);

    for i in 0..result.len() {
        write!(&mut fptr, "{}", result[i]).ok();

        if i != result.len() - 1 {
            write!(&mut fptr, " ").ok();
        }
    }

    writeln!(&mut fptr).ok();
}

