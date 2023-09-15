document.addEventListener("DOMContentLoaded", function () {
    const fetchBooksButton = document.getElementById("fetchBooks");
    const bookList = document.getElementById("bookList");


    fetchBooksButton.addEventListener("click", function () {
        const apiUrl = "book.json"; 

        fetch(apiUrl)
            .then(response => {
                if (!response.ok) {
                    throw new Error(`Network response was not ok (Status: ${response.status})`);
                }
                return response.json();
            })
            .then(booksData => {
                displayBooks(booksData);
            })
            .catch(error => {
                console.error("Error fetching data:", error);
            });
    });

    // Function to display the list of books
    function displayBooks(booksData) {
        // Clear the existing content in the book list
        bookList.innerHTML = "";

        const ol = document.createElement("ol");

        booksData.forEach(function (book) {
            const li = document.createElement("li");
            li.textContent = `${book.author} lives in ${book.country} has written a book of title ${book.tile} in ${book.language} language` ;
            
            ol.appendChild(li)
        
        });

        // Append the list to the book list div
        bookList.appendChild(ol);
    
    }
});
