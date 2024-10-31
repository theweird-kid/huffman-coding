# Huffman Coding

Huffman Coding is a lossless data compression algorithm. It assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This project implements Huffman Coding in C++.

## Features

- Build Huffman Tree from input text
- Generate Huffman Codes for characters
- Encode text using Huffman Codes
- Decode encoded text back to original text
- Log compression details including original size, compressed size, and compression ratio
- Display binary representation of encoded string

## Getting Started

### Prerequisites

- C++ compiler with C++20 support (e.g., `g++`)
- Make utility

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/theweird-kid/huffman-coding.git
    cd huffman-coding
    ```

2. Build the project using `make`:
    ```sh
    make hc
    ```

### Running the Project

1. Run the executable:
    ```sh
    ./main
    ```

### Cleaning Up

1. Clean the build artifacts:
    ```sh
    make clean
    ```

## Usage

Replace the `text` variable in `main.cc` with your input text. The program will output the encoded string, decoded string, and compression details.

### Example

```cpp
std::string text = "your text here"; 