import React from "react";

const Book = ({ book }) => {
  return (
    <div className="book">
      <h2>{book.title}</h2>
      <p>Author: {book.author}</p>
      <p>{book.description}</p>
    </div>
  );
};

export default Book;
