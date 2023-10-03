import React, { useState } from "react";
import "./BookReview.css";

const BookReview = ({ book }) => {
  const [reviewText, setReviewText] = useState("");
  const [reviews, setReviews] = useState([]);

  const handleReviewSubmit = () => {
    if (reviewText.trim() !== "") {
      setReviews([...reviews, reviewText]);
      setReviewText("");
    }
  };

  return (
    <div className="book-reviews">
      <h3>Book Reviews</h3>
      <ul>
        {reviews.map((review, index) => (
          <li key={index}>{review}</li>
        ))}
      </ul>
      <textarea
        rows="3"
        value={reviewText}
        onChange={(e) => setReviewText(e.target.value)}
        placeholder="Write your review..."
      />
      <button onClick={handleReviewSubmit}>Submit Review</button>
    </div>
  );
};

export default BookReview;
