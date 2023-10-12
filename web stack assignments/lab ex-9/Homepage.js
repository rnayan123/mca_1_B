import React, { useState, useEffect } from 'react';
import SearchBar from 'Searchbar';
import BookList from 'BookList';

function HomePage() {
  // Define state to store books and search term
  const [books, setBooks] = useState([]);
  const [searchTerm, setSearchTerm] = useState('');
  const [filteredBooks, setFilteredBooks] = useState([]);

  useEffect(() => {
    // Mock API call to fetch book data (replace with actual API call)
    const fetchBooks = async () => {
      try {
        const response = await fetch('/api/books'); // Adjust the API endpoint
        if (response.ok) {
          const data = await response.json();
          setBooks(data);
        }
      } catch (error) {
        console.error('Error fetching book data:', error);
      }
    };

    fetchBooks();
  }, []); // Empty dependency array ensures this effect runs only once

  useEffect(() => {
    // Filter books based on the search term
    const filtered = books.filter((book) =>
      book.title.toLowerCase().includes(searchTerm.toLowerCase())
    );
    setFilteredBooks(filtered);
  }, [searchTerm, books]);

  return (
    <div>
      <h1>Online Bookstore</h1>
      <SearchBar setSearchTerm={setSearchTerm} />
      <BookList books={filteredBooks} />
    </div>
  );
}

export default HomePage;
