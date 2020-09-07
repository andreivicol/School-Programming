#include <iostream>
#include <vector>
#include <numeric> // numeric for std::accumulate
#include <algorithm> // alg for std::find

std::vector<int> books;
int pages, sizes, number, placeHolder;

int main() {

    std::cin >> pages >> sizes;

    while(std::cin>>number){
        std::cin >> number; //number of books
        std::cin >> placeHolder; // pages in book
        for (int i = 0; i != number; ++i) {
            books.push_back(placeHolder); // append 'number' copies of said book
        }
    }

    std::vector<std::vector<int>> shelves(books.size(), std::vector<int>{pages}); // create std::vector of std::vector
    // having books.size() length(in case only 1 book fits per shelf), each initialized w/ 'pages' value

    for (const auto &book : books) { // for each book in books
        for (auto it = shelves.begin(); it != shelves.end(); ++it) { // scan all shelves starting with the first
            if (std::accumulate(it->begin(), it->end(), 0) >= book) { // check if sum of all pages is >= than current book
                it->push_back(-book); // append '-book' such that std::accumulate is actually diff between 'pages' and added books
                break; // break to not add the same book multiple times
            }
        }
    }

    auto shelvesFinal = std::vector<std::vector<int>>(shelves.begin(), std::find(shelves.begin(), shelves.end(),
                                                                                 std::vector<int>{pages}));
    // vector constructor initializes 'shelvesFinal' to be a slice of 'shelves' that starts at the beginning and ends
    // one before the first occurrence of a vector only containing 'pages'
    // read std::find parameters and return

    for (const auto &shelf : shelvesFinal) { // always use const & when only reading/printing a value
        for (auto it = shelf.begin() + 1; it != shelf.end(); ++it) {
            std::cout << -*it << " ";
        }
        std::cout << '\n';
    }

    return 0;
}