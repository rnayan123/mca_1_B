import React, { useState, useEffect } from "react";
import BookCard from "./BookCard";
import "./BookList.css";

const BookList = () => {
  const [books, setBooks] = useState([]);
  const [searchTerm, setSearchTerm] = useState("");

  useEffect(() => {
    const apiUrl = `https://www.googleapis.com/books/v1/volumes?q=${searchTerm}`;
    fetch(apiUrl)
      .then((response) => response.json())
      .then((data) => {
        if (data.items) {
          setBooks(data.items);
        }
      })
      .catch((error) => console.error(error));
  }, [searchTerm]);

  const handleSearch = (event) => {
    setSearchTerm(event.target.value);
  };

  return (
    <div className="book-list">
      <input
        type="text"
        placeholder="Search books..."
        onChange={handleSearch}
      />
      <div className="book-cards">
        {books.map((book) => (
          <BookCard key={book.id} book={book.volumeInfo} />
        ))}
      </div>
    </div>
  );
};

export default BookList;
