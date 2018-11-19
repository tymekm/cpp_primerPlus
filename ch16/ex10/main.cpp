#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::shared_ptr;

struct Review
{
    string title;
    double price;
    int rating;
};

bool sortTitle(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool sortRating(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool sortPrice(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool fillReview(shared_ptr<Review> rr);
void showReview(const shared_ptr<Review> rr);

int main()
{
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp (new Review); 
    while (fillReview(temp))
    {
	books.push_back(temp);
	temp.reset(new Review);
    }
    vector<shared_ptr<Review>> booksSorted = books;
    if (books.size() > 0)
    {
	char choice;
	cout << "Choose a sorting option (q to quit)\n";
	cout << "Original: o           Title: t\n";
	cout << "Rating ascending: r   Rating descending: R\n";
	cout << "Price ascending: p    Price descending: P\n";

	while (cin >> choice && choice != 'q')
	{
	    switch (choice) 
	    {
	        case 'o':
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	        case 't':
		    sort(booksSorted.begin(), booksSorted.end(), sortTitle);
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	        case 'r':
		    sort(booksSorted.begin(), booksSorted.end(), sortRating);
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	        case 'R':
		    sort(booksSorted.rbegin(), booksSorted.rend(), sortRating);
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	        case 'p':
		    sort(booksSorted.begin(), booksSorted.end(), sortPrice);
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	        case 'P':
		    sort(booksSorted.rbegin(), booksSorted.rend(), sortPrice);
		    for_each(booksSorted.begin(), booksSorted.end(),
			    showReview);
		    break;
	    	
	    }
	    cout << "Choose a sorting option (q to quit)\n";
	    cout << "Original: o           Title: t\n";
	    cout << "Rating ascending: r   Rating descending: R\n";
	    cout << "Price ascending: p    Price descending: P\n";
	}
    }
    else
	cout << "No entries. ";
    cout << "Bye!\n";
    return 0;
}

bool sortTitle(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
    if (r1->title < r2->title)
	return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
	return true;
    else
	return false;
}

bool sortRating(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
    if (r1->rating < r2->rating)
	return true;
    else
	return false;
}

bool sortPrice(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
    if (r1->price < r2->price)
	return true;
    else
	return false;
}

bool fillReview(shared_ptr<Review> rr)
{
    cout << "Enter book title (quit to quit): ";
    getline(cin, rr->title);
    if (rr->title == "quit")
	return false;
    cout << "Enter book rating: ";
    cin >> rr->rating;
    if (!cin)
	return false;
    while (cin.get() != '\n')
	continue;
    cout << "Enter book price: ";
    cin >> rr->price;
    if (!cin)
	return false;
    while (cin.get() != '\n')
	continue;
    return true;
}

void showReview(const shared_ptr<Review> rr)
{
    cout << rr->rating << '\t' << rr->title << '\t' << rr->price << '\n';
}
