import React, { useState } from "react";
import BookReview from "./BookReview"; // Import the BookReview component
import "./BookCard.css";

const BookCard = ({ book }) => {
  const [showReviews, setShowReviews] = useState(false);

  const toggleReviews = () => {
    setShowReviews(!showReviews);
  };

  return (
    <div className="book-card">
      <img
        src={book.imageLinks?.thumbnail || "no-image-available.jpg"}
        alt={book.title}
        className="book-cover"
      />
      <h2>{book.title}</h2>
      <p>Author: {book.authors ? book.authors.join(", ") : "Unknown"}</p>
      <p>{book.description || "No description available."}</p>

      <button onClick={toggleReviews}>
        {showReviews ? "Hide Reviews" : "Show Reviews"}
      </button>

      {showReviews && <BookReview book={book} />}
    </div>
  );
};

export default BookCard;
