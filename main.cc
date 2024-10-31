#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <bitset>

// Node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    // Constructor
    Node(char ch, int freq, Node *left = nullptr, Node *right = nullptr)
        : ch(ch), freq(freq), left(left), right(right)
    {}
};

// Comparator for the priority_queue
struct Compare {
    bool operator () (Node *left, Node *right) {
        return left->freq > right->freq;
    }
};

// Traverse the Huffman Tree and store Huffman codes in a map
void generateCodes(Node *root, std::unordered_map<char, std::string>& huffmanCode, std::string str)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, huffmanCode, str + "0");
    generateCodes(root->right, huffmanCode, str + "1");
}

// Build the Huffman Tree and generate Codes
Node* buildHuffmanTree(const std::unordered_map<char, int>& freq)
{
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (auto &pair: freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    return pq.top();
}

// Encode the input data
std::string encode(const std::string& text, std::unordered_map<char, std::string>& huffmanCode)
{
    std::string encoded_string;
    for (char ch: text) {
        encoded_string += huffmanCode[ch];
    }

    return encoded_string;
}

// Decode the encoded data
std::string decode (const std::string& encoded_string, Node* root)
{
    std::string decoded_string;
    Node* curr = root;

    for (char bit: encoded_string)
    {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;
        
        if (!curr->left && !curr->right) {
            decoded_string += curr->ch;
            curr = root;
        }
    }

    return decoded_string;
}

// Function to convert a string to its binary representation
std::string to_binary(const std::string &str) {
    std::string binaryString;
    for (char ch : str) {
        binaryString += std::bitset<8>(ch).to_string();
    }
    return binaryString;
}

int main(int argc, char* argv[])
{   
    std::cout << "\033[1;37mHuffman Coding Example \033[0m" << std::endl;
    
    std::string text = "this is an example text for huffman encoding";

    // Frequency Analysis
    std::unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Build the huffman Tree
    Node *root = buildHuffmanTree(freq);

    // Generate Huffman Codes
    std::unordered_map<char, std::string> huffmanCode;
    generateCodes(root, huffmanCode, "");

    // Original String
    std::cout << "Original String: " << text << std::endl;

    // string without compression
    std::string no_compression = to_binary(text);
    std::cout << "\033[1;35mWithout Compression: \033[0m" << no_compression << std::endl;

    // Encode 
    std::string encoded_string = encode(text, huffmanCode);
    std::cout << "\033[1;33mEncoded String: \033[0m" << encoded_string << std::endl;

    // Decode
    std::string decoded_string = decode(encoded_string, root);
    std::cout << "\033[1;31mDecoded String: \033[0m" << decoded_string << std::endl;

    // Log compression details with colors
    size_t originalSize = text.size() * 8; // size in bits
    size_t compressedSize = encoded_string.size(); // size in bits
    double compressionRatio = (double)compressedSize / originalSize;

    std::cout << "\033[1;32mOriginal Size (bits): " << originalSize << "\033[0m" << std::endl;
    std::cout << "\033[1;34mCompressed Size (bits): " << compressedSize << "\033[0m" << std::endl;
    std::cout << "\033[1;36mCompression Ratio: " << compressionRatio << "\033[0m" << std::endl;

    std::cout << std::endl;
    return 0;
}