import React from 'react';

function BookList({ books }) {
  if (books.length === 0) {
    return <p>No books found.</p>;
  }

  return (
    <div className="book-list">
      <h2>Books</h2>
      <ul>
        {books.map((book) => (
          <li key={book.id}>
            <a href={`/book/${book.id}`}>{book.title}</a>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default BookList;
